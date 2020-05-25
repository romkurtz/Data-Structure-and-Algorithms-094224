//
// Created by rom_k on 23-Dec-19.
//

#ifndef DS_ALGO_PROJECT_DYNAMIC_GRAPH_H
#define DS_ALGO_PROJECT_DYNAMIC_GRAPH_H

#include "Linked_List_Node.h"
#include "Linked_List_Edge.h"
#include "Rooted_Tree.h"
#include "Stack.h"

class Dynamic_Graph
{
public:
    Dynamic_Graph(): _nodes_list() ,_edges_list(){}
    inline Graph_Node* Insert_Node(unsigned node_key) {return _nodes_list.Prepend_Node(
                node_key);}
    inline Graph_Edge* Insert_Edge(Graph_Node* from, Graph_Node* to)
    {return _edges_list.Prepend_Edge(from, to);}
    void Delete_Node(Graph_Node* node);
    void Delete_Edge(Graph_Edge* edge);
    void DFS_Visit(Graph_Node* node,Stack<Graph_Node*> &Finish_Time_Stack,unsigned &time_stamp) const;
    void DFS_Visit_Transpose(Graph_Node* curr_graph_node, Tree_Node* curr_tree_node , unsigned &time_stamp) const;
    Rooted_Tree* SCC() const ;
    void DFS(Stack<Graph_Node*> &Finish_Time_Stack) const;
    Rooted_Tree* DFS_Transpose(Stack<Graph_Node*> &Finish_Time_Stack) const ;
    Rooted_Tree * BFS_Initialization (Graph_Node* source ,Queue<Graph_Node*>
            &Bfs_Queue)const;
    Rooted_Tree* BFS(Graph_Node* source) const;
    void SCC_Initialization()const ;
    ~Dynamic_Graph(){}

private :

    Linked_List_Node _nodes_list;
    Linked_List_Edge _edges_list;

};


#endif //DS_ALGO_PROJECT_DYNAMIC_GRAPH_H
