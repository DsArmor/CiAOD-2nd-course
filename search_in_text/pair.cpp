#include <iostream>
#include "vector"
#include "string"
using namespace std;

void fill_strs(vector<string> *strs, string str, int start, int end)
{
    string new_str;
    for (int i = start; i < end; i++)
        new_str += str[i];
    if (new_str[end - start - 1] == ',')
        new_str[end - start - 1] = '\0';
    strs->push_back(new_str);
}

vector<string> parse_to_vector(string str){
    vector<string> strs;
    int i = 0;
    int length = 0;
    int bias = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            fill_strs(&strs, str, bias, bias + length);
            bias = i + 1;
            length = 0;
        } else
            length++;
        if (str[i + 1] == '\0')
            fill_strs(&strs, str, bias, bias + length);
        i++;
    }
    return strs;
}

int pair_cmp(vector<string> strs, int i, int j)
{
    int k = 0;
    int diff = 0;
    while (strs[i][k] != '\0' && strs[j][k] != '\0')
    {
        if (strs[i][k] != strs[j][k])
            diff++;
        k++;
    }
    return diff;
}

void find_pair(string str) {
    vector<string> strs;
    int min_diff = str.size();
    vector<string> first;
    vector<string> second;

    strs = parse_to_vector(str);
    if (strs.empty() || strs.size() == 1)
    {
        cout << "Incorrect input";
        return ;
    }
    for (int i = 0; i < strs.size(); i++)
    {
        for (int j = i + 1; j < strs.size(); j++)
        {
            int diff = pair_cmp(strs, i, j);
            diff += abs(int(strs[i].size() - strs[j].size()));
            if (diff <= min_diff)
                min_diff = diff;
        }
    }
    for (int i = 0; i < strs.size(); i++)
    {
        for (int j = i + 1; j < strs.size(); j++)
        {
            int diff = pair_cmp(strs, i, j);
            diff += abs(int(strs[i].size() - strs[j].size()));
            if (diff == min_diff)
            {
                first.push_back(strs[i]);
                second.push_back(strs[j]);
            }
        }
    }
    cout << "Minimum distance: " << min_diff << "\n";
    for (int i = 0; i < first.size(); i++)
        cout << first[i] << " " << second[i] << '\n';
}

