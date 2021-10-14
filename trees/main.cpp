#include "main.h" // MAIN_H

int main()
{
    int n;
    cin >> n;
    s_tree *root = NIL;

    for (int i = 0; i < n; i++)
    {
        char a;
        cin >> a;
//        cout << (int)a << " ";
        tree_insert_data(&root, a, cmp_char);
        tree_inorder_search(root, output_symbol, "");
        cout << "\n\n\n";
    }
//    tree_direct_search(root, output_symbol);
//    tree_inorder_search(root, output_symbol, "");
//    int ave = 0;
//    average(root, &ave);
//    cout << ave / n;
    cout << find_deep(root, 'a', cmp_char);
}