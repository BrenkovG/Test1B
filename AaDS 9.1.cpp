#include <windows.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;
ifstream inp("spisok2.txt");

//список
struct list
{
    //узел
    struct student
    {
        int num;
        string group, surname, name, patron, mark; student* prev; student* next;

        //конструктор для ввода из файла
        student (student *prev = nullptr, student *next = nullptr)
        {inp >> this->group >> this->surname >> this->name >> this->patron >> this->mark;};

        //вывод узла на экран
        void wrt () {cout << num << "." << '\t' << group << ' ' << surname << ' ' << name << ' ' << patron << '\t' << mark << endl;};

    };
    student* head; student* curprev; student* current; student* tail;


    list();
    ~list ();


    void ShowLst();
    void ShowLstRev ();
    void DelNode ();
};



//конструктор списка
list::list()
{
    //обнуление переменных
    this->head = nullptr;
    this->curprev = nullptr;
    this->current = nullptr;
    this->tail = nullptr;

    //счётчик строк
    int lineC = 0;
    for (string ln;!inp.eof(); lineC++) getline(inp, ln);
    inp.clear(); inp.seekg(0);

    cout << "количество записей в файле: " << lineC << endl << endl;

    //считывание данных из файла
    if (this->head == nullptr) {this->head = new student (); this->head->num = 1; this->curprev = this->head;}

    for (int i = 2; i <= lineC ;i++)
    {this->current = new student; this->current->num = i; this->curprev->next = this->current; this->current->prev = this->curprev; this->curprev = this->current;};


    //создание "хвоста" и обнуление переменных
    this->tail = this->current;
    this->curprev = nullptr;
    this->current = nullptr;

}


//деструктор списка
list::~list()
{
    //обнуление переменных
    this->head = nullptr;
    this->curprev = nullptr;
    this->current = nullptr;
}


//вывод списка на экран (прямой порядок)
void list::ShowLst()
{
    this->current = this->head;
    cout << "======================================================" << endl;
    while (this->current != nullptr)
    {
        (*this->current).wrt();
        this->current = this->current->next;
    };
    cout << "======================================================" << endl << endl;

    this->current = nullptr;
}

//вывод списка на экран (обратный порядок)
void list::ShowLstRev()
{
    this->current = this->tail;
    cout << "======================================================" << endl;
    while (this->current != nullptr)
    {
        (*this->current).wrt();
        this->current = this->current->prev;
    };
    cout << "======================================================" << endl << endl;

    this->current = nullptr;
}


//удаление узла
void list::DelNode ()
{
    //для списка из одного элемента
    if (this->current->next == nullptr && this->current->prev == nullptr)
    {
        this->head = nullptr;
        this->tail = nullptr;
        delete this->current;
        this->current = nullptr;
    }
    //для последнего элемента
    else if (this->current->next == nullptr && this->current->prev != nullptr)
    {
        this->tail = this->tail->prev;
        this->tail->next = nullptr;
        student* temp = this->current;
        this->current = this->current->prev;
        delete temp;
    }
    //для первого элемента
    else if (this->current->prev == nullptr && this->current->next != nullptr)
    {
        this->head = this->head->next;
        this->head->prev = nullptr;
        student* temp = this->current;
        this->current = this->current->next;
        delete temp;
    }
    //для всех остальных случаев
    else
    {
        this->current->next->prev = this->current->prev;
        this->current->prev->next = this->current->next;
        student* temp = this->current;
        this->current = this->current->next;
        delete temp;

    }
}

//стек
struct stack
{
    //узел
    struct student
    {
        int num;
        string group, surname, name, patron, mark; student* next;

        //конструктор узла
        student (int num, string group, string surname, string name, string patron, string mark, student *next = nullptr)
        {this->num = num; this->group = group; this->surname = surname; this->name = name; this->patron = patron; this->mark = mark;};

        //вывод узла на экран
        void wrt () {cout << num << "." << '\t' << group << ' ' << surname << ' ' << name << ' ' << patron << '\t' << mark << endl;};

    };
    student* head; student* current;


