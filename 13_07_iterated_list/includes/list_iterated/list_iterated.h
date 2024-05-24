#ifndef LIST_ITERATED_H
#define LIST_ITERATED_H
#include <iostream> 
#include "../../includes/linked_list_functions/linked_list_functions.h"
#include <cassert>
using namespace std; 

template <typename T>
class List{
    public:
        class Iterator{
            public:
                friend class List;
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
        
        List(){
            _head_ptr = nullptr;
            _size = 0;
        }
        ~List(){
             _clear_list(_head_ptr);
        }
        List(const List<T> &copy_this){
            _head_ptr = _copy_list(copy_this._head_ptr);
            _size = copy_this._size;
        }
        List& operator =(const List& RHS){
            if (&RHS == this){
                return *this;
            }
            _head_ptr = _copy_list(RHS._head_ptr);
            _size = RHS._size;
            return *this;
        }
        Iterator insert_head(T i){
            _head_ptr = insert_head_(i);
            return Iterator(_head_ptr);
        }
        Iterator insert_after(T i, Iterator iMarker){
            _head_ptr = insert_after_(i,iMarker._ptr);
            return Iterator(_head_ptr);
        }
        Iterator insert_before(T i, Iterator iMarker){
            _head_ptr = insert_before_(i,iMarker._ptr);
            return Iterator(_head_ptr);
        }
        Iterator insert_sorted(T i){
            _head_ptr = insert_sorted_(i);
            return Iterator(_head_ptr);
        }
        T Delete(List<T>::Iterator iMarker){
            T item = Delete_(iMarker._ptr);
            return item;
        }
        void Print() const{
            Print_();      
        }
        Iterator search(const T& key){
            node<T>* ptr = search_(key);
            return Iterator(ptr);
        }
        Iterator prev(Iterator iMarker){
            node<T>* ptr = prev_(iMarker._ptr);
            return Iterator(ptr);
        }
        T& operator[](int index){
            return _at(_head_ptr,index);
        }
        Iterator begin() const {
            return Iterator(_head_ptr);
        }
        Iterator end() const {
            return Iterator(nullptr);
        }
        Iterator last_node() const{
            
        }
        bool empty() const {return _head_ptr == nullptr;}
        friend ostream& operator<<(ostream& outs, const List<T>& l){
            _print_list(l._head_ptr);
            return outs;
        }
        int size() const {return _size;}
        //.............................................................
        node<T>* insert_head_(T i){
        _head_ptr = _insert_head(_head_ptr,i);
        _size++;
        return _head_ptr;
    }
    node<T>* insert_after_(T i, node<T>* iMarker){
        _head_ptr = _insert_after(_head_ptr,iMarker,i);
        _size++;
        return _head_ptr;
    }
    node<T>* insert_before_(T i, node<T>* iMarker){
        _head_ptr =_insert_before(_head_ptr,iMarker,i);
        _size++;
        return _head_ptr;
    }
    node<T>* insert_sorted_(T i){
        _head_ptr = _insert_sorted(_head_ptr,i);
        _size++;
        return _head_ptr;
    }
    T Delete_(node<T>* iMarker){
       T val = _delete_node(_head_ptr, iMarker);
       if (_head_ptr != nullptr){
       _size--;
       }
       return val;
    }

    void Print_() const{
         _print_list(_head_ptr);
    }

    node<T>* search_(const T& key){
        return _search_list(_head_ptr,key);
    }
    node<T>* prev_(node<T>* iMarker){
        return _previous_node(_head_ptr,iMarker);
    }
        // T& operator[](int index){
        //     return _at(_head_ptr,index);
        // }
        // Iterator begin() const {
        //     return Iterator(_head_ptr);
        // }
        // Iterator end() const {
        //     return Iterator(nullptr);
        // }
        // bool empty() const {return _head_ptr == NULL;}
        // friend ostream& operator<<(ostream& outs, const List<T>& l){
        //     _print_list(l._head_ptr);
        //     return outs;
        // }
        // int size() const {return _size;}
    private:
    node<T>* _head_ptr;
    int _size;
};

#endif



      