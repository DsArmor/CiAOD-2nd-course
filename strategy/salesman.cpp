//
// Created by zelez on 12/6/2021.
//

#include "salesman.h"

/*
5 20
1 2 20
1 3 18
1 4 12
1 5 8
2 1 5
2 3 14
2 4 7
2 5 11
3 1 12
3 2 18
3 4 6
3 5 11
4 1 11
4 2 17
4 3 11
4 5 12
5 1 5
5 2 5
5 3 5
5 4 5
 */

int M = 1000000000;

int find_and_substract(int **adj_matrix, vector<int> x, vector<int> y) {
    int sum = 0;

    for (int i: x) {
        int min = adj_matrix[i][y[0]];
        for (int j: y) {
            if (adj_matrix[i][j] < min)
                min = adj_matrix[i][j];
        }
        for (int j: y) {
            if (adj_matrix[i][j] != M)
                adj_matrix[i][j] -= min;
        }
        sum += min;
    }
    for (int j: y) {
        int min = adj_matrix[x[0]][j];
        for (int i: x) {
            if (adj_matrix[i][j] < min)
                min = adj_matrix[i][j];
        }
        for (int i: x) {
            if (adj_matrix[i][j] != M)
                adj_matrix[i][j] -= min;
        }
        sum += min;
    }
    return sum;
}

sList *find_max_potential(int **adj_matrix, vector<int> x, vector<int> y) {
    auto *potent = new sList();
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < y.size(); j++) {
            if (adj_matrix[x[i]][y[j]] == 0) {
                int min_x = M;
                int min_y = M;
                for (int k: y) {
                    if (min_x > adj_matrix[x[i]][k] && adj_matrix[x[i]][k] != M
                        && k != y[j])
                        min_x = adj_matrix[x[i]][k];
                }
                for (int k: x) {
                    if (min_y > adj_matrix[k][y[j]] && adj_matrix[k][y[j]] != M
                        && k != x[i])
                        min_y = adj_matrix[k][y[j]];
                }
                if (min_y + min_x > potent->potential) {
                    potent->a = x[i];
                    potent->b = y[j];
                    potent->potential = min_x + min_y;
                }
            }
        }
    }
    return potent;
}

void matrix_reduction(int **adj_matrix, vector<int> &x, vector<int> &y, sList *potent, bool f) {
    adj_matrix[potent->a][potent->b] = M;
    if (f) {
        adj_matrix[potent->b][potent->a] = M;
        int i =0;
        while (x[i] != potent->a)
            i++;
        x.erase(x.cbegin() + i);
        i = 0;
        while (y[i] != potent->b)
            i++;
        y.erase(y.cbegin() + i);
    }
}

int **init_matrix(int x, int y) {
    int **adj_matrix;
    adj_matrix = new int *[x];
    for (int i = 0; i < x; i++) {
        adj_matrix[i] = new int[y];
    }
    return adj_matrix;
}

void fill_matrix(int **adj_matrix, int y, int x) {
    for (int i = 0; i < y; i++) {
        int first, second, weight;
        cin >> first >> second >> weight;
        adj_matrix[first - 1][second - 1] = weight;
        if (i < x)
            adj_matrix[i][i] = M;
    }
}

void out_matrix(int **adj_matrix, int x, int y) {
    cout << " |";
    for (int i = 1; i <= x; i++) {
        cout  << setw(5) << i << " ";
    }
    cout << setw(5) << "\n- ";
    for (int i = 1; i <= y; i++) {
        cout  << setw(5) << "- ";
    }
    cout << '\n';
    for (int i = 0; i < x; i++) {
        cout << i + 1 << "|";
        for (int j = 0; j < y; j++) {
            if (adj_matrix[i][j] == M)
                cout << setw(5) << "M" << " ";
            else
                cout << setw(5) << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void fill_node(sNode *node, sNode *root, int size) {
    vector<int> x(root->x);
    vector<int> y(root->y);
    node->x = x;
    node->y = y;
    int **adj_matrix = init_matrix(size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            adj_matrix[i][j] = root->matrix[i][j];
    }
    node->matrix = adj_matrix;
}

vector<sList *> build_tree(int **adj_matrix, int size) {
    vector<sNode *> foliage;
    sNode *min_node;
    sNode *root_root;
    auto *root = new sNode();
    vector<int> x;
    vector<int> y;
    for (int i = 0; i < size; i++) {
        x.push_back(i);
        y.push_back(i);
    }
    root->matrix = adj_matrix;
    root->x = x;
    root->y = y;
    root_root = root;
    root->H = find_and_substract(root->matrix, root->x, root->y);
    while (true) {
        if (root->x.size() == 1){
            root->list.push_back(new sList{root->x[0], root->y[0], 0});
            break;
        }
        for (int i = 0; i < foliage.size(); i++) {
            if (foliage[i] == root) {
                foliage.erase(foliage.cbegin() + i);
                break;
            }
        }
        sList *potent = find_max_potential(root->matrix, root->x, root->y);
        root->left = new sNode();
        root->right = new sNode();
        (root->right->list).assign(root->list.cbegin(), root->list.cend());
        (root->left->list).assign(root->list.cbegin(), root->list.cend());
        //правый
        fill_node(root->right, root, size);
        matrix_reduction(root->right->matrix, root->right->x, root->right->y, potent, true);
        (root->right->list).push_back(potent);
        root->right->H = root->H + find_and_substract(root->right->matrix, root->right->x, root->right->y);
        //левый
        fill_node(root->left, root, size);
        matrix_reduction(root->left->matrix, root->left->x, root->left->y, potent, false);
        root->left->H = root->H + potent->potential;
        find_and_substract(root->left->matrix, root->left->x, root->left->y);

        foliage.push_back(root->left);
        foliage.push_back(root->right);
        min_node = foliage.front();
        for (sNode *t: foliage) {
            if (t->H < min_node->H)
                min_node = t;
        }
        root = min_node;
    }

    for (sList *l: root->list)
        cout << l->a + 1 << "-" << l->b + 1<< '\n';
    cout << root->H << '\n';
    return root->list;
}

int find_locality(vector<sList *> min_way, int finder){
    for (sList *t : min_way)
        if (t->a == finder)
            return t->b;
    return -1;
}