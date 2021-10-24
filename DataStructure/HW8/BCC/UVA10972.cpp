/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1913

參考:     https://reurl.cc/5qWzyv

題目:     每個城市都需要兩條以上的道路來連結其他城市, 避免其中一條道路修理的時候出不去, 求最少需要修建幾條道路

解題思路: 先找出Bridge-Connected Component(這裡簡稱BCC), BCC指的是一個component裡面不會產生bridge, BCC裡的兩個點之間至少有兩條路徑可以到達,
          我們把BCC縮減成一個點簡化, 題目要求我們找每個城市最少有兩條路到其他城市要修建幾條路, 因此只需要找出讓BCC之間最少有兩條路可以走的最少道路量
          先用一個res去找出每個BCC缺少的數量, 最少道路量的算式是(res+1)/2

Code解釋: 先建立無向圖, 用DFS找出BCC的數量, 如果只有一個BCC則不需要修建道路, 接著找這個BCC連接到幾個不同的BCC, 也就是low不一樣的, 同個BCC間low都一樣
          再找出BCC連接數少於2的BCC的數量, 接著再去最少需要的數量

input:    第一行輸入n,m, n代表有幾個node, m代表有接下來有m列, 每一列都是一條線
output:   輸出需要修建的道路數量
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

vector<vector<int>> G;
vector<int> dfn, low;
int bcn, Time;

inline void init(int n)
{
    G.assign(n + 1, vector<int>());
    dfn.assign(n + 1, 0);
    low.assign(n + 1, 0);
    bcn = Time = 0;
}

void DFS(int u, int parent)
{
    dfn[u] = low[u] = ++Time;

    for (auto& v : G[u])
    {
        if (dfn[v])
        {
            if (v != parent) low[u] = min(low[u], dfn[v]);
            continue;
        }

        DFS(v, u);
        low[u] = min(low[u], low[v]);

        if (low[v] > dfn[u]) ++bcn;
    }

}

void solve(int n)
{
    if (bcn == 1)
    {
        cout << "0\n";
        return;
    }

    map<int, int> m;

    for (int u = 1; u <= n; ++u)
    {
        m[low[u]] += 0;

        for (auto& v : G[u])
        {
            if (low[u] != low[v]) ++m[low[u]];
        }
    }
    int ret = 0;

    for (auto& [l, r] : m)
    {
        if (r == 0) ret += 2;
        else if (r == 1) ++ret;
    }

    cout << (ret + 1) / 2 << "\n";
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        init(n);
        int x, y;
        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        for (int i = 1; i <= n; ++i) if (!dfn[i]) DFS(i, -1), ++bcn;

        solve(n);
    }

    return 0;
}




/*void DFS(int n, int parent)
{
    dfn[n] = low[n] = ++Time;

    for (auto& i : G[n])
    {
        if (dfn[i])
        {
            if (i != parent) low[n] = min(low[n], dfn[i]);
            continue;
        }

        DFS(i, n);
        low[n] = min(low[n], low[i]);

        if (low[i] > dfn[n]) ++bcn;
    }
}

void solve(int n)
{
    if (bcn == 1)
    {
        cout << 0 << "\n";
        return;
    }

    map<int, int> m;

    for (int u = 1; u <= n; ++u)
    {
        m[low[u]] += 0;
        for (auto& i : G[u])
        {
            if (low[u] != low[i]) ++m[low[u]];
        }
    }

    int ret = 0;

    for (auto& [_, re] : m)
    {
        if (re == 0) ret += 2;
        else if (re == 1) ++ret;
    }

    cout << (ret + 1) / 2 << "\n";
}

int main()
{
    int n, m;

    while (cin >> n >> m)
    {
        init(n);

        int x, y;
        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        for (int i = 1; i <= n; ++i)
        {
            if (!dfn[i])
            {
                DFS(i, -1);
                ++bcn;
            }
        }

        solve(n);
    }

    return 0;
}*/

/*
3 2
1 2
2 3
10
11
1 2
2 3
3 1
3 7
4 5
5 6
6 4
7 9
6 3
9 8
7 8

1
2
*/

