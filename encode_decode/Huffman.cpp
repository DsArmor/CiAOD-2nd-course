//
// Created by zelez on 11/19/2021.
//

#include "Huffman.h"

map<char, vector<bool>> encode_symbol_H;

_List_const_iterator<_List_val<_List_simple_types<hNode *>>>
ins_list(map<Node_H *, int> dict, const list<Node_H *> &list,
         _List_const_iterator<_List_val<_List_simple_types<hNode *>>> iter,
         Node_H *item) {
    for (Node_H *node: list) {
        if (dict[node] >= dict[item] || iter == list.cend())
            break;
        iter++;
    }
    return iter;
}



Node_H *str_to_tree(string str) {
    map<Node_H *, int> dict;
    list<Node_H *> list;
    for (int i = 0; i < str.length(); i++) {
        int count = 1;
        for (int j = i + 1; j < str.length(); j++) {
            if (str[i] == str[j]) {
                count++;
                str.erase(j, 1);
                j--;
            }
        }
        auto *node = new Node_H;
        node->value = str[i];
        dict[node] = count;
    }
    for (auto &item: dict) {
        auto iter = list.cbegin();
        iter = ins_list(dict, list, iter, item.first);
        list.insert(iter, item.first);
    }
    while (list.size() != 1) {
        Node_H *a = list.front();
        list.pop_front();
        Node_H *b = list.front();
        list.pop_front();
        auto *node = new Node_H;
        node->right = b;
        node->left = a;
        dict[node] = dict[a] + dict[b];
        auto iter = list.cbegin();
        iter = ins_list(dict, list, iter, node);
        list.insert(iter, node);
    }
    return list.front();
}

vector<bool> add_H(vector<bool> code, bool f) {
    code.push_back(f);
    return code;
}

void encode(Node_H *root, const vector<bool> &code) {
    if (root == nullptr)
        return;
    encode(root->left, add_H(code, 0));
    if (root->value != '\0')
        encode_symbol_H[root->value] = code;
    encode(root->right, add_H(code, 1));
}

char find(Node_H *root, vector<bool> *source) {
    while (root->value == '\0') {
        if ((*source).front())
            root = root->right;
        else
            root = root->left;
        (*source).erase((*source).cbegin());
    }
    return root->value;
}

void decode(Node_H *root) {
    string str;
    ifstream in(R"(D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\text_encode.txt)");
    if (in.is_open()) {
        while (getline(in, str));
    }
    in.close();
    vector<bool> source;
    for (char i: str) {
        for (int j = 0; j < 8; j++) {
            bool b = (bool((1 << j) & i));
            source.push_back(b);
        }
    }
    int f = 0;
    for (int i = 0; i < 8; i++) {
        if (source.back())
            f = i;
        source.pop_back();
    }
    for (int i = 0; i <= f; i++)
        source.pop_back();
    ofstream out(R"(D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\text_decode.txt)");
    while (!source.empty())
        out << find(root, &source);
    in.close();
    out.close();
}

void output(Node_H *root, string str) {
    if (root == nullptr)
        return;
    output(root->left, str+'\t');
    if (root->value != '\0')
        cout << root->value;
    output(root->right, str + '\t');
}

void Huffman() {
    string str;
    ifstream in(R"(D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\text.txt)");
    if (in.is_open()) {
        while (getline(in, str));
    }
    in.close();
    cout << str.length();
    cout << str << '\n';
    Node_H *root = str_to_tree(str);
    vector<bool> code;
    encode(root, code);
    output(root, "");
    string ans;
    ofstream out;
    out.open(R"(D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\text_encode.txt)");
    if (out.is_open()) {
        int size = 0;
        char t = '\0';
        vector<bool> entry;
        for (char h: str) {
            for (auto &&i: encode_symbol_H[h])
                entry.push_back(i);
            size += encode_symbol_H[h].size();
            if (size >= 8) {
                for (int i = 0; i < 8; i++) {
                    t |= (entry[0] << i);
                    entry.erase(entry.cbegin());
                }
                out << t;
                t = '\0';
                size -= 8;
            }
        }
        for (int i = 0; i < size; i++) {
            t |= (entry[0] << i);
            entry.erase(entry.cbegin());
        }
        out << t;
        t = '\0';
        t |= (1 << size);
        out << t;
    }
    out.close();
    decode(root);
}