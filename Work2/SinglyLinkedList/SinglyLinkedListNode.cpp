//
// Created by Land on 2020/3/31.
//

#include "SinglyLinkedListNode.h"


template<class T>
SinglyLinkedListNode<T>::SinglyLinkedListNode() = default;

template<class T>
SinglyLinkedListNode<T>::SinglyLinkedListNode(T data, SinglyLinkedListNode<T>* next) {
    this->_data = data;
    this->_next = next;
}


template<class T>
T SinglyLinkedListNode<T>::data() {
    return this->_data;
}

template<class T>
SinglyLinkedListNode<T> *SinglyLinkedListNode<T>::next() {
    return this->_next;
}

template<class T>
void SinglyLinkedListNode<T>::setData(T data) {
    this->_data = data;
}

template<class T>
void SinglyLinkedListNode<T>::setNext(SinglyLinkedListNode *next) {
    this->_next = next;
}


// template definition to avoid linker error.
template class SinglyLinkedListNode<int>;
template class SinglyLinkedListNode<float>;
template class SinglyLinkedListNode<double>;
template class SinglyLinkedListNode<bool>;


