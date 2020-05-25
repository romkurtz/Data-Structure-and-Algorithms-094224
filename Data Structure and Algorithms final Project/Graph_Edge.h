//
// Created by rom_k on 23-Dec-19.
//

#ifndef DS_ALGO_PROJECT_GRAPH_EDGE_H
#define DS_ALGO_PROJECT_GRAPH_EDGE_H
#include <cstddef>
class Graph_Edge;
#include "Graph_Node.h"

class Graph_Edge
{
public:

    Graph_Edge(Graph_Node* from, Graph_Node* to): _from(from), _to(to), _next_in_graph
    (NULL), _prev_in_graph(NULL) , _next_in_adj(NULL), _prev_in_adj(NULL), _next_in_adj_transpose
    (NULL), _prev_in_adj_transpose(NULL){}
    inline Graph_Edge* Get_Next_In_Graph(){return _next_in_graph;}
    inline Graph_Edge* Get_Prev_In_Graph(){return _prev_in_graph;}
    inline Graph_Edge* Get_Next_In_Adj(){return _next_in_adj;}
    inline Graph_Edge* Get_Next_In_Adj_Transpose(){return _next_in_adj_transpose;}
    inline Graph_Node* Get_From(){return _from;}
    inline Graph_Node* Get_To(){return _to;}
    inline void Set_Next_In_Graph(Graph_Edge* edge ){ _next_in_graph=edge;}
    inline void Set_Prev_In_Graph(Graph_Edge* edge){ _prev_in_graph=edge;}
    inline void Set_Next_In_Adj(Graph_Edge* edge ){ _next_in_adj=edge;}
    inline void Set_Prev_In_Adj(Graph_Edge* edge){ _prev_in_adj=edge;}
    inline void Set_Next_In_Adj_Transpose(Graph_Edge* edge ){ _next_in_adj_transpose=edge;}
    inline void Set_Prev_In_Adj_Transpose(Graph_Edge* edge){ _prev_in_adj_transpose=edge;}
    void Delete_From_Adj();
    void Delete_From_Adj_Transpose();


    ~Graph_Edge(){

    }


private:
    Graph_Node* _from;
    Graph_Node* _to;
    Graph_Edge* _next_in_graph;
    Graph_Edge* _prev_in_graph;
    Graph_Edge* _next_in_adj;
    Graph_Edge* _prev_in_adj;
    Graph_Edge* _next_in_adj_transpose;
    Graph_Edge* _prev_in_adj_transpose;
};


#endif //DS_ALGO_PROJECT_GRAPH_EDGE_H
