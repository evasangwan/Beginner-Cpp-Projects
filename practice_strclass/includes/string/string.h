#ifndef STRING_H
#define STRING_H
#include <iostream> 
using namespace std; 

class String{
public:
String();
String(char *str);
String upper();
String lower();
String push_back(char c);
String pushback(const char *c);
String mystrcpy(char*des, char*tocopy);
int length();

friend ostream& operator <<(ostream& outs, String s);
friend istream& operator >>(istream& ins, String s);
private: 
char *_str;
int _capacity;
int _length;
};

#endif
