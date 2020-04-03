//
// Created by Land on 2020/4/1.
//

#include <iostream>
using namespace std;

#include "SinglyLinkedList/SinglyLinkedList.h"
#include "DoublyLinkedList/DoublyLinkedList.h"
#include "SinglyLinkedList/Intersection.cpp"

void run_work2()
{
    cout << "Normal linked list operation" << endl;
    auto *list = new DoublyLinkedList<float>;
    list->push(5.2);
    list->push(4.2);
    list->push(9);
    list->insertNode(2, 7.87);
    list->deleteNode(3);
    list->print();
    cout << endl;

    cout << "Swap in doubly linked list (swap index=2 and index=3)." << endl;
    int doubly_arr[6] = {1, 2, 3, 4, 5, 6};
    auto *doubly = new DoublyLinkedList<int>(doubly_arr, 6);
    // Swap in doubly linked list (swap index=2 and index=3).
    doubly->moveToNext(2);
    doubly->print();
    cout << endl;

    cout << "Swap in singly linked list (swap index=2 and index=3)." << endl;
    int singly_arr[6] = {1, 2, 3, 4, 5, 6};
    auto *singly = new DoublyLinkedList<int>(singly_arr, 6);
    // Swap in singly linked list (swap index=2 and index=3).
    singly->moveToNext(2);
    singly->print();
    cout << endl;

    cout << "The intersection of list2 and list3." << endl;
    int list2_arr[11] = {1, 5, 8, 9, 12, 15, 17, 18, 18, 18, 18};
    auto *list2 = new SinglyLinkedList<int>(list2_arr, 11);
    int list3_arr[10] = {2, 5, 7, 8, 9, 12, 15, 16, 18, 19};
    auto *list3 = new SinglyLinkedList<int>(list3_arr, 10);
    auto *list4 = Intersection<int>(list2, list3);
    list4->print();
    cout << endl;
}
