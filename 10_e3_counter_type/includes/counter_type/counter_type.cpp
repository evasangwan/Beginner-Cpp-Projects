#include "counter_type.h"
#include <iostream> 
using namespace std;

Counter_Type:: Counter_Type(){
    _count = 0;
    _error = 0;
}

Counter_Type:: Counter_Type(int n){
    _count = 0;
    _error = 0;
}

bool Counter_Type:: inc(){
     _count++; 
     _error = is_error();
    if (_error){
        return _error;
    }
    _error = error();
    cout << _count << endl;
    return _error;

}
bool Counter_Type:: dec(){
    _count--;
    _error = is_error();
    if (_error){
        return _error; 
    }
    _error = error();
    cout << _count << endl;
    return _error;
}

bool Counter_Type::is_error() const{
  if (_count < 0){
    return true;
  }
  if (_count > 9){
    return true;
  }
    return false;
}
bool Counter_Type:: reset(){
    _count = 0; 
    _error = false;
    return true;
}

int Counter_Type:: count() const{
    return _count;
}  
bool Counter_Type:: error(){
    return _error;
}
void Counter_Type::print(){
  if (_error!=0){
    cout << "[ERROR]" << endl;
  }
  else{
    cout << "[" << _count << "]" << endl;
  }
}
