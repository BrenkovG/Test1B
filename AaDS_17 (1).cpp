#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <list>
#include <map>

using namespace std;

ifstream fin("spisok2.txt");





struct StudQ
{

	struct student
	{
		student* next; int mark, group; string FullName[3];
	};
	student* head; int size;

	StudQ(){size = 0; head = NULL;};

	void push(int group, string* FullName, int mark);

	void print(int* m = NULL);
};









void StudQ::push(int group, string* FullName, int mark)
{
	if (head == NULL)
	{
		head = new student;
		for (int i = 0; i < 3; i++)
		{
			head->FullName[i] = FullName[i];
		}
		head->group = group;
		head->mark = mark;
		head->next = NULL;
	}
	else
	{
		student* new_element = head;
		while (new_element->next != NULL)
		{
			new_element = new_element->next;
		}
		new_element->next = new student;
		new_element = new_element->next;
		for (int i = 0; i < 3; i++)
		{
			new_element->FullName[i] = FullName[i];
		}
		new_element->group = group;
		new_element->mark = mark;
		new_element->next = NULL;
	}
	size++;
}








void StudQ::print(int* m)
{
	int i = 0; student* element = head;


	while (element != NULL)
	{
		cout << element->group << "\t";
		for (int i = 0; i < 3; i++)
			cout << element->FullName[i] << " ";
		if (element->mark != NULL)
			cout << "\t\t" << element->mark << "\n";
		else
			cout << "\t\tн/я\n";
		element = element->next;
	}
}







int main()
{

	setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);







	StudQ s[9];


	int x, xxx = 911;
	 string f;
	string FullName[3] = { "" };

	int op = 1;
	int it = 0;
	while (!fin.eof())
	{
		if (op)
		{
			char xx[4];
			for (int i = 0; i < 4; i++) fin >> xx[i];
			fin >> x;
		}

		if (x == xxx)
		{
			for (int i = 0; i < 3; i++) fin >> FullName[i];
			char t[5];
			fin >> t;

			if (isdigit(t[0])) s[it].push(x, FullName, atoi(t));
			else s[it].push(x, FullName, NULL);

			op = 1;
		}

		else
		{
			it++;
			op = 0;
			xxx = x;
		}
	}





	map < int, StudQ > StudBook;
	StudBook.emplace(911, s[0]);
	StudBook.emplace(912, s[1]);
	StudBook.emplace(913, s[2]);
	StudBook.emplace(921, s[3]);
	StudBook.emplace(922, s[4]);
	StudBook.emplace(923, s[5]);
	StudBook.emplace(931, s[6]);
	StudBook.emplace(932, s[7]);
	StudBook.emplace(933, s[8]);
	StudQ q;

	while (true)
	{
		printf("\n1. Поиск\n2. Удаление\n3. Вставка элемента\n4. Вывод\n0. Выход\n\n");
		int k; cin >> k; cout << endl;


		if (k == 1)
		{
			cout << "Введите номер группы для поиска:  ";
			int r; cin >> r; cout << endl;
			auto iterator = StudBook.find(r);
			iterator->second.print();
		}


		else
			if (k == 2)
			{
				cout << "Введите номер группы для удаления:  ";
				int r; cin >> r; StudBook.erase(r);
			}




		else if (k == 3)
		{
			int mark, group; string FullName[3];

			cout << "Введите номер группы для добавления:  "; int kl; cin >> kl;
			cout << "Введите данные новых записей: Фамилия, Имя, Отчество, Оценка. После завершения введите '0'\n";

			while (FullName[0] != "0")
			{
				cin >> FullName[0]; if (FullName[0] == "0") break;
				cin >> FullName[1] >> FullName[2] >> mark;
				q.push(kl, FullName, mark);
			}
			StudBook.emplace(kl, q);
		}




		else if (k == 4)
        {
            for (auto iterator = StudBook.begin(); iterator != StudBook.end(); iterator++)
            {
                iterator->second.print(); cout<<"\n\n\n";
            }
        }


			else return 0;

	}


}

