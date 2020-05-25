//
// Created by Billy on 1/5/2020.
//

#ifndef DS_HW_DRY_STACK_H
#define DS_HW_DRY_STACK_H

#include "Queue.h"
template <typename T>
class Stack{
private:
    node<T> *_top;
    unsigned _size;
public:
    Stack(): _top(NULL),_size(0){}
    void Push(T );
    T Pop ();
    bool Is_Empty();
};

template <typename T>
void Stack<T>::Push(T val){
    _size++;
    node<T>* ptr= new node<T>(val);
    ptr->_data = val;
    ptr->_next = _top;
    _top = ptr;
}

template <typename T>
T Stack<T>::Pop(){
    if(!Is_Empty()){
        _size--;
        node<T> *temp=_top;
        T x=_top->getData();
        _top=_top->getNext();
        delete temp;
        return x;
    }
    return NULL;
}


template <class T>
bool Stack<T>::Is_Empty()
{
    return (_top == NULL);
}




#endif //DS_HW_DRY_STACK_H
