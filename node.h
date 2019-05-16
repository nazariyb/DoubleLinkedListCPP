#ifndef DL_LIST_CPP_NODE_H
#define DL_LIST_CPP_NODE_H


struct Node
    {
    int value;
    struct Node *prev;
    struct Node *next;
    };
using Node = struct Node;

#endif //DL_LIST_CPP_NODE_H
