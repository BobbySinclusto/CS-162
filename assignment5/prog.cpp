/***************************************************************************
** File: prog.cpp
** Author: Allen Benjamin
** Date: 03/14/2020
** Description: Shows off my epic linked list implementation
**************************************************************************/

#include "Linked_List.hpp"

int main() {
    Linked_List<int> list1;
    list1.push_front(3);
    list1.push_front(5);
    Linked_List<unsigned int> list2;
    list2.push_front(4294963943);
    list2.push_front(4294963942);
    list2.push_back(20);
    list2.insert(30, 2);
    list2.insert(10, 4);
    list2.insert(1, 0);
    cout << "length: " << list2.get_length() << endl;

    list1.print();
    list2.print();
    cout << endl;
    list2.sort_ascending();
    list2.print();
    return 0;
}