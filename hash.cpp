#include <iostream>
#include <string>
#include <cmath>
#include <list>
#include <algorithm>
#include "hash.h"
#include "linked_list.hpp"

Hash_Table::Hash_Table(int size)
{
    this->size = size;
    this->linked_lists = new LinkedList<string>[size];
    int num_elements = 0;
}

int Hash_Table::Hash_function(string text)
{
    unsigned long hash = 0;
    for (char c : text)
    {
        hash = ((hash << 5) + hash) + c; 
        // hash = (hash * 31 + c) % this->size;
    }
    return hash % this->size;
}


void Hash_Table::Hash_insert(string text)
{
    int index = this->Hash_function(text);
    this->linked_lists[index].AddNode(text);
    // increment num_elements when inserting
    this->num_elements++;
}
LinkedList<string> Hash_Table::Get_slot(int index)
{
    return this->linked_lists[index];
}

float Hash_Table::Standard_deviation()
{
    float mean = this->num_elements / this->size;
    float sum_of_squared_differences = 0;

    for (int i = 0; i < this->size; i++)
    {
        float difference = this->Get_slot(i).Length() - mean;
        sum_of_squared_differences += difference * difference;
    }

    return sqrt(sum_of_squared_differences / (this->size - 1));
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
            cout << temp << " ";
        }
        cout << endl;
    }
}
void Hash_Table::Print_slot_length(int length)
{
    for (int index = 0; index < length; index++)
    {
        LinkedList<string> list_str = this->Get_slot(index);
        printf("Slot %d: %d\n", index, list_str.Length());
    }
}