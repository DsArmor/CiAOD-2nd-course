//
// Created by zelez on 10/13/2021.
//
#include "trees.h"

// создание элемента-заглушки
s_tree sentinel = {BLACK, '\0', nullptr, NIL, NIL};

//создание узла дерева
s_tree *tree_create_node(char symbol, s_tree *parent) {
    auto *new_node = new s_tree();
    new_node->data = symbol;
    new_node->color = RED;
    new_node->left = NIL;
    new_node->right = NIL;
    new_node->parent = parent;
    return (new_node);
}

void left_rotate(s_tree *root) {
    // выполнить малый левый поворот, если нужно
    if (root->parent->left->color == RED) {
        root->parent->parent->right = root;
        s_tree *right_cur = root->right;
        root->right = root->parent;
        root->right->left = right_cur;
        root->right->left->parent = root->right;
        root->parent = root->parent->parent;
        root->right->parent = root;
        root = root->right;
    }
    // левый поворот
    s_tree *left = root->parent->parent->left;
    root->parent->parent->left = tree_create_node(root->parent->parent->data, root->parent->parent);
    root->parent->parent->left->left = left;
    root->parent->parent->left->right = root->parent->left;
    root->parent->parent->left->right->parent = root->parent->parent->left;
    root->parent->parent->data = root->parent->data;
    root->parent->parent->right = root;
    root->parent = root->parent->parent;
}

void right_rotate(s_tree *root) {
    // выполнить малый правый поворот, если надо
    if (root->parent->right->color == RED) {
        root->parent->parent->left = root;
        s_tree *left_cur = root->left;
        root->left = root->parent;
        root->left->right = left_cur;
        root->left->right->parent = root->left;
        root->parent = root->parent->parent;
        root->left->parent = root;
        root = root->left;
    }
    // правый поворот
    s_tree *right = root->parent->parent->right;
    root->parent->parent->right = tree_create_node(root->parent->parent->data, root->parent->parent);
    root->parent->parent->right->right = right;
    root->parent->parent->right->left = root->parent->right;
    root->parent->parent->right->left->parent = root->parent->parent->right;
    root->parent->parent->data = root->parent->data;
    root->parent->parent->left = root;
    root->parent = root->parent->parent;
}

void doBalance(s_tree *root) {
    // пока есть дед
    while (root->parent->parent) {
        // если цвет родителя черный -> все хорошо, выходим
        if (root->parent->color == BLACK)
            return;
        // запомним деда
        s_tree *gr_father = root->parent->parent;
        // если отец и дядя красные, тогда их сделать черными, а деда -> красным
        if (root->parent->parent->right->color == RED
            && root->parent->parent->left->color == RED) {
            root->parent->parent->right->color = BLACK;
            root->parent->parent->left->color = BLACK;
            root->parent->parent->color = RED;
        }
        // родитель красный, но дядя черный, в зависимости от того, является ли текущий родитель
        // правым от деда или левым, сделать левый поворот или правый
        if (root->parent->parent->right->color == RED)
            left_rotate(root);
        else if (root->parent->parent->left->color == RED)
            right_rotate(root);
        // теперь root -> дед
        root = gr_father;
        // если мы в корне, корень сделать черным
        if (!root->parent)
            root->color = BLACK;
        // если root теперь черный, ребалансировка завершена
        if (root->color == BLACK)
            return;
    }
}

void tree_insert_data(s_tree **root, char symbol, bool (*cmp_f)(char, char)) {
    s_tree *parent = nullptr;
    // пока не NIL будем спускаться по дереву
    // выбирая спуск в зависимости от результата компаратора
    while (*root != NIL) {
        // сделать родителем текущий до спуска влево или вправо элемент
        parent = *root;
        if (cmp_f(symbol, (*root)->data))
            root = &((*root)->right);
        else
            root = &((*root)->left);
    }
    // мы находимся в нужном месте, теперь здесь создаем узел
    *root = tree_create_node(symbol, parent);
    // если родитель nullptr -> значит вставка в корень
    if (!parent) {
        (*root)->color = BLACK;
        return;
    }
    // ребалансировка
    doBalance(*root);
}

void tree_direct_search(s_tree *root, void (*apply_f)(s_tree *)) {
    // прямой обход
    // вывести элемент, спуститься влево
    // спуститься вправо, когда вернемся рекурсивно из левого
    if (root == NIL)
        return;
    apply_f(root);
    tree_direct_search(root->left, apply_f);
    tree_direct_search(root->right, apply_f);
}

void tree_collab_inorder_search(s_tree *root, void (*apply_f)(s_tree *, const string &), const string &indent) {
    // сперва спуститься до конца правого, вывести, спуститься влево
    if (root == NIL)
        return;
    tree_collab_inorder_search(root->right, apply_f, indent + "\t");
    apply_f(root, indent);
    tree_collab_inorder_search(root->left, apply_f, indent + "\t");
}

void tree_inorder_search(s_tree *root, void (*apply_f)(s_tree *)) {
    // симметричный обход
    // сперва спуститься до конца левого, вывести, спуститься вправо
    if (root == NIL)
        return;
    tree_inorder_search(root->left, apply_f);
    apply_f(root);
    tree_inorder_search(root->right, apply_f);
}

int find_deep(s_tree *root, char symbol, bool (*cmp_f)(char, char)) {
    // подсчет глубины
    // пока не найдем символ или не дойдем до конца дерева, спускаться по дереву,
    // добавлять глубину
    int count = 0;
    while (root != NIL) {
        count++;
        if (root->data == symbol)
            return (count);
        if (cmp_f(symbol, root->data))
            root = root->right;
        else
            root = root->left;
    }
    return (0);
}

void average(s_tree *root, int *ave, int *count) {
    // среднее арифметическое получим, выполнив симметричный обход дерева
    // на каждом узле прибавим его к ave, на выходе получим сумму всех data узлов
    if (root == NIL)
        return;
    (*count)++;
    average(root->left, ave, count);
    *ave += root->data;
    average(root->right, ave, count);
}