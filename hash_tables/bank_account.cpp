//
// Created by zelez on 9/27/2021.
//

#include "bank_account.h"

Bank_account::Bank_account(int bank_number, string fio, string address)
{
    this->bank_number = bank_number;
    this->fio = fio;
    this->address = address;
}

int Bank_account::getKey() {
    return (bank_number);
}

string Bank_account::getFio() {
    return fio;
}

string Bank_account::getAddress() {
    return address;
}
