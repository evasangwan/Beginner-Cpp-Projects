#ifndef RPN_H
#define RPN_H
#include "../token/token.h"
#include "../queue/MyQueue.h"
#include "../token/integer.h"
#include "../token/operator.h"
#include "../stack/MyStack.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class RPN{
    public:
    RPN(const Queue<Token *> postfix):_postfix(postfix){
        
    }
    double operator ()(const double x=0){
        n = x;
        return evaluate(n);
    }
    double evaluate(double x = 0){
        Stack<Token*> stack;
        // while(!stack.empty()){
        //     stack.pop();
        // }
        Queue<Token*>::Iterator it = _postfix.begin();
        while(!it.is_null()){ 
            Token* temp = *it;
            int type = temp->getType();
            if (type == 1){
                // Token* res = *it;
                stack.push(temp);
                // Token *popped = _postfix.pop();
                // stack.push(popped);
            }
            else if(type == 2){
                Token* one = stack.pop();
                Token* two = stack.pop();

                string op = static_cast<Operator*>(temp)->Op();
                if (op == "+"){
                    double ans = two->getVal() + one->getVal();
                    stack.push(new Integer(ans));
                }

                else if(op == "*"){
                    double ans = two->getVal() * one->getVal();
                    // cout << "got here " << endl;
                    stack.push(new Integer(ans));
                }

                else if(op == "/"){
                    double ans = two->getVal() / one->getVal();
                    stack.push(new Integer(ans));
                    }

                 else if(op == "-"){
                    double ans = two->getVal() - one->getVal();
                    stack.push(new Integer(ans));
                }

                else if(op == "^"){
                    double ans = pow(two->getVal(), one->getVal());
                    stack.push(new Integer(ans));
                }

                else if(op == "@"){
                    if (two->getVal() == -1){   //sin
                        double ans = sin(one->getVal());
                        stack.push(new Integer(ans));
                    }

                    if (two->getVal() == -2){  //cos
                        double ans = cos(one->getVal());
                        stack.push(new Integer(ans));
                    }

                    if (two->getVal() == -3){  //tan
                        double ans = tan(one->getVal());
                        stack.push(new Integer(ans));
                    }

                    if (two->getVal() == -4){ //cot
                        double ans = 1/(tan(one->getVal()));
                        stack.push(new Integer(ans));
                    }

                    if (two->getVal() == -5){  //sec
                        double ans = 1/(cos(one->getVal()));
                        stack.push(new Integer(ans));
                    }

                    if (two->getVal() == -6){  //csc
                        double ans = 1/(sin(one->getVal()));
                        stack.push(new Integer(ans));
                    }
                }

                else if(op == "$"){
                    double ans = -1 * one->getVal();
                    stack.push(new Integer(ans));
                }
            }
        
                else if(type == 3){
                    string func = static_cast<Function*>(temp)->getFunc();
        
                    if (func == "x" || func == "X"){
                        stack.push(new Integer(x));
                    }
                    
                    if (func == "sin"){
                        stack.push(new Integer(-1));
                    }
                    
                    if (func == "cos"){
                        stack.push(new Integer(-2));
                    }

                    if (func == "tan"){
                        stack.push(new Integer(-3));
                    }

                    if (func == "cot"){
                        stack.push(new Integer(-4));
                    }

                    if (func == "sec"){
                        stack.push(new Integer(-5));
                    }

                    if (func == "csc"){
                        stack.push(new Integer(-6));
                    }     

                    if (func == "unary"){
                        stack.push(new Integer(-7));
                    }      
                }
                it++;
            }
         
            Token * res = stack.pop();
            double result = res->getVal();
            return result;
        }

    void set_input(const Queue<Token *> postfix){
        _postfix = postfix;
    }
    
    private:
    Queue<Token *> _postfix;
    double n;
};


#endif