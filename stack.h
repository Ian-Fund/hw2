//
// Created by mathbot on 3/14/18.
//

#ifndef EXTRA_STACK_LL_STACK_H
#define EXTRA_STACK_LL_STACK_H


#include "node.h"

class stack {
public:
    node* head;
    char top();
    void push(char x);
    char pop();
    bool isEmpty();
    stack();
    void print();

};


#endif //EXTRA_STACK_LL_STACK_H
