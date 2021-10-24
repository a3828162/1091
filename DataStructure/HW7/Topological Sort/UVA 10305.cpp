/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1246
*/

#include<iostream>
#include<vector>
#include<list>
#include<functional>
using namespace std;

static auto __ = []
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	return 0;
}();

list<int> ans;
vector<bool> visited, mem;
vector<vector<int>> G;

void DFS(int u)
{
	if (visited[u]) return;
	visited[u] = true;
	for (auto& i : G[u])
	{
		if (!visited[i]) DFS(i);
	}
	ans.push_front(u);
}

int main()
{
	int n, m;
	while (cin >> n >> m && (n || m))
	{
		ans.clear();
		visited.assign(n + 1, false);
		mem.assign(n + 1, false);
		G.assign(n + 1, vector<int>());
		int x, y;
		for (int i = 0; i < m; ++i)
		{
			cin >> x >> y;
			G[x].push_back(y);
			mem[y] = true;
		}

		for (int i = 1; i <= n; ++i)
		{
			if (!mem[i]) DFS(i);
		}

		auto it = ans.begin();
		cout << *it;
		for (++it; it != ans.end(); ++it) cout << " " << *it;
		cout << "\n";
	}

	return 0;
}








/*void DFS(int u)
{
	if (visited[u]) return;
	visited[u] = true;
	for (auto& i : G[u]) DFS(i);
	ans.push_front(u);
}

int main()
{
	int n, m;

	while (cin >> n >> m && n || m)
	{
		ans.clear();
		G.assign(n + 1, vector<int>());
		visited.assign(n + 1, false);
		mem.assign(n + 1, false);

		for (int i = 0; i < m; ++i)
		{
			int x, y;
			cin >> x >> y;
			G[x].push_back(y);
			mem[y] = true;
		}

		for (int i = 1; i <= n; ++i)
		{
			if (!mem[i]) DFS(i);
		}

		cout << ans.front();
		for (auto it = ++ans.begin(); it != ans.end(); ++it) cout << " " << *it;
		cout << '\n';
	}

	return 0;
}*/

/*
5 4
1 2
2 3
1 3
1 5
0 0

1 4 2 5 3
*/

/*int mem[101] = {};
int visited[101] = {};
vector<int> g[101];
list<int> ret;

void DFS(int n)
{
	if (visited[n]) return;
	visited[n] = 1;
	for (int i = 0; i < g[n].size(); ++i) DFS(g[n][i]);
	ret.push_front(n);
}

int main()
{
	int N, M;

	while (cin >> N >> M && (N || M))
	{
		ret.clear();
		fill(mem, mem + 101, 0);
		fill(visited, visited + 101, 0);
		fill(g, g + 101, vector<int>());

		for (int i = 0; i < M; ++i)
		{
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			mem[b] = 1;
		}

		for (int i = 1; i <= N; ++i) if (!mem[i]) DFS(i);

		cout << ret.front();
		for (auto it = ++ret.begin(); it != ret.end(); ++it) cout << " " << *it;
		cout << '\n';
	}

	return 0;
}*/