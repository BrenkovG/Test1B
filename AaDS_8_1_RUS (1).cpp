#include <windows.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;
ifstream inp("spisok2.txt");
ofstream out("spisok_new.txt");
string  RUS(const string&  DOS_string);

//������
struct list
{
    //����
    struct student
    {
        string group, surname, name, patron, mark; student* next;

        //����������� ��� ����� �� �����
        student (student *next = nullptr)
        {inp >> this->group >> this->surname >> this->name >> this->patron >> this->mark;};

        //����������� ��� ����� � ����������
        student (string group, string surname, string name, string patron, string mark, student *next = nullptr)
        {this->group = group; this->surname = surname; this->name = name; this->patron = patron; this->mark = mark;};


        //����� ���� �� �����
        void wrt () {cout << group << ' ' << surname << ' ' << name << ' ' << patron << '\t' << mark << endl;};

        //����� ���� � ����
        void wrfl () {out << group << ' ' << surname << ' ' << name << ' ' << patron << '\t' << mark << endl;};
    };
    student* head; student* curprev; student* current; student* curnext;


    list();
    ~list ();


    void ShowLst();
    void SaveLst();
    void AddNode ();
    void EdtNode ();
    void DelNode ();
    void SortGrp ();
    void SortSur ();
    void SortMrk ();
    void SearchGrp ();
    void SearchSur ();
};

//����������� ������
list::list()
{
    //��������� ����������
    this->head = nullptr;
    this->curprev = nullptr;
    this->current = nullptr;
    this->curnext = nullptr;

    //������� �����
    int lineC = 0;
    for (string ln;!inp.eof(); lineC++) getline(inp, ln);
    inp.clear(); inp.seekg(0);

    cout << "���������� ������� � �����: " << lineC << endl << endl;

    //���������� ������ �� �����
    if (head == nullptr) {this->head = new student (); this->curprev = this->head;}
    this->current = nullptr;
    for (int i = 1; i < lineC ;i++)
        {this->current = new student; this->curprev->next = this->current; this->curprev = this->current;};


    this->curprev = nullptr;
    this->current = nullptr;

}


//���������� ������
list::~list()
{
    //�������� �����
    /*while (head != NULL)
    {
        this->current = this->head->next;
        delete this->current;
        this->current = this->head;
    }*/

    //��������� ����������
    this->head = nullptr;
    this->curprev = nullptr;
    this->current = nullptr;
    this->curnext = nullptr;
}


//����� ������ �� �����
//��������� �������� O(n)
void list::ShowLst()
{
    this->current = this->head;
    cout << "======================================================" << endl;
    int i = 1;
    while (this->current != nullptr)
    {
        cout << i << "." << '\t';
        (*this->current).wrt();
        this->current = this->current->next;
        i++;
    };
    cout << "======================================================" << endl << endl;

    this->current = nullptr;
}


//���������� ������ � ����
//��������� �������� O(n)
void list::SaveLst()
{
    this->current = this->head;
    int i = 1;
    while (this->current != nullptr)
    {
        out << i << "." << '\t';
        (*this->current).wrfl();
        this->current = this->current->next;
        i++;
    };

    this->current = nullptr;
}



//���������� ����
//��������� �������� O(1)
void list::AddNode ()
{
    string group, surname, name, patron, mark;
    cout << "������� ������ ����� ������:" << '\n' <<
    "������ ������� ��� �������� ������" << endl << endl;
    cin >> group >> surname >> name >> patron >> mark;
    cout << endl;
    group = RUS(group); surname = RUS(surname); name = RUS(name); patron = RUS(patron); mark = RUS(mark);
    this->current = new student(group, surname, name, patron, mark);
    this->current->next = this->head; this->head = this->current;
}


//�������������� ����
//��������� �������� O(n)
void list::EdtNode()
{
    int NtEdt;
    string surname;
    this->current = this->head;
    cout << "�������� ������ ��� ��������������:" << '\n' <<
    "����� �������" << endl << endl;
    cin >> NtEdt >> surname; surname = RUS(surname);
    cout << endl;
    int i = 1;
        while (this->current != nullptr)
        {
                if (NtEdt == i && this->current->surname == surname)
                {
                    this->current->wrt();
                    while (true)
                    {
                            string fld;
                            cout << "=======================================" << endl ;
                            cout << "�������� ���� ��� ��������������:" << '\n' <<
                            "1. group - ������" << '\n' <<
                            "2. surname - �������" << '\n' <<
                            "3. name - ���" << '\n' <<
                            "4. patron - ��������" << '\n' <<
                            "5. mark - ������" << '\n' <<
                            "6. exit - �����" << endl << endl;
                            cin >> fld;
                            cout << "=======================================" << endl << endl;


                            if (fld == "group" || fld == "g" || fld == "1") {string NewData; cin >> NewData; NewData = RUS(NewData); this->current->group = NewData; break;}
                            else if (fld == "surname" || fld == "s" || fld == "2") {string NewData; cin >> NewData; NewData = RUS(NewData); this->current->surname = NewData; break;}
                            else if (fld == "name" || fld == "n" || fld == "3") {string NewData; cin >> NewData; NewData = RUS(NewData); this->current->name = NewData; break;}
                            else if (fld == "patron" || fld == "p" || fld == "4") {string NewData; cin >> NewData; NewData = RUS(NewData); this->current->patron = NewData; break;}
                            else if (fld == "mark" || fld == "m" || fld == "5") {string NewData; cin >> NewData; NewData = RUS(NewData); this->current->mark = NewData; break;}
                            else if (fld == "exit" || fld == "e" || fld == "6") {break;}
                            else {cout << "error: wrong command" << endl << endl;}
                    }
                    break;
                }
                i++;
                this->current = this->current->next;
        }
}


