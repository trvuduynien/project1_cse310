/*
CSE 310 Hash Function DIY Contest
Instructor: Yiran "Lawrence" Luo
Your name(s):
Your team alias:
*/

#include <iostream>
#include "hash.h"
using namespace std;

int main()
{
    int k = 0;
    int n = 0;
    string texts[500];

    // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line))
    {
        texts[n] = line;
        n++;
    }
    // WARNING: End of the tokenizer, DO NOT change this part!

    // By this point, k is the # of slots, and n is the # of tokens to fit in
    // texts[] stores the input sequence of tokens/keys to be inserted into your hash table

    // The template is able to be compiled by running
    //   make
    //   ./encoder < inputs/sample_input.txt
    // which puts out the placeholders only.

    // Your time to shine starts now

    Hash_Table hash_table = Hash_Table(k);

    for (int index = 0; index < n; index++)
    {
        if (texts[index].empty()) {
            continue;
        }
        hash_table.Hash_insert(texts[index]);
    }

    cout << "==== Printing the contents of the first 4 slots ====" << endl;

    hash_table.Print_content(k);

    cout << "==== Printing the slot lengths ====" << endl;

    hash_table.Print_slot_length(k);

    cout << "==== Printing the standard variance =====" << endl;

    printf("Standard variance: %.2f", hash_table.Standard_deviation());

    return 0;
}