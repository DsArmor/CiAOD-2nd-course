//
// Created by zelez on 10/13/2021.
//

#ifndef TREES_MAIN_H
#define TREES_MAIN_H

#include <iostream>
#include "string"
#include "trees.h"

using namespace std;

bool cmp_char(char a, char b)
{
    if (a >= b)
        return (true);
    return (false);
}

void output_symbol(s_tree *node)
{
    cout << node->data << " ";
}

void output_symbol(s_tree *node, string indent)
{
    cout << indent << node->data << "\n";
}

#endif //TREES_MAIN_H
