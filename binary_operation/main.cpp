#include <iostream>
#include "bitset"
#include "fstream"
#include "vector"
#include "chrono"

using namespace std;

void ex11()
{
    unsigned char x = 121;
    cout << "before x -> " << (int)x;
    unsigned char maska = 1;
    // установка в 5 бит числа 0
    x = x & (~(maska << 4));
    cout << " after x -> " << (int)x;
}

void ex12()
{
    unsigned char x = 255;
    cout << "before x -> " << (int)x;
    unsigned char maska = 1;
    // установка в 7 бит числа 1
    x = x | (maska << 6);
    cout << " after x -> " << (int)x;
}

void code_listing()
{
    unsigned char x = 121;
    const int n = sizeof(int) * 8; //32
    unsigned maska = (1 << n - 1);
    cout << "Начальный вид маски: " << bitset<n> (maska) << endl;
    cout << "Результат ";
    for (int i = 1; i <= n; i++)
    {
        // итерируясь по битам данного числа
        // последовательно вывести их на экран
        cout << ((x & maska) >> (n - i));
        maska = maska >> 1;
    }
    cout << endl;
}

void sort_bit()
{
    int n;
    int x;
    cout << "Input numbers of array: ";
    cin >> n;
    unsigned maska = 1;
    unsigned char bit_mas = 0;
    for (int i = 0; i < n; i++){
        // считывание чисел и
        // занесение единичек на соответствующую позицию в массив
        cin >> x;
        bit_mas = bit_mas | (maska << x);
    }
    cout << "Our array: " << bitset<8> (bit_mas) << endl;
    cout << "Sorted array: ";
    for (int i = 0; i < 8; i++)
    {
        // проверка на то, что на текущей позиции стоит 1
        // вывод этого на экран
        if (bit_mas & (maska << i))
            cout << i << " ";
    }
}

void sort_bit_64()
{
    int n;
    int x;
    cout << "Input numbers of array: ";
    cin >> n;
    unsigned long long maska = 1;
    unsigned long long bit_mas = 0;
    for (int i = 0; i < n; i++){
        // считывание чисел и
        // занесение единичек на соответствующую позицию в массив
        cin >> x;
        bit_mas = bit_mas | (maska << x);
    }
    cout << "Our array: " << bitset<64> (bit_mas) << endl;
    cout << "Sorted array: ";
    for (int i = 0; i < 64; i++)
    {
        // проверка на то, что на текущей позиции стоит 1
        // вывод этого на экран
        if (bit_mas & (maska << i))
            cout << i << " ";
    }
}

void sort_bit_optimise()
{
    // оптимизированно под массив типа unsighed char[8]
    // таким образом мы можем работать с числами от 0 до < 64
    int n;
    int x;
    cout << "Input numbers of array: ";
    cin >> n;
    unsigned long long maska = 1;
    auto *bit_mas = new unsigned char[8];
    for (int i = 0; i < 8; i++)
        bit_mas[i] = 0;
    for (int i = 0; i < n; i++){
        // считывание чисел и
        // занесение единичек на соответствующую позицию в массив
        cin >> x;
        bit_mas[x/8] = bit_mas[x/8] | (maska << (x % 8));
    }
    cout << "Sorted array: ";
    for (int i = 0; i < 64; i++)
        // проверка на то, что на текущей позиции стоит 1
        // вывод этого на экран
        if (bit_mas[i / 8] & (maska << (i % 8)))
            cout << i << " ";
}

void fill_file()
{
    const int size = 100;
    srand(time(0));
    ofstream file;
    file.open("mas.txt");
    int x;
    for (int i = 0; i < size; i++){
        x = rand();
        file << x << " ";
    }
    file.close();
}

void file_sort()
{
    unsigned int maska = 1;
    ifstream file("mas.txt");
    auto begin = std::chrono::steady_clock::now();
    auto *data = new unsigned char [100000];
    int tmp;
    for (int i = 0; i < 100000; i++)
        data[i] = 0;

    while(file >> tmp)
    {
        data[tmp / 8] |= (maska << (tmp % 8));
        cout << tmp << " ";
    }
    file.close();
    ofstream sort_file("sortred.txt");
    for (int i = 0; i < 8 * 100000; i++)
    {
        if (data[i / 8] & (maska << (i % 8)))
            sort_file << i << " ";
    }
    sort_file.close();
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    cout << "\nThe time: " << elapsed_ms.count() << " ms\n";
    cout << "Used memory (bytes): " << sizeof(unsigned char) * 100000 + sizeof(unsigned int);
}

int main() {
    system("chcp 65001");
//    code_listing();
//    std::cout << "Hello, World!" << std::endl;
//    code_listing();
//    sort_bit_64();
//    sort_bit_optimise();
    fill_file();
    file_sort();
}
