//
// Created by zelez on 9/27/2021.
//

#include "bank_account.h"

BankAccount::BankAccount(int bank_number, string fio, string address)
{
    this->bank_number = bank_number;
    this->fio = fio;
    this->address = address;
}

int BankAccount::getKey() {
    return (bank_number);
}

string BankAccount::getFio() {
    return fio;
}

string BankAccount::getAddress() {
    return address;
}
