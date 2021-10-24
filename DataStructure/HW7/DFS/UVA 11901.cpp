/*
題目連結: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3057
*/

#include<iostream>
#include<vector>
#include<string>
#include<functional>
using namespace std;

static auto __ = []
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	return 0;
}();

int r, c, n, m, w;
vector<vector<int>> G;

void DFS(int x,int y)
{
	if (x < 0 || x >= r || y < 0 || y >= c || G[x][y] == -1) return;

	if (G[x][y]++) return;

	int _x = m, _y = n;

	for (int i = 0; i < 2; ++i)
	{
		DFS(x + _x, y + _y);
		DFS(x - _x, y - _y);
		if (_x && _y)
		{
			DFS(x + _x, y - _y);
			DFS(x - _x, y + _y);
		}
		if (_x == _y) break;
		std::swap(_x, _y);
	}
}

int main()
{
	int T, Case = 0;
	cin >> T;
	while (T--)
	{
		cin >> r >> c >> n >> m;
		G.assign(r, vector<int>(c));
		cin >> w;
		int a, b;
		for (int i = 0; i < w; ++i)
		{
			cin >> a >> b;
			G[a][b] = -1;
		}

		DFS(0, 0);
		--G[0][0];
		int odd = 0, even = 0;
		if (!G[0][0]) ++even;

		for (int i = 0; i < G.size(); ++i)
		{
			for (int j = 0; j < G[i].size(); ++j)
			{
				if (G[i][j] > 0) G[i][j] % 2 == 0 ? ++even : ++odd;
			}
		}

		cout << "Case " << ++Case << ": " << even << " " << odd << "\n";
	}

	return 0;
}



/*void DFS(int x, int y)
{
	if (x < 0 || x >= r || y < 0 || y >= c || G[x][y] == -1) return;
	if (G[x][y]++ != 0) return;
	int _x = m, _y = n;

	for (int i = 0; i < 2; ++i)
	{
		DFS(x + _x, y + _y);
		DFS(x - _x, y - _y);
		if (_x && _y)
		{
			DFS(x + _x, y - _y);
			DFS(x - _x, y + _y);
		}

		if (_x == _y) break;
		std::swap(_x, _y);
	}
}

int main()
{
	int T, Case = 0;
	cin >> T;

	while (T--)
	{
		cin >> r >> c >> m >> n >> w;
		G.assign(r, vector<int>(c));

		int a, b;
		for (int i = 0; i < w; ++i)
		{
			cin >> a >> b;
			G[a][b] = -1;
		}

		DFS(0, 0);
		--G[0][0];

		int odd = 0, even = 0;
		for (int i = 0; i < G.size(); ++i)
		{
			for (int j = 0; j < G[i].size(); ++j)
			{
				if (G[i][j] <= 0) continue;
				G[i][j] & 1 ? ++odd : ++even;
			}
		}

		if (!G[0][0]) ++even;

		cout << "Case " << ++Case << ": " << even << " " << odd << "\n";
	}

	return 0;
}*/

/*
2
3 3 2 1
0
4 4 1 2
2
3 3
1 1

Case 1: 8 0
Case 2: 4 10
*/

/*int r, c, m, n, w;

void DFS(int x, int y, vector<vector<int>>& map)
{
	if (x < 0 || x >= r || y < 0 || y >= c || map[x][y] == -1) return;

	if (map[x][y]++ != 0) return;
	int _x = m, _y = n;

	for (int i = 0; i < 2; ++i)
	{
		DFS(x + _x, y + _y, map);
		DFS(x - _x, y - _y, map);
		if (_x && _y)
		{
			DFS(x + _x, y - _y, map);
			DFS(x - _x, y + _y, map);
		}
		if (_x == _y) break;
		swap(_x, _y);	
	}
}

int main()
{
	int T, Case = 0;
	cin >> T;

	while (T--)
	{
		cin >> r >> c >> m >> n >> w;

		vector<vector<int>> map(r, vector<int>(c));
		
		for (size_t i = 0; i < w; ++i)
		{
			int x, y;
			cin >> x >> y;
			map[x][y] = -1;
		}

		DFS(0, 0, map);
		--map[0][0];

		int odd=0, even = 0;
		for (size_t i = 0; i < map.size(); ++i)
		{
			for(size_t j = 0; j < map[i].size(); ++j)
			{
				if (map[i][j] <= 0) continue;
				map[i][j] & 1 ? ++odd : ++even;
			}
		}

		if (!map[0][0]) ++even;

		cout << "Case " << ++Case << ": " << even << " " << odd << endl;
	}

	return 0;
}*/