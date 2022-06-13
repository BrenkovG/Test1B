#include <windows.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <ctime>

using namespace std;


//список
struct minibus
{
    //узел
    struct passenger
    {
        int num, stop_n;
        passenger* prev; passenger* next;

        //конструктор маршрутки
        passenger (int num, int stop_n, passenger *prev = NULL, passenger *next = NULL)
        {this->num = num; this->stop_n = stop_n;};

        //вывод узла на экран
        void wrt () {cout << num << ". " << stop_n;};

    };
    passenger* head; passenger* current;


    minibus();
    ~minibus ();


    void ShowLst();
    void AddNode (int num);
    void DelNode ();
};

//конструктор списка
minibus::minibus()
{
    //обнуление переменных
    this->current = NULL;

    //создание водителя
    this->head = new passenger (0, -1);
    this->head->prev = this->head->next = this->head;
}


//деструктор списка
minibus::~minibus()
{
    //обнуление переменных
    this->head = NULL;
    this->current = NULL;
}


//вывод списка на экран
void minibus::ShowLst()
{
    this->current = this->head;
    this->current = this->current->next;
    cout << "             ====" << endl << "      =======    =======   " << endl << "=====" << '\t' << '\t' << '\t' << "=====" << endl;
    while (this->current != head)
    {
        cout << "      "; (*this->current).wrt(); cout << '\t';

        this->current = this->current->next;

        if (this->current != head) {(*this->current).wrt(); this->current = this->current->next;} cout << endl;
    };
    cout << "=============================" << endl << endl;

    this->current = NULL;
}


//добавление узла
void minibus::AddNode (int num)
{
    passenger* temp = this->head->prev;
    this->head->prev = new passenger (num, (rand() % 10 + 1));
    temp->next = this->head->prev;
    this->head->prev->prev = temp;
    this->head->prev->next = head;
}


//удаление узла
void minibus::DelNode ()
{
    this->current->next->prev = this->current->prev;
    this->current->prev->next = this->current->next;
    passenger* temp = this->current;
    this->current = this->current->prev;
    delete temp;
}


int main ()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));


    minibus GAZelle; int num = 1;


    while (true)
    {

        for (int stop_n = 1; stop_n <= 10; stop_n++)
        {
            if (GAZelle.head->next == GAZelle.head) {cout << "маршрутка пуста" << endl << endl; system ("pause"); cout << endl << endl;}


            //пассажиры выходят

            GAZelle.current = GAZelle.head->next;

            while (GAZelle.current != GAZelle.head)
            {
                if (GAZelle.current->stop_n == stop_n)
                {
                    GAZelle.DelNode ();
                }
                GAZelle.current = GAZelle.current -> next;
            }

            //пассажиры входят
            for (int i = 0; i < rand () % 6; i++)
            {
                GAZelle.AddNode (num);
                num++;
            }


            cout << "остановка номер " << stop_n << ":" << endl << endl; GAZelle.ShowLst();

            string act;
            cout << endl << "поедем дальше, командир? - Y/N          ";
            cin >> act;
            cout << endl << endl;
            if (act == "N" || act == "n") {return 0;}

        }
    }
}
