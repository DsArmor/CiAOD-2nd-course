#include "search_boyer.h"

void fill_prefix_rev(string str, int *suffix_table) {
    reverse(str.begin(), str.end());
    int *z = new int[str.length()];
    for (int i = 0; i < str.length(); i++) {
        suffix_table[i] = str.length();
        z[i] = 0;
    }
    int left = 0, right = 0;
    for (int i = 1; i < str.length(); i++) {
        z[i] = max(0, min(z[i - left], right - i));
        while (i + z[i] < str.length() && str[z[i]] == str[i + z[i]])
            z[i] += 1;
        if (i + z[i] > right) {
            left = i;
            right = i + z[i];
        }
    }
    for (int i = 0; i < str.length(); i++) {
        if (suffix_table[z[i]] == str.length())
            suffix_table[z[i]] = i;
        if (z[i] + i == str.length()) {
            for (int j = z[i] + 1; j < str.length(); j++)
                suffix_table[j] = i;
            break;
        }
    }
    suffix_table[0] = str.length();
}

//void fill_suffix(string str, int *suffix_table) {
//    int length = str.length();
//    for (int i = 0; i < length - 1; i++) {
//        // заполнить всю таблицу максимальным сдвигом
//        suffix_table[i] = str.length();
//    }
//    suffix_table[0] = 0;
//    for (int i = length - 1, pos = length - 1; i >= 0; i--) {
//        // пройтись по всей длине строки с конца
//        // в pos ляжет последний символ
//        while (pos != 0) {
//            int size = length - i;
//            pos = find_symbol(str, pos - 1); // а тут в pos ляжет первое найденное повторение последнего символа
//            // строки, а при повторном заходе следующее вхождение начиная с pos - 1
//            int bias = length - pos - 1; // сдвиг до этой pos
//            int last = length - 1;
//            int dup_pos = pos; // продублировать
//            if (pos) {
//                for (; size > 0; size--, dup_pos--, last--) {
//                    // цикл до длины суффикса, пока все совпадает, итерироваться
//                    if (dup_pos < 0)
//                        break;
//                    if (str[last] != str[dup_pos])
//                        break;
//                }
//            }
//            if (!size || dup_pos < 0) {
//                // проверка на крайние случаи
//                if (last < 0 || dup_pos < 0 || (last >= 0 && dup_pos >= 0 && str[last] != str[dup_pos])) {
//                    // занести полученный сдвиг
//                    suffix_table[length - i] = bias;
//                    break;
//                }
//            }
//        }
//    }
//    cout << "suffixes:\n";
//    for (int i = 0; i < length; i++) {
//        cout << suffix_table[i] << ' ';
//    }
//    cout << "\n";
//}

void fill_biases(string str, int size, int biases[]) {
    for (int i = 0; i < SIZE; i++) {
        biases[i] = size;
    }
    for (int i = 0; i + 1 < size; i++) {
        biases[(int) str[i]] = size - i - 1;
    }
}

void find_substr(string substr, string str, int biases[], int suffix_table[]) {
    int n = str.length();
    int m = substr.length();
    int i = m - 1;
    int k;

    while (i < n) {
        for (k = m - 1; k >= 0; k--) {
            if (str[i] != substr[k]) {
                if (suffix_table[m - k - 1] != str.length())
                    i += m - k - 1 + suffix_table[m - k - 1];
                else
                    i += m - k - 1 + biases[(int) str[i]];
                break;
            }
            i--;
        }
        if (k == -1) {
            i += 1;
            cout << "found " << i << " ";
            i += m;
        }
    }
}

void search_boyer(string substr, string str) {
    int biases[SIZE];
    int *suffix_table = new int[substr.length()];

    fill_prefix_rev(substr, suffix_table);
//    fill_suffix(substr, suffix_table);
    fill_biases(substr, substr.length(), biases);
    find_substr(substr, str, biases, suffix_table);
}
