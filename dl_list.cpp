#include <ostream>
#include <iostream>
#include "dl_list.h"

List::List () { }

void List::insert (int value, const size_t &index)
{
    if (index == 0) {
        insert_first(value);
        return;
    }
    if (index == length - 1) {
        insert_last(value);
        return;
    }

    size_t cur_index = 0;
    Node *cur_node;
    cur_node = head;
    while (cur_index < index) {
        cur_node = cur_node->next;
        cur_index++;
    }
    auto node = new Node();
    node->value = value;
    node->prev = cur_node->prev;
    node->next = cur_node;

    cur_node->prev->next = node;
    cur_node->prev = node;

    ++length;
}

void List::insert_first (int value)
{
    Node *node = new Node();
    node->value = value;
    node->prev = nullptr;

    if (length != 0) {
        node->next = head;
        head->prev = node;
        head = node;
    } else {
        head = node;
        tail = head;
        node->next = nullptr;
    }

    ++length;
}

void List::insert_last (int value)
{
    Node *node = new Node();
    node->value = value;

    if (length) {
        node->prev = tail;
        tail->next = node;
        tail = node;
    } else {
        node->prev = head;
        head = node;
        tail = head;
    }
    node->next = nullptr;

    ++length;
}

void List::print_connections ()
{
    std::cout << "List length: " << length << std::endl;
    Node *cur_node;
    cur_node = head;
    do {
        std::cout << cur_node->value << " <=> ";
        cur_node = cur_node->next;
    } while (cur_node->next);
    std::cout << cur_node->value << std::endl;
}

Node *List::operator[] (const size_t &index)
{
    size_t cur_index;
    Node *cur_node;
    if (index < length / 2) {
        cur_index = 0;
        cur_node = head;
        while (cur_index < index) {
            cur_node = cur_node->next;
            ++cur_index;
        }
    } else {
        cur_index = length - 1;
        cur_node = tail;
        while (cur_index > index) {
            cur_node = cur_node->prev;
            --cur_index;
        }
    }
    return cur_node;
}

int List::get_value (const size_t &index)
{
    return operator[](index)->value;
}

void List::remove (const size_t &index)
{
    size_t cur_index;
    Node *cur_node;

    if (index == 0) {
        remove_first();
        return;
    }
    if (index == length - 1) {
        remove_last();
        return;
    }

    if (index < length / 2) {
        cur_index = 0;
        cur_node = head;
        while (cur_index < index) {
            cur_node = cur_node->next;
            cur_index++;
        }
    } else {
        cur_index = length - 1;
        cur_node = tail;
        while (cur_index > index) {
            cur_node = cur_node->prev;
            cur_index--;
        }
    }
    cur_node->prev->next = cur_node->next;
    cur_node->next->prev = cur_node->prev;

    --length;
}

void List::remove_first ()
{
    head = head->next;
    delete head->prev;
    head->prev = nullptr;
    --length;
}

void List::remove_last ()
{
    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
    --length;
}
