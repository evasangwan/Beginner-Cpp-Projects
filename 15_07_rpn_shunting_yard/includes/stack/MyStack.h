#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream> 
#include "../../includes/linked_list_functions/linked_list_functions.h"
#include <cassert>
using namespace std; 
template <typename T> 
class Stack{
    public:
        class Iterator{
            public:
            friend class Stack; 
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
        Stack(): _top(nullptr), _size(0){
            //initialized up 
        }
        Stack(const Stack<T>& copyMe){
             _clear_list(_top);
            _top = _copy_list(copyMe._top);
            _size = copyMe._size;
        }
        ~Stack(){
            _clear_list(_top);
        }
        Stack<T>& operator =(const Stack<T>& RHS){
             if (&RHS == this){
                return *this;
            }
             _clear_list(_top);
            _top = _copy_list(RHS._top);
            _size = RHS._size;
            return *this;
        }
        T top(){
            return _top->_item;
        }
        bool empty(){
            return _top == nullptr;
        }
        void push(T item){
           _top = _insert_head(_top,item);
           _size++;
        }
        T pop(){
            T item_ = _delete_node(_top, _top);
            _size--;
            return item_;
        }
        friend ostream& operator<<(ostream& outs, const Stack<T>& printMe){
            _print_list(printMe._top);
            return outs;
        }
        Iterator begin() const{
            return Iterator(_top);
        }
        Iterator end() const{
            return Iterator(nullptr);
        }
        int size() const {return _size;}
    private:
        node<T>* _top;
        int _size;
};
#endif