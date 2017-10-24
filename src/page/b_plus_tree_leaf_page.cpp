/**
 * b_plus_tree_leaf_page.cpp
 */

#include <sstream>
#include <include/page/b_plus_tree_internal_page.h>

#include "common/exception.h"
#include "common/rid.h"
#include "page/b_plus_tree_leaf_page.h"

namespace cmudb {

/*****************************************************************************
 * HELPER METHODS AND UTILITIES
 *****************************************************************************/

/**
 * Init method after creating a new leaf page
 * Including set page type, set current size to zero, set page id/parent id, set
 * next page id and set max size
 */
    INDEX_TEMPLATE_ARGUMENTS
    void B_PLUS_TREE_LEAF_PAGE_TYPE::Init(page_id_t page_id, page_id_t parent_id) {
        SetPageType(IndexPageType::LEAF_PAGE);
        SetSize(0);
        SetPageId(page_id);
        SetParentPageId(parent_id);
        // TODO: what is next page id
        SetNextPageId(INVALID_PAGE_ID);
        SetMaxSize((PAGE_SIZE - HEADER_SIZE) / (sizeof(KeyType) + sizeof(ValueType)));
    }

/**
 * Helper methods to set/get next page id
 */
    INDEX_TEMPLATE_ARGUMENTS
    page_id_t B_PLUS_TREE_LEAF_PAGE_TYPE::GetNextPageId() const {
        return next_page_id_;
    }

    INDEX_TEMPLATE_ARGUMENTS
    void B_PLUS_TREE_LEAF_PAGE_TYPE::SetNextPageId(page_id_t next_page_id) {
        next_page_id_ = next_page_id_;
    }

/**
 * Helper method to find the first index i so that array[i].first >= key
 * NOTE: This method is only used when generating index iterator
 */
    INDEX_TEMPLATE_ARGUMENTS
    int B_PLUS_TREE_LEAF_PAGE_TYPE::KeyIndex(
            const KeyType &key, const KeyComparator &comparator) const {
        for (int i = 0; i < GetSize(); i++) {
            // TODO: same for both eaqual & larger than?
            if (comparator.operator()(array[i].first, key) >= 0) {
                return i;
            }
        }
        return -1;
    }

/*
 * Helper method to find and return the key associated with input "index"(a.k.a
 * array offset)
 */
    INDEX_TEMPLATE_ARGUMENTS
    KeyType B_PLUS_TREE_LEAF_PAGE_TYPE::KeyAt(int index) const {
        KeyType key;
        return array[index].first;
    }

/*
 * Helper method to find and return the key & value pair associated with input
 * "index"(a.k.a array offset)
 */
    INDEX_TEMPLATE_ARGUMENTS
    const MappingType &B_PLUS_TREE_LEAF_PAGE_TYPE::GetItem(int index) {
        return array[index];
    }

/*****************************************************************************
 * INSERTION
 *****************************************************************************/
/*
 * Insert key & value pair into leaf page ordered by key
 * @return  page size after insertion
 */
    INDEX_TEMPLATE_ARGUMENTS
    int B_PLUS_TREE_LEAF_PAGE_TYPE::Insert(const KeyType &key,
                                           const ValueType &value,
                                           const KeyComparator &comparator) {
        // TODO: Bi-search
        int i = 0;
        for (; i < GetSize(); i++) {
            if (comparator.operator()(GetItem(i).first, key) == key) {
                // TODO: change value or not? return value?
                return GetSize();
            }
            if (comparator.operator()(GetItem(i).first, key) == key) {
                break;
            }
        }
        for (int j = GetSize() - 1; j >= i; j--) {
            array[j + 1] = array[j];
        }
        array[i].first = key;
        array[i].second = value;
        SetSize(GetSize() + 1);
        return GetSize();
    }

/*****************************************************************************
 * SPLIT
 *****************************************************************************/
/*
 * Remove half of key & value pairs from this page to "recipient" page
 */
    INDEX_TEMPLATE_ARGUMENTS
    void B_PLUS_TREE_LEAF_PAGE_TYPE::MoveHalfTo(
            BPlusTreeLeafPage *recipient,
            __attribute__((unused)) BufferPoolManager *buffer_pool_manager) {
        recipient->CopyHalfFrom(array, GetSize());
        SetSize(GetSize() / 2);
//        int size = (GetSize() + 1) / 2;
//        recipient->CopyHalfFrom(array, size);
//        for (int i = size; i < GetSize(); i++) {
//            array[i - size] = array[i];
//        }
//        SetSize(GetSize() - size);
    }

