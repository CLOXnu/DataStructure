//
// Created by Land on 2020/3/31.
//

#include <iostream>
using namespace std;

#include "SinglyLinkedList.h"

template<class T>
SinglyLinkedList<T>::SinglyLinkedList() = default;

template<class T>
SinglyLinkedList<T>::SinglyLinkedList(T *array, unsigned size) {
    if (size == 0)
        return;
    auto *lastNode = new SinglyLinkedListNode<T>();
    for (unsigned i = 0; i < size; i++) {
        auto *currNode = new SinglyLinkedListNode<T>;
        currNode->setData(*(array + i));
        if (i == 0)
            this->_head = currNode;

        lastNode->setNext(currNode);
        lastNode = lastNode->next();
    }
}


template<class T>
SinglyLinkedListNode<T>* SinglyLinkedList<T>::head() {
    return this->_head;
}

template<class T>
void SinglyLinkedList<T>::setHead(SinglyLinkedListNode<T> *head) {
    this->_head = head;
}


template<class T>
void SinglyLinkedList<T>::print() {
    SinglyLinkedListNode<T>* currNode = this->_head;
    cout << "Print LinkedList: ";
    while (currNode != nullptr)
    {
        cout << currNode->data() << " ";
        currNode = currNode->next();
    }
    cout << endl;
}


template<class T>
SinglyLinkedListNode<T> *SinglyLinkedList<T>::getNode(unsigned index) {
    if (index == 0)
        return this->head();
    SinglyLinkedListNode<T>* currNode = this->head();
    for (int i = 0; i < index; i++)
    {
        if (currNode == nullptr)
            return nullptr;
        currNode = currNode->next();
    }
    return currNode;
}

template<class T>
SinglyLinkedListNode<T> *SinglyLinkedList<T>::findNode(T data) {
    SinglyLinkedListNode<T> *currNode = this->head();
    while (currNode != nullptr)
    {
        if (currNode->data() == data)
            return currNode;
        currNode = currNode->next();
    }
    return nullptr;
}

template<class T>
SinglyLinkedListNode<T> *SinglyLinkedList<T>::findNode(T data, unsigned &index) {
    SinglyLinkedListNode<T> *currNode = this->head();
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
void SinglyLinkedList<T>::insertNode(unsigned index, T data) {
    if (index == 0)
    {
        auto* newNode = new SinglyLinkedListNode<T>(data, this->head());
        this->setHead(newNode);
        return;
    }
    SinglyLinkedListNode<T>* lastNode = this->getNode(index-1);
    auto* newNode = new SinglyLinkedListNode<T>(data, lastNode->next());
    lastNode->setNext(newNode);
}

template<class T>
void SinglyLinkedList<T>::deleteNode(unsigned index) {
    if (index == 0)
    {
        SinglyLinkedListNode<T>* node = this->head();
        this->setHead(this->head()->next());
        delete node;
        return;
    }
    SinglyLinkedListNode<T>* lastNode = this->getNode(index-1);
    if (lastNode == nullptr || lastNode->next() == nullptr)
        return;
    SinglyLinkedListNode<T>* currNode = lastNode->next();
    lastNode->setNext(currNode->next());
    delete currNode;
}

template<class T>
void SinglyLinkedList<T>::moveToNext(unsigned index) {
    if (index == 0)
    {
        SinglyLinkedListNode<T>* currNode = this->head();
        SinglyLinkedListNode<T>* nextNode = currNode->next();
        this->setHead(nextNode);
        currNode->setNext(nextNode->next());
        nextNode->setNext(currNode);
        return;
    }
    SinglyLinkedListNode<T>* lastNode = this->getNode(index-1);
    if (lastNode == nullptr || lastNode->next() == nullptr || lastNode->next()->next() == nullptr)
        return;
    SinglyLinkedListNode<T>* currNode = lastNode->next();
    SinglyLinkedListNode<T>* nextNode = currNode->next();

    lastNode->setNext(nextNode);
    currNode->setNext(nextNode->next());
    nextNode->setNext(currNode);

}

template<class T>
void SinglyLinkedList<T>::push(T data) {
    this->insertNode(0, data);
}

template<class T>
SinglyLinkedListNode<T>* SinglyLinkedList<T>::pop() {
    SinglyLinkedListNode<T>* node = this->head();
    this->deleteNode(0);
    return node;
}


// template definition to avoid linker error.
template class SinglyLinkedList<int>;
template class SinglyLinkedList<float>;
template class SinglyLinkedList<double>;
template class SinglyLinkedList<bool>;


