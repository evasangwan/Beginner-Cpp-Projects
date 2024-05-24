// #ifndef RPN_H
// #define RPN_H
// #include "token.h"
// #include "operator.h"
// #include "tokenstr.h"
// #include "relational.h"
// #include "logical.h"
// #include "../stack/MyStack.h"
// #include "../queue/MyQueue.h"
// #include "../bplustree/map.h"
// #include "../bplustree/multimap.h"
// #include <iostream>
// #include <iomanip>
// #include <cmath>
// #include <vector>
// #include <algorithm>
// using namespace std;

// class RPN{
//     public:
//     RPN(const Queue<Token *> postfix):_postfix(postfix){

//     }
//     vector<long> evaluate(Map<string,long> &field_map, vector<MMap<string,long>> &mmap){
//         Stack<Token*> stack;
//         Queue<Token*>::Iterator it = _postfix.begin();
//         vector<vector<long>> recs;
//         vector<long> recnos;
//         vector<vector<long>> result;
//         //cout << _postfix << endl;
//         recnos.clear();
//         while (!it.is_null()){
//             // cout << " i " << i << endl;
//             Token* temp = *it;
//             // cout << "temp " << temp << endl;
//             int type = temp->getType();
//             // cout << "type is " << type << endl;
//             // cout << "temp is " << *temp << endl;
//             if (type == 1){    //meaning its a tokenstr
//                 stack.push(temp);
//             }
//             if (type == 2){    //meaning its an operator
                
