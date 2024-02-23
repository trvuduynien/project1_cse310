#ifndef HASH_H
#define HASH_H
#include "linked_list.hpp"
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.

class Hash_Table
{
private:
    int size;
    // define an array of linked lists
    LinkedList<string> *linked_lists;
    int num_elements;

public:
    Hash_Table(int size);
    int Hash_function(string text);
    void Hash_insert(string text);
    LinkedList<string> *Get_slot(int index);
    //define function calculate Standard deviation
    float Standard_deviation();
    void Print_content(int length);
}

#endif
