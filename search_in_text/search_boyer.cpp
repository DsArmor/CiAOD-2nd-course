#include "search_boyer.h"

void fill_prefix_rev(string str, int *suffix_table) {
    reverse(str.begin(), str.end()); //перевернуть строку
    int *z = new int[str.length()];
    for (int i = 0; i < str.length(); i++) {
        suffix_table[i] = str.length();
        z[i] = 0;
    } // заполнили таблицу суффиксов длиной подстроки и массив z -> 0
    int left = 0, right = 0;
    for (int i = 1; i < str.length(); i++) { // реализация z-функции
        z[i] = max(0, min(z[i - left], right - i)); // сдвиг префикса
        while (i + z[i] < str.length() && str[z[i]] == str[i + z[i]])
            z[i] += 1; // увеличим сдвиг
        if (i + z[i] > right) {
            left = i; // сдвиг левой границы z-блока
            right = i + z[i]; // сдвиг правой границы z-блока
        }
    }
    for (int i = 0; i < str.length(); i++)
        cout << z[i] << " ";
    for (int i = 0; i < str.length(); i++) {
        // проверка на то, что мы это не изменяли ранее
        if (suffix_table[z[i]] == str.length())
            suffix_table[z[i]] = i; // заполнить сдвигом
        // проверка на то, что текущая длина префикса
        // + позиция совпадают с длиной строки
        if (z[i] + i == str.length()) {
            // в таком случае заполнить все до конца массива суффиксов
            // сдвигом на i позиций
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
    // заполнение плохими символами
    for (int i = 0; i + 1 < size; i++) {
        biases[(int) str[i]] = size - i - 1;
    }
}

void find_substr(string substr, string str, int biases[], int suffix_table[]) {
    int n = str.length();
    int m = substr.length();
    int i = m - 1;
    int k;
    int shift = 0;
    int turbo_shift = 0;
    int u = m;
    list<int> answer;

    while (i < n) {
        // пока меньше длины строки
        for (k = m - 1; k >= 0; k--) {
            // с конца подстроки
            if (str[i] != substr[k]) {
                // если не равны элементы
                if (suffix_table[m - k - 1] != substr.length())
                    // сдвиг сделать по таблице суффиксов
                    shift = m - k - 1 + max(turbo_shift, suffix_table[m - k - 1]);
                else
                    // сдвиг по таблице плохих символов
                    shift = m - k - 1 + max(turbo_shift, biases[(int) str[i]]);
                break;
            }
            // remove 2
            if (u != 0 and k == m - 1 - shift)
                k -= u; // если до этого мы уже такой суффикс сравнили
            i--;
        }
        // turbo_shift = 0;
        turbo_shift = u - m + 1 + k; // вычисление турбосдвига
        // проверка на то, что смщеение было по турбосдвигу
        if (shift == m - k - 1 + suffix_table[m - k - 1])
            u = min((m - shift), m - k - 1);
        else if (turbo_shift < biases[(int) str[i]])
            u = 0;
        // дошли до конца подстроки
        if (k == -1) {
            i += 1;
            answer.push_back(i);
            cout << "found " << i << " ";
            i += m;
        } else
            // добавим к i полученный сдвиг
            i += shift;
    }
}

void search_boyer(string substr, string str) {
    int biases[SIZE];
    int *suffix_table = new int[substr.length()];

    fill_prefix_rev(substr, suffix_table); // заполнить таблицу суффиксов
    fill_biases(substr, substr.length(), biases); // таблицу плохих символов
    find_substr(substr, str, biases, suffix_table); // сам алгоритм поиска
}
