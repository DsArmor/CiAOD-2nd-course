#include "main.h" // MAIN_H

void menu_choose(int a, s_tree **root);

void rand_fill(s_tree **root){
    cout << "n = ";
    char a;
    int n;
    cin >> n;
    cout << "Tree: ";
    for (int i = 0; i < n; i++)
    {
        a = rand() % 90 + 38;
        cout << a << " ";
        tree_insert_data(root, a, cmp_char);
    }
    cout << "\n";
    menu_choose(2, root);
    menu_choose(3, root);
    menu_choose(4, root);
}

void menu(){
    cout << "\nMenu: \n";
    cout << "0 -> end\n";
    cout << "1 -> insert node\n";
    cout << "2 -> direct traverse\n";
    cout << "3 -> inorder traverse\n";
    cout << "4 -> my output tree\n";
    cout << "5 -> average\n";
    cout << "6 -> find deep\n";
    cout << "7 -> all func at random tree\n";
    cout << "Input number: ";
}

void menu_choose(int a, s_tree **root)
{
    int ave = 0;
    int count = 0;
    char c;

    switch (a) {
        case 1:
            cout << "Symbol: ";
            cin >> c;
            tree_insert_data(root, c, cmp_char);
            break;
        case 2:
            cout << "Direct: ";
            tree_direct_search(*root, output_symbol);
            cout << "\n";
            break;
        case 3:
            cout << "Inorder: ";
            tree_inorder_search(*root, output_symbol);
            cout << "\n";
            break;
        case 4:
            cout << "\n ----------------------------------------------- \n";
            tree_collab_inorder_search(*root, output_symbol, "");
            cout << "\n ----------------------------------------------- \n";
            break;
        case 5:
            cout << "ave = ";
            average(*root, &ave, &count);
            if (count)
                cout << ave / count << "\n";
            else
                cout << "Empty tree\n";
            break;
        case 6:
            cout << " Search item: ";
            char b;
            cin >> b;
            cout << "\ndeep = ";
            cout << find_deep(*root, b, cmp_char) << "\n";
            break;
        case 7:
            rand_fill(root);
        case 0:
            return ;
    }
}

int main()
{
    srand(time(nullptr));
    s_tree *root = NIL;
    int n;
    n = 1;
    while (n != 0)
    {
        menu();
        cin >> n;
        menu_choose(n, &root);
    }
}