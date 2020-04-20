//
// Created by Land on 2020/4/20.
//

#ifndef DATASTRUCTURE_DEQUE_H
#define DATASTRUCTURE_DEQUE_H

#include "DequeNode.h"


template <class T>
class Deque {
public:
    Deque() = default;
    DequeNode<T> *head() { return this->_head; };
    void setHead(DequeNode<T> *head);
    DequeNode<T> *rear() { return this->_rear; };
    void setRear(DequeNode<T> *rear);

    void push(T data);
    bool pop();
    bool pop(T &data);
    void inject(T data);
    bool eject();
    bool eject(T &data);

    void print();

private:
    DequeNode<T> *_head = nullptr;
    DequeNode<T> *_rear = nullptr;
};


#endif //DATASTRUCTURE_DEQUE_H
