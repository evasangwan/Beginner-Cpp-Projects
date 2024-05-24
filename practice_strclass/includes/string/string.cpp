#include "string.h"
#include <cstring>

String::String(){
    int min_cap = 50;
    _capacity = min_cap;
    _str = new char[_capacity];
}
String::String(char *str){
    int min_cap = 50;
    _capacity = min_cap;
    _str = new char[_capacity];
    //strcpy(_str, str);
    mystrcpy(_str, str);
}

String String:: mystrcpy(char*des, char*tocopy){
    char *dp = des;
    char *cp = tocopy;
    while (*cp != '\0'){
        *cp = *dp;
        cp++;
        dp++;
    }
    *dp = '\0';
    return des;
}
    // int newlength = length();
    // char *new_str = new char[_capacity];
    // char *new_ptr = new_str;
    // char *ptr = _str;
    // for (int i = 0; i < _length; i++){
    //     *new_ptr = *ptr;
    //     new_ptr++;
    //     ptr++;
    // }
    // *new_ptr = '\0';
    // String copied_str(_str);
    // return copied_str;



    // char *new_str = new char[_capacity];
    // char *np = new_str;
    // char *p = _str;
    // _length = length();
    // for (int i = 0; i < _length; i++){
    //     *np = *p;
    //     np++;
    //     p++;
    // }
    // return *this;

String String:: upper(){
    // char *ptr = _str;
    // while (*ptr != NULL){
    //     *ptr = toupper(*ptr);
    //      ptr++;
    // }
    // return *this;
    char *ptr = _str; 
    while (*ptr <= 'z' && *ptr >= 'a'){
        *ptr = *ptr - 32;
         ptr++;
    }
    return *this;
}
String String:: lower(){
    //A = 65 a = 97
    char *ptr = _str; 
    while (*ptr <= 'Z' && *ptr >= 'A'){
        *ptr = *ptr + 32;
         ptr++;
    }
    return *this;
}
String String:: push_back(char c){
    _length = length();
    if (_length >= _capacity){
        _capacity *= 2; 
        char *new_str = new char [_capacity];
        mystrcpy(new_str, _str);
        delete [] _str;
        _str = new_str;
    }
    char *ptr = _str; 
    for (int i = 0; i < _length; i++){
        ptr++;
    }
    *ptr = c; 
    _length++;
    ptr++;
    *ptr = '\0';
    _length++;
    return *this;
    }

String String:: pushback(const char *c){
    _length = length();
    int c_length = strlen(c);
    if (_length + c_length >= _capacity){
        _capacity*= 2; 
        char *new_str = new char [_capacity];
        strcpy(new_str, _str);
        delete [] _str;
        _str = new_str; 
    }
    char *ptr = _str; 
    for (int i = 0; i < _length; i++){
        ptr++;
    }
    strcpy(ptr, c);
    _length += c_length;
    return *this;
}


int String:: length(){
    _length = strlen(_str);
     return _length;
}
ostream& operator<<(ostream& outs, String s){
outs << s._str;
return outs; 
}
istream& operator >>(istream& ins, String s){
    ins >> s._str;
    return ins;
}

// //    _length = length();
//     if (_length >= _capacity){
//         _capacity *= 2; 
//     }
//      char *new_str = new char[_capacity];
//      strcpy(new_str, _str);
//      delete [] _str;
//      _str = new_str;
//      char *p = _str;
//      for (int i = 0; i < _length; i++){
//         p++;
//      }
//     *p = c;
//     _length++;
//     p++;
//     *p = '\0';
//     _length++;
//     return *this;