//�������� ����
//��������� �������� O(n)
void list::DelNode ()
{
    int NtDel;
    string surname;
    this->curprev = this->head;
    cout << "�������� ������ ��� ��������:" << '\n' <<
    "����� �������" << endl << endl;
    cin >> NtDel >> surname; surname = RUS(surname);
    cout << endl;
    if (NtDel == 1)
    {
        if (this->head->surname == surname)
        {
            this->head = this->head->next;
            delete this->curprev;
        }
    }
    else
    {
        int i = 2;
        while (this->curprev->next != nullptr)
        {
                if (NtDel == i && this->curprev->next->surname == surname)
                {
                    this->current = this->curprev->next;
                    this->curprev->next = this->current->next;
                    delete this->current;
                    break;
                }
        i++;
        this->curprev = this->curprev->next;
        }
    }
}


//���������� �� ������
//��������� �������� O(n^2)
void list::SortGrp ()
{
    this->current = this->head; this->curnext = this->head;

    //���������� ����� "������"
    while (this->curnext->next != nullptr)
    {
        if (this->current == this->head && this->curnext->next->group < this->current->group) {this->current = this->curnext;}
        else if (this->curnext->next->group < this->current->next->group) {this->current = this->curnext;}
        this->curnext = this->curnext->next;
    }
    if (this->current != this->head)
    {
        swap(this->head->next, this->current->next->next);
        swap(this->head, this->current->next);
    }


    this->curprev = this->head; this->current = this->head; this->curnext = this->head;


    //���������� ���������� �����
    while (this->curprev->next != nullptr)
    {
        while (this->curnext->next != nullptr)
        {
            if (this->curnext->next->group < this->current->next->group)
            {
                this->current = this->curnext;
            };
            this->curnext = this->curnext->next;
        }
        if (this->curprev != this->current)
        {
            swap(this->curprev->next->next, this->current->next->next);
            swap(this->curprev->next, this->current->next);
        }
        this->curprev = this->curprev->next; this->current = this->curprev; this->curnext = this->curprev;
    }

    this->curprev = nullptr; this->current = nullptr; this->curnext = nullptr;
}

//���������� �� ��������
//��������� �������� O(n^2)
void list::SortSur ()
{
    this->current = this->head; this->curnext = this->head;

    //���������� ����� "������"
    while (this->curnext->next != nullptr)
    {
        if (this->current == this->head && this->curnext->next->surname < this->current->surname) {this->current = this->curnext;}
        else if (this->curnext->next->surname < this->current->next->surname) {this->current = this->curnext;}
        this->curnext = this->curnext->next;
    }
    if (this->current != this->head)
    {
        swap(this->head->next, this->current->next->next);
        swap(this->head, this->current->next);
    }


    this->curprev = this->head; this->current = this->head; this->curnext = this->head;


    //���������� ���������� �����
    while (this->curprev->next != nullptr)
    {
        while (this->curnext->next != nullptr)
        {
            if (this->curnext->next->surname < this->current->next->surname)
            {
                this->current = this->curnext;
            };
            this->curnext = this->curnext->next;
        }
        if (this->curprev != this->current)
        {
            swap(this->curprev->next->next, this->current->next->next);
            swap(this->curprev->next, this->current->next);
        }
        this->curprev = this->curprev->next; this->current = this->curprev; this->curnext = this->curprev;
    }

    this->curprev = nullptr; this->current = nullptr; this->curnext = nullptr;
}



