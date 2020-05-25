//
// Created by rom_k on 26-Dec-19.
//

#include "Tree_Node.h"

void Tree_Node::Add_child(Tree_Node* child,Tree_Node* prev)
{
    if(_left_child == NULL)
    {
        _left_child = child;
    }
    else
    {
        prev->_right_sibling = child;
    }
}