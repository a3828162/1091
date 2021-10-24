/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&category=0&problem=3873
*/

#include<iostream>
#include<vector>
using namespace std;

static auto __ = []
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	return 0;
}();

int m, s, t;
vector<int> G;
vector<bool> visited, dfsV;//只能用bool不能用int

int DFS(int n)
{
	if (dfsV[n]) return 0;
	visited[n] = dfsV[n] = true;
	return 1 + DFS(G[n]);
}

int main()
{
	int T, Case = 0;
	cin >> T;
	while (T--)
	{
		cin >> m;
		G.assign(m + 1, 0);
		visited.assign(m + 1, false);
		for (int i = 0; i < m; ++i)
		{
			cin >> s >> t;
			G[s] = t;
		}
		int tmp = 0, max = 0, ans = 0;
		for (int i = 1; i <= m; ++i)
		{
			dfsV.assign(m + 1, false);
			if (!visited[i]) tmp = DFS(i);
			if (tmp > max) max = tmp, ans = i;
		}
		cout << "Case " << ++Case << ": " << ans << "\n";
	}

	return 0;
}









/*int DFS(int u)
{
	if (dfsV[u]) return 0;
	visited[u] = dfsV[u] = 1;
	return 1 + DFS(G[u]);
}

int main()
{
	int T, Case = 0;;
	cin >> T;

	while (T--)
	{
		cin >> m;
		G.assign(m + 1, 0);
		visited.assign(m + 1, false);

		for (int i = 0; i < m; ++i)
		{
			cin >> s >> t;
			G[s] = t;
		}

		int max = -1, ans = 0;

		for (int i = 1; i <= m; ++i)
		{
			if (visited[i]) continue;

			dfsV.assign(m + 1, false);
			int tmp = DFS(i);
			if (tmp > max) max = tmp, ans = i;
		}
		
		cout << "Case " << ++Case << ": " << ans << "\n";
	}

	return 0;
}*/

/*
3
3
1 2
2 3
3 1
4
1 2
2 1
4 3
3 2
5
1 2
2 1
5 3
3 4
4 5

Case 1: 1
Case 2: 4
Case 3: 3
*/

/*vector<int> adj;
vector<bool> visited, dfsV;

int DFS(int now)
{
	if (dfsV[now]) return 0;
	visited[now] = dfsV[now] = true;
	return 1 + DFS(adj[now]);
}

int main()
{
	int N, cn = 0;

	cin >> N;

	while (N--)
	{
		int n;
		cin >> n;

		adj.assign(n + 1, 0);
		for (size_t i = 0; i < n; ++i)
		{
			int l, a;
			cin >> l >> a;
			adj[l] = a;
		}

		visited.assign(n + 1, false);

		int output = 0, max = -1, ret = 0;

		for (size_t i = 1; i <= n; ++i)
		{
			if (visited[i]) continue;

			dfsV.assign(n + 1, false);
			output = DFS(i);
			if (output > max)max = output, ret = i;
		}

		cout << "Case " << ++cn << ": " << ret << endl;
	}

	return 0;
}*/