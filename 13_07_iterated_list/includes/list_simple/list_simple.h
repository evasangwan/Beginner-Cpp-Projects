#ifndef LIST_SIMPLE_H
#define LIST_SIMPLE_H
#include <iostream> 
#include "../../includes/linked_list_functions/linked_list_functions.h"
#include <cassert>
using namespace std; 

template <class T>
class List{
    public: 
    List(){
        head = nullptr;
        _size = 0;
    }

    ~List(){
        _clear_list(head);
    }
    List(const List<T> &copyThis){
        head = _copy_list(copyThis.head);
        _size = copyThis._size;
    }
    List& operator =(const List& RHS){
        if(&RHS == this){
            return *this;
        }
        _clear_list(head);
        head = _copy_list(RHS.head);
        _size = RHS._size;
        return *this;
    }

    node<T>* insert_head(T i){
        head = _insert_head(head,i);
        _size++;
        return head;
    }
    node<T>* insert_after(T i, node<T>* iMarker){
        head = _insert_after(head,iMarker,i);
        _size++;
        return head;
    }
    node<T>* insert_before(T i, node<T>* iMarker){
        head =_insert_before(head,iMarker,i);
        _size++;
        return head;
    }
    node<T>* insert_sorted(T i){
        head = _insert_sorted(head,i);
        _size++;
        return head;
    }
    T Delete(node<T>* iMarker){
       T val = _delete_node(head, iMarker);
       if (head != nullptr){
       _size--;
       }
       return val;
    }

    void Print() const{
         _print_list(head);
    }

    node<T>* search(const T& key){
        return _search_list(head,key);
    }
    node<T>* prev(node<T>* iMarker){
        return _previous_node(head,iMarker);
    }
    T& operator[] (int index){
       return _at(head,index);
    }
    node<T>* begin() const{
        return head;
    }
    node<T>* end() const{
        return nullptr;
    }
    bool empty() const {return head == nullptr;}
    int size() const {return _size;}
    // template <class U> 
    friend ostream& operator <<(ostream& outs, const List<T>& l){
        _print_list(l.head);
        return outs;
    //       node<U>* walker = l.head;

    // outs << "[";
    // while (walker != nullptr) {
    //     outs << walker->_item;

    //     if (walker->_next != nullptr) {
    //         outs << "]->[";
    //     } else {
    //         outs << "]";
    //     }

    //     walker = walker->_next;
    // }
    // outs << " |||";
    // return outs;
    }

    private:
    node<T>* head;
    int _size;
};
#endif