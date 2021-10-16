//
// Created by zelez on 10/13/2021.
//

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include "trees.h"

using namespace std;

bool cmp_char(char a, char b) {
    if (a >= b)
        return (true);
    return (false);
}

void output_symbol(s_tree *node) {
    cout << node->data << " ";
}

void output_symbol(s_tree *node, const string &indent) {
    string color;
    if (node->color == RED)
        color = "RED";
    else
        color = "BLACK";
    cout << indent << node->data << " " << color << "\n";
}

#endif //MAIN_H
