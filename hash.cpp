#include <iostream>
#include <cmath>
#include "hash.h"
#include "linked_list.hpp"

Hash_Table::Hash_Table(int size)
{
    this->size = size;
    this->linked_lists = new LinkedList<string>[size];
    this->num_elements = 0;
}

Hash_Table::~Hash_Table()
{
    for (int index = 0; index < this->size; index++)
    {
        this->linked_lists[index].~LinkedList();
    }
    delete[] this->linked_lists;
}

int Hash_Table::Hash_function(string text)
{
    int num_chars = text.length();
    return num_chars % this->size;
}

void Hash_Table::Hash_insert(string text)
{
    int index = this->Hash_function(text);
    this->linked_lists[index].AddNode(text);
    this->num_elements++;
}

float Hash_Table::Standard_deviation()
{
    float standardDeviation = 0, mean;
    mean = float(this->num_elements) / this->size;
    for (int index = 0; index < this->size; ++index)
    {
        standardDeviation = standardDeviation + pow(this->linked_lists[index].Length() - mean, 2) / this->size;
    }
    return sqrt(standardDeviation);
}

void Hash_Table::Print_content(int length)
{
    for (int index = 0; index < length; index++)
    {
        printf("Slot %d:", index);
        for (int node_index = 0; node_index < this->linked_lists[index].Length(); node_index++)
        {
            string temp = this->linked_lists[index].Retrieve(node_index);
            cout << temp << " ";
        }
        cout << endl;
    }
}

void Hash_Table::Print_slot_length(int length)
{
    for (int index = 0; index < length; index++)
    {
        printf("Slot %d: %d\n", index, this->linked_lists[index].Length());
    }
}