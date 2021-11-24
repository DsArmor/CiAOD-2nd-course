//
// Created by zelez on 11/19/2021.
//

#ifndef ENCODE_DECODE_SHANNON_FANO_H
#define ENCODE_DECODE_SHANNON_FANO_H

#include <iostream>
#include "queue"
#include "list"
#include "map"
#include "sstream"
#include <windows.h>
#include "fstream"

using namespace std;

typedef struct sNode{
    char value = '\0';
    sNode *left = nullptr;
    sNode *right = nullptr;
} Node_S;

void Shannon_fano();

#endif //ENCODE_DECODE_SHANNON_FANO_H
