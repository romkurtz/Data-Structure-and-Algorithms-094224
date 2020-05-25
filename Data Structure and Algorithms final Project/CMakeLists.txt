cmake_minimum_required(VERSION 3.15)
project(DS_HW_dry)

set(CMAKE_CXX_STANDARD 98)

add_executable(DS_HW_dry main.cpp Graph_Node.cpp Graph_Node.h Graph_Edge.cpp Graph_Edge.h
        Tree_Node.h Tree_Node.cpp Rooted_Tree.cpp Rooted_Tree.h Dynamic_Graph.cpp
        Dynamic_Graph.h Linked_List_Node.cpp Linked_List_Node.h Linked_List_Edge.cpp
        Linked_List_Edge.h Queue.h Stack.h)