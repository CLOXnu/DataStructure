//
// Created by Land on 2020/3/9.
//

#include <iostream>
using namespace std;

#include <iomanip>
#include <cmath>

#include "Work1.h"

Work1::Work1() = default;

void Work1::start() {
    this->inputNumber();
    this->roundNumber(2);
    this->printDigit();
}

void Work1::inputNumber() {
    cout << "请输入一个小数。" << endl;
    cout << "Please input a decimal number." << endl;
    while(true)
    {
        cout << ": ";
        if (cin >> this->number)
            break;
        cout << "输入有误，请重新输入。" << endl;
        cout << "Incorrect input, please try again." << endl;

        // 清除 I/O 缓存。 Clear I/O cache.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void Work1::roundNumber(unsigned bits) {
    double d = this->number * pow(10, bits);
    long l = lround(d);
    this->number = l / pow(10, bits);
}

void Work1::printDigit() {
    cout << "结果是" << endl;
    cout << "The result is" << endl;
    cout << fixed << setprecision(2) << this->number << endl;
}
