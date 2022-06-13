#include <iostream>
#include <math.h>

using namespace std;


//вычисление произведения от числа l до числа m
//сложность функции O(n)

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


    //ввод значений n и m

    cout << "enter values:\n";
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    cout << endl;


    //проверка введённых данных

    if (m > n or m <= 0 or n <= 0)
    {
        cout << "error\n";
        return 0;
    };


    //вычисление количества сочетаний
    //сложность элемента O(n)+ O(n)

    C = (calc(n-m+1, n))/(calc(1, m));
    cout << "C = " << C;
    cout << endl;


    return 0;
}

//суммарная сложность программы O(n) + O(n) = O(n)
