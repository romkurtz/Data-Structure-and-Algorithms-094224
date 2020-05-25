//
// Created by rom_k on 23-Dec-19.
//
#include "Dynamic_Graph.h"


void Dynamic_Graph::Delete_Node(Graph_Node *node) {
    if(node->Get_in_Degree()==0 && node->Get_out_Degree()==0){
        _nodes_list.Delete_Node(node);
    }
}
void Dynamic_Graph::Delete_Edge(Graph_Edge *edge){
    _edges_list.Delete_Edge(edge);
}

Rooted_Tree * Dynamic_Graph::BFS_Initialization(Graph_Node *source,
         Queue<Graph_Node*>&Bfs_Queue) const
{

    // clean prev state
    Graph_Node* temp = _nodes_list.Get_Head();
    while (temp!=NULL)
    {
        temp->Set_Color(0);
        temp->Set_Compatible(NULL);
        temp->Set_Distance(INFINITE);
        temp = temp->Get_Next();
    }

    // start tree in head node
    Tree_Node *root = new Tree_Node(source->Get_key(),0);
    source->Set_Compatible(root);
    Rooted_Tree *rootTree = new Rooted_Tree(root);
    source->Set_Color(1);
    source->Set_Distance(0);
    Bfs_Queue.Enqueue(source);
    return rootTree;
}

Rooted_Tree* Dynamic_Graph::BFS(Graph_Node *source) const {
    Queue<Graph_Node*> BfsQueue;
    Rooted_Tree *rootTree = BFS_Initialization(source, BfsQueue);
    source->Set_Compatible(rootTree->Get_Root());
    Graph_Node *CurrentGraphNode = NULL;
    Tree_Node *CurrentTreeNode = NULL;
    Tree_Node *prev = NULL;

    while (!BfsQueue.Is_Empty())
    {
        CurrentGraphNode = BfsQueue.Dequeue();
        CurrentTreeNode = CurrentGraphNode->Get_Compatible();
        Graph_Edge *edge_of_adj = CurrentGraphNode->Get_adj_head();

        while (edge_of_adj)
        {
            Graph_Node* neighbor = edge_of_adj->Get_To();
            if (neighbor->Get_Color() == 0)
            {
                Tree_Node *neighbor_Tree_Node = new Tree_Node(neighbor->Get_key(),
                                                              neighbor->Get_Distance());
                neighbor->Set_Compatible(neighbor_Tree_Node);
                neighbor_Tree_Node->Set_Parent(CurrentTreeNode);
                CurrentTreeNode->Add_child(neighbor_Tree_Node, prev);
                prev = neighbor_Tree_Node;
                neighbor->Set_Color(1);
                neighbor->Set_Distance(CurrentGraphNode->Get_Distance() + 1);
                BfsQueue.Enqueue(neighbor);
            }
            edge_of_adj = edge_of_adj->Get_Next_In_Adj();
        }
        prev = NULL;
        CurrentGraphNode->Set_Color(2);
    }

    return rootTree;
}


void Dynamic_Graph::DFS_Visit_Transpose(Graph_Node *curr_graph_node, Tree_Node* curr_tree_node ,
                                        unsigned &time_stamp)const
{
    time_stamp++;
    Tree_Node* prev = NULL;
    curr_graph_node->Set_Discovery(time_stamp);
    curr_graph_node->Set_Color(1);
    curr_graph_node->Set_Compatible(curr_tree_node);
    Graph_Edge *edge_of_adj = NULL;
    edge_of_adj = curr_graph_node->Get_adj_transpose_head();
    Tree_Node *neighbor_tree_node = NULL;
    while (edge_of_adj!=NULL)
    {

        Graph_Node* neighbor_graph_node = edge_of_adj->Get_From();
        if (neighbor_graph_node->Get_Color() == 0)
        {
            neighbor_tree_node = new Tree_Node(neighbor_graph_node->Get_key(),
                                               neighbor_graph_node->Get_Distance());
            neighbor_graph_node->Set_Compatible(neighbor_tree_node);
            neighbor_tree_node->Set_Parent(curr_tree_node);
            curr_tree_node->Add_child(neighbor_tree_node, prev);
            prev = neighbor_tree_node;
            DFS_Visit_Transpose(neighbor_graph_node, neighbor_tree_node , time_stamp);
        }
        edge_of_adj = edge_of_adj->Get_Next_In_Adj_Transpose();
    }
    curr_graph_node->Set_Color(2);
    time_stamp++;
    curr_graph_node->Set_Finish(time_stamp);
}

Rooted_Tree *Dynamic_Graph::DFS_Transpose(Stack<Graph_Node*>&Finish_Time_Stack) const
{
    unsigned time = 0;

    Tree_Node* dummy = new Tree_Node(0, 0);
    Rooted_Tree* SCC_Tree = new Rooted_Tree(dummy);
    Tree_Node* prev = NULL;

    while(!Finish_Time_Stack.Is_Empty())
    {
        Graph_Node* curr_node = Finish_Time_Stack.Pop();

        if (curr_node->Get_Color() == 0)
        {
            Tree_Node* curr_tree_node = new Tree_Node(curr_node->Get_key(),
                                                      curr_node->Get_Distance());
            curr_node->Set_Compatible(curr_tree_node);
            DFS_Visit_Transpose(curr_node, curr_tree_node , time);
            curr_tree_node->Set_Parent(dummy);
            dummy->Add_child(curr_tree_node, prev);
            prev = curr_tree_node;
        }
    }
    return SCC_Tree;
}



void Dynamic_Graph::DFS_Visit(Graph_Node *node,Stack<Graph_Node*> &Finish_Time_Stack,
                              unsigned &time_stamp) const
{
    time_stamp++;
    node->Set_Discovery(time_stamp);
    node->Set_Color(1);
    Graph_Edge *edge_in_adj = node->Get_adj_head();

    while (edge_in_adj != NULL)
    {
        Graph_Node *neighbor = edge_in_adj->Get_To();
        if (neighbor->Get_Color() == 0)
        {
            DFS_Visit(neighbor, Finish_Time_Stack, time_stamp);
        }
        edge_in_adj = edge_in_adj->Get_Next_In_Adj();
    }
    node->Set_Color(2);
    time_stamp++;
    node->Set_Finish(time_stamp);
    Finish_Time_Stack.Push(node);
}

void Dynamic_Graph::DFS(Stack<Graph_Node*> &Finish_Time_Stack)const
{

    unsigned time = 0;
    Graph_Node* node = _nodes_list.Get_Head();

    while (node != NULL)
    {
        if (node->Get_Color() == 0)
        {
            DFS_Visit(node, Finish_Time_Stack, time);
        }
        node = node->Get_Next();
    }
}


void Dynamic_Graph::SCC_Initialization() const
{
    Graph_Node* node = _nodes_list.Get_Head();
    while (node != NULL)
    {
        node->Set_Compatible(NULL);
        node->Set_Color(0);
        node->Set_Discovery(0);
        node->Set_Finish(0);
        node = node->Get_Next();
    }
}

Rooted_Tree* Dynamic_Graph::SCC() const
{
    Stack<Graph_Node*> Finish_Time_Stack;

    SCC_Initialization();
    DFS(Finish_Time_Stack);

    SCC_Initialization();
    Rooted_Tree* SCC_Tree = DFS_Transpose(Finish_Time_Stack);

    return SCC_Tree;
}


