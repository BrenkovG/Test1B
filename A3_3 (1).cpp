#include <iostream>
#include <math.h>

using namespace std;


//O(n^2)
void minor (int **with, int size, int n, int m, int **without)
{
    int adn = 0, adm = 0;

    for(int k = 0; k < size-1; k++)
    {
        if(k == n){adn = 1;};
        adm = 0;
        for(int i = 0; i < size-1; i++)
            {
                if(i == m) {adm = 1;};
                without[k][i] = with[k + adn][i + adm];
            }
    }
}


//O(n)
int determinant (int **A, int size)
{
    int det = 0, sign = 1;


    if(size == 1) {return A[0][0];}
    else if(size == 2) {return A[0][0]*A[1][1] - A[0][1]*A[1][0];}
    else
    {
        int **B = new int*[size-1];
        for(int i = 0; i < size-1; i++) {B[i] = new int[size-1];};
        for(int j = 0; j < size; j++)
        {
            minor (A, size, 0, j, B);
            det = det + (sign * A[0][j] * determinant (B, size-1));
            sign = -sign;
        };
        for(int i = 0; i < size-1; i++){delete [] B[i];};
        delete [] B;
    }

    return det;
}
//R(D=n) =n-1   Ц общее число вершин дерева рекурсии
//Rv(D=n)=n-2   Ц объем рекурсии без листьев (внутренние вершины)
//Rl(D=n)=1     Ц количество листьев дерева рекурсии
//Hr(D=n)=n-1   Ц глубина рекурсии


//O(n) + O(n^2) + O(n^2) + O(n) + O(n) = O(n^2)
int main ()
{
    int n;
    cin >> n;
    cout << endl;


    int** A = new int* [n];
    for (int count = 0; count < n; count++)
    {
        A[count] = new int[n];
    };


    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            A[k][i] = -100 + rand() % 201;
        }
    };


    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            cout << A[k][i] << '\t';
        }
        cout << endl;
    };

    cout << endl << determinant (A, n) << endl;

    for (int count = 0; count < n; count++)
    {
        delete[] A[count];
    };


    return 0;
}
