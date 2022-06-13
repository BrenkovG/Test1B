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
//R(D=n) = n+1  Ц общее число вершин дерева рекурсии
//Rv(D=n)= n    Ц объем рекурсии без листьев (внутренние вершины)
//Rl(D=n)= 1    Ц количество листьев дерева рекурсии
//Hr(D=n)= n+1  Ц глубина рекурсии


int main()
{
    int n;
    cin >> n;
    num (n);
}
