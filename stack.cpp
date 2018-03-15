//
// Created by mathbot on 3/14/18.
//

#include "stack.h"

stack::stack()
{
    head = NULL;
}

bool stack::isEmpty()
{
    if ( head == NULL){
        return  true;
    }
    else return false;
}

char stack::pop()
{
    char x;
    if(!isEmpty())
    {
        node* temp = head;
        head = temp->next;
        x = temp->data;
        delete temp;
    }
    else{
        cout<<"Empty Stack\n";
    }

}

void stack::push(char x) {
    node* temp = new node(x);
    temp->next = head;
    head = temp;

}

char stack::top() {
    return head->data;
}

void stack::print() {
    if(!isEmpty()){
        node* temp = head;
        while(temp !=0){
            cout<<temp->data<< " ";
            temp = temp->next;
        }
        cout<<endl;
    }
    else cout<<"Empty Stack\n";
}