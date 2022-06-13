#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;
ifstream inp("D:\\arr.txt");


int main () {
    int n, upper, lower, er = 0;
    cin >> n;
    cout << endl;
    if (n % 2 == 0){cout << "error" << endl; return 0;};
    int arr[n];


    //���� ������� �� �����
    //��������� �������� O(n)
    for (int i = 0; i < n; i++) {inp >> arr[i];};
    inp.close();


    //����� ������� �� �����
    //��������� �������� O(n)
    for (int i = 0; i < n; i++)
        {
            cout << arr[i] << '\t';
        };
    cout << endl << endl;


    //����� � ����� ������� �� �����
    //��������� �������� O(n^2)
    for (int i = 0; i < n; i++)
    {
        upper = 0; lower = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] < arr[j]){upper++;};
            if (arr[i] > arr[j]){lower++;};
        }
        if (upper == lower){cout << arr[i] << endl; return 0;}
    }

    cout << "error" << endl;
    return 0;
}

//��������� ��������� ��������� 2*O(n) + O(n^2) = O(n^2)
