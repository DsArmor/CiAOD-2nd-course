//
// Created by zelez on 9/26/2021.
//

#include "main.h"

int main() {
    auto *my_table = new HashTable<BankAccount>(5);
    char c = 'a';
    for (int i = 0; i < 10; i++) {
        string s = "";
        s += c++;
        auto *chel = new BankAccount(i * 10 + i / 13 + i, s + to_string(i), s);
        my_table->insert(chel);
    }
    my_table->output();
    c = 'a';
    for (int i = 0; i < 10; i++) {
        string s = "";
        s += c++;
        auto *chel = new BankAccount(i * 10 + i / 13 + i, s + to_string(i), s);
        my_table->remove(chel);
    }
    my_table->output();
    auto *chel = new BankAccount(13, "k", "f");
    my_table->remove(chel);

    my_table->remove(my_table->find(99));
    my_table->output();
}