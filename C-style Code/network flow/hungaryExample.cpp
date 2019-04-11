#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>
#include <map>
#include <set>
#include <bitset>
#include <ctime>

#define INF 0x3f3f3f3f
#define memset0(x) memset(x, 0, sizeof(x))
#define memsetM1(x) memset(x, -1, sizeof(x))
#define memsetINF(x) memset(x, INF, sizeof(x))

using namespace std;

const int MAXN = 505;

bool graph[MAXN][MAXN];

bool vis[MAXN];
int match[MAXN];

int n, m, k;

void init()
{
	memset0(graph);
	memsetM1(match);
}

bool dfs(int u)
{
	for (int v = 1; v <= m; v++)
	{
		if (graph[u][v])
		{
			if (vis[v])
			{
				continue;
			}
			vis[v] = true;

			if (match[v] == -1 || dfs(match[v]))
			{
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}

int hungary()
{
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		memset0(vis);
		if (dfs(i))
		{
			res++;
		}
	}
	
	return res;
}

int main()
{
	while (scanf("%d", &k) != EOF)
	{
		if (k == 0)
		{
			break;
		}
		scanf("%d%d", &n, &m);
		init();

		for (int i = 0; i < k; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);

			graph[u][v] = 1;
		}

		int ans = hungary();

		printf("%d\n", ans);
	}

	cin.get();
	cin.get();
	return 0;
}
