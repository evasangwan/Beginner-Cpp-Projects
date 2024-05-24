#include "MCounter.h"
#include <iostream> 
using namespace std;

MCounter:: MCounter(){
    _count = 0;
    _error = false;
    cout << "In constr Mcounter" << endl;
}

int MCounter:: add(int n){
    _count += n;
    _error = false;
    if (is_error()){
        _error = true;
        return -9999;
    }
    return _count;
}

int MCounter:: add_1(){
    if (is_error()){
        _error = true;
        return -9999;
    }
    return add(1);
}   

int MCounter:: add_10(){
    if (is_error()){
        _error = true;
        return -9999;
    }
    return add(10);
}   

int MCounter:: add_100(){
    if (is_error()){
        _error = true;
        return -9999;
    }
    return add(100);
}   

int MCounter:: add_1000(){
    if (is_error()){
        _error = true;
        return -9999;
    }
    return add(1000);
}   

int MCounter:: reset(){
    _count = 0;
    _error = false; 
    return _count;
}

 int MCounter:: count() const{
    return _count;
 }    

 bool MCounter:: error() const{
    return _error;
 }

 bool MCounter:: is_error() const{
    if (_count > 9999){
        return true;
    }
    return false;
 }










