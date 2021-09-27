//
// Created by zelez on 9/26/2021.
//

#include "main.h"

int main() {
    auto *my_table = new HashTable<Bank_account>(15);
    char c = 'a';
    for (int i = 0; i < 30; i++) {
        string s = "";
        s += c++;
        auto *chel = new Bank_account(i * 10 + i / 13 + i, s, s);
        my_table->insert(chel);
    }
    my_table->output();
    c = 'a';
    for (int i = 0; i < 30; i++) {
        string s = "";
        s += c++;
        auto *chel = new Bank_account( i * 10 + i / 13 + i, s, s);
        my_table->remove(chel);
    }
    my_table->output();
//    my_table->remove(my_table->find(133));

}