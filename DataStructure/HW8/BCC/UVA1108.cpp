/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3549

參考:     https://reurl.cc/3LE9eR

題目:     礦工在工作的時候為了避免礦洞崩塌所以會設置逃生通道(也就是安全點), 請你找出最少需要幾個安全點跟設置安全點的方法數

解題思路: 找出BCC(Biconnected Component), BCC指的是一個component裡面不存在割點, 若一張圖裡有多個BCC,重疊的部分就是割點,
          把一個BCC視為一個點, 割點也視為一個點,可以把一張圖縮減成Block Cutpoint Tree, 像測資一中, 1 4是一個BCC, 1 2 3 5 6
          也是一個BCC, 因此重疊的1就是割點, 在此題中把BCC當作礦脈BCC中的每個點都看成一個洞, 割點則視為中繼站, 若一個BCC
          連結到兩個以上的割點, 不需要設置安全點, 因為無論哪個點(包括割點)崩塌都可以從其中一個割點逃到另一個BCC的安全點,
          而如果只有一個割點, 則需要在BCC中任意設置一個安全點, 避免割點崩塌導致工人逃不出去, 而若是整張圖就是一個BCC,
          則需要設置兩個安全點, 避免其中一個安全點崩塌而逃不出去    

Code解釋: 用給的測資先建圖, 用tarjan找cutpoint, 接著在DFS裡找出這個BCC裡有幾個點跟連接幾個cut point, 如果BCC連結到
          兩個以上的cut point, 就算其中一個cutpoint崩塌也可以透過其他cutpoint到其他BCC裡的安全點, 如果BCC只有連接到
          一個cut point, 則需要在BCC裡面設置一個安全點,避免cut point崩塌, 所以設置安全點的可能數就是每個BCC中點的個數相乘, 
          而如果圖沒有cut point則至少需要設置兩個安全點, 方法數是BCC.size()*(BCC.size()-1)/2,

input:    n代表有幾個連通的邊,0代表程式結束
output:   輸出最少需要幾個安全點跟設置安全點的方法數
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
};

map<int, vector<int>> G;
map<int, int> dfn, low;
int Time, comS;
unordered_set<int> visited, iscut, comcut;

inline void init(int n)
{
    G.clear();
    dfn.clear();
    low.clear();
    Time = 0;
    visited.clear();
    iscut.clear();
}

void DFS(int u, int parent)
{
    int child = 0;
    low[u] = dfn[u] = ++Time;

    for (auto& v : G[u])
    {
        if (dfn[v]) 
        {
            if (parent != v) low[u] = min(low[u], dfn[v]);
            continue;
        }

        ++child;
        DFS(v, u);
        low[u] = min(low[u], low[v]);

        if (low[v] >= dfn[u] && (child >= 2 || parent != -1)) iscut.insert(u);
    }
}

void findbcc(int u)
{
    visited.insert(u);
    ++comS;

    for (auto& v : G[u])
    {
        if (visited.count(v) || iscut.count(v))
        {
            if (iscut.count(v)) comcut.insert(v);
            continue;
        }
        findbcc(v);
    }
}

