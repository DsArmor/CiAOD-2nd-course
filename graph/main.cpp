#include <iostream>
#include "map"

using namespace std;

/*
6 10
1 2 8
1 3 4
2 5 3
2 4 6
3 2 3
3 6 10
3 4 2
4 6 1
4 5 3
5 6 4
 */

int min_way;
int pattern;

struct Node {
    int value = 0;
    map<Node *, int> points;
    Node *parent = nullptr;
};

Node *best;

Node *create_node(int start, int **adj_matrix, int x, int end, Node *parent) {
    Node *in = new Node();
    in->value = start - 1;
    if (parent != nullptr && parent == in->parent)
        return in;
    in->parent = parent;
    if (in->value == end)
        return in;
    for (int i = 0; i < x; i++) {
        if (adj_matrix[start - 1][i] != 0) {
            in->points[create_node(i + 1, adj_matrix, x, end, in)] = adj_matrix[start - 1][i];
        }
    }
    return in;
}

void search_way(Node *node, int weight, int end, int sum) {
    sum += weight;
    if (end - 1 == node->value && sum < min_way){
        min_way = sum;
        best = node;
    }
    for (auto kv: node->points) {
        search_way(kv.first, kv.second, end, sum);
    }
}

void out_min_way(Node *temp){
    if (temp == nullptr)
        return;
    out_min_way(temp->parent);
    if (temp != best)
        cout << temp->value + 1 << "->";
    else
        cout << temp->value + 1;
}

void build_tree(int start, int end, int **adj_matrix, int x) {
    Node *root = create_node(start, adj_matrix, x, end, nullptr);
    search_way(root, 0, end, 0);
    if (min_way != pattern){
        cout << min_way << '\n';
        out_min_way(best);
    } else
        cout << "Пути не существует";
}

void initial_matrix(int **adj_matrix, int x) {
    for (int i = 0; i < x; i++)
        adj_matrix[i] = new int[x];
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            adj_matrix[i][j] = 0;
        }
    }
}

void fill_matrix(int **adj_matrix, int y) {
    for (int i = 0; i < y; i++) {
        int first, second, weight;
        cin >> first >> second >> weight;
        adj_matrix[first - 1][second - 1] = weight;
        min_way += weight;
    }
    min_way+=1;
    pattern = min_way;
}

void out_matrix(int **adj_matrix, int x) {
    cout << " |";
    for (int i = 1; i <= x; i++) {
        cout << i << " ";
    }
    cout << "\n¯ ";
    for (int i = 1; i <= x; i++) {
        cout << "¯ ";
    }
    cout << '\n';
    for (int i = 0; i < x; i++) {
        cout << i + 1 << "|";
        for (int j = 0; j < x; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int x, y;
    cin >> x >> y;
    int **adj_matrix = new int *[x];
    initial_matrix(adj_matrix, x);
    fill_matrix(adj_matrix, y);
    out_matrix(adj_matrix, x);

    int a, b;
    cin >> a >> b;
    build_tree(a, b, adj_matrix, x);
}
