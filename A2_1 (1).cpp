#include <iostream>
#include <math.h>

using namespace std;

//O(2^n)
int Fiba(int n)
{
    if (n<3) {return 1;};
    return Fiba(n-1)+Fiba(n-2);
}
//R(D=n) =(n-3)^2 + n   Ц общее число вершин дерева рекурсии
//Rv(D=n)=n+1           Ц объем рекурсии без листьев (внутренние вершины)
//Rl(D=n)=(n-3)^2 - 1   Ц количество листьев дерева рекурсии
//Hr(D=n)=n-1           Ц глубина рекурсии


int main()
{
    int n;
    cin >> n;
    cout << Fiba (n);

    return 0;
}
