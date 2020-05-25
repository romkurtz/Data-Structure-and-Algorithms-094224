//
// Created by Billy on 12/30/2019.
//

#ifndef DS_HW_DR_QUEUE_H
#define DS_HW_DR_QUEUE_H
#include <cstddef>

template <typename T>
struct node{
    T _data;
    node<T> *_next;

    node(T d);
    T getData ();
    void setNext (node<T> *);
    node<T>* getNext ();
};

template <typename T>
node<T>::node(T d)
{
    _data=d;
    _next=NULL;
}

template <typename T>
T node<T>::getData(){
    return _data;
}

template <typename T>
void node<T>::setNext (node<T> *ptr){
    _next=ptr;
}

template <typename T>
node<T> * node<T>::getNext(){
    return _next;
}




template <typename T>
class Queue{
private:
    node<T> *_front;
    node<T> *_rear;
    unsigned _size;
public:
    Queue(): _front(NULL), _rear(NULL), _size(0){}
    void Enqueue(T );
    T Dequeue ();
    T Get_Front();
    bool Is_Empty();
    unsigned Get_Size();
};

template <typename T>
void Queue<T>::Enqueue(T val){
    _size++;
    node<T> *ptr=new node<T>(val);
    if(_rear == NULL && _front == NULL){
        _rear=ptr;
        _front=ptr;
    }
    else{
        _rear->setNext(ptr);
        _rear=ptr;
    }
}

template <typename T>
T Queue<T>::Dequeue(){
    if(!Is_Empty()){
        _size--;
        node<T> *ptr=_front;
        T x=_front->getData();
        if (_front == _rear)
        {
            _rear = NULL;
            _front = NULL;
        }
        else
        {
        _front=_front->getNext();
        }
        delete ptr;
        return x;
    }
    return NULL;
}

template <typename T>
T Queue<T>::Get_Front(){
    if(!Is_Empty()){
        return _front->getData();
    }
    return NULL;
}
template <class T>
bool Queue<T>::Is_Empty()
{
    return (_front == NULL);
}
template <class T>
unsigned Queue<T>::Get_Size()
{
    return _size;
}




#endif //DS_HW_DR_QUEUE_H
