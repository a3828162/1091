/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2678

參考:     無

題目:     政府想要節省電費，只需有一條經過每個點的路徑有燈就好，請找出比每條路都架設路燈還省多少錢

解題思路: 先找出MST(Minimum Spanning Tree)，MST是架設路燈最便宜的路徑，因此只需要把總架設的錢減掉MST裡的花費就好

Code解釋: 建一個struct去儲存邊的資訊，用容器去存edge,parent,rank，再sort，接著Kruskal找到答案

input:    輸入n,m代表有n個點m條邊,接下來m列輸入u,v,cost，邊的兩點跟花費
output:   輸出省多少錢
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static auto __ = []
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	return 0;
}();

struct edge
{
	int u;
	int v;
	int cost;

	bool operator<(const edge& r) { return cost < r.cost; }
};

vector<edge> edges;
vector<int> parent, Rank;
int n, m, cost;

int find(int f)
{
	return parent[f] == f ? f : parent[f] = find(parent[f]);
}

void Kruskal()
{
	int j = 0;

	for (auto& [u, v, w] : edges)
	{
		int a = find(u), b = find(v);

		if (a != b)
		{
			if (Rank[a] < Rank[b]) parent[a] = b;
			else if (Rank[a] > Rank[b]) parent[b] = a;
			else if (Rank[a] == Rank[b]) parent[a] = b, ++Rank[b];

			cost -= w;
			if (++j == n - 1) return;
		}
	}

}

int main()
{
	while (cin >> n >> m && (n || m))
	{
		parent.assign(n, 0);
		Rank.assign(n, 0);
		edges.assign(m, edge());
		cost = 0;

		for (int i = 0; i < m; ++i)
		{
			cin >> edges[i].u >> edges[i].v >> edges[i].cost;
			cost += edges[i].cost;
		}

		for (int i = 0; i < n; ++i) parent[i] = i;

		sort(begin(edges), end(edges));

		Kruskal();

		cout << cost << "\n";
	}

	return 0;
}

/*vector<edge> edges;
vector<int> parent, Rank;

int n, m, TotalCost;

int find(int f)
{
	return parent[f] == f ? f : parent[f] = find(parent[f]);
}

void Kruskal()
{
	int edgeN = 0;

	for (auto& [left, right, cost] : edges)
	{
		int a = find(left), b = find(right); //找parent

		if (a != b)
		{
			if (Rank[a] < Rank[b]) parent[a] = b; //Union搜尋優化
			else if (Rank[a] > Rank[b]) parent[b] = a;
			else parent[a] = b, ++Rank[b];

			TotalCost -= cost;

			if (++edgeN == n - 1) return;
		}
	}
}

int main()
{
	while (cin >> n >> m && (m || n))
	{
		edges.assign(m, edge());
		parent.assign(n, 0);
		Rank.assign(n, 0);

		TotalCost = 0;

		for (int i = 0; i < m; ++i)
		{
			cin >> edges[i].u >> edges[i].v >> edges[i].cost;
			TotalCost += edges[i].cost;
		}

		for (int i = 0; i < n; ++i) parent[i] = i; //每個node的初始parent都是自己
		
		sort(edges.begin(), edges.end());

		Kruskal();

		cout << TotalCost << "\n";
	}

	return 0;
}*/

/*
7 11
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11
0 0

51
*/