//
// Created by Land on 2020/4/20.
//

#ifndef DATASTRUCTURE_DEQUENODE_H
#define DATASTRUCTURE_DEQUENODE_H


template<class T>
class DequeNode {
public:
    DequeNode() = default;
    explicit DequeNode(T data);
    DequeNode(DequeNode<T> *prev, DequeNode<T> *next);
    DequeNode(T data, DequeNode<T> *prev, DequeNode<T> *next);
    DequeNode<T> *prev(){ return this->_prev; };
    DequeNode<T> *next(){ return this->_next; };
    void set_prev(DequeNode<T> *node);
    void set_next(DequeNode<T> *node);
    void set_prev_neighbor(DequeNode<T> *node);
    void set_next_neighbor(DequeNode<T> *node);

    T data(){ return this->_data; };
    void set_data(T data){ this->_data = data; };
private:
    T _data;
    DequeNode<T> *_prev = nullptr;
    DequeNode<T> *_next = nullptr;
};


#endif //DATASTRUCTURE_DEQUENODE_H
