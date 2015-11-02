/* ----------------------------------------------------------------------------
 * Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * A singly linked list type for `int`s, implementing the `List` interface.
 *
 * (See documentation in "list.h")
 */

#ifndef LIST1_H
#define LIST1_H
// ----------------------------------------------------------------------------

#include "list.h"

class List1 : public List {
    private:

        // --------------------------------------------------------------------
        // types
        // --------------------------------------------------------------------

        struct Node {
            Node * next;
            int value;
        };
        /**
         * Our `List` will be made up of `Node`s.  Each node will have
         * - A pointer to the next node (the node after it in the list) (or
         *   `nullptr` if it's the last node).
         * - A value (the actual data that's supposed to be at this position in
         *   the list).
         *
         * Notes:
         * - Recall that a `struct` is just like a `class` in C++ except that
         *   its default access specifier is `public` rather than `private`.
         *   In keeping with common practice (and what one would *have* to do
         *   in C) this `struct` has no explicit access specifier, and only
         *   contains data members.
         */

        // --------------------------------------------------------------------
        // data members
        // --------------------------------------------------------------------

        Node * mHead;
        /**
         * A pointer to the first element of the list.
         */

        int mLength;
        /**
         * The length of the list (to make normalizing indices efficient).
         */

    public:

        // --------------------------------------------------------------------
        // constructors and destructors
        // --------------------------------------------------------------------

        List1();
        /**
         * Create a new list, initializing all private data members.
         */

        ~List1();
        /**
         * (See documentation in "list.h")
         */

        // --------------------------------------------------------------------
        // getters and setters
        // --------------------------------------------------------------------

        int length() const;
        /**
         * (See documentation in "list.h")
         */

        // --------------------------------------------------------------------
        // public list operations
        // --------------------------------------------------------------------

        void insert(int index, const int value);
        /**
         * (See documentation in "list.h")
         */

        int remove(int index);
        /**
         * (See documentation in "list.h")
         */

        int peek(int index) const;
        /**
         * (See documentation in "list.h")
         */
};

// ----------------------------------------------------------------------------
#endif  // LIST1_H

