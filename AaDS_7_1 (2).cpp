#include <windows.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <ctime>


using namespace std;
ifstream inp("spisok1.txt");


int line_count ()
{
    int c = 0; string ln;
    while (!inp.eof()) {getline(inp, ln); c++;};
    inp.clear(); inp.seekg(0); return c;
}

struct student
{
    string group, surname, name, patron;
    float lb1, lb2, lb3, lb4, lb5, lb7, res;

    void rd () {inp >> group >> surname >> name >> patron >> lb1 >> lb2 >> lb3 >> lb4 >> lb5 >> lb7 >> res;};
    void wrt () {cout << group << ' ' << surname << ' ' << name << ' ' << patron << '\t'
    << '\t' << lb1 << '\t' << lb2 << '\t' << lb3 << '\t' << lb4 << '\t' << lb5 << '\t' << lb7 << '\t' << res;};
};



/*���������� ������� �������� ������
��������� ��������� O(n^2) (���� � ��������� ����)
����� ���������� ��� ���������� �� ������� -  0.108, �� ����� - 0.103*/
void SelectionSortRes (student* page, int n)
{
    student mn;
    for (int i = 0; i < n-1; i++)
    {
        mn.res = page [0].res;
        int place = 0;
        for (int j = 1; j < n - i; j++)
        {
                if (mn.res > page [j].res)
                {
                    mn.res = page [j].res;
                    place = j;
                }
        }
        swap(page [place], page [n-1 - i]);
    }
}

void SelectionSortSur (student* page, int n)
{
    student mn;
    for (int i = 0; i < n-1; i++)
    {
        mn.surname = page [0].surname;
        int place = 0;
        for (int j = 1; j < n - i; j++)
        {
                if (mn.surname < page [j].surname)
                {
                    mn.surname = page [j].surname;
                    place = j;
                }
        }
        swap(page [place], page [n-1 - i]);
    }
}



/*���������� ������� �������� ���������
��������� ��������� O(n^2) (���� � ��������� ����)
����� ���������� ��� ���������� �� ������� -  0.123, �� ����� - 0.123*/
void InsertionSortRes (student* page, int n)
{
    for (int i = 0; i < n; i++)
        {
            for (int j = i; (j > 0) && page[j-1].res < page[j].res; j--)
            {
                swap(page[j-1],page[j]);
            }
        }
}

void InsertionSortSur (student* page, int n)
{
    for (int i = 0; i < n; i++)
        {
            for (int j = i; (j > 0) && page[j-1].surname > page[j].surname; j--)
            {
                swap(page[j-1],page[j]);
            }
        }
}



/*���������� ������� �����
��������� ��������� O(log(n^2)) (3 �����, ��������� ���� � �����, ������ ������� � ����������� ���������)
����� ���������� ��� ���������� �� ������� - 0.102, �� ����� - 0.102*/
void ShellSortRes (student* page, int n)
{
    int step, i, j;
    student tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
            {
                tmp = page[i];
                for (j = i; j >= step; j -= step)
                {
                    if (tmp.res > page[j - step].res)
                        page[j] = page[j - step];
                    else
                    break;
                }
                page[j] = tmp;
            }
}

void ShellSortSur (student* page, int n)
{
    int step, i, j;
    student tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
            {
                tmp = page[i];
                for (j = i; j >= step; j -= step)
                {
                    if (tmp.surname < page[j - step].surname)
                        page[j] = page[j - step];
                    else
                    break;
                }
                page[j] = tmp;
            }
}



/*������ �������������, � ����� ������ �������, �������� ���������� ������� �����, ��������� ���� 3 �����
���������� ������� � ���������� ����� ���������� ��������� ���������
� ����� ������ ������� ����� ����������� � ����� ������� �������� ����� �����
���� ����� ����������� ��������� ���������� �������, � ���������� ���������� ���� ����� ���������

�����: ����� ����� �������� ����� �������, ��������� �� ��������� ������� ���������� � ����� ������� ���������,
�� ��� ����� ��� ��������� ������ ����, ��� ������ ��� ����� ����������� � ����� �������*/
int main ()
{

    setlocale(LC_ALL, "Russian");

    cout << "���������� ������� � �����: ";
    int n; string act; n = line_count(); cout << n << endl;


    student *page = new student [n];
    for (int i = 0; i < n; i++) page[i].rd();


    cout << endl << "=======================================" << endl ;
    cout << "�������� ��������:" << '\n' <<
    "show - ������� �� ����� �������� ������" << '\n' <<
    "name - ������������� �� �����" << '\n' <<
    "summ - ������������� �� ������" << '\n' <<
    "exit - ����� " << endl << endl;
    cin >> act;
    cout << "=======================================" << endl;


    if (act != "e" and act != "exit" and (act == "sh" or act == "show" or act == "s" or act == "summ" or act == "n" or act == "name"))
    {
        if(act == "sh" or act == "show");
        string s;
        if (act == "s" or act == "summ" or act == "n" or act == "name")
        {
            cout << endl << "=======================================" << endl ;
            cout << "�������� ������ ����������:" << '\n' <<
            "select - ����� �������� ������" << '\n' <<
            "insert - ����� �������� ���������" << '\n' <<
            "shell - ����� �����" << endl << endl;
            cin >> s;
            cout << "=======================================" << endl;
        }
        if ((act == "s" or act == "summ") and (s == "s" or s == "select" or s == "i" or s == "insert" or s == "sh" or s == "shell"))
        {
            srand(time(0));
            if(s == "s" or s == "select") SelectionSortRes (page, n);
            if(s == "i" or s == "insert") InsertionSortRes (page, n);
            if(s == "sh" or s == "shell") ShellSortRes (page, n);
            cout << "����� ������ ���������: " << clock() / 1000.0 << endl;
        }

        if ((act == "n" or act == "name") and (s == "s" or s == "select" or s == "i" or s == "insert" or s == "sh" or s == "shell"))
        {
            srand(time(0));
            if(s == "s" or s == "select") SelectionSortSur (page, n);
            if(s == "i" or s == "insert") InsertionSortSur (page, n);
            if(s == "sh" or s == "shell") ShellSortSur(page, n);
            cout << "����� ������ ���������: " << clock() / 1000.0 << endl;
        }

        if (act == "sh" or act == "show" or
        ((act == "s" or act == "summ") and (s == "s" or s == "select" or s == "i" or s == "insert" or s == "sh" or s == "shell")) or
        ((act == "n" or act == "name") and (s == "s" or s == "select" or s == "i" or s == "insert" or s == "sh" or s == "shell")) )
        {
            cout << endl << endl << "====================================================================================================================" << endl;
            for (int i = 0; i < n; i++) {page[i].wrt(); cout << endl;};
        }
    }


    delete [] page; inp.close(); return 0;
}
