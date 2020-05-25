//
// Created by Billy on 12/25/2019.
//

#include "Linked_List_Edge.h"





Graph_Edge* Linked_List_Edge::Prepend_Edge(Graph_Node* from , Graph_Node* to) {

    Graph_Edge* edge = new Graph_Edge(from,to);
    edge->Set_Next_In_Graph(_head);
    if(_head!=NULL)
    {
        _head->Set_Prev_In_Graph(edge);
    }
    _head = edge;
    from->Increase_Out_Degree();
    to->Increase_In_Degree();

    from->Prepend_To_Adj(edge);
    to->Prepend_To_Adj_Transpose(edge);

    return edge;
}



void Linked_List_Edge::Delete_Edge(Graph_Edge* edge)
{
    if(edge->Get_Next_In_Graph() != NULL)
    {
        edge->Get_Next_In_Graph()->Set_Prev_In_Graph(edge->Get_Prev_In_Graph());
    }
    if(edge->Get_Prev_In_Graph() != NULL)
    {
        edge->Get_Prev_In_Graph()->Set_Next_In_Graph(edge->Get_Next_In_Graph());
    }
    else //case deleting the head.(the only node when prev = null).
    {
        _head = edge->Get_Next_In_Graph();
    }

    edge->Get_From()->Decrease_Out_Degree();
    edge->Get_To()->Decrease_In_Degree();

    edge->Delete_From_Adj();
    edge->Delete_From_Adj_Transpose();

    delete edge;
}


Linked_List_Edge::~Linked_List_Edge(){
    Graph_Edge* cur = _head;
    Graph_Edge* prev = NULL;
    while (cur !=NULL){
        prev = cur;
        cur = cur->Get_Next_In_Graph();
        delete prev;
    }
}