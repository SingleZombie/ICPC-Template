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
#include <complex>

#define INF 0x3f3f3f3f
#define memset0(x) memset(x, 0, sizeof(x))
#define memsetM1(x) memset(x, -1, sizeof(x))
#define memsetINF(x) memset(x, INF, sizeof(x))

using namespace std;

const int MAXN = 40005;
const int MAXLOG = 20;

typedef pair<int, long long> pii;
vector<pii> graph[MAXN];
int rt;
int layer[MAXN];
pii pa[MAXN][MAXLOG]; // .first == 0 means not exist

int n, m;

void init()
{
	for (int i = 0; i < MAXN; i++)
	{
		graph[i].clear();
	}
	rt = 1;
}

pii goUp(int l, int step)
{
	pii res = make_pair(l, 0);
	while (step)
	{
		int lowbit = 1;
		int tmp = step;
		while (tmp)
		{
			if (tmp % 2 == 1)
			{
				break;
			}
			tmp /= 2;
		}
		res.second += pa[l][lowbit].second;
		res.first = pa[l][lowbit].first;
		step -= lowbit;
		l = pa[l][lowbit].first;
	}
	return res;
}

void getLayer(int u = rt, int pre = -1, int l = 1)
{
	layer[u] = l;
	for (int i = 0; i < graph[u].size(); i++)
	{
		int v = graph[u][i].first;
		if (v == pre)
		{
			continue;
		}
		pa[v][1] = make_pair(u, graph[u][i].second);
		for (int i = 2; i < MAXLOG; i++)
		{
			if (pa[v][i - 1].first)
			{
				int papa = pa[v][i - 1].first;
				if (pa[papa][i - 1].first)
				{
					pa[v][i] = make_pair(pa[papa][i - 1].first, 
						pa[papa][i - 1].second + pa[v][i - 1].second);
				}
				else
				{
					for (int j = i; j < MAXLOG; j++)
					{
						pa[v][i] = make_pair(0, 0);
					}
					break;
				}
			}
			else
			{
				for (int j = i; j < MAXLOG; j++)
				{
					pa[v][i] = make_pair(0, 0);
				}
				break;
			}
		}
		getLayer(v, u, l + 1);
	}
}

long long dis(int a, int b)
{
	long long ans = 0;
			if (layer[a] > layer[b])
			{
				swap(a, b);
			}
			pii tmp = goUp(b, layer[b] - layer[a]);
			ans += tmp.second;
			b = tmp.first;

			if (a == b)
			{
				printf("%lld\n", ans);
			}
			else
			{
				for (int i = MAXLOG - 1; i >= 0; i--)
				{
					if (pa[a][i].first == 0)
					{
						continue;
					}
					if (pa[a][i] != pa[b][i])
					{
						ans += pa[a][i].second + pa[b][i].second;
						a = pa[a][i].first;
						b = pa[b][i].first;
					}
				}
				for (int i = 0; i < MAXLOG; i++)
				{
					if (pa[a][i].first == 0)
					{
						continue;
					}
					if (pa[a][i] == pa[b][i])
					{
						ans += pa[a][i].second + pa[b][i].second;
						break;
					}
				}

				printf("%lld\n", ans);
			}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int startTime = clock();
#endif

	int t;
	scanf("%d", &t);
	while (t--)
	{
		init();
		scanf("%d%d", &n, &m);

		for (int i = 0; i < n - 1; i++)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			graph[u].push_back(make_pair(v, w));
			graph[v].push_back(make_pair(u, w));
		}

		getLayer();

		while (m--)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			
		}
	}


#ifndef ONLINE_JUDGE
	printf("Time = %dms\n", clock() - startTime);
#endif
	return 0;
}
