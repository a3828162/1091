/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&category=0&problem=104
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

vector<vector<char>> G;
vector<int> candle;
int m, step;

void DFS(char f,char t)
{
	if (step && step % m == 0)
	{
		cout << t << " ";
		candle[t - 'A'] = 1;
	}

	for (auto& i : G[f - 'A'])
	{
		if (i != t && !candle[i - 'A'])
		{
			++step;
			DFS(i, f);
			return;
		}
	}

	cout << "/" << f << "\n";
}

int main()
{
	string input;

	char f, t;
	while (cin>>input && input != "#")
	{
		G.assign(26, vector<char>());
		candle.assign(26, 0);
		step = 0;

		for (int i = 0; i < input.size();)
		{
			if (input[i] == ':')
			{
				int j = i + 1;
				while (input[j] != ';' && input[j] != '.')
				{
					G[input[i - 1] - 'A'].push_back(input[j++]);
				}
				i = j + 1;
			}
			else ++i;
		}

		cin >> f >> t >> m;

		DFS(f, t);
	}

	return 0;
}


/*void DFS()
{
	if (step && step % m == 0) cout << t << " ", candle[t - 'A'] = 1;

	for (auto& i : G[f - 'A'])
	{
		if (i != t && !candle[i - 'A'])
		{
			++step;
			t = f;
			f = i;
			DFS();
			return;
		}

	}

	cout << "/" << f << "\n";
}

int main()
{
	string s;

	while (cin >> s && s != "#")
	{
		cin >> f >> t >> m;
		G.assign(26, vector<char>());
		candle.assign(26, 0);

		for (int i = 0; i < s.size();)
		{
			if (s[i] == ':')
			{
				int j = i + 1;
				while (s[j] != ';' && s[j] != '.') G[s[i - 1] - 'A'].push_back(s[j++]);
				i = j + 1;
			}
			else ++i;
		}
		step = 0;

		DFS();
	}

	return 0;
}*/

/*
A:BCD;B:AD;D:BG;F:H;G:DEH;E:FGH;H:EG;C:AD. A C 3
#

D F G /E
*/

/* void DFS(vector<vector<char>> graph, char m, char t, int k, vector<int> candle, int steps)
{
    if (steps && steps % k == 0) cout << t << " ", candle[t - 'A'] = 1;

	auto& v = graph[m - 'A'];
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] != t && !candle[v[i] - 'A'])
		{
			++steps;
			DFS(graph, v[i], m, k, candle, steps);
			return;
		}
	}

	cout << "/" << m << endl;
}

int main()
{
	string s;

	while (cin >> s && s != "#")
	{
		int k;
		char m, t;

		cin >> m >> t >> k;

		vector<vector<char>> graph(26);

		for (int i = 0; i < s.size();)
		{
			if (s[i] == ':')
			{
				int j = i + 1;
				while (s[j] != ';' && s[j] != '.') graph[s[i - 1] - 'A'].push_back(s[j++]);
				i = j + 1;
			}
			else ++i;
		}

		int steps = 0;
		vector<int> candles(26);

		DFS(graph, m, t, k, candles, steps);
	}

	return 0;
}*/