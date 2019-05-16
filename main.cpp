#include <iostream>
#include "dl_list.h"


int main ()
{
    auto list = new List();
    std::cout << "list size: " << list->get_length() << " (0)" << std::endl;

    list->insert_last(10);
    std::cout << std::endl;
    std::cout << "insert last: 10" << std::endl;
    std::cout << "list size: " << list->get_length() << " (1)" << std::endl;
    std::cout << "list head: " << list->get_value(0) << " (10)" << std::endl;
    std::cout << "list tail: " << list->get_value(list->get_length() - 1) << " (10)" << std::endl;

    list->insert_last(20);
    std::cout << std::endl;
    std::cout << "insert last: 20" << std::endl;
    std::cout << "list size: " << list->get_length() << " (2)" << std::endl;
    std::cout << "list head: " << list->get_value(0) << " (10)" << std::endl;
    std::cout << "list tail: " << list->get_value(list->get_length() - 1) << " (20)" << std::endl;

    list->print_connections();
    std::cout << "( 10 <=> 20 )" << std::endl;

    list->insert_last(30);
    std::cout << std::endl;
    std::cout << "insert last: 30" << std::endl;
    std::cout << "list size: " << list->get_length() << " (3)" << std::endl;
    std::cout << "list head: " << list->get_value(0) << " (10)" << std::endl;
    std::cout << "list tail: " << list->get_value(list->get_length() - 1) << " (30)" << std::endl;

    list->print_connections();
    std::cout << "( 10 <=> 20 <=> 30 )" << std::endl;

    list->insert_first(-10);
    std::cout << std::endl;
    std::cout << "insert first: -10" << std::endl;
    list->print_connections();
    std::cout << "( -10 <=> 10 <=> 20 <=> 30 )" << std::endl;

    list->insert_first(-20);
    std::cout << std::endl;
    std::cout << "insert first: -20" << std::endl;
    list->print_connections();
    std::cout << "( -20 <=> -10 <=> 10 <=> 20 <=> 30 )" << std::endl;

    list->insert(15, 3);
    std::cout << std::endl;
    std::cout << "insert 15 on position 3: " << std::endl;
    list->print_connections();
    std::cout << "( -20 <=> -10 <=> 10 <=> 15 <=> 20 <=> 30 )" << std::endl;

    list->insert(-30, 0);
    std::cout << std::endl;
    std::cout << "insert -30 on position 0: " << std::endl;
    list->print_connections();
    std::cout << "( -30 <=> -20 <=> -10 <=> 10 <=> 15 <=> 20 <=> 30 )" << std::endl;

    std::cout << "\nval first: " << list->get_value(0) << " (-30)" << std::endl;
    std::cout << "\nval last: " << list->get_value(list->get_length() - 1) << " (30)" << std::endl;

    list->print_connections();
    std::cout << "( -30 <=> -20 <=> -10 <=> 10 <=> 15 <=> 20 <=> 30 )" << std::endl;
    list->remove_last();
    std::cout << std::endl;
    std::cout << "remove last: " << std::endl;
    list->print_connections();
    std::cout << "( -30 <=> -20 <=> -10 <=> 10 <=> 15 <=> 20 )" << std::endl;
    std::cout << "val last: " << list->get_value(list->get_length() - 1) << " (20)" << std::endl;

    list->print_connections();
    std::cout << "( -30 <=> -20 <=> -10 <=> 10 <=> 15 <=> 20)" << std::endl;
    list->remove_first();
    std::cout << std::endl;
    std::cout << "remove first: " << std::endl;
    list->print_connections();
    std::cout << "( -20 <=> -10 <=> 10 <=> 15 <=> 20)" << std::endl;
    std::cout << "\nval first: " << list->get_value(0) << " (-20)" << std::endl;

    std::cout << "val 0: " << list->get_value(0) << " (-20)" << std::endl;
    std::cout << "val 1: " << list->get_value(1) << " (-10)" << std::endl;
    std::cout << "val 2: " << list->get_value(2) << " (10)" << std::endl;
    std::cout << "val 3: " << list->get_value(3) << " (15)" << std::endl;
    std::cout << "val 4: " << list->get_value(4) << " (20)" << std::endl;

    list->print_connections();
    std::cout << "( -20 <=> -10 <=> 10 <=> 15 <=> 20 )" << std::endl;
    list->remove(4);
    std::cout << std::endl;
    std::cout << "remove on position 4: " << std::endl;
    list->print_connections();
    std::cout << "( -20 <=> -10 <=> 10 <=> 15 )" << std::endl;

    list->remove(1);
    std::cout << std::endl;
    std::cout << "remove on position 1: " << std::endl;
    list->print_connections();
    std::cout << "( -20 <=> 10 <=> 15 )" << std::endl;
    return 0;
}