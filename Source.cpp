#include <iostream>
#include "pr_queue.h"
#include "AdjancentMatrixGraph1.h"
#include <set>
#include <vector>
#include <list>
#include <stack>

using std::set;
using std::make_pair;
using std::pair;
using std::vector;
using std::list;
using std::stack;

const int INF = 1000000;
const int V = 6;

void prim(AdjancentMatrixGraph*& gr, pr_queue q, vector<bool>& used, int start, set<pair<int, int>>& T, vector<pair<int, int>>& dist);
void prim1(AdjancentMatrixGraph*& G, int start, set<pair<int ,int>> &T);
bool f(vector<pair<int, int>> vec, vector<bool> used);

int main() {
	AdjancentMatrixGraph *gr = new AdjancentMatrixGraph(V);
	AdjancentMatrixGraph* gr1 = new AdjancentMatrixGraph(V);

	pr_queue q(100);
	vector<bool> used(gr->getSize()+1);
	gr->insert(0, 1, 6);
	gr->insert(0, 2, 1);
	gr->insert(0, 3, 5);
	gr->insert(1, 2, 5);
	gr->insert(1, 4, 3);
	gr->insert(2, 4, 6);
	gr->insert(2, 5, 4);
	gr->insert(2, 3, 5);
	gr->insert(3, 5, 2);
	gr->insert(5, 4, 6);

	gr1->insert(1, 2, 6);
	gr1->insert(1, 3, 1);
	gr1->insert(1, 4, 5);
	gr1->insert(2, 3, 5);
	gr1->insert(2, 5, 3);
	gr1->insert(3, 5, 6);
	gr1->insert(3, 6, 4);
	gr1->insert(3, 4, 5);
	gr1->insert(4, 6, 2);
	gr1->insert(6, 5, 6);
	vector<pair<int, int>> dist;
	set < pair<int, int>> Tm;
	prim1(gr1, 1, Tm);

	//prim1(gr);
	for (auto& it : Tm)
		std::cout << it.first << ' ' << it.second << '\n';
}

void prim(AdjancentMatrixGraph*& gr, pr_queue q, vector<bool>& used, int start, set<pair<int, int>>& T, vector<pair<int, int>>& dist) {
	//bool flag = 1;
	//while (flag) {
		//for (bool i : used)
			//if (!used[i])
				//flag = 1;
		auto vec = gr->adjacent_vertices(start);
		used[start] = 1;
		for (auto& it : vec) {
			int next = it.first;
			int weight = it.second;
			if (!used[next]) 
				q.push(start, next, weight);
		}
		T.insert(q.top());
		q.clear();
		//for (bool i : used)
		if (!used[q.top().second])
			prim(gr, q, used, q.top().second, T, dist);
		//if ()
		//start = q.top().second;
		//q.pop();
		//start = q.
	
}


void prim1(AdjancentMatrixGraph*& G, int start, set<pair<int, int>>& T) { 
	vector<bool> used(G->getSize() + 1); //задание размера массиву посещенных вершин
	pr_queue q(100);//выделение памяти под очередь с приоритетом (ребра с наименьшим весом имеют наибольший приоритет)
	while (!used[start]) { //цикл пока текущая вершина не является пройденной
		used[start] = 1; //пометка текущей вершины как посещенной
		auto vec = G->adjacent_vertices(start); // массив вершин, в которые можно пойти из текущей (start)
		for (auto& it : vec) //перебор вершин графа
			if (!used[it.first]) //ести не посещенная, то
			    q.push(start, it.first, it.second); //добавляем в очередь (start - текущая, it.first - куда идем из start, it.second - вес ребра)
		if (!used[q.top().second]) //если вторая вершина наименьшего ребра в очереди не посещена, то
		  T.insert(q.top()); //добавляем ребро в множество решений (минимальное оставное дерево)
		start = q.top().second; //переприсваиваем текущей вершине следующую вершину, которая должна быть в минимальном оставном дереве
		q.pop(); //достаём ребро из очереди
	}
}

bool f(vector<pair<int, int>> vec, vector<bool> used) {
	for (auto& it : vec)
		if (used[it.second] == 1)
			return 0;
	return 1;
}
