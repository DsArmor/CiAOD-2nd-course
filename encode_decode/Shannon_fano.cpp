//
// Created by zelez on 11/19/2021.
//

#include "Shannon_fano.h"

map<char, vector<bool>> encode_symbol_S;

_List_const_iterator<_List_val<_List_simple_types<sNode *>>>
ins_list(map<Node_S *, int> dict, const list<Node_S *> &list,
         _List_const_iterator<_List_val<_List_simple_types<sNode *>>> iter,
         Node_S *item) {
    for (Node_S *node: list) {
        if (dict[node] >= dict[item] || iter == list.cend())
            break;
        iter++;
    }
    return iter;
}

int find_pos(vector<Node_S*> nodes, map<Node_S *, int> dict)
{
    int sum_begin = 0, sum_end = 0, end = 1;
    int i = 0;
    for (; i < nodes.size(); i++){
        sum_begin+=dict[nodes.at(i)];
        if (sum_begin > sum_end) {
            sum_end += dict[nodes.at(nodes.size() - end)];
            end++;
        }
        if (i >= nodes.size() - end)
            break;
    }
    return (i);
}

Node_S* build_tree(vector<Node_S*> nodes, const map<Node_S *, int>& dict){
    if (nodes.size() == 1)
        return nodes.back();
    int pos = find_pos(nodes, dict);
    vector<Node_S*> left(nodes.begin(), nodes.begin() + pos + 1);
    vector<Node_S*> right(nodes.begin() + pos + 1, nodes.end());
    auto *nodeS = new Node_S;
    nodeS->left = build_tree(left, dict);
    nodeS->right = build_tree(right, dict);
    return nodeS;
}

Node_S *str_to_tree(string str) {
    map<Node_S *, int> dict;
    list<Node_S *> list;
    for (int i = 0; i < str.length(); i++) {
        int count = 1;
        for (int j = i + 1; j < str.length(); j++) {
            if (str[i] == str[j]) {
                count++;
                str.erase(j, 1);
                j--;
            }
        }
        auto *node = new Node_S;
        node->value = str[i];
        dict[node] = count;
    }
    for (auto &item: dict) {
        auto iter = list.cbegin();
        iter = ins_list(dict, list, iter, item.first);
        list.insert(iter, item.first);
    }
    vector<Node_S*> nodes;
    for (Node_S * node : list)
        nodes.push_back(node);
    return build_tree(nodes, dict);
}

vector<bool> add_S(vector<bool> code, bool f){
    code.push_back(f);
    return code;
}

void encode(Node_S *root, const vector<bool>& code) {
    if (root == nullptr)
        return;
    encode(root->left, add_S(code, 0));
    if (root->value != '\0')
        encode_symbol_S[root->value] = code;
    encode(root->right, add_S(code, 1));
}

char find(Node_S *root, vector<bool> *source){
    while (root->value == '\0'){
        if ((*source).front())
            root = root->right;
        else
            root = root->left;
        (*source).erase((*source).cbegin());
    }
    return root->value;
}

void decode(Node_S *root){
    string str;
    ifstream in(R"(D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\text_encode.txt)");
    if (in.is_open()){
        while (getline(in, str));
    }
    in.close();
    vector<bool> source;
    for (char i : str){
        for (int j = 0; j < sizeof(char) * 8; j++){
            bool b = (bool((1 << j)  &  i));
            source.push_back(b);
        }
    }
    int f = 0;
    for (int i = 0; i < sizeof(str[0]) * 8; i++){
        if (source.back())
            f = i + 1;
        source.pop_back();
    }
    for (int i = 0; i < f; i++)
        source.pop_back();
    ofstream out(R"(D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\text_decode.txt)");
    while (!source.empty())
        out << find(root, &source);
    in.close();
    out.close();
}

void Shannon_fano() {
    string str, str1;
    ifstream in(R"(D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\text.txt)");
    if (in.is_open()) {
        while (getline(in, str1)){
            str +=str1;
            str += '\n';
        }
    }
    str.pop_back();
    in.close();
    Node_S *root = str_to_tree(str);
    vector<bool> code;
    encode(root, code);
    string ans;
    ofstream out;
    out.open(R"(D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\text_encode.txt)");
    if (out.is_open()){
        int size = 0;
        char t = '\0';
        vector<bool> entry;
        for (char h: str) {
            for (auto && i : encode_symbol_S[h])
                entry.push_back(i);
            size += encode_symbol_S[h].size();
            if (size >= sizeof(h) * 8){
                for (int i = 0; i < sizeof(h) * 8; i++){
                    t |= (entry[0] << i);
                    entry.erase(entry.cbegin());
                }
                out << t;
                t = '\0';
                size -= sizeof(h) * 8;
            }
        }
        t = '\0';
        for (int i = 0 ; i < size; i++){
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
