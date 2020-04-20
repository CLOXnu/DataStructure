//
// Created by Land on 2020/4/20.
//

#include <iostream>
using namespace std;
#include "Deque.h"

template<class T>
void Deque<T>::push(T data) {
    auto *headNode = new DequeNode<T>(data);
    headNode->set_next_neighbor(this->head());
    this->setHead(headNode);
}

template<class T>
bool Deque<T>::pop(T &data) {
    if (this->head() == nullptr) {
        return false;
    }
    auto *head = this->head();
    data = head->data();
    this->setHead(this->head()->next());

    delete head;
    return true;
}

template<class T>
bool Deque<T>::pop() {
    T temp;
    return this->pop(temp);
}

template<class T>
void Deque<T>::inject(T data) {
    auto *rearNode = new DequeNode<T>(data);
    rearNode->set_prev_neighbor(this->rear());
    this->setRear(rearNode);
}

template<class T>
bool Deque<T>::eject(T &data) {
    if (this->rear() == nullptr) {
        return false;
    }
    auto *rear = this->rear();
    data = rear->data();
    this->setRear(this->rear()->prev());

    delete rear;
    return true;
}

template<class T>
bool Deque<T>::eject() {
    T temp;
    return this->eject(temp);
}

template<class T>
void Deque<T>::setHead(DequeNode<T> *head) {
    if (head == nullptr) {
        this->_head = nullptr;
        this->_rear = nullptr;
    } else {
        this->_head = head;
        this->_head->set_prev(nullptr);
    }
    if (this->_rear == nullptr) {
        this->_rear = head;
    }
}

template<class T>
void Deque<T>::setRear(DequeNode<T> *rear) {
    if (rear == nullptr) {
        this->_head = nullptr;
        this->_rear = nullptr;
    } else {
        this->_rear = rear;
        this->_rear->set_next(nullptr);
    }
    if (this->_head == nullptr) {
        this->_head = rear;
    }
}

template<class T>
void Deque<T>::print() {
    DequeNode<T>* currNode = this->_head;
    cout << "Print Deque: ";
    while (currNode != nullptr)
    {
        cout << currNode->data() << " ";
        currNode = currNode->next();
    }
}


// template definition to avoid linker error.
template class Deque<int>;
template class Deque<float>;
template class Deque<double>;
template class Deque<bool>;
