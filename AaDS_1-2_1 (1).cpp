#include <iostream>
#include <math.h>

using namespace std;

int main ()
{

    int m1, n1, m2, n2;


    //���� �������� ������

    cout << "enter values:\n" << endl;
    cout << "m1 = ";
    cin >> m1;
    cout << "n1 = ";
    cin >> n1;
    cout << endl;
    cout << "m2 = ";
    cin >> m2;
    cout << "n2 = ";
    cin >> n2;
    cout << endl;


    //�������� �������� ������

    if (n1 != m2)
    {
        cout << "error\n";
        return 0;
    };


    int A[m1][n1];
    int B[m2][n2];


    //���������� ������ A � B
    //��������� �������� O(n^2)

    for (int k = 0; k < m1; k++)
    {
        for (int i = 0; i < n1; i++)
        {
            A[k][i] = -100 + rand() % 201;
        };
    };

    //��������� �������� O(n^2)

    for (int k = 0; k < m2; k++)
    {
        for (int i = 0; i < n2; i++)
        {
            B[k][i] = -100 + rand() % 201;
        };
    };


    //����� ������ A � B

    cout << "A [" << m1 << "]" << "[" << n1 << "]:"<< endl;
    for (int k = 0; k < m1; k++)
        {
            for (int i = 0; i < n1; i++)
            {
                cout << A[k][i] << '\t';
            };
            cout << endl;
        };
    cout << endl;


    cout << "B [" << m2 << "]" << "[" << n2 << "]:"<< endl;
    for (int k = 0; k < m2; k++)
        {
            for (int i = 0; i < n2; i++)
            {
                cout << B[k][i] << '\t';
            };
            cout << endl;
        };
    cout << endl;


    int C[m1][n2];


    //���������� ������� C
    //��������� �������� O(n^3)

    for (int k = 0; k < m1; k++)
        {
            for (int i = 0; i < n2; i++)
            {
                C[k][i] = 0;
                for (int x = 0; x < n1; x++)
                {
                    C[k][i] = A[k][x]*B[x][i] + C[k][i];
                };
            };
        };

    //����� ������� C

    cout << "C [" << m1 << "]" << "[" << n2 << "]:"<< endl;
    for (int k = 0; k < m1; k++)
        {
            for (int i = 0; i < n2; i++)
            {
                cout << C[k][i] << '\t';
            };
        cout << endl;
        };


    return 0;
}

//��������� ��������� ��������� 2*O(n^2) + O(n^3) = O(n^3)
