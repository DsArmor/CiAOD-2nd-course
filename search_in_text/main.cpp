#include "main.h"

using namespace std;

int main() {
    string str;
    string substr;
    getline(cin, str);
    getline(cin, substr);
    search_boyer(substr, str);
//    find_pair(str);
    return 0;
}
