#include<iostream>
#include <fstream>
#include <windows.h>

using namespace std;


void Prim()
{
    cout << "алгоритм Прима" << endl << endl;
    #define INF 9999999
    int a,b,u,v,n,i,j,ne=1;
    int visited[10]={0}, min, mincost=0, cost[10][10];

	int path[100]={0}; //массив с вершинами
	int path_index=0;


	cout << "Количество вершин = "; cin >> n;
	cout << endl << "Стоимость пути:\n";



	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
	    if (i == j) cost[i][j]=INF;
	    else
        {
            printf("из [%c] в [%c] = ", i+64, j+64);
            cin >> cost[i][j];
            if(cost[i][j]==0) cost[i][j]=INF;
        }
	}
	visited[1]=1;
	cout<<"\n";

	while(ne < n)
	{
		for(i=1,min=INF;i<=n;i++)
		for(j=1;j<=n;j++)
		if(cost[i][j]< min)
		if(visited[i]!=0)
		{
			min=cost[i][j];
			a=u=i;
			b=v=j;
		}
		if(visited[u]==0 || visited[v]==0)
		{
			path[path_index]=b;
			path_index++;



			printf("[%c] [%c] = %d \n", a+64, b+64, min);
			ne++;
			//cout<<"\n "<<ne++<<"  "<<a<<"  "<<b<<min;


			//ne++;
			mincost+=min;
			visited[b]=1;

		}
		cost[a][b]=cost[b][a]=INF;
	}



}






struct edge
{
    int n1,n2; //прилегающие вершины
    int w; //вес ребра
};


int cmp(const void* a,const void* b) //сравнение ребёр
{
    edge* c = (edge*)a;
    edge* d = (edge*)b;
    return c->w - d->w;
}






int color(int n, int* nodes, int* last_n) // получение цвета вершины
{
    int c;
    if (nodes[n] < 0) return nodes[*last_n = n];// вершина n имеет цвет nodes[n]

    c = color(nodes[n], nodes, last_n);

    nodes[n] = *last_n;//вершина n имеет цвет такой же, как и вершина с номером nodes[n]
    return c;
}





void Kruskal()
{
    cout << "алгоритм Краскала" << endl << endl;
    int i, j, n, k;
    int *last_n = new int;



    cout << "Количество вершин = ";
    cin >> k;
    cout << endl;
    int *nodes = new int[k]; // вершины графа



    for(i = 0; i < k; i++)
        nodes[i] = -1 - i;

    cout << "Количество рёбер = ";
    cin >> n;
    cout << endl;
    edge edges[n]; // ребра графа


    cout<<"Стоимость пути:\n";
    for (int ic=0, nc=0; ic < k && nc < n; ic++)
        for (int jc=ic+1; jc < k && nc < n; jc++)
        {
            printf("из [%c] в [%c] = ", ic+65, jc+65);
            int temp; cin >> temp;
            if(temp != 0) {edges[nc].n1 = ic; edges[nc].n2 = jc; edges[nc].w = temp; nc++;}
        }
    cout << endl;



    qsort(edges, n, sizeof(edge), cmp); // сортируем все ребра в порядке возрастания весов

    for(i = 0; i < n; i++)
    {
        int c2 = color(edges[i].n2, nodes, last_n);
        if (color(edges[i].n1, nodes, last_n) != c2) // если ребро соединяет вершины различных цветов
        {
            nodes [*last_n] = edges[i].n2; //добавляем ребро и перекрашиваем вершины
            printf("[%c] [%c] = %d \n", edges[i].n1+65, edges[i].n2+65, edges[i].w);
        }
    }
}







int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    printf ("\nВыберите действие: \n 1. алгоритм Прима \n 2. алгоритм Краскала \n 3. оба \n\n");
    int ch; cin >> ch; cout << endl << endl;

    if (ch == 1 || ch == 3) Prim();
    if (ch == 3) cout << endl << "===================================" << endl << endl;
    if (ch == 2 || ch == 3) Kruskal();

}
