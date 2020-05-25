//
// Created by Billy on 12/25/2019.
//

#include "Linked_List_Node.h"

Graph_Node* Linked_List_Node::Prepend_Node(unsigned key)
{
    Graph_Node* node = new Graph_Node(key);
    node->Set_Next(_head);
    if(_head!=NULL)
    {
        _head->Set_Prev(node);
    }

    _head = node;
    return node;
}


void Linked_List_Node::Delete_Node(Graph_Node* node){
    if(node->Get_Next()!=NULL)
    {
        node->Get_Next()->Set_Prev(node->Get_Prev());
    }
    if(node->Get_Prev()!=NULL)
    {
        node->Get_Prev()->Set_Next(node->Get_Next());
    }
    else //case deleting the head.(the only node when prev = null).
    {
        _head = node->Get_Next();
    }
    delete node;
}
Linked_List_Node::~Linked_List_Node() {
    Graph_Node *cur = _head;
    Graph_Node *prev = NULL;
    while (cur != NULL) {
        prev = cur;
        cur = cur->Get_Next();
        delete prev;
    }
}