    //конструктор стека
    stack ()
    {
        //обнуление переменных
        this->head = nullptr;
        this->current = nullptr;
    };

    //добавление нового узла
    void add (int num, string group, string surname, string name, string patron, string mark)
    {
        if (this->head == nullptr) {this->head = new student (num, group, surname, name, patron, mark); this->current = this->head;}
        else {this->current = new student (num, group, surname, name, patron, mark); this->current->next = this->head; this->head = this->current;}
    }
};




//очередь
struct queue
{
    //узел
    struct student
    {
        int num;
        string group, surname, name, patron, mark; student* next;

        //конструктор узла
        student (int num, string group, string surname, string name, string patron, string mark, student *next = nullptr)
        {this->num = num; this->group = group; this->surname = surname; this->name = name; this->patron = patron; this->mark = mark;};

        //вывод узла на экран
        void wrt () {cout << num << "." << '\t' << group << ' ' << surname << ' ' << name << ' ' << patron << '\t' << mark << endl;};

    };
    student* head; student* current;


    //конструктор очереди
    queue ()
    {
        //обнуление переменных
        this->head = nullptr;
        this->current = nullptr;
    };

    //добавление нового узла
    void add (int num, string group, string surname, string name, string patron, string mark)
    {
        if (this->head == nullptr) {this->head = new student (num, group, surname, name, patron, mark); this->current = this->head;}
        else {this->current->next = new student (num, group, surname, name, patron, mark); this->current = this->current->next;}
    }
};




int main ()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    list page; stack stk; queue que;


    //задание 3: удаление и добавление в стек каждого 10-го узла с начала списка
    page.current = page.head;
    for (int i = 1; page.current != nullptr; i++)
    {
        if (i % 10 == 0) {stk.add (page.current->num, page.current->group, page.current->surname, page.current->name, page.current->patron, page.current->mark); page.DelNode(); page.current = page.current->prev;}
        page.current = page.current->next;
    }


    //задание 5 часть 1: удаление и добавление в стек первого узла списка
    page.current = page.head; stk.add (page.current->num, page.current->group, page.current->surname, page.current->name, page.current->patron, page.current->mark); page.DelNode();


    //вывод стека на экран
    cout << endl << endl << "|stack|" << endl << "======================================================" << endl;
    stk.current = stk.head;
    while (stk.current != nullptr){stk.current->wrt(); stk.current = stk.current->next;};
    cout << "======================================================" << endl << endl << endl;


    //задание 5 часть 2: удаление и добавление в очередь последнего узла списка
    page.current = page.tail; que.add (page.current->num, page.current->group, page.current->surname, page.current->name, page.current->patron, page.current->mark); page.DelNode();


    //задание 4: удаление и добавление в очередь каждого 10-го узла с конца списка
    page.current = page.tail;
    for (int i = 0; page.current != nullptr; i++)
    {
        if (i % 10 == 0 && i != 0) {que.add (page.current->num, page.current->group, page.current->surname, page.current->name, page.current->patron, page.current->mark); page.DelNode();}
        page.current = page.current->prev;
    }


    //вывод очереди на экран
    cout << endl << "|queue|" << endl << "======================================================" << endl;
    que.current = que.head;
    while (que.current != nullptr){que.current->wrt(); que.current = que.current->next;};
    cout << "======================================================" << endl << endl << endl;


    //вывод списка на экран
    while (true)
        {
            string act;
            cout << "=======================================" << endl;
            cout << "1. show - вывод списка" << '\n' <<
            "2. show_rev - вывод списка в обратном порядке" << '\n' <<
            "3. exit - выход" << endl << endl;
            cin >> act;
            cout << "=======================================" << endl << endl;

            //задание 1: вывод списка на экран в прямом порядке
            if (act == "show" || act == "s" || act == "1") {page.ShowLst();}
            //задание 2: вывод списка на экран в обратном порядке
            else if (act == "show_rev" || act == "sr" || act == "2") {page.ShowLstRev();}
            //выход
            else if (act == "exit" || act == "e" || act == "3") {inp.close(); return 0;}
        }
}
