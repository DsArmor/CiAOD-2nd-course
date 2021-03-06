//
// Created by zelez on 10/13/2021.
//

#ifndef TREES_H
#define TREES_H

#define NIL &sentinel

#include <string>

using namespace std;

typedef struct t_tree s_tree;

typedef enum {
    RED, BLACK
} node_color;

struct t_tree {
    node_color color;
    char data;
    s_tree *parent;
    s_tree *left;
    s_tree *right;
};

extern s_tree sentinel;

// вставка элемента
void tree_insert_data(s_tree **root, char symbol, bool (*cmp_f)(char, char));

// прямой обход дерева
void tree_direct_search(s_tree *root, void (*apply_f)(s_tree *));

// симметричный обход дерева
void tree_inorder_search(s_tree *root, void (*apply_f)(s_tree *));

// мой обход дерева для красивого вывода
void tree_collab_inorder_search(s_tree *root, void (*apply_f)(s_tree *, const string &), const string &indent);

// поиск среднего арифметического
void average(s_tree *root, int *ave, int *count);

// поиск глубины
int find_deep(s_tree *root, char symbol, bool (*cmp_f)(char, char));

#endif //TREES_TREES_H
