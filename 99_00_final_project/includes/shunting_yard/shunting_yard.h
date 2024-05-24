#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H
#include "../token/token.h"
#include "../queue/MyQueue.h"
#include "../stack/MyStack.h"
#include "../token/operator.h"
#include "../token/integer.h"
#include "../../includes/token/function.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class ShuntingYard{
    public:
    ShuntingYard(const string& t):eq(t){
        string s;    //for the numbers 
        for (int i = 0; i <eq.size(); i++){
            if (eq[i] == '('){
                _postfix.push(new LeftParen("("));
            }

            if (eq[i] == ')'){
                _postfix.push(new RightParen(")"));
            }
            
            //checking for operators 
            if (!isalnum(eq[i]) && eq[i] != ' ' && eq[i] != '(' && eq[i] != ')' && eq[i] != '.'){
                if (i > 1 && eq[i] == '-' && eq[i-1]== '^'){  //if its the - from x^-1, don't push it in 
                    
                }
                else if (eq[i] == '-' && eq[i+1]== 'x' || eq[i+1]== 'X'){   // -x^2 or -X^2 (unary minus)
                    _postfix.push(new Function("unary"));
                    _postfix.push(new Operator("$"));
                }
                else{
                string s(1, eq[i]);
                //cout << "eq[i] " << eq[i] << endl;
                _postfix.push(new Operator(s));
                if (s == "^" && eq[i+1] == '-'){ //if x^-1 
                    string num(1, eq[i+2]);    //means the next char is a number.
                    double number = stod(num);
                    number *= -1;
                    _postfix.push(new Integer(number));
                }
                }
            }


            //checking for (x) or sin/cos/tan..etc
            if (isalpha(eq[i])){
                if (eq[i] == 'X' || eq[i] == 'x'){
                    _postfix.push(new Function("x"));
                     if (eq[i+1]== '('){
                        _postfix.push(new Operator("*"));    //if it's x(1/x)) or something
                    }
                }

                if (eq[i]== 's'){
                    if (eq[i+1] == 'i'){
                        if (eq[i+2]== 'n'){
                            _postfix.push(new Function("sin"));
                            _postfix.push(new Operator("@"));
                        }
                    }
                }

                if (eq[i]== 'c'){
                    if (eq[i+1]== 'o'){
                        if (eq[i+2]== 's'){
                            _postfix.push(new Function("cos"));
                            _postfix.push(new Operator("@"));
                        }
                    }
                }

                if (eq[i]== 't'){
                    if (eq[i+1]== 'a'){
                        if (eq[i+2]== 'n'){
                            _postfix.push(new Function("tan"));
                            _postfix.push(new Operator("@"));
                        }
                    }
                }
                
                if (eq[i]== 'c'){
                    if (eq[i+1]== 'o'){
                        if (eq[i+2]== 't'){
                            _postfix.push(new Function("cot"));
                            _postfix.push(new Operator("@"));
                        }
                    }
                }

                if (eq[i]== 's'){
                    if (eq[i+1]== 'e'){
                        if (eq[i+2]== 'c'){
                            _postfix.push(new Function("sec"));
                            _postfix.push(new Operator("@"));
                        }
                    }
                }
                if (eq[i]== 'c'){
                    if (eq[i+1]== 's'){
                        if (eq[i+2]== 'c'){
                            _postfix.push(new Function("csc"));
                            _postfix.push(new Operator("@"));
                        }
                    }
                }

            }
            
            try{
            if (isdigit(eq[i]) || eq[i] == '.'){
                if (i > 2 && eq[i-1] == '-' && eq[i-2] == '^'){  //if its x^-1 don't do anything since we took care of it in check for op

                }
                else if(i>1 && eq[i] == '0' && eq[i-1] == '/'){ //if something / by 0
                    string a(eq[i], 1);
                    double num = stod(a);
                    throw double(num);
                }
                else{
                s += eq[i]; //adds the number to a string 
                if (!isdigit(eq[i+1])){
                    double number = stod(s);  
                    _postfix.push(new Integer(number));
                    // cout << "number " << number << endl;
                    s.clear();
                    if (eq[i+1] == 'x' || eq[i+1] == 'X'){
                        _postfix.push(new Operator("*"));    //multiply if for ex: 4x -> 4*x
                    }
                    if (eq[i+1]== '('){
                        _postfix.push(new Operator("*"));    //if it's 4(sin(x))
                    }
                }
                }
            }
            }
            catch (double num){
                while (!_postfix.empty()){
                    _postfix.pop();
                }
                _postfix.push(new Function ("tan"));
                _postfix.push(new Operator ("@"));
                _postfix.push(new LeftParen("("));
                _postfix.push(new Function("x"));
                _postfix.push(new RightParen("("));
                break;
            }
        //cout << _postfix << endl;
        }
        
}

    ShuntingYard(const Queue<Token *> postfix):_postfix(postfix){
        
    }

    ShuntingYard(){
        
    }

    Queue<Token *> postfix() {
        Queue<Token *> Postfix;
        Stack<Token*> stack;
        Queue<Token*>::Iterator it = _postfix.begin();
        while (!it.is_null()){
            Token* temp = *it;
            //cout << *temp << endl;
            int type = temp->getType();
            if (type == 1 || type == 3){
                //cout << *temp << endl;
                Postfix.push(temp);
            } 

            else if (type == 4){
                stack.push(temp);
            } 

            else if (type == 5){
                while (!stack.empty() && stack.top()->getType() != 4){
                    Token* pop = stack.pop();
                    Postfix.push(pop);
                }
                stack.pop();  
            } 

            else{
                while (!stack.empty() && temp->getPrecedence()<= stack.top()->getPrecedence() && stack.top()->getPrecedence()!= 4){
                    Token * popped = stack.pop();
                    Postfix.push(popped);
                }
                stack.push(temp);
            }

            it++;
        }
        while (!stack.empty()){
            Token *popped = stack.pop();
            Postfix.push(popped);
        }
        return Postfix;
    }

    Queue<Token *> postfix(Queue<Token *> infix){
        _postfix = infix;
        Queue<Token *> Postfix;
        Stack<Token*> stack;
        Queue<Token*>::Iterator it = _postfix.begin();

        while (!it.is_null()){
            Token* temp = *it;
            int type = temp->getType();

            if (type == 1 || type == 3){
                Postfix.push(temp);
            } 

            else if (type == 4){
                stack.push(temp);
            } 

            else if (type == 5){
                while (!stack.empty() && stack.top()->getType() != 4){
                    Token* pop = stack.pop();
                    Postfix.push(pop);
                }
                stack.pop();  
            } 

            else{
                while (!stack.empty() && temp->getPrecedence()<= stack.top()->getPrecedence() && stack.top()->getPrecedence()!= 4){
                    Token * popped = stack.pop();
                    Postfix.push(popped);
                }
                stack.push(temp);
            }

            it++;
        }

        while (!stack.empty()){
            Token *popped = stack.pop();
            Postfix.push(popped);
        }
        return Postfix;
    }

    void infix(Queue<Token *> infix){
        _postfix = infix;
    }

private:
    Queue<Token *> _postfix;
    string eq;
};

#endif