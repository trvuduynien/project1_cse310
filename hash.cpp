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

    // number of characters in the input string
    int num_chars = text.length();
    return num_chars % size;
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
    float sum, standardDeviation = 0, mean;

    mean = this->num_elements / this->size;

    // sqrt(1/n*(x_i-mean)^2)

    for (int i = 0; i < size; ++i)
    {
        standardDeviation = sqrt(pow(linked_lists[i].Length() - mean, 2) / this->size);
    }
    return standardDeviation;
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