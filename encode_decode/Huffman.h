//
// Created by zelez on 11/19/2021.
//

#ifndef ENCODE_DECODE_HUFFMAN_H
#define ENCODE_DECODE_HUFFMAN_H

#include <iostream>
#include "queue"
#include "list"
#include "map"
#include "sstream"
#include "fstream"

using namespace std;

typedef struct hNode{
    char value = '\0';
    hNode *left = nullptr;
    hNode *right = nullptr;
} Node_H;

void Huffman();

#endif //ENCODE_DECODE_HUFFMAN_H
