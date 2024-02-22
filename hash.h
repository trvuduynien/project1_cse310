#ifndef HASH_H
#define HASH_H
#include <iostream>
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.


int hash_function(string text);

class Hash_Table {
    private:
    int size;
    //define an array of linked lists
    LinkedList<string>* linked_lists;


    public:
    Hash_Table(int size);
    int Hash_function(string text);
    void Hash_insert(string text);
    Linkedlist<string> Get_key(int index);

}
#endif