//             }
//             if (type == 3){    //meaning its a relational op
//                 Token* value = stack.pop();  
//                 Token* fieldname = stack.pop();
//                 const string val = static_cast<TokenStr*>(value)->getStr();
//                 const string field = static_cast<TokenStr*>(fieldname)->getStr();
//                 string op = static_cast<Relational*>(temp)->Op();
//                 const long index = field_map[field];
//                 if (op == "="){
//                     recs.clear();
//                     recs.push_back(mmap[index].get(val));
//                     vector<long> t;
//                     for (int i = 0; i < recs.size(); i++){
//                         vector<long> temp = recs[i];
//                         for (int j = 0; j < temp.size(); j++){
//                              t.push_back(temp[j]);
//                         }
//                     }
//                     result.push_back(t);
//                 }
//                 if (op == "<"){
//                     recs.clear();
//                     MMap<string,long>::Iterator iter = mmap[index].begin();
//                     while (iter != mmap[index].end()){
//                         if ((*iter).key < val ){
//                             // vector<vector<long>>::iterator i = find(recs.begin(),recs.end(),(*iter).value_list);
//                             // if (i == recs.end()){  //meaning it was not found 
//                                 recs.push_back((*iter).value_list);
//                             // }
//                         }
//                         iter++;
//                     }
//                     vector<long> t;
//                     for (int i = 0; i < recs.size(); i++){
//                         vector<long> temp = recs[i];
//                         for (int j = 0; j < temp.size(); j++){
//                              t.push_back(temp[j]);
//                         }
//                     }
//                     result.push_back(t);
//                 }
//                 if (op == ">"){
//                     recs.clear();
//                     MMap<string,long>::Iterator iter = mmap[index].begin();
//                     while (iter != mmap[index].end()){
//                         if ((*iter).key > val){
//                             // vector<vector<long>>::iterator i = find(recs.begin(),recs.end(),(*iter).value_list);
//                             // if (i == recs.end()){  //meaning it was not found 
//                                 recs.push_back((*iter).value_list);
//                             // }
//                         }
//                         iter++;
//                     }
//                     vector<long> t;
//                     for (int i = 0; i < recs.size(); i++){
//                         vector<long> temp = recs[i];
//                         for (int j = 0; j < temp.size(); j++){
//                              t.push_back(temp[j]);
//                         }
//                     }
//                     result.push_back(t);
//                 }
//                 if (op == ">="){
//                     recs.clear();
//                     MMap<string,long>::Iterator iter = mmap[index].begin();
//                     while (iter != mmap[index].end()){
//                         if ((*iter).key >= val){
//                             // vector<vector<long>>::iterator i = find(recs.begin(),recs.end(),(*iter).value_list);
//                             // if (i == recs.end()){  //meaning it was not found 
//                                 recs.push_back((*iter).value_list);
//                             // }
//                         }
//                         iter++;
//                     }
//                     // cout << "over there " << endl;
//                     // cout << recs << endl;
//                     vector<long> t;
//                     for (int i = 0; i < recs.size(); i++){
//                         vector<long> temp = recs[i];
//                         for (int j = 0; j < temp.size(); j++){
//                              t.push_back(temp[j]);
//                         }
//                     }
//                     result.push_back(t);
//                 }
//                 if (op == "<="){
//                     recs.clear();
//                     MMap<string,long>::Iterator iter = mmap[index].begin();
//                     while (iter != mmap[index].end()){
//                         if ((*iter).key <= val){
//                             // vector<vector<long>>::iterator i = find(recs.begin(),recs.end(),(*iter).value_list);
//                             // if (i == recs.end()){  //meaning it was not found 
//                                 recs.push_back((*iter).value_list);
//                             // }
//                         }
//                         iter++;
//                     }
//                     // cout << "over here " << endl;
//                     // cout << recs << endl;
//                     vector<long> t;
//                     for (int i = 0; i < recs.size(); i++){
//                         vector<long> temp = recs[i];
//                         for (int j = 0; j < temp.size(); j++){
//                              t.push_back(temp[j]);
//                         }
//                     }
//                     result.push_back(t);
//                 }
//                 for (int i = 0; i < result.size(); i++){
//                     vector<long> temp = result[i];
//                     for (int j = 0; j < temp.size(); j++){
//                         recnos.push_back(temp[j]);
//                     }
//                 }
//             }   
//             if (type == 4){
//                 string log = static_cast<Logical*>(temp)->Op();
//                 // cout << "RESULT " << endl;
//                 // cout << result << endl;
//                 if (log == "and"){
//                     vector<long> res;
//                     // cout << "~~~~~~~~~~~~~~~~~~~~~"<<endl;
//                     // cout << result.size() << endl;
//                     vector<long> one;
//                     vector<long> two;
//                     if (result[0].size() > result[1].size()){
//                         one = result[0];
//                         two = result[1];
//                     }
//                     else{
//                         one = result[1];
//                         two = result[0];
//                     }
//                     // cout << "one " << endl;
//                     // cout << one << endl;
//                     // cout << "two: " << endl;
//                     // cout << two << endl;
//                     for (int i = 0; i < one.size(); i++){
//                         int m = 0;
//                         for (int j = 0; j < two.size(); j++){
//                             if (one[i] == two[j] && m < 1){
//                                 res.push_back(one[i]);
//                                 m++;
//                             }
//                             // cout << "RECS "<<endl;
//                             // cout << recs << endl;
//                         }
//                     }
//                     recnos = res;
//                     result.clear();
//                     result.push_back(res);
//                     res.clear();
//                 }
//                 if (log == "or"){
//                     vector<long> res;
//                     vector<long> one;
//                     vector<long> two;
//                     if (result[0].size() > result[1].size()){
//                         one = result[0];
//                         two = result[1];
//                     }
//                     else{
//                         one = result[1];
//                         two = result[0];
//                     }
//                     for (int i = 0; i < two.size(); i++){
//                         vector<long>::iterator t = find(res.begin(),res.end(),two[i]);
//                         if (t == res.end()){
//                             res.push_back(two[i]);
//                         }
//                     }
//                     for (int i = 0; i < one.size(); i++){
//                         int m = 0;
//                         for (int j = 0; j < two.size(); j++){
//                             if (one[i] == two[j] && m < 1){
//                                 res.push_back(one[i]);
//                                 m++;
//                             }
//                         }
//                         vector<long>::iterator t = find(res.begin(),res.end(),one[i]);
//                         if (t == res.end()){  //meaning it was not found 
//                             res.push_back(one[i]);
//                         }
//                     }
//                     recnos = res;
//                     result.clear();
//                     result.push_back(res);
//                     res.clear();
//                 }
//             }
//             it++;
//         }
//         recs.clear();
//         result.clear();
//         return recnos;
//     }

//     private:
//         Queue<Token *> _postfix;
        
// };


// #endif
