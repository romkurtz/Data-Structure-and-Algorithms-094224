//
// Created by rom_k on 23-Dec-19.
//

#include "Graph_Edge.h"

void Graph_Edge::Delete_From_Adj()
{
    if(_next_in_adj != NULL)
    {
        _next_in_adj->_prev_in_adj = _prev_in_adj;
    }
    if(_prev_in_adj != NULL)
    {
        _prev_in_adj->_next_in_adj = _next_in_adj;
    }
    else //case deleting the head.(the only node when prev = null).
    {
        Get_From()->Set_adj_head(_next_in_adj);
    }
}

void Graph_Edge::Delete_From_Adj_Transpose()
{
    if(_next_in_adj_transpose != NULL)
    {
        _next_in_adj_transpose->_prev_in_adj_transpose = _prev_in_adj_transpose;
    }
    if(_prev_in_adj_transpose != NULL)
    {
        _prev_in_adj_transpose->_next_in_adj_transpose = _next_in_adj_transpose;
    }
    else //case deleting the head.(the only node when prev = null).
    {
        Get_To()->Set_adj_head_transpose(_next_in_adj_transpose);
    }

}
