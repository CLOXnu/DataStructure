//
// Created by Land on 2020/4/20.
//

#include <iostream>
using namespace std;

#include "Deque.h"


void run_work3()
{
    cout << "0: exit\n"
            "1: push\n"
            "2: pop\n"
            "3: inject\n"
            "4: eject\n\n"
            "请输入要执行的操作 (0, 1, 2, 3, 4)\n" << endl;

    auto *deque = new Deque<int>();

    while (true)
    {
        int input = 0;

        deque->print();

        while (true)
        {
            cout << " : ";
            if (cin >> input)
                break;
            cout << "输入有误，请重新输入。";

            // 清除 I/O 缓存。 Clear I/O cache.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (input == 0) {
            break;
        }

        int random = rand() % 100;
        switch (input)
        {
            case 1: deque->push(random); break;
            case 2: deque->pop(); break;
            case 3: deque->inject(random); break;
            case 4: deque->eject(); break;
            default: break;
        }
    }
}