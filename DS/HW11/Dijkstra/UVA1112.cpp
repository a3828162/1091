/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3553
*/

#include <iostream>
#include <vector>
#include <climits>
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
vector<int> D;
int T, n, m, start, Time, ans;
int x, y, w;

void Dijk()
{
	D[start] = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(start);

	while(!pq.empty())
	{
		int u = pq.top();
		pq.pop();

		for (auto& v : G[u])
		{
			if (D[v.first] > D[u] + v.second)
			{
				D[v.first] = D[u] + v.second;
				pq.push(v.first);
			}
		}
	}
}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> start >> Time >> m;
		G.assign(n + 1, vector<pair<int, int>>());
		D.assign(n + 1, INT_MAX);

		for (int i = 0; i < m; ++i)
		{
			cin >> x >> y >> w;
			G[y].push_back({ x,w });
		}

		Dijk();
		ans = 0;

		for (int i = 1; i <= n; ++i) if (D[i] <= Time) ++ans;
		cout << ans << "\n";
		if (T) cout << "\n";
	}

	return 0;
}







/*
1

4
2
1
8
1 2 1
1 3 1
2 1 1
2 4 1
3 1 1
3 4 1
4 2 1
4 3 1

3
*/

/*void Dijkstra()
{
	priority_queue<int, vector<int>, greater<int>> Q;
	D[start] = 0;
	Q.push(start);

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

	for (int i = 1; i <= n; ++i) if (D[i] <= Time) ++ans;
	cout << ans << "\n";
	if (T) cout << "\n";
}

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> n >> start >> Time >> m;
		G.assign(n + 1, vector<pair<int, int>>());
		D.assign(n + 1, 1e9);
		ans = 0;

		for (int i = 0; i < m; ++i)
		{
			cin >> x >> y >> w;
			G[y].push_back(pair<int, int>(x, w));
		}

		Dijkstra();
	}

	return 0;
}*/