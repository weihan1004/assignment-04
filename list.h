/* ----------------------------------------------------------------------------
 * Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * An interface for lists containing `int`s.
 *
 *
 * Implementation notes:
 *
 * - In keeping with C++ conventions for arrays, the index of the first `Node`
 *   is 0.
 *
 * - An index passed to any of these functions is normalized before use by
 *   taking `index %= length()`, and then `index += length()` if necessary to
 *   make `index` positive.
 *     - This has the effect of making all integers valid indices, so we don't
 *       have to worry about index out of bounds errors.
 *     - This also has the effect of making the list appear circular, which can
 *       be convenient (e.g. the last element will be the `-1`st element, as in
 *       Python).
 *     - In an implementation, it would probably be better to keep a variable,
 *       `mLength`, and use that instead of `length()` in any calculations.
 *
 * - All objects are allocated on the heap (or free store).  Errors are ignored
 *   (for now) but if `new` is used and allocation fails, a `std::bad_alloc`
 *   will be thrown (or simply not caught).
 *
 *
 * Notes:
 *
 * - We'll probably generalize this class using templates later.
 *
 * - In this class, we use `m` (for "member") as a prefix for private data
 *   members.
 *     - It is common practice in C++ to prefix or suffix the names of private
 *       data members in order to 1) make it obvious that they are private data
 *       members, and 2) avoid name conflicts with functions (e.g. `mLength`
 *       could not be called simply `length` because `length()` is a function,
 *       and `length` is short for `&length`, which is the address of the
 *       function `length()`) and other data members.
 *
 * - We use `length()` instead of `getLength()` in keeping with the `length()`
 *   method on `string`, and because it very well could be more than just a
 *   getter: if we the implementation doesn't have an `mLength` variable, or
 *   similar, `length()` will have to count the elements in the list.
 *
 * - What exactly a `Node` is will vary depending on the implementation, so
 *   each implementation must create its own.
 *     - For example, a singly linked list might have `Node` defined as
 *       `private` inside its class, as a `struct` containing a `Node * next`
 *       and an `int value`.  A doubly linked list would also need its `Node`
 *       to contain a `Node * previous`.
 */

#ifndef LIST_H
#define LIST_H
// ----------------------------------------------------------------------------

class List {
    public:

        virtual ~List() = default;
        /**
         * Destruct a list, first destructing all elements of the list.
         */

        virtual int length() const = 0;
        /**
         * Returns the number of elements in the list.
         */

        virtual void insert(int index, const int value) = 0;
        /**
         * Insert the value in the list so that its `Node` has index `index`
         * (normalized as described above).
         */

        virtual int remove(int index) = 0;
        /**
         * Remove the `Node` at `index` (normalized as described above) from
         * the list, and return the value it contained (or `0` if the list is
         * empty).
         */

        virtual int peek(int index) const = 0;
        /**
         * Return the value inside the `Node` at `index` (normalized as
         * described above) (or return `0` if the list is empty), without
         * modifying the list.
         */
};

// ----------------------------------------------------------------------------
#endif  // LIST_H

