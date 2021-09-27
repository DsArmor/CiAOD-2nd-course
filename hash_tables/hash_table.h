//
// Created by zelez on 9/26/2021.
//

#ifndef HASH_TABLES_MAIN_H
#define HASH_TABLES_MAIN_H

# include "iostream"
# include "bank_account.h"

template<class Data>
class HashTable {
private:
    int size;
    double full_size;
    Data **mas;

    int hash(int key);

    void resize();

public:
    HashTable();

    explicit HashTable(int size);

    void insert(Data *data);

    void remove(Data *data);

    void output();

    Data *find(int key);
};

template<class Data>
HashTable<Data>::HashTable(int size) {
    this->size = size;
    this->full_size = 0;
    mas = new Data *[size];
    for (int i = 0; i < size; i++)
        mas[i] = nullptr;
}

template<class Data>
void HashTable<Data>::insert(Data *data) {
    int position = hash(data->getKey());
    full_size++;
    if (full_size / (double) size > 0.75) {
        resize();
    }
    int i = 1;
    while (mas[position] != 0) {
        position += i;
        i += 2;
        position %= size;
    }
    mas[position] = data;
}


template<class Data>
void HashTable<Data>::remove(Data *data) {
    int position = hash(data->getKey());
    int temp = position;
    int i = 1;
    while (true) {
        if (mas[position] != nullptr)
            if (mas[position]->getKey() == data->getKey())
                break;
        position += i;
        i += 2;
        position %= size;
        if (temp == position) {
            cout << "Incorrect input\n";
            return;
        }
    }
    delete mas[position];
    mas[position] = nullptr;// вроде так
    // очистить ячейку массива не удаляя ее
}


template<class Data>
void HashTable<Data>::output() {
    for (int i = 0; i < size; i++) {
        cout << i << " ";
        if (mas[i] != nullptr) {
            cout << "bank_number " << mas[i]->getKey() << " ";
            cout << "fio " << mas[i]->getFio() << " ";
            cout << "address " << mas[i]->getAddress();
        }
        cout << "\n";
    }
}

template<class Data>
Data *HashTable<Data>::find(int key) {
    int position = hash(key);
    int i = 1;
    while (mas[position]->getKey() != key) {
        position += i;
        i += 2;
        position %= size;
        if (mas[position] == nullptr)
            return nullptr;
    }
    return (mas[position]);
}


template<class Data>
void HashTable<Data>::resize() {
    size *= 2;
    Data **tmp_mas = mas;
    this->mas = new Data *[size];
    for (int i = 0; i < size; i++)
        mas[i] = nullptr;
    int j = 1;
    for (int i = 0; i < size / 2; i++) {
        if (tmp_mas[i] != nullptr) {
            int position = hash(tmp_mas[i]->getKey());
            while (mas[position] != 0) {
                position += j;
                j += 2;
                position %= size;
            }
            mas[position] = tmp_mas[i];
        }
    }
//    cout << "test" << "\n";
//    output();
}

template<class Data>
int HashTable<Data>::hash(int key) {
    return (key % this->size);
}

template<class Data>
HashTable<Data>::HashTable() {
    size = 0;
    full_size = 0;
    mas = nullptr;
}

#endif //HASH_TABLES_MAIN_H
