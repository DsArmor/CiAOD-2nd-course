//
// Created by zelez on 10/13/2021.
//

#include "trees.h"

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
    char tmp = root->parent->data;
    root->parent->data = root->data;
    root->parent->right = tree_create_node(tmp, root->parent);
    root->parent->left = NIL;

    root->parent->parent->left->left =
            tree_create_node(root->parent->parent->left->data, root->parent->parent->left);
    root->parent->parent->left->left->color = BLACK;

    root->parent->parent->left->data = root->parent->parent->data;
    root->parent->parent->left->color = RED;

    root->parent->parent->data = root->parent->data;
    root->parent->data = root->data;
    root->parent->right = root->right;
    free(root);
}

void right_rotate(s_tree *root)
{
    char tmp = root->parent->data;
    root->parent->data = root->data;
    root->parent->left = tree_create_node(tmp, root->parent);
    root->parent->right = NIL;

    root->parent->parent->right->right =
            tree_create_node(root->parent->parent->right->data, root->parent->parent->right);
    root->parent->parent->right->right->color = BLACK;

    root->parent->parent->right->data = root->parent->parent->data;
    root->parent->parent->right->color = RED;

    root->parent->parent->data = root->parent->data;
    root->parent->data = root->data;
    root->parent->left = root->left;
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
        {
            (*root)->color = BLACK;
            return ;
        }
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

void tree_inorder_search(s_tree *root, void (*apply_f)(s_tree *, string), string indent)
{
    if (root == NIL)
        return ;
    tree_inorder_search(root->left, apply_f, indent + "\t");
    apply_f(root, indent);
    tree_inorder_search(root->right, apply_f, indent + "\t");
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