/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include<algorithm>
using namespace std;
#define N 1010

int n, tot;
int dfn[N], low[N], vis[N], de[N], dcnt, bcnt;
vector<int>e[N];

void init()
{
    dcnt = bcnt = 0;
    for (int i = 1; i <= n; i++)
    {
        dfn[i] = 0;
        e[i].clear();
        vis[i] = de[i] = 0;
    }
}

void dfs(int u, int fa)
{
    dfn[u] = low[u] = ++dcnt;
    vis[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == fa) continue;
        if (!vis[v]) //树边
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) //找到一个桥,新增一个连通分量
                bcnt++;
        }
        else if (vis[v] == 1) //后向边i
            low[u] = min(low[u], dfn[v]);
    }
}

void solve()
{
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            dfs(i, -1);
            bcnt++;
        }

    if (bcnt == 1) //整个图本身就是个双连通分量
    {
        cout << 0 << endl; return;
    }

    bool used[N];
    memset(used, false, sizeof(used));
    for (int i = 1; i <= n; i++)
    {
        if (e[i].size() == 0) //孤立点，它自身形成一个连通分量
        {
            used[low[i]] = true; continue;
        }

        for (int j = 0; j < e[i].size(); j++)
        {
            int u = i;
            int v = e[i][j];
            used[low[u]] = used[low[v]] = true;
            if (low[u] != low[v]) //不同的连通分量
                de[low[u]]++;
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)  //扫描缩点后每个点的度
        if (used[i] && de[i] == 0) //度为0即孤立点
            res += 2;
        else if (de[i] == 1) //叶子
            res++;
    cout << (res + 1) / 2 << endl;
}

int main()
{
    while (cin >> n >> tot)
    {
        init();
        while (tot--)
        {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
            //偷懒直接用vector建图不用静态链表了
        }
        solve();
    }
    return 0;
}*/

/*#include<iostream>
#include<algorithm>
#define ll long long
#define pb push_back
using namespace std;
const int maxn = 1005;
int to[maxn * 1000], ne[maxn * 1000], num, dc, uu, vv, K, ans;
int hd[maxn], n, m, col[maxn], dfn[maxn], low[maxn], D[maxn];
bool ban[maxn * 1000];
inline void add(int x, int y) { to[++num] = y, ne[num] = hd[x], hd[x] = num; }

inline void init() {
	fill(ban, ban + num + 1, 0), num = 1;
	memset(hd, 0, sizeof(hd)), ans = 0;
	memset(col, 0, sizeof(col));
	memset(dfn, 0, sizeof(dfn));
	memset(D, 0, sizeof(D));
}

void dfs(int x, int fa) {
	dfn[x] = low[x] = ++dc;
	for (int i = hd[x]; i; i = ne[i]) {
		if (to[i] == fa) continue;
		if (!dfn[to[i]]) {
			dfs(to[i], x), low[x] = min(low[x], low[to[i]]);
			if (low[to[i]] > dfn[x]) ban[i] = ban[i ^ 1] = 1;
		}
		else low[x] = min(low[x], dfn[to[i]]);
	}
}

void Search(int x) {
	col[x] = K;
	for (int i = hd[x]; i; i = ne[i]) if (!ban[i] && !col[to[i]]) Search(to[i]);
}

inline void calc() {
	for (int i = 0; i <= num; i++) if (ban[i]) D[col[to[i]]]++;
	for (int i = 1; i <= K; i++) if (D[i] < 2) ans += 2 - D[i];
}

int main() {
	while (cin >> n >> m) {
		init(), dc = K = 0;
		for (int i = 1; i <= m; i++) cin >> uu >> vv , add(uu, vv), add(vv, uu);
		for (int i = 1; i <= n; i++) if (!dfn[i]) dfs(i, -1);
		for (int i = 1; i <= n; i++) if (!col[i]) K++, Search(i);
		if (K == 1) puts("0");
		else calc(), printf("%d\n", (ans + 1) >> 1);
	}
	return 0;
}*/