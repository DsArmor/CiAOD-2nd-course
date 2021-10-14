//
// Created by zelez on 10/13/2021.
//

#pragma once

#ifndef TREES_TREES_H
#define TREES_TREES_H

#define NIL &sentinel

#include "string"
using namespace std;

typedef struct t_tree s_tree;

typedef enum{RED, BLACK} node_color;

struct t_tree
{
    node_color color;
    char data;
    s_tree *parent;
    s_tree *left;
    s_tree *right;
};

s_tree sentinel = {BLACK, '\0', nullptr, NIL, NIL};

void tree_insert_data(s_tree **root, char symbol, bool (*cmp_f)(char, char));
void tree_direct_search(s_tree *root, void (*apply_f)(s_tree *));
void tree_inorder_search(s_tree *root, void (*apply_f)(s_tree *, string), string indent);
void average(s_tree *root, int *ave);
int find_deep(s_tree *root, char symbol,  bool (*cmp_f)(char, char));


#endif //TREES_TREES_H
