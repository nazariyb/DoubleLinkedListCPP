#ifndef DL_LIST_CPP_DL_LIST_H
#define DL_LIST_CPP_DL_LIST_H

#include <glob.h>
#include "node.h"

class List
    {
    Node *head;
    Node *tail;
    size_t length;
public:
    List();
    void insert (int value, const size_t &index);
    void insert_first (int value);
    void insert_last (int value);
    void print_connections ();
    Node* operator[] (const size_t &index);
    int get_value (const size_t &index);
    void remove (const size_t &index);
    void remove_first ();
    void remove_last ();
    inline size_t get_length() { return length; }
    };

#endif //DL_LIST_CPP_DL_LIST_H
