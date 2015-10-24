/* ----------------------------------------------------------------------------
 * Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * Program to demonstrate the use of our singly and doubly linked lists.
 */

#include <chrono>

#include <iostream>
using std::cout;
using std::endl;

#include "list.h"
#include "list1.h"
#include "list2.h"

// ----------------------------------------------------------------------------

void print_list(const List & list) {
    for (unsigned int i = 0; i < list.length(); i++)
        cout << list.peek(i) << " ";
    cout << endl;
}

// ----------------------------------------------------------------------------

void test_functions(int list_type) {
    if (list_type < 1 || list_type > 2) {
        cout << "ERROR: test_functions(): invalid list_type\n";
        return;
    }

    List * list;
    switch (list_type) {
        case 1: list = new List1; break;
        case 2: list = new List2; break;
    }

    cout << "-----------------\n";
    cout << "test_functions(" << list_type << ")\n";
    cout << "-----------------\n";

    list->insert(0,7);
    print_list(*list);
    list->remove(0);

    list->insert(-1,7);
    print_list(*list);
    list->remove(-1);

    list->insert(10,7);
    print_list(*list);
    list->remove(10);

    cout << "-----------------\n";

    list->insert(0,1);
    list->insert(0,2);
    list->insert(0,3);
    print_list(*list);
    list->remove(0);
    list->remove(0);
    list->remove(0);

    list->insert(-1,1);
    list->insert(-1,2);
    list->insert(-1,3);
    print_list(*list);
    list->remove(-1);
    list->remove(-1);
    list->remove(-1);

    list->insert(10,1);
    list->insert(10,2);
    list->insert(10,3);
    print_list(*list);
    list->remove(10);
    list->remove(10);
    list->remove(10);

    cout << "-----------------\n";

    for (int i = 0; i < 5; i++)
        list->insert(-1,i);
    cout << list->length() << endl;
    for (int i = 0; i < 5; i++)
        cout << list->remove(0) << " ";
    cout << endl;

    for (int i = 0; i < 5; i++)
        list->insert(-1,i);
    for (int i = 0; i < 5; i++)
        cout << list->remove(-1) << " ";
    cout << endl;

    for (int i = 0; i < 5; i++)
        list->insert(-1,i);
    for (int i = 0; i < 5; i++)
        cout << list->remove(10) << " ";
    cout << endl;

    cout << "-----------------\n";

    delete list;
}

void test_speed(int list_type) {
    if (list_type < 1 || list_type > 2) {
        cout << "ERROR: test_memory(): invalid list_type\n";
        return;
    }

    List * list;
    switch (list_type) {
        case 1: list = new List1; break;
        case 2: list = new List2; break;
    }

    cout << "-------------\n";
    cout << "test_speed(" << list_type << ")\n";
    cout << "-------------\n";

    const int count = 50000;

    std::chrono::time_point<std::chrono::system_clock> begin;
    std::chrono::time_point<std::chrono::system_clock> end;
    std::chrono::duration<double> elapsed;

    // front insert
    begin = std::chrono::system_clock::now();
    for (int i = 0; i < count; i++)
        list->insert(0,i);
    end = std::chrono::system_clock::now();
    elapsed = end - begin;
    cout << "front: insert " << count << " elements: "
         << elapsed.count() << " seconds\n";

    // front remove
    begin = std::chrono::system_clock::now();
    for (int i = 0; i < count; i++)
        list->remove(0);
    end = std::chrono::system_clock::now();
    elapsed = end - begin;
    cout << "front: remove " << count << " elements: "
         << elapsed.count() << " seconds\n";

    // middle insert
    begin = std::chrono::system_clock::now();
    for (int i = 0; i < count; i++)
        list->insert( list->length()/2, i );
    end = std::chrono::system_clock::now();
    elapsed = end - begin;
    cout << "middle: insert " << count << " elements: "
         << elapsed.count() << " seconds\n";

    // middle remove
    begin = std::chrono::system_clock::now();
    for (int i = 0; i < count; i++)
        list->remove( list->length()/2 );
    end = std::chrono::system_clock::now();
    elapsed = end - begin;
    cout << "middle: remove " << count << " elements: "
         << elapsed.count() << " seconds\n";

    // back insert
    begin = std::chrono::system_clock::now();
    for (int i = 0; i < count; i++)
        list->insert(-1,i);
    end = std::chrono::system_clock::now();
    elapsed = end - begin;
    cout << "back: insert " << count << " elements: "
         << elapsed.count() << " seconds\n";

    // back remove
    begin = std::chrono::system_clock::now();
    for (int i = 0; i < count; i++)
        list->remove(-1);
    end = std::chrono::system_clock::now();
    elapsed = end - begin;
    cout << "back: remove " << count << " elements: "
         << elapsed.count() << " seconds\n";

    for (int i = 0; i < count; i++)
        list->insert(0, i);
    // peek all element
    begin = std::chrono::system_clock::now();
    for (int i = 0; i < count; i++)
        list->peek(i);
    end = std::chrono::system_clock::now();
    elapsed = end - begin;
    cout << "peek " << count << " elements: "
         << elapsed.count() << " seconds\n";

    cout << "-------------\n";

    delete list;
}

void test_memory(int list_type) {
    if (list_type < 1 || list_type > 2) {
        cout << "ERROR: test_memory(): invalid list_type\n";
        return;
    }

    List * list;
    switch (list_type) {
        case 1: list = new List1; break;
        case 2: list = new List2; break;
    }

    cout << "--------------\n";
    cout << "test_memory(" << list_type << ")\n";
    cout << "--------------\n";

    for (int i = 0; i < 100000000; i++)
        list->insert(0,i);

    cout << "pause: ";
    std::cin.get();

    delete list;

    cout << "pause: ";
    std::cin.get();

    cout << "--------------\n";
}

// ----------------------------------------------------------------------------

int main() {
//     test_functions(1);
//     test_functions(2);

//     test_speed(1);
//     test_speed(2);

//     test_memory(1);
//     test_memory(2);

    return 0;  // success
}

