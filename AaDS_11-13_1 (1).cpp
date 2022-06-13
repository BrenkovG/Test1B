#include <windows.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <ctime>

using namespace std;
ifstream inp("spisok2.txt");
ifstream inpD("Data.txt");
ofstream out("Data.txt");


//������
struct list
{
    //����
    struct student
    {
        string group, surname, name, patron, mark; student* prev; student* next;

        //�����������
        student(string group)
        {
            this->prev = NULL; this->next = NULL;
            this->group = group; inp >> this->surname >> this->name >> this->patron >> this->mark;
        };

        //����� ���� �� �����
        void wrt() {cout << group << ' ' << surname << ' ' << name << ' ' << patron << '\t' << mark << endl;};

    };
    student* head; student* curprev; student* current; student* tail;


    list();
    ~list();


    void ShowLst();
    void AddNode(string group);
    void RandSwap();
};


//����������� ������
list::list()
{
    //��������� ����������
    this->head = NULL;
    this->curprev = NULL;
    this->current = NULL;
    this->tail = NULL;
}


//���������� ������
list::~list()
{
    //��������� ����������
    this->head = NULL;
    this->curprev = NULL;
    this->current = NULL;
}

//���������� ���� � ������
void list::AddNode(string group)
{
    if (this->head == NULL) {this->tail = this->head = new student(group);}
    else {this->tail->next = new student(group); this->tail->next->prev = this->tail; this->tail = this->tail->next;};
}
void list::RandSwap()
{
    int c = 0;

    this->current = this->head;

    for (;this->current != NULL;c++) this->current = this->current->next;



    this->curprev = this->head->next;
    int mvh = rand() % c +  2;
    for (int i = 0; (this->curprev->next->next != NULL) && (i < mvh);i++) this->curprev = this->curprev->next;
    swap (this->curprev->next->prev, this->head->next->prev);
    swap (this->curprev->next->next, this->head->next->next);
    this->curprev->prev->next = this->head;
    swap (this->curprev->prev, this->head->prev);
    this->head = this->curprev;





    this->current = this->head;

    for (int k = 3; (this->current->next != NULL) && (this->current->next->next != NULL) && (this->current->next->next->next != NULL) && (k < c); k++)
    {
        int mv = 1 + rand() % (c-k);

        this->curprev = this->current->next;

        for (int a = 0; (this->curprev->next != NULL) && (this->curprev->next->next != NULL) && (this->curprev->next->next->next != NULL) && (a < mv); a++)
        {
            this->curprev = this->curprev->next;
        }



        swap (this->curprev->next->next->prev, this->current->next->next->prev);
        swap (this->curprev->next->next, this->current->next->next);
        swap (this->curprev->next->prev, this->current->next->prev);
        swap (this->curprev->next, this->current->next);


        this->current = this->current->next;
    }
}



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



/////////////////////////////////////      /////////////////////////////////////




//������
struct tree
{
    struct student
    {
        string group, surname, name, patron, mark; student* prev; student* left; student* right;

        //�����������
        student (string group, string surname, string name, string patron, string mark)
        {
            this->prev = NULL; this->left = NULL; this->right = NULL;
            this->group = group; this->surname = surname; this->name = name; this->patron = patron; this->mark = mark;
        };

        //����� ���� �� �����
        void wrt () {cout << group << ' ' << surname << ' ' << name << ' ' << patron << '\t' << mark;};

    };
    student* head; student* current;

    tree();
    ~tree();


    void AddNode (string group, string surname, string name, string patron, string mark);
    void AddRand (string group, string surname, string name, string patron, string mark);
    void show (student* CurOut, int i);

};


//����������� ������
tree::tree()
{
    //��������� ����������
    this->head = NULL;
    this->current = NULL;
}


//���������� ������
tree::~tree()
{
    //��������� ����������
    this->head = NULL;
    this->current = NULL;
}


//���������� ���� � ������
void tree::AddNode(string group, string surname, string name, string patron, string mark)
{
    if (this->head == NULL) {this->head = new student(group, surname, name, patron, mark);}
    else
        {
            this->current = this->head;
            while(true)
            {
                if (surname >= this->current->surname && this->current->right != NULL) {this->current = this->current->right;}

                else if (surname < this->current->surname && this->current->left != NULL) {this->current = this->current->left;}

                else if (surname >= this->current->surname && this->current->right == NULL)
                    {this->current->right = new student (group, surname, name, patron, mark); this->current->right->prev = this->current; break;}

                else if (surname < this->current->surname && this->current->left == NULL)
                    {this->current->left = new student (group, surname, name, patron, mark); this->current->left->prev = this->current; break;}
            }
        };
}


