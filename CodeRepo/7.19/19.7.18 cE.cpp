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

const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3fll;
#define memset0(x) memset(x, 0, sizeof(x))
#define memsetM1(x) memset(x, -1, sizeof(x))
#define memsetINF(x) memset(x, INF, sizeof(x))

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

const int MAXN = 4005;

ll dp[MAXN][MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int startTime = clock();
#endif
	int n, m;

	while (scanf("%d%d", &n, &m) != EOF)
	{
		int zero = 2000;
		for (int i = 0; i <= 2 * (n + m); i++)
		{
			memset0(dp[i]);
		}
		dp[0][zero] = 1;
		for (int i = 1; i <= 2 * (n + m); i++)
		{
			for (int j = zero - n; j <= zero + m; j++)
			{
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
			}
		}
		printf("%lld\n", dp[2 * (n + m)][zero]);
	}


#ifndef ONLINE_JUDGE
	printf("Time = %dms\n", clock() - startTime);
#endif
	return 0;
}
