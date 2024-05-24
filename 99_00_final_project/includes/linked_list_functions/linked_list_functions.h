#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H
#include <iostream> 
#include "../../includes/node/node.h"
#include <cassert>
using namespace std; 

template <typename T>
void _print_list(node<T>* head){
    node<T>* walker = head;
    while (walker != nullptr){
        cout << *walker->_item << "-> ";
        walker = walker->_next;
    }
    cout << " |||";
}

template <typename T> 
node<T>* _search_list(node<T>* &head, const T& key){
    node<T>* walker = head;
    while(walker != nullptr){
        if (walker->_item == key){
            return walker;
        }
        walker = walker->_next;
    }
    return nullptr;
}

template <typename T>
node<T>* _insert_head(node<T>* &head, T insert_this){
    node<T> *_temp = new node<T>(insert_this);
    _temp ->_next = head;
    head = _temp;
    return head;
}

template <typename T> 
node<T>* _insert_after(node<T>* &head, node<T>* after_this, T insert_this){
    // assert((_search_list(head, after_this->_item)) != nullptr);
    /*
        if head is nullptr, insert at head.
        otherwise insert after after_this;
    
    
    */
    if(head == nullptr){
        head = _insert_head(head,insert_this);
        return head;
    }
    node<T> *_temp = new node<T>(insert_this);
    _temp ->_next = after_this ->_next;
    after_this->_next= _temp; 
    return _temp;
}

template <typename T>
node<T>* _insert_before(node<T>* &head, node<T>* before_this, T insert_this){
    // assert((_search_list(head, before_this->_item)) != nullptr);
    if(head == before_this){
        head = _insert_head(head,insert_this);
        return head;
    }
    node<T>* ptr = _previous_node(head,before_this);
    node<T> *_temp = new node<T>(insert_this);
    _temp->_next = before_this;
    ptr->_next = _temp;
    return _temp;
    // node<T>* walker = head;
    // node<T> *_temp = new node<T>(insert_this);
    // while(walker->_next != nullptr){
    //     if(walker->_next == before_this){
    //         _temp->_next = before_this;
    //         walker->_next = _temp;
    //         return head;
    //     }
    //     walker = walker->_next;
    // }
    // assert(true && "call should never come here, mistake");
    // return nullptr;
}

template <typename T>
node<T>* _previous_node(node<T>* head, node<T>* prev_to_this){
    // assert((_search_list(head, prev_to_this->_item)) != nullptr);
    // assert(head != nullptr);
    if (prev_to_this == head || head == nullptr){   
        return nullptr;
    }
    node<T>* walker = head;
    while(walker != nullptr){
        if (walker->_next == prev_to_this){
            return walker;
        }
        walker = walker->_next;
    }
    assert(true && "call should never come here, mistake");
    return nullptr;
}

template <typename T>
T _delete_node(node<T>* &head, node<T>* delete_this){
    assert(delete_this != nullptr);
    if (delete_this == head){
        node<T> *_temp = delete_this;
        T item = delete_this->_item;
        head = head->_next;
        _temp->_next = nullptr;
        delete _temp;
        return item;
    }
    node<T>* ptr = _previous_node(head,delete_this);
    node<T> *_temp = ptr->_next;
    T item = _temp->_item;
    ptr->_next = _temp->_next;
    _temp->_next = nullptr;
    delete _temp;
    return item;
}

template<typename T> 
void _clear_list(node<T>* &head){
    node<T> *leader = head;
    while(leader != nullptr){
        node<T> *follower = leader;
        leader = leader->_next;
        // follower->_next = nullptr;
        delete follower;
    }
    head = nullptr;
}

template <typename T>
T _at(node<T>*head, int pos){
    // int i = 0;
    // node<T> *walker = head;
    // while (walker != nullptr){
    //     i++;
    //     walker = walker->_next;
    // }
    // assert(pos <= i && pos >= 0);
    node<T> *walker = head;
    for (int j = 0; j < pos; j++){
        walker = walker->_next;
    }
    if (walker == nullptr){
        T item = 0;
        return item;
    }
    T item = walker->_item;
    return item;
}

template <typename T>
node <T>* _where_this_goes(node<T>* head, T item, bool ascending = true){
    // assert(head != nullptr);
    if (ascending){
    if (head == nullptr||item < head->_item){
        return nullptr;
    }
    node<T> *leader = head;
    node<T> *follower = leader;
    while(leader!= nullptr && leader->_item < item){
        follower = leader;
        leader = leader->_next;
    }
        return follower;
}
//descending
    if (head == nullptr||item > head->_item){
        return nullptr;
    }
    node<T> *leader = head;
    node<T> *follower = leader;
    // node<T> *follower = leader;
    while(leader!= nullptr && leader->_item > item){
        follower = leader;
        leader = leader->_next;
    }
    
        return follower;
}


template <typename T>
node<T>* _insert_sorted(node<T>* &head, T item, bool ascending = true){
    node<T>* ptr = _where_this_goes(head,item);
       if(head == nullptr || ptr == nullptr){
        head = _insert_head(head,item);
        return head;
    }
    // node<T>* _temp = new node<T>(item);
    // _temp->_next = ptr->_next;
    // ptr->_next = _temp;
    // return head; 
    head = _insert_after(head,ptr,item);
    return head;
}             

template <typename T>
node<T>* _insert_sorted_and_add(node<T>* &head, T item, bool ascending = true){
    
}

// template <typename T>
// node<T>* _last_node(node<T>* head){
//     node<T>* walker = head;
//     while (walker->_next != nullptr){
//         walker = walker->_next;
//     }
//     return walker;
// }

//duplicate list and return the last node of the copy
template <typename T>
node<T>* _copy_list(node<T>* &dest, node<T>* src){
    if(src == nullptr){
        return nullptr;
    }
    node<T>* walker = src;
    dest = new node<T>(walker->_item);
    node<T>* destptr = dest;
    walker = walker->_next;

    while (walker != nullptr) {
        destptr->_next = new node<T>(walker->_item);
        destptr = destptr->_next;
        walker = walker->_next;
    }
    return destptr;
}

//duplicate list and return the head of copy
template <typename T> 
node <T>* _copy_list(node<T>* head){
    node<T>* dest = nullptr;
    node<T>* _last = _copy_list(dest, head);
    return dest;
}

#endif