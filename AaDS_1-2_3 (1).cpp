#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>
#include <ctime>


using namespace std;


ofstream outBS("D:\\Program Files\\CPP\\Bisection.txt");
ofstream outGS("D:\\Program Files\\CPP\\Golden-section.txt");
ofstream outFN("D:\\Program Files\\CPP\\Fibonacci.txt");


//вычисление значения функции
//сложность функции O(1)

double FuncComp(double x)
{
    double y = pow(x, 3) - x + exp(-x);
    return (y);
}


//метод «деления отрезка пополам»
//данная функция имеет сложность O(log n), поскольку содержит цикл, а все операторы внутри цикла имеют сложность O(1), и за пределами цикла аналогично

double Bisection(double a, double b, double h)
{
    srand(time(0));
    int c = 0;
    double a1 = a, b1 = b, a0, b0;
    double av, bv, sv, fa, fb;

    do
    {
        a0 = a1;
        b0 = b1;

        double pt = (b0 - a0) / 10;
        av = (a0 + b0) / 2 - pt;
        bv = 2 * pt + av;

        fa = FuncComp(av);
        fb = FuncComp(bv);

        if (fa <= fb)
        {
            sv = av;
            a1 = a0;
            b1 = bv;
        }
        else if (fa > fb)
        {
            a1 = av;
            sv = bv;
            b1 = b0;
        };
        c++;
        outBS << c << "." << '\t' << "x = " << (a1 + b1) / 2 << '\t' << " y = "<< FuncComp((a1 + b1) / 2) << endl;
        cout << c << "." << '\t' << "x = " << (a1 + b1) / 2 << '\t' << " y = "<< FuncComp((a1 + b1) / 2) << endl;
    }
    while (b1 - a1 > h);

    sv = (a1 + b1) / 2;
    outBS << endl << "Total execution time: " << clock()/1000.0 << endl << "Completed in " << c << " steps" << endl << endl;
    cout << endl << "Total execution time: " << clock()/1000.0 << endl << "Completed in " << c << " steps" << endl << endl;
    return (sv);
}


//метод «золотого сечения»
//данная функция имеет сложность O(log n), поскольку содержит цикл, а все операторы внутри цикла имеют сложность O(1), и за пределами цикла аналогично

double GoldenSection(double a, double b, double h)
{
    srand(time(0));
    int c = 0;
    double a1 = a, b1 = b, a0, b0;
    double av, bv, sv, fa, fb;

    do
    {
        a0 = a1;
        b0 = b1;

        double pt = (b0 - a0) * 2;
        av = (pt / (3 + pow(5, 0.5))) + a0;
        bv = (pt / (1 + pow(5, 0.5))) + a0;

        fa = FuncComp(av);
        fb = FuncComp(bv);

        if (fa <= fb)
        {
            sv = av;
            a1 = a0;
            b1 = bv;
        }
        else if (fa > fb)
        {
            a1 = av;
            sv = bv;
            b1 = b0;
        };
        c++;
        outGS << c << "." << '\t' << "x = " << (a1 + b1) / 2 << '\t' << " y = "<< FuncComp((a1 + b1) / 2) << endl;
        cout << c << "." << '\t' << "x = " << (a1 + b1) / 2 << '\t' << " y = "<< FuncComp((a1 + b1) / 2) << endl;

    }
    while (b1 - a1 > h);

    sv = (a1 + b1) / 2;
    outGS << endl << "Total execution time: " << clock()/1000.0 << endl << "Completed in " << c << " steps" << endl << endl;
    cout << endl << "Total execution time: " << clock()/1000.0 << endl << "Completed in " << c << " steps" << endl << endl;
    return (sv);
}


//метод Фибоначчи
//данная функция имеет сложность O(log n), поскольку содержит цикл, а все операторы внутри цикла имеют сложность O(1), и за пределами цикла аналогично

double Fibonacci(double a, double b, double h)
{
    srand(time(0));
    int Fpa = 1, Fpr = 1, Ffu = Fpr + Fpa, c = 0;
    double a1 = a, b1 = b, a0, b0;
    double av, bv, sv, fa, fb;

    do
    {
        a0 = a1;
        b0 = b1;

        double pt = (b0 - a0);
        av = (Fpa * pt) / Ffu + a0;
        bv = (Fpr * pt) / Ffu + a0;

        fa = FuncComp(av);
        fb = FuncComp(bv);

        if (fa <= fb)
        {
            sv = av;
            a1 = a0;
            b1 = bv;
        }
        else if (fa > fb)
        {
            a1 = av;
            sv = bv;
            b1 = b0;
        };
        Fpa = Fpr;
        Fpr = Ffu;
        Ffu = Fpr + Fpa;
        c++;
        outFN << c << "." << '\t' << "x = " << (a1 + b1) / 2 << '\t' << " y = "<< FuncComp((a1 + b1) / 2) << endl;
        cout << c << "." << '\t' << "x = " << (a1 + b1) / 2 << '\t' << " y = "<< FuncComp((a1 + b1) / 2) << endl;
    }
    while (b1 - a1 > h);

    sv = (a1 + b1) / 2;
    outFN << endl << "Total execution time: " << clock()/1000.0 << endl << "Completed in " << c << " steps" << endl << endl;
    cout << endl << "Total execution time: " << clock()/1000.0 << endl << "Completed in " << c << " steps" << endl << endl;
    return (sv);
}


int main()
{
    cout.setf(ios::fixed);
    outBS.setf(ios::fixed);
    outGS.setf(ios::fixed);
    outFN.setf(ios::fixed);
start:
    string ac;
    double a, b, h, C;


    //выбор действия

    cout << "1" << '\t' << "- Bisection search \n2" << '\t' << "- Golden-section search \n3" << '\t' << "- Fibonacci search \nall" << '\t' << "- Use all methods \nexit" << '\t' << "- Exit the program \n\n";
error:
    cin >>  ac;
    if (ac == "exit" or ac == "e"){outBS.close();outGS.close();outFN.close();return 0;};
    if (ac != "1" and ac != "2" and ac != "3" and ac != "all" and ac != "exit" and ac != "a" and ac != "e") {cout << "error [wrong command]\n"; goto error;};


    //ввод границ поиска и точности

    cout << endl << "a = ";
    cin >>  a;
    cout << "b = ";
    cin >>  b;
    if (a >= b) {cout << "error [wrong value A or B]\n"; goto error;};
    cout << "h = ";
    cin >>  h;
    cout << endl;


    //поиск значений

    if (ac == "1" or ac == "all" or ac == "a")
    {
        C = Bisection (a, b, h);
        outBS << "x = " << C << endl << "y = "<< FuncComp(C) << endl;
        cout << "x = " << C << endl << "y = "<< FuncComp(C) << endl << endl;
    };
    if (ac == "2" or ac == "all" or ac == "a")
    {
        C = GoldenSection (a, b, h);
        outGS << "x = " << C << endl << "y = "<< FuncComp(C) << endl;
        cout << "x = " << C << endl << "y = "<< FuncComp(C) << endl << endl;
    };
    if (ac == "3" or ac == "all" or ac == "a")
    {
        C = Fibonacci (a, b, h);
        outFN << "x = " << C << endl << "y = "<< FuncComp(C) << endl;
        cout << "x = " << C << endl << "y = "<< FuncComp(C) << endl << endl;
    };
    goto start;
}

//суммарная сложность программы O(log n) + O(log n) + O(log n) = O(log n)
