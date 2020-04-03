//
// Created by Land on 2020/3/31.
//

#ifndef DATASTRUCTURE_SINGLYLINKEDLISTNODE_H
#define DATASTRUCTURE_SINGLYLINKEDLISTNODE_H


template <class T>
class SinglyLinkedListNode {
private:
    T _data;
    SinglyLinkedListNode<T>* _next = nullptr;
public:
    SinglyLinkedListNode();
    SinglyLinkedListNode(T data, SinglyLinkedListNode<T>* next);

    T data();
    SinglyLinkedListNode<T>* next();

    void setData(T data);
    void setNext(SinglyLinkedListNode* next);
};


#endif //DATASTRUCTURE_SINGLYLINKEDLISTNODE_H
