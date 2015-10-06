**TODO**
- Add things from chapter 11 ("More OOP")

## Linked Lists

### Requirements

- Write a class called `List1`, in `list1.h`, implementing a singly linked list
  that conforms to the interface in `list.h` (i.e. `List1` should be a concrete
  class that inherits from `List`).

- In `main.cpp` write functions (to be called in `main()`) to test the
  following aspects of your list:
    - Construction
        - Make sure that all data members are initialized properly.
    - `length()`, `insert()`, `remove()`, and `peek()`
        - These should probably be tested together, since you can't really test
          any of them in isolation.
    - Destruction
        - Make sure all `Node`s are freed when the list is deleted or goes out
          of scope.
        - This could be tested in various ways.  One way would be to put
          debugging print statements in the relevant destructors, and make sure
          (with a small list) that all the appropriate destructors are called.
          Alternately (or perhaps in addition), this could be tested by
          creating a list, filling it with lots of `Node`s, making sure that
          your program's memory usage increases appropriately, deleting the
          list (or letting it go out of scope), and making sure your program's
          memory usage goes back to about where it was befor the list was
          created.  In Windows, you may be able to do this using the "Task
          Manager"; on OS X, you can use the "Activity Monitor".

  These functions should use pointers to type `List`, rather than pointers to,
  or objects of, type `List1`.  This way, your code will be able to use,
  without modification, any class implementing the `List` interface.


### Suggestions

- For a singly linked list, you will probably want a `private`

    ```c++
    struct Node {
        Node * next;
        int value;
    };
    ```

  to serve as your `Node` type, as well as a `Node * mHead;` that always points
  to the first element of the list, and an `int mLength;` that is always set to
  the number of elements currently in the list.  In the implementation file,
  depending on where you're referencing it, you may need to use the fully
  qualified name for `Node` (i.e.  `List1::Node` instead of `Node`).

- Don't forget to write a constructor!

- Remember to fully document your `class List1` header file.  I should be able
  to tell what your class does (but not necessarily how it does it) by reading
  *only* this file (along with any files that this file explicitly references;
  e.g. you may wish to reference the documentation in the interface file,
  `list.h`).


### Challenge

- Write a class called `List2`, in `list2.h`, implementing the interface in
  `list.h` as a doubly linked list.

- Use the same functions and `main()` that you wrote to test your singly linked
  list to test your doubly linked list as well (this should be trivial, if you
  followed the requirement about using pointers to type `List` rather than
  pointers to, or objects of, type `List1`).


### Style

- Document and format your code well and consistently.
- Wrap lines at 79 or 80 columns whenever possible.
- End your file with a blank line.
- Do *not* use `using namespace std;`.  You may get around typing `std::` in
  front of things or with, e.g., `using std::cout;`.

- Concrete classes must have both `.h` and `.cpp` files, with member functions
  defined in the `.cpp` files.  If it makes sense, you may put multiple classes
  into one pair of `.h` and `.cpp` files.

- `main()` must have its own `.cpp` file.  I suggest calling it `main.cpp`.

- Declare member functions and function arguments as `const` when appropriate
  (pretty much whenever possible).

- Include your copyright and license information at the top of every file,
  followed by a brief description of the file's contents, e.g.

    ```c++
    /* ----------------------------------------------------------------------------
     * Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
     * Released under the [MIT License] (http://opensource.org/licenses/MIT)
     * ------------------------------------------------------------------------- */

    /**
     * A short program to print "Hello World!" to standard output.
     */
    ```

- Use "include guards" in all `.h` files.  Be sure to give the preprocessor
  variable a (unique) name corresponding to the file name.  For example, in
  `list.h`:

    ```c++
    #ifndef LIST_H
    #define LIST_H
    // ----------------------------------------------------------------------------

    // ... everything besides the copyright information and file description

    // ----------------------------------------------------------------------------
    #endif  // LIST_H
    ```


-------------------------------------------------------------------------------
[![Creative Commons License](https://i.creativecommons.org/l/by/4.0/88x31.png)]
(http://creativecommons.org/licenses/by/4.0/)  
Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>  
This work is licensed under a [Creative Commons Attribution 4.0 International
License] (http://creativecommons.org/licenses/by/4.0/)  
Project located at <https://github.com/2015-fall-csuf-benblazak-cpsc-121>

