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
    void resize(int k);
public:
    HashTable();
    explicit HashTable(int size);
    void insert(Data *data);
    void remove(Data *data);
    void output();
    Data *find(int key);
};

template<class Data>
HashTable<Data>::HashTable(int size) { // инициализация приватных полей
    this->size = size;
    this->full_size = 0;
    mas = new Data *[size];
    for (int i = 0; i < size; i++)
        // принудительное заполнение массива null pointers
        mas[i] = nullptr;
}

template<class Data>
void HashTable<Data>::insert(Data *data) {
    int position = hash(data->getKey());
    full_size++; // увеличить заполненность массива на 1
    if (full_size / (double) size > 0.75) { // сравнение с коэффициентом нагрузки
        resize(2); // пересоздание массива
    }
    int i = 1;
    while (mas[position] != 0) { // поиск свободного места для вставки в массив
        position += i * i;
        i++; //квадратичное пробирование
        position %= size;
    }
    mas[position] = data; // вставка
}

template<class Data>
void HashTable<Data>::remove(Data *data) {
    if (data == nullptr)
        return ;
    int position = hash(data->getKey()); // получить хэш от ключа
    int i = 1;
    if (mas[position] == nullptr)
        return ;
    while (mas[position]->getKey() != data->getKey()) //пока не найдем совпадение
    {
        position += i * i;
        i++; // квадратичное пробирование
        position %= size;
        if (mas[position] == nullptr)
            // значит то, что мы пытаемся удалить doesn't exist
            return ;
    }
    delete mas[position]; // удаление элементы
    mas[position] = nullptr;
    full_size--;
    resize(1); // пересоздать массив
    // это необходимо, чтобы коллизии данной ячейки перестроились
}

template<class Data>
void HashTable<Data>::output() {
    for (int i = 0; i < size; i++) {
        // вывод на экран всех элементов, ключи которых не nullptr
        cout << i << " ";
        if (mas[i] != nullptr) {
            cout << " bank_number " << mas[i]->getKey() << ", ";
            cout << "fio " << mas[i]->getFio() << ", ";
            cout << "address " << mas[i]->getAddress();
        }
        cout << "\n";
    }
}

template<class Data>
Data *HashTable<Data>::find(int key) { // поиск по ключу элемента в массиве
    int position = hash(key);
    int i = 1;
    if (mas[position] == nullptr)
        return nullptr;
    while (mas[position]->getKey() != key) {
        position += i * i;
        i++; // квадратичное пробирование
        position %= size;
        if (mas[position] == nullptr)
            // если мы попали в пустую ячейку, такого элемента не существует
            return nullptr;
    }
    return (mas[position]);
}


template<class Data>
void HashTable<Data>::resize(int k) { // пересоздание массива
    size *= k;
    Data **tmp_mas = mas; // копия массива
    this->mas = new Data *[size]; // пересоздание массива вдвое большей длины
    for (int i = 0; i < size; i++) // инициализация nullptr
        mas[i] = nullptr;
    int j = 1;
    for (int i = 0; i < size / k; i++) {
        // до предыдущей длины идти по копии массива
        if (tmp_mas[i] != nullptr) { // если в ячейке что-то есть рехэшировать
            int position = hash(tmp_mas[i]->getKey()); // получение нового хэша
            while (mas[position] != 0) {
                // поиск первой пустой ячейки, начиная с позиции хэша
                position += j * j;
                j++;
                position %= size;
            }
            mas[position] = tmp_mas[i]; // вставка
        }
    }
    delete [] tmp_mas;
//    cout << "rehash complete" << "\n";
//    output();
}

template<class Data>
int HashTable<Data>::hash(int key) {
    // функция хэштрования по остатку от деления счета в банке на размер массива
    return (key % this->size);
}

template<class Data>
HashTable<Data>::HashTable() { // default constructor (пусть будет)
    size = 0;
    full_size = 0;
    mas = nullptr;
}

#endif //HASH_TABLES_MAIN_H
