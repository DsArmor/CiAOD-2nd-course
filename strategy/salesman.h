//
// Created by zelez on 12/6/2021.
//

#ifndef STRATEGY_SALESMAN_H
#define STRATEGY_SALESMAN_H


#include "iostream"
#include <iomanip>
#include "vector"

using namespace std;

typedef struct tList{
    int a, b, potential = 0;
} sList;

typedef struct tNode{
    int H;
    vector<sList *> list;
    vector<int> x, y;
    int **matrix;
    tNode *left;
    tNode *right;
} sNode;

extern int M;

int **init_matrix(int x, int y);
int find_locality(vector<sList *> min_way, int finder);
vector<sList *> build_tree(int **adj_matrix, int size);
void fill_node(sNode *node, sNode *root, int size);
void out_matrix(int **adj_matrix, int x, int y);
void fill_matrix(int **adj_matrix, int y, int x);


#endif //STRATEGY_SALESMAN_H
