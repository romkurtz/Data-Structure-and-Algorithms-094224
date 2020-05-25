//
// Created by rom_k on 23-Dec-19.
//

#include "Graph_Node.h"
void Graph_Node::Set_Distance(unsigned d)
{
    _distance = d;
    if (_compatible_tree_node)
    {
        _compatible_tree_node->Set_Distance(d);
    }
}


void Graph_Node::Set_Finish(unsigned f)
{
    _finish = f;
    if (_compatible_tree_node)
    {
        _compatible_tree_node->Set_Finish(f);
    }
}

void Graph_Node::Prepend_To_Adj(Graph_Edge *edge)
{
    if (_adj_head==NULL)
    {
        _adj_head=edge;
    }
    else
    {
        _adj_head->Set_Prev_In_Adj(edge);
        edge->Set_Next_In_Adj(_adj_head);
        _adj_head = edge;
    }
}
void Graph_Node::Prepend_To_Adj_Transpose(Graph_Edge *edge)
{
    if (_adj_transpose_head==NULL)
    {
        _adj_transpose_head=edge;
    }
    else
    {
        _adj_transpose_head->Set_Prev_In_Adj_Transpose(edge);
        edge->Set_Next_In_Adj_Transpose(_adj_transpose_head);
        _adj_transpose_head = edge;
    }
}

void Graph_Node::Set_Discovery(unsigned t)
{
    _discovery = t;
    if (_compatible_tree_node)
    {
        _compatible_tree_node->Set_Discovery(t);
    }
}
