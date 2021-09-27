//
// Created by zelez on 9/26/2021.
//

#ifndef HASH_TABLES_BANK_ACCOUNT_H
#define HASH_TABLES_BANK_ACCOUNT_H

# include <string>

using namespace std;

class Bank_account
{
private:
    int bank_number;
    string fio;
    string address;
public:
    Bank_account(int bank_number, string fio, string address);
    int getKey();
    string getFio();
    string getAddress();
};

#endif //HASH_TABLES_BANK_ACCOUNT_H