    INDEX_TEMPLATE_ARGUMENTS
    void B_PLUS_TREE_LEAF_PAGE_TYPE::CopyHalfFrom(MappingType *items, int size) {
        int half = size - (size / 2);
        for (int i = size - half; i < size; i++) {
            array[i - size + half] = items[i];
        }
        SetSize(half);
    }

/*****************************************************************************
 * LOOKUP
 *****************************************************************************/
/*
 * For the given key, check to see whether it exists in the leaf page. If it
 * does, then store its corresponding value in input "value" and return true.
 * If the key does not exist, then return false
 */
    INDEX_TEMPLATE_ARGUMENTS
    bool B_PLUS_TREE_LEAF_PAGE_TYPE::Lookup(const KeyType &key, ValueType &value,
                                            const KeyComparator &comparator) const {
        // TODO: bi-search
        for (int i = 0; i < GetSize(); i++) {
            if (comparator.operator()(key, array[i].first) == 0) {
                value = array[i].second;
                return true;
            }
        }
        return false;
    }

/*****************************************************************************
 * REMOVE
 *****************************************************************************/
/*
 * First look through leaf page to see whether delete key exist or not. If
 * exist, perform deletion, otherwise return immdiately.
 * NOTE: store key&value pair continuously after deletion
 * @return   page size after deletion
 */
    INDEX_TEMPLATE_ARGUMENTS
    int B_PLUS_TREE_LEAF_PAGE_TYPE::RemoveAndDeleteRecord(
            const KeyType &key, const KeyComparator &comparator) {
        // TODO: bi-search
        for (int i = 0; i < GetSize(); i++) {
            if (comparator.operator()(key, array[i].first) == 0) {
                for (int j = i + 1; j < GetSize(); j++) {
                    array[j - 1] = array[j];
                }
                SetSize(GetSize() - 1);
                return GetSize();
            }
        }
        return GetSize();
    }

/*****************************************************************************
 * MERGE
 *****************************************************************************/
/*
 * Remove all of key & value pairs from this page to "recipient" page, then
 * update next page id
 */
    INDEX_TEMPLATE_ARGUMENTS
    void B_PLUS_TREE_LEAF_PAGE_TYPE::MoveAllTo(BPlusTreeLeafPage *recipient,
                                               int, BufferPoolManager *) {
        recipient->CopyAllFrom(array, GetSize());
        SetSize(0);
        // TODO: what to change
        SetNextPageId(INVALID_PAGE_ID);
    }

    INDEX_TEMPLATE_ARGUMENTS
    void B_PLUS_TREE_LEAF_PAGE_TYPE::CopyAllFrom(MappingType *items, int size) {
        for (int i = 0; i < size; i++) {
            array[i + GetSize()] = items[i];
        }
        IncreaseSize(size);
    }

/*****************************************************************************
 * REDISTRIBUTE
 *****************************************************************************/
/*
 * Remove the first key & value pair from this page to "recipient" page, then
 * update relavent key & value pair in its parent page.
 */
    INDEX_TEMPLATE_ARGUMENTS
    void B_PLUS_TREE_LEAF_PAGE_TYPE::MoveFirstToEndOf(
            BPlusTreeLeafPage *recipient,
            BufferPoolManager *buffer_pool_manager) {
        recipient->CopyLastFrom(array[0]);
        BPlusTreeInternalPage* parent = (BPlusTreeInternalPage*)buffer_pool_manager->FetchPage(GetParentPageId());
        //TODO: what is key
        parent->SetKeyAt(parent->ValueIndex(GetPageId()), array[1]);
        for (int i = 1; i < GetSize(); i++) {
            array[i - 1] = array[i];
        }
        SetSize(GetSize() - 1);
    }

    INDEX_TEMPLATE_ARGUMENTS
    void B_PLUS_TREE_LEAF_PAGE_TYPE::CopyLastFrom(const MappingType &item) {
        array[GetSize()] = item;
        SetSize(GetSize() + 1);
    }
/*
 * Remove the last key & value pair from this page to "recipient" page, then
 * update relavent key & value pair in its parent page.
 */
    INDEX_TEMPLATE_ARGUMENTS
    void B_PLUS_TREE_LEAF_PAGE_TYPE::MoveLastToFrontOf(
            BPlusTreeLeafPage *recipient, int parentIndex,
            BufferPoolManager *buffer_pool_manager) {
        recipient->CopyFirstFrom(array[0], parentIndex, buffer_pool_manager);
        SetSize(GetSize() - 1);
    }

    INDEX_TEMPLATE_ARGUMENTS
    void B_PLUS_TREE_LEAF_PAGE_TYPE::CopyFirstFrom(
            const MappingType &item, int parentIndex,
            BufferPoolManager *buffer_pool_manager) {
        for (int i = GetSize() - 1; i >= 0; i--) {
            array[i + 1] = array[i];
        }
        array[0] = item;
        BPlusTreeInternalPage* parent = (BPlusTreeInternalPage*)buffer_pool_manager->FetchPage(GetParentPageId());
        //TODO: what is key
        parent->SetKeyAt(parent->ValueIndex(GetPageId()), array[1]);
    }

/*****************************************************************************
 * DEBUG
 *****************************************************************************/
    INDEX_TEMPLATE_ARGUMENTS
    std::string B_PLUS_TREE_LEAF_PAGE_TYPE::ToString(bool verbose) const {
        if (GetSize() == 0) {
            return "";
        }
        std::ostringstream stream;
        if (verbose) {
            stream << "[pageId: " << GetPageId() << " parentId: " << GetParentPageId()
                   << "]<" << GetSize() << "> ";
        }
        int entry = 0;
        int end = GetSize();
        bool first = true;

        while (entry < end) {
            if (first) {
                first = false;
            } else {
                stream << " ";
            }
            stream << std::dec << array[entry].first;
            if (verbose) {
                stream << "(" << array[entry].second << ")";
            }
            ++entry;
        }
        return stream.str();
    }

    template
    class BPlusTreeLeafPage<GenericKey<4>, RID,
            GenericComparator<4>>;

    template
    class BPlusTreeLeafPage<GenericKey<8>, RID,
            GenericComparator<8>>;

    template
    class BPlusTreeLeafPage<GenericKey<16>, RID,
            GenericComparator<16>>;

    template
    class BPlusTreeLeafPage<GenericKey<32>, RID,
            GenericComparator<32>>;

    template
    class BPlusTreeLeafPage<GenericKey<64>, RID,
            GenericComparator<64>>;
} // namespace cmudb
