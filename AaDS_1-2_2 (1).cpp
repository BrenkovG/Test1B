#include <iostream>
#include <math.h>

using namespace std;


//���������� ������������ �� ����� l �� ����� m
//��������� ������� O(n)

int calc(int l, int u)
{
    int r = 1;
    for (; l <= u; l++)
    {
        r *= l;
    };
    return r;
}

int main()
{

    int n, m, C;


    //���� �������� n � m

    cout << "enter values:\n";
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    cout << endl;


    //�������� �������� ������

    if (m > n or m <= 0 or n <= 0)
    {
        cout << "error\n";
        return 0;
    };


    //���������� ���������� ���������
    //��������� �������� O(n)+ O(n)

    C = (calc(n-m+1, n))/(calc(1, m));
    cout << "C = " << C;
    cout << endl;


    return 0;
}

//��������� ��������� ��������� O(n) + O(n) = O(n)
