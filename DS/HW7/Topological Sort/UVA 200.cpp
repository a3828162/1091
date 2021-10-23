/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=136
*/

#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

static auto __ = []
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	return 0;
}();

vector<int> visited, mem;
vector<vector<int>> G;
list<char> ans;

void DFS(int n)
{
	if (visited[n]) return;
	visited[n] = 1;
	for (auto& v : G[n])
	{
		if (!visited[v]) DFS(v);
	}

	ans.push_front(n + 'A');
}

int main()
{
	string s1, s2;
	
	G.assign(26, vector<int>());
	visited.assign(26, 0);
	mem.assign(26, 0);
	cin >> s1;
	while (cin >> s2 && s2 != "#")
	{
		int s = (int)min(s1.size(), s2.size());
		for (int i = 0; i < s; ++i)
		{
			if (mem[s1[i] - 'A'] == 0) mem[s1[i] - 'A'] = 1;
			if (mem[s2[i] - 'A'] == 0) mem[s2[i] - 'A'] = 1;
			
			if (s1[i] != s2[i])
			{
				G[s1[i] - 'A'].push_back(s2[i] - 'A');
				mem[s2[i] - 'A'] = 2;
				break;
			}
		}
		s1 = s2;
	}

	for (int i = 0; i < 26; ++i)
	{
		if (mem[i] == 1) DFS(i);
	}

	for (auto& i : ans) cout << i;
	cout << "\n";

	return 0;
}


/*void DFS(int u)
{
	if (visited[u]) return;
	visited[u] = 1;

	for (auto& i : G[u]) DFS(i);
	{
		if (!visited[i]) DFS(i);
	}

	ans.push_front(u + 'A');
}*/

/*int main()
{
	string s1, s2;

	cin >> s1;

	ans.clear();
	visited.assign(26, 0);
	mem.assign(26, 0);
	G.assign(26, vector<int>());

	while (cin >> s2 && s2 != "#")
	{
		int s = min(s1.size(), s2.size());

		for (int i = 0; i < s; ++i)
		{
			if (!mem[s1[i] - 'A']) mem[s1[i] - 'A'] = 1;
			if (!mem[s2[i] - 'A']) mem[s2[i] - 'A'] = 1;

			if (s1[i] != s2[i])
			{
				G[s1[i] - 'A'].push_back(s2[i] - 'A');
				mem[s2[i] - 'A'] = 2;
				break;
			}
		}
		s1 = s2;
	}

	for (int i = 0; i < 26; ++i) if (mem[i] == 1) DFS(i);

	for (auto& i : ans) cout << i;
	cout << "\n";

	return 0;
}*/

/*
XWY
ZX
ZXY
ZXW
YWWX
#

XZYW
*/

/*vector<int> g[26];
list<char> ret;
int visited[26] = {};

void DFS(int n)
{
	if (visited[n] == 1) return;
	visited[n] = 1;

	for (int i = 0; i < g[n].size(); ++i)
	{
		if (visited[g[n][i]] != 2) DFS(g[n][i]);
	}
	visited[n] = 2;

	ret.push_front(n + 'A');
}

int main()
{
	string s1, s2;
	cin >> s1;

	int mem[26] = {};
	while (cin >> s2 && s2 != "#")
	{
		int l = min(s1.size(), s2.size());
		for (int i = 0; i < l; ++i)
		{
			if (!mem[s1[i] - 'A']) mem[s1[i] - 'A'] = 1;
			if (!mem[s2[i] - 'A']) mem[s2[i] - 'A'] = 1;

			if (s1[i] != s2[i])
			{
				g[s1[i] - 'A'].push_back(s2[i] - 'A');
				mem[s2[i] - 'A'] = 2;
				break;
			}
		}
		s1 = s2;
	}

	for (int i = 0; i < 26; ++i) if (mem[i] == 1) DFS(i);

	for (auto it = ret.begin(); it != ret.end(); ++it) cout << *it;
	cout << endl;

	return 0;
}*/