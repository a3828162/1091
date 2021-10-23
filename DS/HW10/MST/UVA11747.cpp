/*
�D�سs��: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2847

�Ѧ�:     �L

�D��:     ���A�@�i�ϡA��XMinimum Spanning Tree(²��MST)�A��X�Ҧ����OMST���䪺weight

���D���: ����MST�A�A�⤣�OMST����s�_��

Code����: �سy�@��struct�h�x�s�䪺��ơA��vector��e���s��,parent��rank����T�A�M��ƧǡA���ۦbKruskal�䵪��

input:    ��Jn,m�A�N��n���I��m�C��A�C�C��Ju,v,w�A�C���䪺���I��weight
output:   ��X�Ҧ������OMST���䪺weight
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge
{
	int u;
	int v;
	int weight;

	bool operator<(const edge& r) { return weight < r.weight; }
};

static auto __ = []
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	return 0;
}();

vector<edge> edges;
vector<int> parent, Rank, ans;
int n, m;

int find(int f)
{
	return parent[f] == f ? f : parent[f] = find(parent[f]);
}

void Kruskal()
{
	for (auto& [u, v, w] : edges)
	{
		int a = find(u), b = find(v);
		
		if (a != b)
		{
			if (Rank[a] < Rank[b]) parent[a] = b;
			else if (Rank[a] > Rank[b]) parent[b] = a;
			else if (Rank[a] == Rank[b]) parent[a] = b, ++Rank[b];
		}
		else
		{
			ans.push_back(w);
		}
	}

}

int main()
{
	while (cin >> n >> m && (n || m))
	{
		edges.assign(m, edge());
		parent.assign(n, 0);
		Rank.assign(n, 0);
		ans.clear();

		for (int i = 0; i < m; ++i)
		{
			cin >> edges[i].u >> edges[i].v >> edges[i].weight;
		}

		for (int i = 0; i < n; ++i) parent[i] = i;

		sort(begin(edges), end(edges));

		Kruskal();

		if (ans.empty()) cout << "forest\n";
		else
		{
			cout << ans[0];
			for (int i = 1; i < ans.size(); ++i) cout << " " << ans[i];
			cout << "\n";
		}
	}

	return 0;
}

/*vector<edge> edges;
vector<int> parent, Rank, ans;
int n, m;

int find(int f)
{
	return parent[f] == f ? f : parent[f] = find(parent[f]);
}

void Kruskal()
{
	for (auto& [left, right, weight] : edges)
	{
		int a = find(left), b = find(right); //��parent

		if (a != b)
		{
			if (Rank[a] < Rank[b]) parent[a] = b; //Union�j�M�u��
			else if (Rank[a] > Rank[b]) parent[b] = a;
			else parent[a] = b, ++Rank[b];
		}
		else ans.push_back(weight);
	}
}

int main()
{
	while (cin >> n >> m && (n || m))
	{
		edges.assign(m, edge());
		parent.assign(n, 0);
		Rank.assign(n, 0);
		ans.clear();

		for (int i = 0; i < m; ++i) cin >> edges[i].u >> edges[i].v >> edges[i].weight;

		for (int i = 0; i < n; ++i) parent[i] = i; //�C��node����lparent���O�ۤv

		sort(edges.begin(), edges.end());

		Kruskal();

		if (ans.empty()) cout << "forest\n";
		else
		{
			cout << ans[0];
			for (int i = 1; i < ans.size(); ++i) cout << " " << ans[i];
			cout << "\n";
		}
	}

	return 0;
}*/

/*
3 3
0 1 1
1 2 2
2 0 3
4 5
0 1 1
1 2 2
2 3 3
3 1 4
0 2 0
3 1
0 1 1
0 0

3
2 4
forest
*/