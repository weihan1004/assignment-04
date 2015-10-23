/* ----------------------------------------------------------------------------
 * Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

#include "list1.h"

// ----------------------------------------------------------------------------
// constructors and destructors
// ----------------------------------------------------------------------------

List1::List1() : mHead(nullptr), mLength(0) {}

List1::~List1() {
    while (mHead != nullptr)
        remove(0);
}

// ----------------------------------------------------------------------------
// getters and setters
// ----------------------------------------------------------------------------

int List1::length() const { return mLength; }

// ----------------------------------------------------------------------------
// public list operations
// ----------------------------------------------------------------------------

void List1::insert(int index, const int value) {
    Node * n = new Node;  // may throw `std::bad_alloc`
    n->value = value;

    mLength++;
    index %= mLength;
    if (index < 0)
        index += mLength;

    if (index == 0) {
        // insert as first element
        n->next = mHead;
        mHead = n;

    } else {
        // find the previous element
        Node * p = mHead;
        for (int i = 1; i < index; i++)
            p = p->next;

        // insert after
        n->next = p->next;
        p->next = n;
    }
}

int List1::remove(int index) {
    if (mHead == nullptr)
        return 0;  // list is empty

    index %= mLength;
    if (index < 0)
        index += mLength;

    Node * n;
    int value;

    if (index == 0) {
        // remove first element
        n = mHead;
        mHead = mHead->next;

    } else {
        // find the previous element
        Node * p = mHead;
        for (int i = 1; i < index; i++)
            p = p->next;

        // remove the one after
        n = p->next;
        p->next = p->next->next;
    }

    value = n->value;

    mLength--;
    delete n;
    return value;
}

int List1::peek(int index) const {
    if (mHead == nullptr)
        return 0;  // list is empty

    index = (index < 0) ? index % mLength + mLength : index % mLength;

    // find the element
    Node * n = mHead;
    for (int i = 0; i < index; i++)
        n = n->next;

    return n->value;
}

