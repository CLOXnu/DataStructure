//
// Created by Land on 2020/4/1.
//

#include "DoublyLinkedListNode.h"

template<class T>
DoublyLinkedListNode<T>::DoublyLinkedListNode() = default;

template<class T>
DoublyLinkedListNode<T>::DoublyLinkedListNode(T data, DoublyLinkedListNode<T>* prev, DoublyLinkedListNode<T>* next) {
    this->_data = data;
    this->_prev = prev;
    this->_next = next;
}


template<class T>
T DoublyLinkedListNode<T>::data() {
    return this->_data;
}

template<class T>
DoublyLinkedListNode<T> *DoublyLinkedListNode<T>::next() {
    return this->_next;
}

template<class T>
DoublyLinkedListNode<T> *DoublyLinkedListNode<T>::prev() {
    return this->_prev;
}

template<class T>
void DoublyLinkedListNode<T>::setData(T data) {
    this->_data = data;
}

template<class T>
void DoublyLinkedListNode<T>::setNext(DoublyLinkedListNode *next) {
    this->_next = next;
}

template<class T>
void DoublyLinkedListNode<T>::setPrev(DoublyLinkedListNode *prev) {
    this->_prev = prev;
}


// template definition to avoid linker error.
template class DoublyLinkedListNode<int>;
template class DoublyLinkedListNode<float>;
template class DoublyLinkedListNode<double>;
template class DoublyLinkedListNode<bool>;
