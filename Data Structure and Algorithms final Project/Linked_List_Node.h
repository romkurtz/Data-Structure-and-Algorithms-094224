//
// Created by Billy on 12/25/2019.
//

#ifndef DS_ALGO_PROJECT_LINKED_LIST_NODE_H
#define DS_ALGO_PROJECT_LINKED_LIST_NODE_H


#include "Graph_Node.h"


class Linked_List_Node {
public:
    
    Linked_List_Node():_head(NULL),_tail(NULL){};
    inline Graph_Node* Get_Head()const{ return _head;}
    Graph_Node* Prepend_Node(unsigned key);
    void Delete_Node(Graph_Node* node);
    ~Linked_List_Node();

private:
    Graph_Node* _head;
    Graph_Node* _tail;
};


#endif //DS_ALGO_PROJECT_LINKED_LIST_NODE_H
