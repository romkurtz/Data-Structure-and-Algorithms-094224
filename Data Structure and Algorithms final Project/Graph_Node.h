//
// Created by rom_k on 23-Dec-19.
//

#ifndef DS_ALGO_PROJECT_GRAPH_NODE_H
#define DS_ALGO_PROJECT_GRAPH_NODE_H
#include <cstddef>
#include "Tree_Node.h"
class Graph_Node;
#include "Graph_Edge.h"

#define INFINITE 2147483647

class Tree_Node;
template <typename T> class Queue;
class Graph_Node
{

public:

    Graph_Node(unsigned key): _key(key), _next(NULL), _prev(NULL), _in_degree(0), _out_degree(0)
               , _color(0), _distance(INFINITE), _discovery(0) , _finish(0), _adj_head(NULL),
                              _adj_transpose_head(NULL), _compatible_tree_node(NULL){}
    ~Graph_Node(){}
    inline unsigned Get_key() const{ return _key;}
    inline Graph_Node* Get_Next(){return _next;}
    inline Graph_Node* Get_Prev(){return _prev;}
    inline void Set_Next(Graph_Node* node){ _next = node;}
    inline void Set_Prev(Graph_Node* node) { _prev = node;}
    inline unsigned Get_out_Degree() const {return _out_degree;}
    Graph_Edge* Get_adj_head(){ return _adj_head;}
    void  Set_adj_head(Graph_Edge* head){_adj_head = head;}
    Graph_Edge* Get_adj_transpose_head(){ return _adj_transpose_head;}
    void  Set_adj_head_transpose(Graph_Edge* head){_adj_transpose_head = head;}
    inline void Increase_Out_Degree() {_out_degree++;}
    inline void Decrease_Out_Degree(){_out_degree--;}
    inline unsigned Get_in_Degree() const{return _in_degree;}
    inline void Increase_In_Degree() {_in_degree++;}
    inline void Decrease_In_Degree(){_in_degree--;}
    inline unsigned Get_Color()const {return _color;}
    inline void Set_Color(unsigned color){_color = color;}
    void Set_Distance(unsigned d);
    inline unsigned Get_Distance(){return _distance;}
    void Set_Discovery(unsigned t);
    void Set_Finish(unsigned f);
    inline Tree_Node* Get_Compatible()const {return _compatible_tree_node;}
    inline void Set_Compatible(Tree_Node* myTwin){ _compatible_tree_node = myTwin;}
    void Prepend_To_Adj(Graph_Edge* edge);
    void Prepend_To_Adj_Transpose(Graph_Edge* edge);




private:

    unsigned _key;
    Graph_Node* _next;
    Graph_Node* _prev;
    unsigned _in_degree;
    unsigned _out_degree;
    unsigned _color; //0 - white, 1 - grey, 2 - black.
    unsigned _distance;
    unsigned _discovery;
    unsigned _finish;
    Graph_Edge* _adj_head;
    Graph_Edge* _adj_transpose_head;
    Tree_Node* _compatible_tree_node;

};

#endif //DS_ALGO_PROJECT_GRAPH_NODE_H
