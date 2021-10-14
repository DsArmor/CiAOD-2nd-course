//
// Created by zelez on 10/13/2021.
//

#include "trees.h"

s_tree sentinel = {BLACK, '\0', nullptr, NIL, NIL};

s_tree *tree_create_node(char symbol, s_tree *parent)
{
    auto *new_node = new s_tree();
    new_node->data = symbol;
    new_node->color = RED;
    new_node->left = NIL;
    new_node->right = NIL;
    new_node->parent = parent;
    return (new_node);
}

void left_rotate(s_tree *root)
{
    s_tree *left = root->parent->parent->left;
//    s_tree *left_child = root->parent->parent->left->left;
//    s_tree *right_child = root->parent->parent->left->right;
    root->parent->parent->left = tree_create_node(root->parent->parent->data, root->parent->parent);
    root->parent->parent->left->left = left;
    root->parent->parent->left->right = root->parent->left;
    root->parent->parent->left->left->parent = root->parent->parent->left;
//    root->parent->parent->left->right = right_child;
    root->parent->parent->data = root->parent->data;

//    s_tree *parent = root->parent->parent;
//    root->parent->parent->right = root;
//    root->parent->parent = parent;
//    root->parent = root;


//work хоть как то
    root->parent->data = root->data;
    root->parent->left = root->left; // не факт
    root->parent->right = root->right;
    free(root);
}

void right_rotate(s_tree *root)
{
    s_tree *left_child = root->parent->parent->right->left;
    s_tree *right_child = root->parent->parent->right->right;
    root->parent->parent->right = tree_create_node(root->parent->parent->data, root->parent->parent);
    root->parent->parent->right->left = left_child;
    root->parent->parent->right->right = right_child;
    root->parent->parent->data = root->parent->data;
    root->parent->data = root->data;
    root->parent->left = NIL;
    free(root);
}

void tree_insert_data(s_tree **root, char symbol, bool (*cmp_f)(char, char))
{
    s_tree *parent = nullptr;
    while (*root != NIL)
    {
        parent = *root;
        if (cmp_f(symbol, (*root)->data))
            root = &((*root)->right);
        else
            root = &((*root)->left);
    }
    *root = tree_create_node(symbol, parent);
    if (!parent)
    {
        (*root)->color = BLACK;
        return ;
    }
    while ((*root)->parent->parent)
    {
        if ((*root)->parent->color == BLACK)
            return ;
        s_tree **tmp = &((*root)->parent->parent);
        if ((*root)->parent->parent->right->color == RED
        && (*root)->parent->parent->left->color == RED)
        {
            (*root)->parent->parent->right->color = BLACK;
            (*root)->parent->parent->left->color = BLACK;
            (*root)->parent->parent->color = RED;
        }
        if ((*root)->parent->parent->right->color == RED)
            left_rotate(*root);
        else if ((*root)->parent->parent->left->color == RED)
            right_rotate(*root);
        root = tmp;
        if (!(*root)->parent)
            (*root)->color = BLACK;
        if ((*root)->color == BLACK)
            return ;
    }
}

void tree_direct_search(s_tree *root, void (*apply_f)(s_tree *))
{
    if (root == NIL)
        return ;
    apply_f(root);
    tree_direct_search(root->left, apply_f);
    tree_direct_search(root->right, apply_f);
}

void tree_inorder_search(s_tree *root, void (*apply_f)(s_tree *, const string &), const string &indent)
{
    if (root == NIL)
        return ;
    tree_inorder_search(root->right, apply_f, indent + "\t");
    apply_f(root, indent);
    tree_inorder_search(root->left, apply_f, indent + "\t");

}

int find_deep(s_tree *root, char symbol,  bool (*cmp_f)(char, char))
{
    int count = 0;
    while (root != NIL)
    {
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

void average(s_tree *root, int *ave)
{
    if (root == NIL)
        return ;
    average(root->left, ave);
    *ave += root->data;
    average(root->right, ave);
}