/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=813

#特別注意NO都是大寫^^ 且getline要放在while裡面
*/

#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;

static auto __ = []
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	return 0;
}();

bool track;
vector<vector<int>> G;
vector<bool> visited;
string S;

void DFS(string ans)
{
	if (ans.size() == S.size())
	{
		cout << ans[0];
		for (int i = 1; i < ans.size(); ++i) cout << " " << ans[i];
		cout << "\n";
		track = true;
		return;
	}

	for (auto& i : S)
	{
		if (visited[i - 'A']) continue;

		//for (int j = 0; j < ans.size(); ++j)
	//	{
		//	if (G[i - 'A'][ans[j] - 'A']) return;
		//}
		for (auto& j : ans)
		{
			if (G[i - 'A'][j - 'A']) return;
		}

		visited[i - 'A'] = 1;
		DFS(ans + i);
		visited[i - 'A'] = 0;
	}
}

int main()
{
	int T;
	cin >> T;
	string str;
	cin.ignore();
	while (T--)
	{
		G.assign(26, vector<int>(26));
		visited.assign(26, false);
		S.clear();
		track = false;

		getline(cin, str);
		getline(cin, str);
		stringstream ss(str);
		string tmp;
		while (ss >> tmp) S += tmp;
		sort(begin(S), end(S));

		getline(cin, str);
		ss.clear();
		ss.str(str);
		while (ss >> tmp)
		{
			G[tmp[0] - 'A'][tmp[2] - 'A'] = 1;
		}

		DFS("");

		if (!track) cout << "NO\n";
		if (T) cout << "\n";
	}

	return 0;	
}



/*void DFS(string ans)
{
	if (ans.size() == S.size())
	{
		cout << ans[0];
		for (int i = 1; i < ans.size(); ++i) cout << " " << ans[i];
		cout << "\n";
		track = true;
		return;
	}

	for (auto& i : S)
	{
		if (visited[i - 'A']) continue;

		for (int j = 0; j < ans.size(); ++j)
		{
			if (G[i - 'A'][ans[j] - 'A']) return;
		}

		visited[i - 'A'] = 1;
		DFS(ans + i);
		visited[i - 'A'] = 0;
	}

}

int main()
{
	int T;
	cin >> T;
	cin.ignore();
	string str;

	while (T--)
	{
		G.assign(26, vector<int>(26));
		visited.assign(26, false);
		S.clear();
		track = false;

		getline(cin, str);
		getline(cin, str);
		stringstream ss(str);
		string tmp;
		while (ss >> tmp) S += tmp;
		sort(S.begin(), S.end());

		getline(cin, str);
		ss.clear();
		ss.str(str);

		while (ss >> tmp) G[tmp[0] - 'A'][tmp[2] - 'A'] = 1;

		DFS("");

		if (!track) cout << "NO\n";
		if (T) cout << "\n";
	}

	return 0;
}*/

/*
1

A B F G
A<B B<F

A B F G
A B G F
A G B F
G A B F
*/
