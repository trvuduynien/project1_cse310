#include <iostream>
#include <string>
#include <cmath>
#include "hash.h"
#include "linked_list.hpp"

using namespace std;

int Hash_Table::Hash_function(string text){
    
    this->size = size; 
    // number of characters in the input string
    int num_chars = text.length(); 
    return num_chars % size; 
}