#include <iostream>
#include <math.h>

using namespace std;

//O(2^n)
int calc(int n, int m)
{
    if (m == n || m == 0) {return 1;};
    if (m != 1) {return calc(n-1, m) + calc(n-1, m-1);}
    else {return n;};
}
//R(D(n, m)) =2*n+1 Ц общее число вершин дерева рекурсии
//Rv(D(n, m))=n     Ц объем рекурсии без листьев (внутренние вершины)
//Rl(D(n, m))=n+1   Ц количество листьев дерева рекурсии
//Hr(D(n, m))=n-1   Ц глубина рекурсии


int main()
{

    int n, m;

    cin >> n;
    cin >> m;

    if (m > n or m < 0)
    {
        cout << "error\n";
        return 0;
    };

    cout << calc (n, m);

    return 0;
}
