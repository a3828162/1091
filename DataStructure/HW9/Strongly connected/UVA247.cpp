/*
�Ѧ�:     https://reurl.cc/LdroQy
          https://reurl.cc/EzlvmK
          https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=183
          
�D��:     ���@�a�q�H���q�O���F�Ҧ��H�������q�ܪ������A�L�̷Q��X�Ҧ����q�ܰ��(calling circles)�|�Ҩӻ��A�p�GA����B�AB����C�AC�S����A
          �AABC�����N�i�H�����@�ӤH���۷��q�A�L�̴N�Φ��@��calling circle�C�����pD�i�H����A�A��A���ॴ��D�AD��A�N����calling circle�C

���D���: ��XStrongly Connected Component(²��SCC)�ASCC�O�ucomponent���������I��������Ҧ����i�q�A�@�i���V�Ϫ�SCC���|���ۭ��|�A
          ���k�O�Hdfs�j���C���I�ýs��(�s�bdfn�}�C��)�A�P�ɧ�C�ӷj�L���I���@��stack���A���p�J��s����ۤv�p��(���e�j�L���I)�A
          �N�N�������͡A���ɷ|��o�ӭ�(���F�̫e�����I)�����blow�}�C�̡A�C�����@��dfs���n�ˬd�U�@�Ӫ�low�p�G��ۤv�p�A�ۤv��low�]�n��s�C
          ���p�@���Ix�����C��dfs��dfn���M����low(�@�}�l�O�]���۵�)�A�N���ر��p�G�L���ݩ�@�����A�ΥL�O�@�������̫e�����I�A�ӳo��ر��p���
          ���O�j�s������(�u�O�Ĥ@�ӱ��p�u���ۤv)�C�o�ɭԴN��s�bstack�����I�@�Ӥ@�ӥ�X�ӡA�����Xx�A�o���I�N�O�@�ӱj�s������A�]�N�O�@��calling circle�C

Code����: �ݸ�

input:    ��Jn,m�An�O���X�ӤH�Am�O���X����A�䪺���ǬO�e�������᭱���H
output:   ��X�Ҧ���SCC,�]�N�O�D�حn��calling circles
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
        for (int i = 1; i <= N; ++i)    //�O�o1~N���n�T�{�L
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