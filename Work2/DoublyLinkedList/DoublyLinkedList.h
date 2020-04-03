//
// Created by Land on 2020/4/1.
//

#ifndef DATASTRUCTURE_DOUBLYLINKEDLIST_H
#define DATASTRUCTURE_DOUBLYLINKEDLIST_H


#include "DoublyLinkedListNode.h"

template<class T>
class DoublyLinkedList {
private:
    DoublyLinkedListNode<T>* _head = nullptr;
public:
    DoublyLinkedList();
    DoublyLinkedList(T *array, unsigned size);

    DoublyLinkedListNode<T>* head();
    void setHead(DoublyLinkedListNode<T>* head);

    void print();

    DoublyLinkedListNode<T>* getNode(unsigned index);
    DoublyLinkedListNode<T> *findNode(T data, unsigned int &index);
    void insertNode(unsigned index, T data);
    void deleteNode(unsigned index);
    void moveToNext(unsigned index);

    void push(T data);
    DoublyLinkedListNode<T>* pop();
};


#endif //DATASTRUCTURE_DOUBLYLINKEDLIST_H