//���������� ���� � rand-������
void tree::AddRand(string group, string surname, string name, string patron, string mark)
{
    if (this->head == NULL) {this->head = new student(group, surname, name, patron, mark);}
    else
        {
            this->current = this->head;
            while(true)
            {
                int ch = rand() % 2;
                if (ch == 1 && this->current->right != NULL) {this->current = this->current->right;}

                else if (ch == 0 && this->current->left != NULL) {this->current = this->current->left;}

                else if (ch == 1 && this->current->right == NULL)
                    {this->current->right = new student (group, surname, name, patron, mark); this->current->right->prev = this->current; break;}

                else if (ch == 0 && this->current->left == NULL)
                    {this->current->left = new student (group, surname, name, patron, mark); this->current->left->prev = this->current; break;}
            }
        };
}


//����� ������ �� �����
void tree::show(student* CurOut, int i = 0)
{
    if (CurOut->right != NULL) this->show(CurOut->right, i+1);
    for (int c = 0; c < i; c++) cout << "  ";
    CurOut->wrt();
    cout << endl;
    if (CurOut->left != NULL) this->show(CurOut->left, i+1);
}





/////////////////////////////////////      /////////////////////////////////////

/////////////////////////////////////      /////////////////////////////////////





//������
struct listD
{
    //����
    struct node
    {
        int data; node* prev; node* next;

        //�����������
        node ()
        {
            this->prev = NULL; this->next = NULL;
            inpD >> this->data;
        };

        node (int data)
        {
            this->prev = NULL; this->next = NULL;
            this->data = data;
        };

        //����� ���� �� �����
        void wrt () {cout << data << endl;};

    };
    node* head; node* current; node* tail;


    listD();
    ~listD();


    void ShowLst();
    void AddNode();
    void DelNode();
};


//����������� ������
listD::listD()
{
    //��������� ����������
    this->head = NULL;
    this->current = NULL;
    this->tail = NULL;

    if (this->head == NULL) {this->head = new node (); this->current = this->head;}

    while (!inpD.eof())
    {this->current->next = new node; this->current->next->prev = this->current; this->current = this->current->next;};


    //�������� "������" � ��������� ����������
    this->tail = this->current;
    this->current = NULL;
}


//���������� ������
listD::~listD()
{
    //��������� ����������
    this->head = NULL;
    this->current = NULL;
}

//���������� ���� � ������
void listD::AddNode()
{
    cout << "������� ������ ��� ����������: " << endl;
    int data; cin >> data;

    if (this->head == NULL) {this->tail = this->head = new node(data);}
    else {this->tail->next = new node(data); this->tail->next->prev = this->tail; this->tail = this->tail->next;};
}




//�������� ���� �� ������
void listD::DelNode()
{
    cout << "������� ������ ��� ��������: " << endl;
    int data; cin >> data;

    this->current = this->head;
    while (this->current->next != NULL && this->current->data != data) this->current = this->current->next;

    if (this->current->data != data) cout << "Wrong number" << endl;
    else if (this->current == this->head) {this->head = this->head->next; this->head->prev = NULL;}
    else if (this->current == this->tail) {this->tail = this->tail->prev; this->tail->next = NULL;}
    else {this->current = this->current->prev; this->current->next = this->current->next->next; delete [] (this->current->next->next->prev); this->current->next->next->prev = this->current;}
}










/////////////////////////////////////      /////////////////////////////////////










//������
struct treeD
{
    struct node
    {
        int data; node* prev; node* left; node* right;

        //�����������
        node (int data)
        {
            this->prev = NULL; this->left = NULL; this->right = NULL;
            this->data = data;
        };

        //����� ���� �� �����
        void wrt () {cout << data;};

    };
    node* head; node* current;

    treeD();
    ~treeD();


    void AddNode (int data);
    void AddRand (int data);
    void show (node* CurOut, int i);

};


//����������� ������
treeD::treeD()
{
    //��������� ����������
    this->head = NULL;
    this->current = NULL;
}


//���������� ������
treeD::~treeD()
{
    //��������� ����������
    this->head = NULL;
    this->current = NULL;
}


//���������� ���� � ������
void treeD::AddNode(int data)
{
    if (this->head == NULL) {this->head = new node(data);}
    else
        {
            this->current = this->head;
            while(true)
            {
                if (data >= this->current->data && this->current->right != NULL) {this->current = this->current->right;}

                else if (data < this->current->data && this->current->left != NULL) {this->current = this->current->left;}

                else if (data >= this->current->data && this->current->right == NULL)
                    {this->current->right = new node (data); this->current->right->prev = this->current; break;}

                else if (data < this->current->data && this->current->left == NULL)
                    {this->current->left = new node (data); this->current->left->prev = this->current; break;}
            }
        };
}


//����� ������ �� �����
void treeD::show(node* CurOut, int i = 0)
{
    if (CurOut->right != NULL) this->show(CurOut->right, i+1);
    for (int c = 0; c < i; c++) cout << '\t';
    CurOut->wrt();
    cout << endl;
    if (CurOut->left != NULL) this->show(CurOut->left, i+1);
}














/////////////////////////////////////      /////////////////////////////////////

/////////////////////////////////////      /////////////////////////////////////



