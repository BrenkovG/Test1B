#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;
ifstream inp("D:\\arr.txt");


int main () {
    int n, temp;
    cin >> n;
    cout << endl;
    int arr[n];


    //ввод массива из файла
    //сложность элемента O(n)
    for (int i = 0; i < n; i++) {inp >> arr[i];};
    inp.close();


    //вывод массива на экран
    //сложность элемента O(n)
    for (int i = 0; i < n; i++)
        {
            cout << arr[i] << '\t';
        };
    cout << endl << endl;


    //сортировка пузырьком
    //сложность элемента O(n^2)
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }


    //вывод массива на экран
    //сложность элемента O(n)
    for (int i = 0; i < n; i++)
        {
            cout << arr[i] << '\t';
        };

    cout << endl;


    return 0;
}

//суммарная сложность программы 3*O(n) + O(n^2) = O(n^2)
