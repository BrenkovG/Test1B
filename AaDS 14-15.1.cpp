#include <Windows.h>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


void srch (int n, int** RoadMap, int start, int task = 1)
{
    int i, j;


    //заполнение нулевых маршрутов для корректной работы алгоритма
	int limit = 0; for (i = 0; i < n; i++) for (j = 0; j < n; j++) limit += RoadMap[i][j];
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) if (RoadMap[i][j] == 0) RoadMap[i][j] = limit;



	int* way = new int[n]; bool* visit = new bool[n];



	//заполнение массивов посещения и путей из начальной вершшины
	for (i = 0; i < n; i++) {visit[i] = false; way[i] = RoadMap[start][i];}
	visit[start] = true;



	for (i = 0; i < n - 1; i++)
    {
		int MinCostNum = 0;
		for (j = 1; j < n; j++)
		{
			if (!visit[MinCostNum]) {if (!visit[j] && way[j] <= way[MinCostNum]) MinCostNum = j;} //нахождение минимальной возможной текущей стоимости (нахождение постоянной метки)
			else MinCostNum++;
		}

		visit[MinCostNum] = true;

		for (j = 1; j < n; j++)
			if (!visit[j])
				if (way[MinCostNum] + RoadMap[MinCostNum][j] < way[j])
                    {way[j] = way[MinCostNum] + RoadMap[MinCostNum][j];} //нахождение новых кратчайших маршрутов с учётом новой вершины (расчёт временных меток)
	}






	if (task == 1)
    {
        cout << endl << "Стоимость тура в отдельные города: " << endl << endl;


        for (i = 0; i < n; i++) if (i != start) {char let = 65 +i; cout << '\t' << let;}
        cout << endl;

        for (i = 0; i < n; i++) if (i != start) cout << '\t' << way[i];
        cout << endl << endl;


        int sum = 0;
        for (int i = 0; i < n; i++) if (i != start) sum += way[i];
            cout << "Суммарная стоимость всего тура = " << sum << endl;
    }

    if (task == 2) cout << endl << "Минимальная возможная затрата топлива = " << way [n-1];
}













int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");



	int task;
	printf ("Выберите действие: \n 1. Задача 1 \n 2. Задача 2 \n 3. Задача 2, но только для квадртаных карт (для карт n*n, т.е. кол-во вершин - квадрат натурального числа) \n\n");
	cin >> task; cout << endl;
	switch (task)
	{
	    case 1:
	    {

            //создание массива
            int n; cout << "Количество городов = "; cin >> n;
            int** RoadMap = new int*[n];
            for (int i = 0; i < n; i++) RoadMap[i] = new int[n];

            cout << endl << "Ввод данных о стоимости пути: " << endl;
            for (int i = 0; i < n; i++)
            {
                char il = 65+i;
                for (int j = 0; j < n; j++)
                {
                    char jl = 65+j;
                    if (i != j) {cout << "Из " << il << " " << "в " << jl << ":" << '\t'; cin >> RoadMap[i][j];}
                    else RoadMap[i][j] = 0;
                }
            }

            int start; cout << endl << "номер начального города = "; cin >> start; srch(n, RoadMap, start-1);
            break;
        }



        case 2:
            {
            int n; cout << "Количество узлов = "; cin >> n;
            int** RoadMap = new int*[n];
            for (int i = 0; i < n; i++) RoadMap[i] = new int[n];

            cout << endl << "Ввод данных о затратах топлива: " << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = i; j < n; j++)
                {
                    if (i != j) {cout << "Из " << i+1 << " " << "в " << j+1 << ":" << '\t'; cin >> RoadMap[i][j]; RoadMap[j][i] = 0;}
                    else RoadMap[i][j] = 0;
                }
            }

            srch(n, RoadMap, 0, 2);
            break;
            }

        case 3:
            {
            int line; cout << "Количество узлов на одной стороне карты (квадратный корень из количества узлов) = "; cin >> line;
            int n = line * line;
            int** RoadMap = new int*[n];
            for (int i = 0; i < n; i++) RoadMap[i] = new int[n];

            cout << endl << "Ввод данных о затратах топлива: " << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = i; j < n; j++)
                {
                    if ( (i + line == j) || (i + 1 == j && (j % line != 0)))
                        {cout << "Из " << i+1 << " " << "в " << j+1 << ":" << '\t'; cin >> RoadMap[i][j]; RoadMap[j][i] = 0;}
                    else RoadMap[j][i] = RoadMap[i][j] = 0;
                }
            }

            srch(n, RoadMap, 0, 2);
            break;
            }

    }
}