//���������� �� �������
//��������� �������� O(n^2)
void list::SortMrk ()
{
    this->current = this->head; this->curnext = this->head;

    //���������� ����� "������"
    while (this->curnext->next != nullptr)
    {
        if (this->current == this->head && this->curnext->next->mark < this->current->mark) {this->current = this->curnext;}
        else if (this->curnext->next->mark < this->current->next->mark) {this->current = this->curnext;}
        this->curnext = this->curnext->next;
    }
    if (this->current != this->head)
    {
        swap(this->head->next, this->current->next->next);
        swap(this->head, this->current->next);
    }


    this->curprev = this->head; this->current = this->head; this->curnext = this->head;


    //���������� ���������� �����
    while (this->curprev->next != nullptr)
    {
        while (this->curnext->next != nullptr)
        {
            if (this->curnext->next->mark < this->current->next->mark)
            {
                this->current = this->curnext;
            };
            this->curnext = this->curnext->next;
        }
        if (this->curprev != this->current)
        {
            swap(this->curprev->next->next, this->current->next->next);
            swap(this->curprev->next, this->current->next);
        }
        this->curprev = this->curprev->next; this->current = this->curprev; this->curnext = this->curprev;
    }

    this->curprev = nullptr; this->current = nullptr; this->curnext = nullptr;
}

//����� �� ������
//��������� �������� O(n)
void list::SearchGrp ()
{
    string group;
    this->current = this->head;
    cout << "������� ������" << endl << endl;
    cin >> group; group = RUS(group);
    cout << endl;
    int i = 1;
    while (this->current != nullptr)
    {
        if(this->current->group == group) {cout << i << "." << '\t'; this->current->wrt();};
        this->current = this->current->next;
        i++;
    }
}


//����� �� �������
//��������� �������� O(n)
void list::SearchSur ()
{
    string surname;
    this->current = this->head;
    cout << "������� �������" << endl << endl;
    cin >> surname; surname = RUS(surname);
    cout << endl;
    int i = 1;
    while (this->current != nullptr)
    {
        if(this->current->surname == surname) {cout << i << "." << '\t'; this->current->wrt();};
        this->current = this->current->next;
        i++;
    }
}





//�������� ��������� O(n^2)
int main ()
{
    setlocale(LC_ALL, "Russian");

    list page;


    while (true)
    {
        string act, type;
        cout << "=======================================" << endl ;
        cout << "�������� ��������:" << '\n' <<
        "1. show - ������� �� ����� ������" << '\n' <<
        "2. sort - �������������" << '\n' <<
        "3. find - ����� �������" << '\n' <<
        "4. add - �������� �������" << '\n' <<
        "5. edit - �������� �������" << '\n' <<
        "6. delete - ������� �������" << '\n' <<
        "7. save - ������� ������ � ����" << '\n' <<
        "8. exit - �����" << endl << endl;
        cin >> act;
        cout << "=======================================" << endl << endl;
        if (act == "show" || act == "sh" || act == "1") {page.ShowLst();}

        else if (act == "sort" || act == "s" || act == "2")
        {
            cout << "=======================================" << endl ;
            cout << "�������� ������ ����������:" << '\n' <<
            "1. group - �� ������" << '\n' <<
            "2. surname - �� �������" << '\n' <<
            "3. mark - �� �������" << '\n' <<
            "4. exit - �����" << endl << endl;
            cin >> type;
            cout << "=======================================" << endl << endl;
            if (type == "group" || type == "g" || type == "1") {page.SortGrp ();}
            else if (type == "surname" || type == "s" || type == "2") {page.SortSur ();}
            else if (type == "exit" || type == "e" || type == "3") {page.SortMrk();}
            else {cout << "error: wrong command" << endl << endl;}
        }

        else if (act == "find" || act == "f" || act == "3")
        {
            while (true)
            {
                cout << "=======================================" << endl ;
                cout << "�������� ������ ������:" << '\n' <<
                "1. group - �� ������" << '\n' <<
                "2. surname - �� �������" << '\n' <<
                "3. exit - �����" << endl << endl;
                cin >> type;
                cout << "=======================================" << endl << endl;
                if (type == "group" || type == "g" || type == "1") {page.SearchGrp();}
                else if (type == "surname" || type == "s" || type == "2") {page.SearchSur();}
                else if (type == "exit" || type == "e" || type == "3") {break;}
                else {cout << "error: wrong command" << endl << endl;}
            }
        }

        else if (act == "add" || act == "a" || act == "4") {page.AddNode();}
        else if (act == "edit" || act == "ed" || act == "5") {page.EdtNode();}
        else if (act == "delete" || act == "d" || act == "6") {page.DelNode();}
        else if (act == "save" || act == "sv" || act == "7") {page.SaveLst();}
        else if (act == "exit" || act == "e" || act == "8") {inp.close(); return 0;}
        else {cout << "error: wrong command" << endl << endl ;}
    }
}

//����������� �����
string  RUS(const string&  DOS_string)
{
    char*  p_buf = new char[DOS_string.length() + 1];
    OemToCharA(DOS_string.c_str(), p_buf);
    string  res(p_buf);
    delete[] p_buf;
    return res;
}
