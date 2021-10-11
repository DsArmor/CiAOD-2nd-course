//
// Created by zelez on 10/11/2021.
//

#ifndef SEARCH_IN_TEXT_PAIR_H
#define SEARCH_IN_TEXT_PAIR_H

#include <iostream>
#include "vector"
#include "string"

using namespace std;

//принимает на вход массив строк для добавления нового элемента
//и изначальную строку
//индекс начала записи из строки str и индекс конца записи
//ничего не возвращает, однако массив строк передается по указателю,
//к нему добавляется новый элемент
//это изменение отражается и в массиве строк функции, вызвавшей эту функцию
void fill_strs(vector<string> *strs, string str, int start, int end);

//принимает на вход строку строку
//возвращает массив строк, разделителем для которых полсужили ',' и ' '
vector<string> parse_to_vector(string str);

//сравннивает i-ый элемент с j-ым в массиве строк
//возвращает расстояние между элементами
int pair_cmp(vector<string> strs, int i, int j);

//принимает строку
//находит пары, выводит пары на экран и ничего не возвращает
void find_pair(string str);


#endif //SEARCH_IN_TEXT_PAIR_H
