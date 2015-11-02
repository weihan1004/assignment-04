/* ----------------------------------------------------------------------------
 * Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

#include "list2.h"

// ----------------------------------------------------------------------------
// private list operations
// ----------------------------------------------------------------------------

List2::Node * List2::find(int index) const {
    if (mLength == 0)
        return nullptr;

    index %= mLength;
    if (index < 0)
        index += mLength;

    Node * n;

    // closer to the beginning of the list
    if (index+1 <= mLength/2) {
        n = mHead;
        for (int i = 0; i < index; i++)
            n = n->next;

    // closer to the end of the list (or in the middle)
    } else {
        n = mTail;
        for (int i = mLength-1; i > index; i--)
            n = n->previous;
    }

    return n;
}

void List2::remove(Node * n) {
    if (n == nullptr)
        return;

    if (mLength == 1) {
        // only `Node`
        mHead = nullptr;
        mTail = nullptr;

    } else if (n == mHead) {
        // first `Node`
        mHead = n->next;
        n->next->previous = nullptr;

    } else if (n == mTail) {
        // last `Node`
        mTail = n->previous;
        n->previous->next = nullptr;

    } else {
        // otherwise
        n->previous->next = n->next;
        n->next->previous = n->previous;
    }

    delete n;
    mLength--;
}

// ----------------------------------------------------------------------------
// constructors and destructors
// ----------------------------------------------------------------------------

List2::List2() : mHead(nullptr), mTail(nullptr), mLength(0) {}

List2::~List2() {
    while (mHead != nullptr)
        remove(mHead);
}

// ----------------------------------------------------------------------------
// getters and setters
// ----------------------------------------------------------------------------

int List2::length() const { return mLength; }

// ----------------------------------------------------------------------------
// public list operations
// ----------------------------------------------------------------------------

void List2::insert(int index, const int value) {
    Node * n = new Node;  // may throw `std::bad_alloc`

    mLength++;
    index %= mLength;
    if (index < 0)
        index += mLength;

    n->value = value;

    if (mLength == 1) {
        // only `Node`
        n->previous = nullptr;
        n->next = nullptr;

        mHead = n;
        mTail = n;

    } else if (index == 0) {
        // first `Node`
        n->previous = nullptr;
        n->next = mHead;

        mHead->previous = n;

        mHead = n;

    } else if (index == mLength-1) {
        // last `Node`
        n->previous = mTail;
        n->next = nullptr;

        mTail->next = n;

        mTail = n;

    } else {
        // otherwise
        Node * p = find(index-1);

        n->previous = p;
        n->next = p->next;

        n->previous->next = n;
        n->next->previous = n;
    }
}

int List2::remove(int index) {
    if (mLength == 0)
        return 0;  // list is empty

    Node * n = find(index);
    int value = n->value;

    remove(n);
    return value;
}

int List2::peek(int index) const {
    if (mLength == 0)
        return 0;  // list is empty

    return find(index)->value;
}

