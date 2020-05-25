//
// Created by rom_k on 23-Dec-19.
//
#ifndef DS_ALGO_PROJECT_ROOTED_TREE_H
#define DS_ALGO_PROJECT_ROOTED_TREE_H
#include <ostream>
#include "Tree_Node.h"


class Rooted_Tree
{
public:
    Rooted_Tree():_root(NULL){}
    Rooted_Tree(Tree_Node* root):_root(root){}
    Tree_Node* Get_Root()const { return _root;}
    void Print_By_Layer(std::ostream& stream) const;
    void preorder_help(Tree_Node* node, std::ostream &stream) const;
    void Preorder_Print(std::ostream& stream) const;
    static void Destroy_Recursive(Tree_Node* node);
    ~Rooted_Tree(){Destroy_Recursive(_root);}



private:
    Tree_Node* _root;
};


#endif //DS_ALGO_PROJECT_ROOTED_TREE_H
