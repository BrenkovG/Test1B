#include <iostream>
#include <math.h>

using namespace std;

//O(n)
int num(int n)
{
    int a = 0, m = n;
    if (n != 153)
        {
            for (;m != 0;) {a = a + pow (m % 10, 3); m = m / 10;cout << " m " << m << " a " << a << endl;};
            cout << a << endl;
            num (a);
        };
    return 0;
}
//R(D=n) = n+1  � ����� ����� ������ ������ ��������
//Rv(D=n)= n    � ����� �������� ��� ������� (���������� �������)
//Rl(D=n)= 1    � ���������� ������� ������ ��������
//Hr(D=n)= n+1  � ������� ��������


int main()
{
    int n;
    cin >> n;
    num (n);
}
