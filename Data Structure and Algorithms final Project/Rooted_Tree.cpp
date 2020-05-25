//
// Created by rom_k on 23-Dec-19.
//

#include "Rooted_Tree.h"


void Rooted_Tree::Print_By_Layer(std::ostream &stream) const
{
    if (_root==NULL)
        return;

    Queue<Tree_Node*> q;
    q.Enqueue(_root);
    while (!q.Is_Empty())
    {
        unsigned n = q.Get_Size();

        while (n > 0)
        {

            Tree_Node* p = q.Get_Front();
            q.Dequeue();
            stream << p->Get_Key() ;
            if (n > 1)
                stream<<",";

            p = p->Get_Left_Child();
            if (p!=NULL)
            {
                q.Enqueue(p);
                while (p->Get_Right_Sibling() != NULL)
                {
                    q.Enqueue(p->Get_Right_Sibling());
                    p = p->Get_Right_Sibling();
                }
            }
            n--;
        }
        if(!q.Is_Empty())
            stream << std::endl;
    }
}

void Rooted_Tree::preorder_help(Tree_Node *node, std::ostream &stream) const
{
    if (node == NULL)
        return;
    while (node)
    {
        stream << "," << node->Get_Key();
        if (node->Get_Left_Child())
            preorder_help(node->Get_Left_Child(), stream);
        node = node->Get_Right_Sibling();
    }
}
void Rooted_Tree::Preorder_Print(std::ostream &stream) const
{

    if(_root!= NULL)
    {
        stream<< _root->Get_Key();
        preorder_help(_root->Get_Left_Child(), stream);
    }
}

void Rooted_Tree::Destroy_Recursive(Tree_Node *node)
{
    if(node)
    {
        Destroy_Recursive(node->Get_Right_Sibling());
        Destroy_Recursive(node->Get_Left_Child());
    }

    delete node;
}
