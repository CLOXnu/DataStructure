//
// Created by Land on 2020/4/1.
//

#ifndef DATASTRUCTURE_DOUBLYLINKEDLISTNODE_H
#define DATASTRUCTURE_DOUBLYLINKEDLISTNODE_H


template <class T>
class DoublyLinkedListNode {
private:
    T _data;
    DoublyLinkedListNode<T>* _next = nullptr;
    DoublyLinkedListNode<T>* _prev = nullptr;
public:
    DoublyLinkedListNode();
    DoublyLinkedListNode(T data, DoublyLinkedListNode<T>* prev, DoublyLinkedListNode<T>* next);

    T data();
    DoublyLinkedListNode<T>* next();
    DoublyLinkedListNode<T>* prev();

    void setData(T data);
    void setNext(DoublyLinkedListNode* next);
    void setPrev(DoublyLinkedListNode* prev);
};


#endif //DATASTRUCTURE_DOUBLYLINKEDLISTNODE_H
