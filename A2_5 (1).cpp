#include <iostream>
#include <math.h>

using namespace std;

//O(n)
int robot(int k, int co)
{
    int n = k, c = co + 1;
    if (n != 1)
        {
            if (n%2 == 0){n = n / 2; cout  << c << "." << '\t' << n << endl; robot (n, c);}
            else {n--; cout  << c << "." << '\t' << n << endl; robot (n, c);};
        };
    return 0;
}
//R(k, co) = 9   Ц общее число вершин дерева рекурсии
//Rv(k, co)= 8   Ц объем рекурсии без листьев (внутренние вершины)
//Rl(k, co)= 1   Ц количество листьев дерева рекурсии
//Hr(k, co)= 9   Ц глубина рекурсии


int main()
{
    int c = 1,  n = 100;
    cout  << c << "." << '\t' << n << endl;
    robot (n, c);
}
