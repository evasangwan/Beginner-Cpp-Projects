#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <iostream> 
#include "../../includes/linked_list_functions/linked_list_functions.h"
#include <cassert>
using namespace std; 
template <typename T>
class Queue{
    public:
        class Iterator{
            public:
            friend class Queue; 
            Iterator(){
                _ptr = nullptr;
            }
            Iterator(node<T>* p){
                _ptr = p;
            }
            T& operator *(){
                assert(_ptr&&"*() called on null Iterator."); //make sure not trying to dereference nullptr
                return _ptr->_item;
            }
            T* operator ->(){
                assert(_ptr);
                return &_ptr->_item;
            }
            bool is_null(){
                if (_ptr == nullptr){
                    return true;
                }
                return false;
            }
            friend bool operator !=(const Iterator& left, const Iterator& right){
                if (left._ptr != right._ptr){
                    return true;
                }
                return false;
            }
            friend bool operator ==(const Iterator& left, const Iterator& right){
                if (left._ptr == right._ptr){
                    return true;
                }
                return false; 
            }
            Iterator& operator++(){   //p = ++it;  (changes both to the changed number)
                assert(_ptr && "++() called on null iterator.");
                _ptr= _ptr->_next;
                return *this;
            }
            friend Iterator operator++(Iterator& it, int unused){       //p = it++;   (changes it but not p)
                assert(it._ptr && "++() called on null iterator.");
                Iterator hold = it;
                it._ptr = it._ptr->_next;
                return hold;
            }
            private:
                node<T>* _ptr;
        };

        Queue(): _front(nullptr), _rear(nullptr), _size(0){
            //initialized up
        }
        Queue(const Queue<T>& copyMe){
            _front = _copy_list(copyMe._front);
            _rear = copyMe._rear;
            _size = copyMe._size;    
        }
        ~Queue(){
            _clear_list(_front);
        }
        Queue& operator=(const Queue<T>& RHS){
            if (&RHS == this){
                return *this;
            }
            _front = _copy_list(RHS._front);
            _rear = RHS._rear;
            _size = RHS._size;
            return *this;
        }

        bool empty(){
            return _front == nullptr;
        }
        T front(){
            return _front->_item;
        }
        T back(){
            return _rear->_item;
        }

        void push(T item){
            // if (_front == nullptr){
            //     _rear = _insert_after(_front, _rear, item);
            //     _size++;
            // }
            // else{
            _rear = _insert_after(_front, _rear, item); 
            _size++;
            // }
        }
        T pop(){
            T item_ = _delete_node(_front,_front);
            _size--;
            return item_;
        }

        Iterator begin() const{
            return Iterator(_front);
        }
        Iterator end() const{
            return Iterator(nullptr);
        }
        void print_pointers(){
            _print_list(_front);
        }
        int size() const {return _size;}
        friend ostream& operator<<(ostream& outs, const Queue<T>& printMe){
            _print_list(printMe._front);
            return outs;
        }
    private:
        node<T>* _front;
        node<T>* _rear;
        int _size;
};
#endif