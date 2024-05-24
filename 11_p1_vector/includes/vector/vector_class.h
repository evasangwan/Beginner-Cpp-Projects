#ifndef VECTOR_CLASS_H
#define VECTOR_CLASS_H
#include <iostream> 
#include "../../includes/add_entry/add_entry.h"
#include "../../includes/array_functions/array_functions.h"
using namespace std; 

template <class T> 
class Vector{
    public: 
    //Big Three 
    Vector(const Vector &other){
        _capacity = other._capacity; 
        how_many = other.how_many;
        _arr = allocate<T>(_capacity);
        copy_array(_arr, other._arr, _capacity);
    }

    ~Vector(){
        delete[] _arr;
    }

    Vector& operator =(const Vector &RHS){
        if(&RHS == this){
            return *this;
        }
        delete[] _arr; 
        _capacity = RHS._capacity;
        how_many = RHS.how_many;
        _arr = allocate<T>(_capacity);
        copy_array(_arr, RHS._arr, _capacity);
        return *this; 
    }
    
    Vector(int capacity = 100){
        _capacity = capacity; 
        _arr = allocate<T>(_capacity);
        how_many = 0;
    }

    Vector(T*arr, int size){
          how_many = size;
          _capacity = size;
          _arr = copy_array(arr, how_many);
    }   

    //Member Access Functions 
    T& operator [](int index){
        T* ptr = _arr;
        ptr += index;
        return *ptr;
    }   

    const T& operator [](int index) const{
        T* ptr = _arr;
        ptr += index;
        return *ptr;
    }

    T& at (int index){                   //return reference to item at position index
        T* ptr = _arr;
        ptr += index;
        return *ptr;
    }      

    const T& at (int index) const{       //return a const item at position index 
        T* ptr = _arr;
        ptr += index;
        return *ptr;
    }   

    T& front(){                          //return item at position 0 
        T*ptr = _arr;
        return *ptr;
    }     

    T& back(){                           //return item at last position 
        int index = how_many - 1;
        T*ptr = _arr;
        ptr += index;
        return *ptr;
    }      

    //Push and Pop Functions 
    Vector& operator +=(const T& item){     //push back (add)  
        push_back(item);
        return *this;
    }  

    void push_back(const T& item){          //append to end     //j calls add entry
        _arr = add_entry(_arr, item, how_many, _capacity);
    }     

    T pop_back(){                           //remove last item and return it 
        T popped = 0;
        _arr = remove_last_entry(_arr, popped, how_many, _capacity);
        return popped;
    }                     

    //Insert and Erase 
    void insert(int insert_here, const T& insert_this){             //insert at position 
        _arr = insert_entry(_arr, insert_this, insert_here, how_many, _capacity);
    }   

    void erase(int erase_this_index){                 //erase item at this position 
        _arr = erase_entry(_arr, erase_this_index, how_many, _capacity);
    }                      

    int index_of(const T& item){                      //searches for item, returns index
        int index = search(_arr, how_many, item);
        return index; 
    }                          

    //Size and Capacity 
    void set_capacity(int capacity){                    //allocate this space  //call reallocate make sure its not smaller than size 
        if (capacity > how_many){
            _capacity = capacity;
            _arr = reallocate(_arr, how_many, _capacity);
        }
        else{
        return;
        }
    }         

    int size() const {return how_many;}        //returns size

    int capacity() const {return _capacity;}   //return capacity

    bool empty() const{                        //returns true if vector is empty 
        if (how_many == 0){
        return true;
        }
        return false;
    }      
    
    //OUTPUT
    friend ostream& operator<<(ostream& outs, const Vector<T>& _a){
        print_array(_a._arr, _a.how_many, _a._capacity, outs);
        return outs;
    } 

    private:
    int _capacity;
    int how_many;
    T* _arr;

};

#endif