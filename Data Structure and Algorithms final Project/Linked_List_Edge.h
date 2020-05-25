//
// Created by Billy on 12/25/2019.
//

#ifndef DS_ALGO_PROJECT_LINKED_LIST_EDGE_H
#define DS_ALGO_PROJECT_LINKED_LIST_EDGE_H
#include "Graph_Edge.h"

class Linked_List_Edge{
public:

    Linked_List_Edge():_head(NULL),_tail(NULL){}
    Graph_Edge* Prepend_Edge(Graph_Node* from, Graph_Node*  to);
    void Delete_Edge(Graph_Edge* edge);
    ~Linked_List_Edge();



private:
    Graph_Edge* _head;
    Graph_Edge* _tail;

};


#endif //DS_ALGO_PROJECT_LINKED_LIST_EDGE_H
