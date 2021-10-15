#include "main.h" // MAIN_H

int main()
{
    srand(time(nullptr));
    cout << " n = ";
    int n;
    cin >> n;
    s_tree *root = NIL;

    char a = 'A';
    cout << "Tree: ";
    for (int i = 0; i < n; i++)
    {
        a = rand() % 80 + 38;
        cout << a << " ";
//        cin >> a;
//        cout << (int)a << " ";
        tree_insert_data(&root, a, cmp_char);
    }
    cout << "\n ----------------------------------------------- \n";
    tree_collab_inorder_search(root, output_symbol, "");
    cout << "\n ----------------------------------------------- \n";
    cout << "\n Direct: ";
    tree_direct_search(root, output_symbol);
    cout << "\n Inorder: ";
    tree_inorder_search(root, output_symbol);
    cout << "\n ave = ";
    int ave = 0;
    average(root, &ave);
    cout << ave / n;
    cout << "\n deep = ";
    cout << find_deep(root, 'a', cmp_char);
}