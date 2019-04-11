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

const int MAXN = 305;

int money[MAXN][MAXN];
int exLeft[MAXN];
int exRight[MAXN];
bool visLeft[MAXN];
bool visRight[MAXN];
int match[MAXN];
int slack[MAXN];

int n;

bool dfs(int left)
{
	visLeft[left] = true;

	for (int i = 0; i < n; i++)
	{
		if (visRight[i])
		{
			continue;
		}
		int gap = exLeft[left] + exRight[i] - money[left][i];
		if (gap == 0)
		{
			visRight[i] = true;
			if (match[i] == -1 || dfs(match[i]))
			{
				match[i] = left;
				return true;
			}
		}
		else
		{
			slack[i] = min(slack[i], gap);
		}
	}

	return false;
}

int km()
{
	memsetM1(match);
	memset0(exRight);
	memset0(exLeft);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			exLeft[i] = max(exLeft[i], money[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		memsetINF(slack);

		while (true)
		{
			memset0(visLeft);
			memset0(visRight);

			if (dfs(i))
			{
				break;
			}

			int d = INF;
			for (int j = 0; j < n; j++)
			{
				if (!visRight[j])
				{
					d = min(d, slack[j]);
				}
			}

			for (int j = 0; j < n; j++)
			{
				if (visLeft[j])
				{
					exLeft[j] -= d;
				}
				if (visRight[j])
				{
					exRight[j] += d;
				}
				else
				{
					slack[j] -= d;
				}
			}
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		res += money[match[i]][i];
	}

	return res;
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &money[i][j]);
			}
		}

		printf("%d\n", km());
	}

	cin.get();
	cin.get();
	return 0;
}
