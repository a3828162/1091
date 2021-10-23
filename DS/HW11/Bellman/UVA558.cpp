#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
//#include <tuple>
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
	int w;
};

vector < edge > edges;
vector < int > dist;
int T, n, m, u, v, w;

bool Bellman()
{
	dist[0] = 0;

	for (int i = 0; i < n - 1; ++i)
	{
		for (auto& [u, v, w] : edges)
		{
			if (dist[u] != INT_MAX) dist[v] = min(dist[v], dist[u] + w);
		}
	}

	for (auto& [u, v, w] : edges) if (dist[v] > dist[u] + w) return true;

	return false;
}

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> n >> m;

		edges.clear();
		dist.assign(n, INT_MAX);

		for (int i = 0; i < m; ++i)
		{
			cin >> u >> v >> w;
			edges.push_back({ u,v,w });
		}

		if (Bellman()) cout << "possible\n";
		else cout << "not possible\n";
	}


	return 0;
}