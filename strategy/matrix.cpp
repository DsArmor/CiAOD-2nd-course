//
// Created by zelez on 12/7/2021.
//

#include "matrix.h"
#include "salesman.h"

int _min(int a, int b) {
    if (a > b)
        return b;
    return a;
}

bool check_square(int **matrix, int i, int j, int x, int y, int min_) {
    int i1, j1;
    i1 = i;
    j1 = j;
    if (matrix[i][j] == 0 && min_ == 1)
        return true;
    do {
        matrix[i][j1] = 1;
        i1++;
        j1++;
    } while (i1 < x - min_ && j1 < y - min_ && matrix[i1][j] == 0 && matrix[i][j1] == 0);
    i1--; j1--;
    if (i1 - i >= 1 || j1 - j >= 1) {
        if (check_square(matrix, i + 1, j + 1, x, y, _min(i1 - i, j1 - j)))
            return true;
    }
    j++;
    for (; i < x - 1; i++) {
        for (; j < y - 1; j++) {
            if (matrix[i][j] == 0)
                if (check_square(matrix, i, j, x, y, 0))
                    return true;
        }
        j = 0;
    }
    return false;
}


bool for_matrix() {
    int x, y, z;
    cin >> x >> y >> z;
    int **matrix = init_matrix(x, y);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < z; i++) {
        int first, second;
        cin >> first >> second;
        matrix[first - 1][second - 1] = 1;
    }
    out_matrix(matrix, x, y);
    for (int i = 0; i < x - 1; i++) {
        for (int j = 0; j < y - 1; j++) {
            if (matrix[i][j] == 0)
            {
                bool f = check_square(matrix, i, j, x, y, 0);
                out_matrix(matrix, x, y);
                return f;
            }
        }
    }
    return false;
}
