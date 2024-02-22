#include <iostream>
#include <string>
#include <cmath>
#include "hash.h"
#include "linked_list.hpp"

Hash_Table::Hash_Table(int size)
{
    this->size = size;
    this->linked_lists = new LinkedList<string>[size];
}
int Hash_Table::Hash_function(string text)
{
    return 0;
}
void Hash_Table::Hash_insert(string text)
{
    int index = this->Hash_function(text);
    this->linked_lists[index].AddNode(text);
}
LinkedList<string> *Hash_Table::Get_slot(int index)
{
    return this->linked_lists[index];
}
void Hash_Table::Print_content(int length)
{
    for (int index = 0; index < length; index++)
    {
        LinkedList<string> list_str = this->Get_slot(index);
        printf("Slot %d:", index);
        for (int node_index = 0; node_index < list_str.Length(); node_index++)
        {
            string temp = list_str.Retrieve(node_index);
            printf("%s ", temp);
        }
        cout << endl;
    }
}