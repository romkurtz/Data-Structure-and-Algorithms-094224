//
// Created by rom_k on 26-Dec-19.
//

#ifndef DS_HW_DRY_TREE_NODE_H
#define DS_HW_DRY_TREE_NODE_H
#include "Queue.h"


class Tree_Node
{
public:
    Tree_Node(unsigned key, unsigned distance):_key(key),_parent(NULL),_right_sibling(NULL),
    _left_child(NULL),_distance(distance),_discovery(0),_finish(0){}
    unsigned Get_Key(){ return _key;}
    Tree_Node* Get_Left_Child(){ return _left_child;}
    Tree_Node* Get_Right_Sibling(){ return _right_sibling;}
    void Set_Distance(unsigned distance){ _distance = distance;}
    void Set_Discovery(unsigned time){_discovery = time;}
    void Set_Finish(unsigned finish){ _finish = finish;}
    void Set_Parent(Tree_Node* parent){_parent = parent;}
    void Add_child(Tree_Node* child,Tree_Node* Left_Sibling);
    ~Tree_Node(){}


private:
    unsigned _key;
    Tree_Node* _parent;
    Tree_Node* _right_sibling;
    Tree_Node* _left_child;
    unsigned _distance;
    unsigned _discovery;
    unsigned _finish;
};


#endif //DS_HW_DRY_TREE_NODE_H
