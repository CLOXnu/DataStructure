//
// Created by Land on 2020/4/1.
//


#include "SinglyLinkedList.h"
#include "SinglyLinkedListNode.h"

template <class T>
SinglyLinkedList<T> *Intersection(SinglyLinkedList<T> *list1, SinglyLinkedList<T> *list2)
{
    auto *intersection = new SinglyLinkedList<T>;
    SinglyLinkedListNode<T> *currNode = list1->head();
    while (currNode != nullptr)
    {
        if (list2->findNode(currNode->data()) != nullptr && intersection->findNode(currNode->data()) == nullptr)
            intersection->push(currNode->data());
        currNode = currNode->next();
    }
    return intersection;
}
