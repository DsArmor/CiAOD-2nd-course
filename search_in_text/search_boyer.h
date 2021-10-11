//
// Created by zelez on 10/2/2021.
//

#ifndef SEARCH_IN_TEXT_SEARCH_BOYER_H
#define SEARCH_IN_TEXT_SEARCH_BOYER_H

# define SIZE 256
#include "string"
#include "iostream"
#include "list"

using namespace std;

//передается строка и массив таблицы суффиксов по указателю
//void, внутри происходит заполнение массива суффиксов
void fill_prefix_rev(string str, int *suffix_table);

//передается строка, длина подстроки, массив сдвигов по символу,
//переданный по указателю
//void, внутри происходит заполнение массива сдвигов
void fill_biases(string str, int size, int biases[]);

//передается подстрока, строка, массив плохих символов и хороших суффиксов
//производится поиск подстроки в строке с выводом на экран, поэтому void
void find_substr(string substr, string str, int biases[], int suffix_table[]);

//на вход поступает подстрока и строка
//реализация алгоритма Бойера-Мура с турбосдвигом
void search_boyer(string substr, string str);

#endif //SEARCH_IN_TEXT_SEARCH_BOYER_H
