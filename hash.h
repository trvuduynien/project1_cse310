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
    float Standard_deviation();
    void Print_content(int length);
    void Print_slot_length(int length);
    ~Hash_Table();
};

#endif
