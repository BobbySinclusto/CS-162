/***************************************************************************
** File: Node.hpp
** Author: Allen Benjamin
** Date: 03/14/2020
** Description: Represents a single node of a linked list
**************************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node {
public:
    T val; // Stores the value of this node
    Node *next; // Stores the pointer to the next node

    /********************************************************
    ** Function: Node constructor
    ** Description: initializes member variables
    ** Input: value, pointer to next node
    ** Pre-Conditions: none
    ** Post-Conditions: member variables are initialized
    ********************************************************/
    Node(T v = 0, Node *n = nullptr);
};

template <typename T>
Node<T>::Node(T v, Node<T> *n) {
    val = v;
    next = n;
}

#endif