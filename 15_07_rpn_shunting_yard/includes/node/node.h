#ifndef NODE_H
#define NODE_H
#include <iostream> 
#include <cassert>
using namespace std; 

template <typename T>
struct node{
    T _item;
    node *_next;

    node(const T& item = T(), node *next = nullptr): _item(item), _next(next){
        //blank, initialized up
    }
    // template <typename U>
    friend ostream& operator <<(ostream& outs, const node<T> &printMe){
        const node<T>* walker = &printMe;
        outs << "[" << walker->_item << "]-> ";
        return outs;
    }
};

#endif