void MkFile (int c, int min, int max )
{
    if (c > (max - min + 1) || min > max) {cout << "�������� ��������! " << endl << endl; return;}
    srand(time(NULL));

    int arr[c];

    for (int i = 0; i < c; i++)
    {
        int arrch;
        do
        {
            arrch = min + rand() % (max + 1);
            for (int j = 0; j <= i; j++)
            {
                if (arr [j] == arrch) break;
                else if (j == i) arr[i] = arrch;
            }
        }
        while (arr[i] != arrch);

    };

    for (int i = 0; i < c; i++) {out << arr[i] << "  ";};
    out.close();
    cout << "�������� ����� ���������" << endl << endl;
}





void FillTree(list* Rd, tree* Wrt, bool R = false)
{
    if (R == false)
    {
        (*Rd).current = (*Rd).head;
        while ((*Rd).current != NULL)
        {
            (*Wrt).AddNode((*Rd).current->group, (*Rd).current->surname, (*Rd).current->name, (*Rd).current->patron, (*Rd).current->mark);
            (*Rd).current = (*Rd).current->next;
        }
    }


    else if (R == true)
    {
        (*Rd).current = (*Rd).head;
        while ((*Rd).current != NULL)
        {
            (*Wrt).AddRand((*Rd).current->group, (*Rd).current->surname, (*Rd).current->name, (*Rd).current->patron, (*Rd).current->mark);
            (*Rd).current = (*Rd).current->next;
        }
    }
}




int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));


    //������������ 11 � 12
    /*list page_1; list page_2; list page_3; list page_4;


    //���������� �������
    string group;

    while (!inp.eof())
    {
        inp >> group;
        if (group == "���-911" || group == "���-913") {page_1.AddNode(group);}
        if (group == "���-921" || group == "���-923") {page_2.AddNode(group);}
        if (group == "���-931" || group == "���-933") {page_3.AddNode(group);}
        if (group == "���-912" || group == "���-932") {page_4.AddNode(group);}
        getline (inp, group);
    };






    int a = 0;


    printf ("\n�������� �������� ��� ���-911 � ���-913: \n 1. �������� ������ \n 2. rand \n 3. rand ������ \n\n");
    cin >> a;


    tree plant_1;

    switch (a){
        case 1: FillTree(&page_1, &plant_1); break;
        case 2: FillTree(&page_1, &plant_1, true); break;
        case 3: page_1.RandSwap(); FillTree(&page_1, &plant_1); break;}
    plant_1.show(plant_1.head);




    printf ("\n�������� �������� ��� ���-921 � ���-923: \n 1. �������� ������ \n 2. rand \n 3. rand ������ \n\n");
    cin >> a;


    tree plant_2;

    switch (a){
        case 1: FillTree(&page_2, &plant_2); break;
        case 2: FillTree(&page_2, &plant_2, true); break;
        case 3: page_2.RandSwap(); FillTree(&page_2, &plant_2); break;}
    plant_2.show(plant_2.head);




    printf ("\n�������� �������� ��� ���-931 � ���-933: \n 1. �������� ������ \n 2. rand \n 3. rand ������ \n\n");
    cin >> a;


    tree plant_3;

    switch (a){
        case 1: FillTree(&page_3, &plant_3); break;
        case 2: FillTree(&page_3, &plant_3, true); break;
        case 3: page_3.RandSwap(); FillTree(&page_3, &plant_3); break;}
    plant_3.show(plant_3.head);




    printf ("\n�������� �������� ��� ���-912 � ���-932: \n 1. �������� ������ \n 2. rand \n 3. rand ������ \n\n");
    cin >> a;


    tree plant_4;

    switch (a){
        case 1: FillTree(&page_4, &plant_4); break;
        case 2: FillTree(&page_4, &plant_4, true); break;
        case 3: page_4.RandSwap(); FillTree(&page_4, &plant_4); break;}
    plant_4.show(plant_4.head);*/

    MkFile (50, 1, 65);


    listD nums;

    treeD* NumD = new treeD;

    nums.current = nums.head;
    while (nums.current != NULL)
    {
        (*NumD).AddNode(nums.current->data);
        nums.current = nums.current->next;
    }

    int aInf;

    while (aInf != 0)
    {
        printf ("\n�������� ��������: \n 1. ����� ������ \n 2. ���������� ���� \n 3. �������� ���� \n 0. ����� \n\n");
        cin >> aInf;

        switch (aInf){
            case 1: (*NumD).show ((*NumD).head); break;

            case 2: nums.AddNode(); NumD = new treeD;
                    nums.current = nums.head;
                    while (nums.current != NULL)
                    {
                        (*NumD).AddNode(nums.current->data);
                        nums.current = nums.current->next;
                    }
                    (*NumD).show ((*NumD).head); break;

            case 3: nums.DelNode(); NumD = new treeD;
                    nums.current = nums.head;
                    while (nums.current != NULL)
                    {
                        (*NumD).AddNode(nums.current->data);
                        nums.current = nums.current->next;
                    }
                    (*NumD).show ((*NumD).head); break;}

    }
}
