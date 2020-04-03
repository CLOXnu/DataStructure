//
// Created by Land on 2020/3/31.
//

#ifndef DATASTRUCTURE_SINGLYLINKEDLIST_H
#define DATASTRUCTURE_SINGLYLINKEDLIST_H

#include "SinglyLinkedListNode.h"


template <class T>
class SinglyLinkedList {
private:
    SinglyLinkedListNode<T>* _head = nullptr;
public:
    SinglyLinkedList();
    SinglyLinkedList(T *array, unsigned size);

    SinglyLinkedListNode<T>* head();
    void setHead(SinglyLinkedListNode<T>* head);

    void print();

    SinglyLinkedListNode<T>* getNode(unsigned index);
    SinglyLinkedListNode<T> *findNode(T data);
    SinglyLinkedListNode<T> *findNode(T data, unsigned int &index);
    void insertNode(unsigned index, T data);
    void deleteNode(unsigned index);
    void moveToNext(unsigned index);

    void push(T data);
    SinglyLinkedListNode<T>* pop();

};


#endif //DATASTRUCTURE_SINGLYLINKEDLIST_H
