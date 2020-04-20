//
// Created by Land on 2020/4/20.
//

#include "DequeNode.h"

template<class T>
DequeNode<T>::DequeNode(T data) {
    this->_data = data;
}

template<class T>
DequeNode<T>::DequeNode(T data, DequeNode<T> *prev, DequeNode<T> *next) {
    this->_data = data;
    this->_prev = prev;
    this->_next = next;
}

template<class T>
DequeNode<T>::DequeNode(DequeNode<T> *prev, DequeNode<T> *next) {
    this->_prev = prev;
    this->_next = next;
}

template<class T>
void DequeNode<T>::set_prev(DequeNode<T> *node) {
    this->_prev = node;
}

template<class T>
void DequeNode<T>::set_next(DequeNode<T> *node) {
    this->_next = node;
    if (node != nullptr)
    {
        node->_prev = this;
    }
}

template<class T>
void DequeNode<T>::set_prev_neighbor(DequeNode<T> *node) {
    this->set_prev(node);
    if (node != nullptr)
    {
        node->_next = this;
    }
}

template<class T>
void DequeNode<T>::set_next_neighbor(DequeNode<T> *node) {
    this->set_next(node);
    if (node != nullptr)
    {
        node->_prev = this;
    }
}


// template definition to avoid linker error.
template class DequeNode<int>;
template class DequeNode<float>;
template class DequeNode<double>;
template class DequeNode<bool>;
