#include <iostream>
#include <conio.h>
using namespace std;

int main() {
  float a,b,c;
  char o;
  cout << "Enter first number\n" ;
  cin >> a ;
  cout << "Enter operation" << '\n';
  cin >> o ;
  cout << "Enter second number" << '\n';
  cin >> b ;
  if (o=='+') {c=a+b;};
  if (o=='-') {c=a-b;};
  if (o=='*') {c=a*b;};
  if ((o=='/') && (b!=0)) {c=a/b;}
  cout << "Your result is " << c ;
  return 0;
}