int main()
{
    int n, Case = 0;
    while (cin >> n && n)
    {
        init(n);
        int x, y;

        for (int i = 0; i < n; ++i)
        {
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        for (auto&[i,_]:G)
        {
            if (!dfn[i]) DFS(i, -1);
        }

        vector<int> D;
        for (auto& [i, _] : G)
        {
            comcut.clear();
            comS = 0;
            if (!visited.count(i)&&!iscut.count(i)) findbcc(i);

            if (comcut.size() == 1) D.push_back(comS);
        }

        long long ways = 1, mn = D.size();

        for (auto& i : D)ways *= i;

        if (D.size() == 0) mn = 2, ways = (G.size() * (G.size() - 1)) / 2;

        cout << "Case " << ++Case << ": " << mn << " " << ways << "\n";
    }

    return 0;
}








/*void DFS(int n, int parent)
{
    int child = 0;
    dfn[n] = low[n] = ++Time;

    for (auto& i : G[n])
    {
        if (dfn[i])
        {
            if (i != parent) low[n] = min(low[n], dfn[i]);
            continue;
        }

        ++child;
        DFS(i, n);
        low[n] = min(low[n], low[i]);

        if (low[i] >= dfn[n] && (child >= 2 || parent != -1)) iscut.insert(n);
    }
}

void findBCC(int u)
{
    visited.insert(u);
    ++comS;

    for (auto& v : G[u])
    {
        if (visited.count(v) || iscut.count(v))
        {
            if (iscut.count(v)) comcut.insert(v);
            continue;
        }

        findBCC(v);
    }

}

int main()
{
    int n, Case = 0;

    while (cin >> n && n)
    {
        init(n);
        int x, y;
        for (int i = 0; i < n; ++i)
        {
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        for (auto& [i, _] : G) if (!dfn.count(i)) DFS(i, -1);

        vector<int> D;
        for (auto& [i, _] : G)
        {
            if (visited.count(i) || iscut.count(i)) continue;

            comS = 0;
            comcut.clear();
            findBCC(i);

            if (comcut.size() == 1) D.push_back(comS);
        }

        long long ways = 1, mn = D.size();

        for (auto& i : D) ways *= i;

        if (D.empty()) mn = 2, ways = (long long)G.size() * (long long)(G.size() - 1) / 2;

        cout << "Case " << ++Case << ": " << mn << " " << ways << "\n";
    }

    return 0;
}*/

/*
9
1 3
4 1
3 5
1 2
2 6
1 5
6 3
1 6
3 2
6
1 2
1 3
2 4
2 5
3 6
3 7
0

Case 1: 2 4
Case 2: 4 1
*/

/*#include<iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define MAXN 65536

vector<int> g[MAXN];
int visited[MAXN], time, back[MAXN], depth[MAXN];
int cutPoint[MAXN];

void tarjan(int u, int p, int root) {
    back[u] = depth[u] = ++time;
    visited[u] = 1;
    int child = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!visited[v]) {
            tarjan(v, u, root);
            back[u] = min(back[u], back[v]);
            child++;
            if ((u == root && child > 1) || (u != root && back[v] >= depth[u]))
                cutPoint[u]++;
        }
        else if (v != p) {
            back[u] = min(back[u], depth[v]);
        }
    }
}

set<int> adjCutPt;
int comSize = 0;
void dfs(int u) {
    visited[u] = 1, comSize++; //找出component內有幾個點
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i]; 
        if (cutPoint[v]) 	adjCutPt.insert(v);
        if (cutPoint[v] || visited[v])
            continue;
        dfs(v);
    }
}
int main(){
    int n, m, x, y;
    int cases = 0;
    while (cin >> m&& m) {
        int used[MAXN] = {}, usedn = 0; //usedn是點的個數
        fill(g, g + MAXN, vector<int>());
        n = 0;

        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            n = max(n, max(x, y));
            used[--x] = used[--y] = 1;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        for (auto& i : used) usedn += i; //有幾個node
        time = 0;
        fill(visited, visited + MAXN, 0);
        fill(cutPoint, cutPoint + MAXN, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i] && used[i])
                tarjan(i, -1, i);
        }

        vector<int> D;
        fill(visited, visited + MAXN, 0);

        for (int i = 0; i < n; i++)
            if (!visited[i] && !cutPoint[i]) {
                comSize = 0, adjCutPt.clear();
                dfs(i);
                if (adjCutPt.size() == 1) //如果component只有連結一個cut point才需要計算
                    D.push_back(comSize);
            }

        long long ways = 1, mn = D.size();
        for (int i = 0; i < D.size(); i++)
            ways *= D[i];
        if (D.size() == 0)	ways = (long long) usedn * (usedn - 1) / 2, mn = 2;
        cout << "Case " << ++cases << ": " << mn << " " << ways << endl;
    }
    return 0;
}*/
