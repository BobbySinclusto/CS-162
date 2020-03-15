/***************************************************************************
** File: Linked_List.hpp
** Author: Allen Benjamin
** Date: 03/14/2020
** Description: Represents a linked list
**************************************************************************/

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "Node.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Linked_List {
private:
    unsigned int length; // Number of nodes in list
    Node<T> *head; // Pointer to firsrt node in the list

    /********************************************************
    ** Function: mergesort
    ** Description: sorts the list in ascending order using mergesort
    ** Input: pointer to start of list, size
    ** Pre-Conditions: list has at least one element
    ** Post-Conditions: list is sorted, new head is returned
    ********************************************************/
    Node<T>* mergesort(Node<T> *, unsigned int);

    /********************************************************
    ** Function: merge
    ** Description: combines two sorted lists into one sorted list
    ** Input: pointer to start of lists and sizes
    ** Pre-Conditions: lists are sorted
    ** Post-Conditions: list is sorted, new head is returned
    ********************************************************/
    Node<T>* merge(Node<T> *, unsigned int, Node<T> *, unsigned int);

public:
    /********************************************************
    ** Function: Linked_List constructor
    ** Description: initializes member variables
    ** Input: none
    ** Pre-Conditions: none
    ** Post-Conditions: member variables are initialized
    ********************************************************/
    Linked_List();

    /********************************************************
    ** Function: Linked_List destructor
    ** Description: deletes the list
    ** Input: none
    ** Pre-Conditions: none
    ** Post-Conditions: list is deleted
    ********************************************************/
    ~Linked_List();

    /********************************************************
    ** Function: get_length
    ** Description: returns the length of the list
    ** Input: none
    ** Pre-Conditions: none
    ** Post-Conditions: returns the length of the list
    ********************************************************/
    unsigned int get_length();

    /********************************************************
    ** Function: print
    ** Description: prints the list
    ** Input: none
    ** Pre-Conditions: the list has been initialized
    ** Post-Conditions: prints the list
    ********************************************************/
    void print();

    /********************************************************
    ** Function: clear
    ** Description: deletes all the nodes in the list
    ** Input: none
    ** Pre-Conditions: none
    ** Post-Conditions: all nodes in the list are deleted
    ********************************************************/
    void clear();

    /********************************************************
    ** Function: push_front
    ** Description: appends a node to the front of the list
    ** Input: value of node to add
    ** Pre-Conditions: none
    ** Post-Conditions: appends a node with given value to the front of the list
    ********************************************************/
    unsigned int push_front(T);

    /********************************************************
    ** Function: push_back
    ** Description: appends a node to the back of the list
    ** Input: value of node to add
    ** Pre-Conditions: none
    ** Post-Conditions: appends a node with given value to the back of the list
    ********************************************************/
    unsigned int push_back(T);

    /********************************************************
    ** Function: insert
    ** Description: appends a node to the specified position in the list
    ** Input: value of node to add
    ** Pre-Conditions: none
    ** Post-Conditions: appends a node with given value to the list
    ********************************************************/
    unsigned int insert(T, unsigned int);

    /********************************************************
    ** Function: sort_ascending
    ** Description: sorts the list in ascending order using mergesort
    ** Input: none
    ** Pre-Conditions: list has at least one element
    ** Post-Conditions: list is sorted
    ********************************************************/
    void sort_ascending();

    /********************************************************
    ** Function: sort_descending
    ** Description: sorts the list in descending order using recursive selection sort
    ** Input: none
    ** Pre-Conditions: list has at least one element
    ** Post-Conditions: list is sorted
    ********************************************************/
    void sort_descending();
};

template <typename T>
Linked_List<T>::Linked_List() {
    length = 0;
    head = nullptr;
}

template <typename T>
Linked_List<T>::~Linked_List() {
    clear();
}

template <typename T>
unsigned int Linked_List<T>::get_length() {
    return length;
}

template <typename T>
void Linked_List<T>::print() {
    Node<T> *current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

template <typename T>
void Linked_List<T>::clear() {
    Node<T> *to_delete = head;
    while (head != nullptr) {
        to_delete = head->next;
        delete head;
        head = to_delete;
    }
    length = 0;
}

template <typename T>
unsigned int Linked_List<T>::push_front(T v) {
    head = new Node<T>(v, head);
    return ++length;
}

template <typename T>
unsigned int Linked_List<T>::push_back(T v) {
    Node<T> *last = head;
    if (last == nullptr) {
        head = new Node<T>(v);
    }
    else {
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = new Node<T>(v);
    }
    return ++length;
}

template <typename T>
unsigned int Linked_List<T>::insert(T v, unsigned int index) {
    if (index == 0) {
        head = new Node<T>(v, head);
    }
    else if (index > length || index < 0) {
        throw new out_of_range("Index out of range.");
    }
    else {
        Node<T> *prev = head;
        for (int i = 0; i < index - 1; ++i) {
            prev = prev->next;
        }
        prev->next = new Node<T>(v, prev->next);
    }
    return ++length;
}

template <typename T>
void Linked_List<T>::sort_ascending() {
    head = mergesort(head, length);
}

template <typename T>
Node<T>* Linked_List<T>::mergesort(Node<T> *start, unsigned int size) {
    if (size <= 1) {
        start->next = nullptr;
        return start;
    }
    Node<T> *second = start;
    for (int i = 0; i < (size-1)/2+1; ++i) {
        second = second->next;
    }
    return merge(mergesort(start, (size-1)/2+1), (size-1)/2+1, mergesort(second, size/2), size/2);
}

template <typename T>
Node<T>* Linked_List<T>::merge(Node<T> *first, unsigned int first_size, Node<T> *second, unsigned int second_size) {
    Node<T> *new_head = first->val < second->val ? first : second; // Keep track of where the head of the list should be so we can return it later
    Node<T> *prev = nullptr;
    int i = 0, j = 0;

    while (i < first_size && j < second_size) {
        if (first->val < second->val) {
            prev = first;
            first = first->next;
            ++i;
        }
        else {
            prev = second;
            second = second->next;
            prev->next = first;
            ++j;
        }
    }
    if (first != nullptr) first->next = second;
    return new_head;
}

/*
//Old dumb merge function
template <typename T>
Node<T>* Linked_List<T>::merge(Node<T> *first, unsigned int first_size, Node<T> *second, unsigned int second_size) {
    Node<T> *new_head = first->val < second->val ? first : second; // Keep track of where the head of the list should be so we can return it later
    Node<T> *prev = nullptr;
    int i = 0, j = 0;

    while (i < first_size && j < second_size) {
        if (first->val < second->val) {
            prev = first;
            if (++i < first_size) first = first->next;
        }
        else {
            if(prev != nullptr) prev->next = second;
            prev = second;
            if (++j < second_size) {
                second = second->next;
            }
            else {
                second = nullptr;
            }
            prev->next = first;
        }
    }
    first->next = second;
    for (; i < first_size && first->next != nullptr; ++i) {
        if (++j < first_size) {
            first = first->next;
        }
        else {
            first = nullptr;
        }
    }
    for (; j < second_size && second->next != nullptr; ++j) {
       if (++j < second_size) {
            second = second->next;
        }
        else {
            second = nullptr;
        }
    }
    return new_head;
}
*/

#endif