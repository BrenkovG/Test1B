#include <iostream>
#include <math.h>

using namespace std;

//O(n)
int NOD(int a, int b)
{
    while (a != 0 && b != 0)
        if (a > b) {a = a%b;} else {b = b%a;};
    return a+b;
}


int main ()
{
    int a, b;
    cin >> a;
    cin >> b;
    cout << NOD(a, b);
}
