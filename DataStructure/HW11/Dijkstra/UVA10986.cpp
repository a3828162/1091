/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1927
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static auto __ = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

vector<vector<pair<int, int>>> G;
vector<int> D, visited;
int T, Case = 0;
int n, m, s, t;
int u, v, w;

void Dijkstra()
{
	priority_queue<int, vector<int>, greater<int>> Q;
	Q.push(s);
	D[s] = 0;

	while (!Q.empty())
	{
		int now = Q.top();
		Q.pop();

		for (auto& i : G[now])
		{
			if (D[i.first] > D[now] + i.second)
			{
				D[i.first] = D[now] + i.second;
				Q.push(i.first);
			}
		}
	}
	if (D[t] == 1e9) cout << "Case #" << ++Case << ": " << "unreachable\n";
	else cout << "Case #" << ++Case << ": " << D[t] << "\n";

}

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> n >> m >> s >> t;

		G.assign(n+1, vector<pair<int, int>>());
		D.assign(n+1, 1e9);
		visited.assign(n+1, 0);

		for (int i = 0; i < m; ++i)
		{
			cin >> u >> v >> w;
			G[u].push_back({ v, w });
			G[v].push_back({ u, w });
		}

		Dijkstra();
	}

	return 0;
}

/*
3
2 1 0 1
0 1 100
3 3 2 0
0 1 100
0 2 200
1 2 50
2 0 0 1

Case #1: 100
Case #2: 150
Case #3: unreachable
*/