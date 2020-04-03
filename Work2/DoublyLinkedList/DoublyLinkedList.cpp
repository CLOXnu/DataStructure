//
// Created by Land on 2020/4/1.
//

#include <iostream>
using namespace std;

#include "DoublyLinkedList.h"

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() = default;

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(T *array, unsigned size) {
    if (size == 0)
        return;
    auto *lastNode = new DoublyLinkedListNode<T>;
    for (unsigned i = 0; i < size; i++) {
        auto *currNode = new DoublyLinkedListNode<T>;
        currNode->setData(*(array + i));
        if (i == 0)
            this->_head = currNode;

        lastNode->setNext(currNode);
        currNode->setPrev(lastNode);
        lastNode = lastNode->next();

    }
}


template<class T>
DoublyLinkedListNode<T>* DoublyLinkedList<T>::head() {
    return this->_head;
}

template<class T>
void DoublyLinkedList<T>::setHead(DoublyLinkedListNode<T> *head) {
    this->_head = head;
}


template<class T>
void DoublyLinkedList<T>::print() {
    DoublyLinkedListNode<T>* currNode = this->_head;
    cout << "Print LinkedList: ";
    while (currNode != nullptr)
    {
        cout << currNode->data() << " ";
        currNode = currNode->next();
    }
    cout << endl;
}


template<class T>
DoublyLinkedListNode<T> *DoublyLinkedList<T>::getNode(unsigned index) {
    if (index == 0)
        return this->head();
    DoublyLinkedListNode<T>* currNode = this->head();
    for (int i = 0; i < index; i++)
    {
        if (currNode == nullptr)
            return nullptr;
        currNode = currNode->next();
    }
    return currNode;
}

template<class T>
DoublyLinkedListNode<T> *DoublyLinkedList<T>::findNode(T data, unsigned &index) {
    DoublyLinkedListNode<T> *currNode = this->head();
    unsigned i = 0;
    while (currNode != nullptr)
    {
        if (currNode->data() == data)
        {
            index = i;
            return currNode;
        }
        currNode = currNode->next();
        i++;
    }
    return nullptr;
}

template<class T>
void DoublyLinkedList<T>::insertNode(unsigned index, T data) {
    if (index == 0)
    {
        DoublyLinkedListNode<T>* nextNode = this->head();
        auto* newNode = new DoublyLinkedListNode<T>(data, nullptr, nextNode);
        if (nextNode != nullptr)
            nextNode->setPrev(newNode);
        this->setHead(newNode);
        return;
    }
    DoublyLinkedListNode<T>* lastNode = this->getNode(index-1);
    DoublyLinkedListNode<T>* nextNode = lastNode->next();
    auto* newNode = new DoublyLinkedListNode<T>(data, lastNode, nextNode);
    lastNode->setNext(newNode);
    if (nextNode != nullptr)
        nextNode->setPrev(newNode);
}

template<class T>
void DoublyLinkedList<T>::deleteNode(unsigned index) {
    if (index == 0)
    {
        DoublyLinkedListNode<T>* node = this->head();
        DoublyLinkedListNode<T>* nextNode = node->next();
        this->setHead(nextNode);
        if (nextNode != nullptr)
            nextNode->setPrev(nullptr);
        delete node;
        return;
    }
    DoublyLinkedListNode<T>* currNode = this->getNode(index);
    if (currNode == nullptr)
        return;
    DoublyLinkedListNode<T>* lastNode = currNode->prev();
    DoublyLinkedListNode<T>* nextNode = currNode->next();
    if (lastNode != nullptr)
        lastNode->setNext(nextNode);
    if (nextNode != nullptr)
        nextNode->setPrev(lastNode);
    delete currNode;
}

template<class T>
void DoublyLinkedList<T>::moveToNext(unsigned index) {
    if (index == 0)
    {
        DoublyLinkedListNode<T>* currNode = this->head();
        DoublyLinkedListNode<T>* nextNode = currNode->next();
        this->setHead(nextNode);
        currNode->setNext(nextNode->next());
        currNode->setPrev(nextNode);
        nextNode->setNext(currNode);
        nextNode->setPrev(nullptr);
        return;
    }
    DoublyLinkedListNode<T>* currNode = this->getNode(index);
    if (currNode == nullptr || currNode->next() == nullptr)
        return;
    DoublyLinkedListNode<T>* lastNode = currNode->prev();
    DoublyLinkedListNode<T>* nextNode = currNode->next();

    lastNode->setNext(nextNode);
    currNode->setNext(nextNode->next());
    currNode->setPrev(nextNode);
    nextNode->setNext(currNode);
    nextNode->setPrev(lastNode);

}

template<class T>
void DoublyLinkedList<T>::push(T data) {
    this->insertNode(0, data);
}

template<class T>
DoublyLinkedListNode<T>* DoublyLinkedList<T>::pop() {
    DoublyLinkedListNode<T>* node = this->head();
    this->deleteNode(0);
    return node;
}


// template definition to avoid linker error.
template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<double>;
template class DoublyLinkedList<bool>;
