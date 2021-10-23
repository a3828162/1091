/*
參考:     https://reurl.cc/LdroQy
          https://reurl.cc/EzlvmK
          https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=183
          
題目:     有一家電信公司記錄了所有人之間打電話的紀錄，他們想找出所有的通話圈圈(calling circles)舉例來說，如果A打給B，B打給C，C又打給A
          ，ABC之間就可以跟任何一個人互相溝通，他們就形成一個calling circle。但假如D可以打給A，但A不能打給D，D跟A就不算calling circle。

解題思路: 找出Strongly Connected Component(簡稱SCC)，SCC是只component內的任兩點之間雙方皆有路可通，一張有向圖的SCC不會互相重疊，
          做法是以dfs搜索每個點並編號(存在dfn陣列裡)，同時把每個搜過的點丟到一個stack中，假如遇到編號比自己小的(之前搜過的點)，
          就代表有環產生，此時會把這個值(能到達最前面的點)紀錄在low陣列裡，每做完一次dfs都要檢查下一個的low如果比自己小，自己的low也要更新。
          假如一個點x做完每條dfs而dfn仍然等於low(一開始是設為相等)，代表兩種情況：他不屬於一個環，或他是一個環中最前面的點，而這兩種情況其實
          都是強連接元件(只是第一個情況只有自己)。這時候就把存在stack中的點一個一個丟出來，直到丟出x，這些點就是一個強連接元件，也就是一個calling circle。

Code解釋: 待補

input:    輸入n,m，n是有幾個人，m是有幾個邊，邊的順序是前面打給後面的人
output:   輸出所有的SCC,也就是題目要的calling circles
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <unordered_set>
using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

map<string, int> dfn, low;
map<string, vector<string>> G;
stack<string> s;
unordered_set<string> instack;
int n, m, Time;

inline void init(int n)
{
    dfn.clear();
    G.clear();
    low.clear();
    Time = 0;
    instack.clear();
    while (!s.empty()) s.pop();
}

void DFS(string u)
{
    s.push(u);
    instack.insert(u);
    low[u] = dfn[u] = ++Time;

    for (auto& v : G[u])
    {
        if (dfn[v])
        {
            if (instack.count(v)) low[u] = min(low[u], dfn[v]);
            continue;
        }

        DFS(v);
        low[u] = min(low[u], low[v]);
    }

    if (dfn[u] == low[u])
    {
        while (1)
        {
            string tmp = s.top();
            s.pop();
            instack.erase(tmp);

            if (tmp == u)
            {
                cout << tmp << "\n";
                break;
            }
            else cout << tmp << ", ";
        }
    }

}

int main()
{
    int n, m, Case = 0;
    while (cin >> n >> m && (n || m))
    {
        init(n);
        string s1, s2;
        for (int i = 0; i < m; ++i)
        {
            cin >> s1 >> s2;
            G[s1].push_back(s2);
        }

        cout << "Calling circles for data set " << ++Case << ":\n";

        for (auto& [i, _] : G)
        {
            if (!dfn[i]) DFS(i);
        }
    }

    return 0;
}







/*void DFS(string n)
{
    dfn[n] = low[n] = ++Time;
    s.push(n);
    instack.insert(n);

    for (auto& i : G[n])
    {
        if (dfn[i])
        {
            if (instack.count(i)) low[n] = min(low[n], dfn[i]);
            continue;
        }

        DFS(i);
        low[n] = min(low[n], low[i]);
    }

    if (dfn[n] == low[n])
    {
        string tmp;
        while (1)
        {
            tmp = s.top();
            s.pop();
            instack.erase(tmp);
            cout << tmp;
            if (tmp != n) cout << ", ";
            else break;
        }
        cout << "\n";
    }
}

int main()
{
    int Case = 0;
    while (cin >> n >> m && (n || m))
    {
        init(n);

        string s1, s2;
        for (int i = 0; i < m; ++i)
        {
            cin >> s1 >> s2;
            G[s1].push_back(s2);
        }

        cout << "Calling circles for data set " << ++Case << ":" << "\n";

        for (auto& [i, _] : G)
        {
            if (!dfn[i]) DFS(i);
        }
    }

    return 0;
}*/

/*
5 6
Ben Alexander
Alexander Dolly
Dolly Ben
Dolly Benedict
Benedict Dolly
Alexander Aaron
14 34
John Aaron
Aaron Benedict
Betsy John
Betsy Ringo
Ringo Dolly
Benedict Paul
John Betsy
John Aaron
Benedict George
Dolly Ringo
Paul Martha
George Ben
Alexander George
Betsy Ringo
Alexander Stephen
Martha Stephen
Benedict Alexander
Stephen Paul
Betsy Ringo
Quincy Martha
Ben Patrick
Betsy Ringo
Patrick Stephen
Paul Alexander
Patrick Ben
Stephen Quincy
Ringo Betsy
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Quincy Martha
0 0

Calling circles for data set 1:
Ben, Alexander, Dolly, Benedict
Aaron
Calling circles for data set 2:
John, Betsy, Ringo, Dolly
Aaron
Benedict
Paul, George, Martha, Ben, Alexander, Stephen, Quincy, Patrick
*/

/*#include <map>
#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include<stack>

using namespace std;

map<string, int> Map;
string numToStr[30];

vector<int> edge[30];
int dfn[30], low[30];
vector<int> Stack;
bool inStack[30];

int dfs_clock, scc_cnt;
vector<int> scc_ans[30];

void Initial(int N);
void Tarjan(int cur);

int main()
{
    ios::sync_with_stdio(false);
    int N, M, Case = 0;
    while (cin >> N >> M && (N || M)) {
        Initial(N);

        // Input
        string name1, name2;
        for (int i = 0, index = 1; i < M; ++i) {
            cin >> name1 >> name2;
            if (!Map[name1]) { Map[name1] = index; numToStr[index++] = name1; }
            if (!Map[name2]) { Map[name2] = index; numToStr[index++] = name2; }
            edge[Map[name1]].push_back(Map[name2]);
        }

        // SCC
        for (int i = 1; i <= N; ++i)    //記得1~N都要確認過
            if (!dfn[i]) Tarjan(i);

        // Output
        if (Case != 0) cout << endl;
        cout << "Calling circles for data set " << ++Case << ":" << endl;
        for (int i = 0; i < scc_cnt; ++i) {
            for (int j = 0; j < scc_ans[i].size() - 1; ++j)
                cout << numToStr[scc_ans[i][j]] << ", ";
            cout << numToStr[scc_ans[i].back()] << endl;
        }
    }
}
void Initial(int N)
{
    for (int i = 0; i <= N; ++i) {
        edge[i].clear();
        scc_ans[i].clear();
        dfn[i] = low[i] = inStack[i] = 0;
    }
    Map.clear();
    Stack.clear();
    dfs_clock = scc_cnt = 0;
}
void Tarjan(int cur)
{
    dfn[cur] = low[cur] = ++dfs_clock;
    Stack.push_back(cur);
    inStack[cur] = true;

    for (int nxt : edge[cur]) {
        if (!dfn[nxt]) {
            Tarjan(nxt);
            low[cur] = min(low[cur], low[nxt]);
        }
        else if (inStack[nxt])
            low[cur] = min(low[cur], dfn[nxt]);
    }

    if (dfn[cur] == low[cur]) {
        int nxt;
        do {
            nxt = Stack.back();
            scc_ans[scc_cnt].push_back(nxt);
            Stack.pop_back();
            inStack[nxt] = false;
        } while (cur != nxt);
        ++scc_cnt;
    }
}*/