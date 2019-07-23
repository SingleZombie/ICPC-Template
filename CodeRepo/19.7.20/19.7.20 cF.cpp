//#include <iostream>
//#include <vector>
//#include <cstdio>
//#include <algorithm>
//#include <cmath>
//#include <cstdlib>
//#include <string>
//#include <cstring>
//#include <queue>
//#include <stack>
//#include <functional>
//#include <map>
//#include <set>
//#include <bitset>
//#include <ctime>
//#include <complex>
//
//const int INF = 0x3f3f3f3f;
//const long long INFLL = 0x3f3f3f3f3f3f3f3fll;
//#define memset0(x) memset(x, 0, sizeof(x))
//#define memsetM1(x) memset(x, -1, sizeof(x))
//#define memsetINF(x) memset(x, INF, sizeof(x))
//
//using namespace std;
//
//const int MAXN = 30;
//int v[MAXN][MAXN];
//int arr1[MAXN], arr2[MAXN];
//
//using ll = long long;
//ll ans;
//int n;
//
//void dfs(int i = 0, int sum1 = 0, int sum2 = 0, ll cAns = 0)
//{
//	if (cAns > ans)
//	{
//		ans = cAns;
//	}
//	if (i + 1 <= 2 * n)
//	{
//		ll tmp = 0;
//		if (sum1 + 1 <= n)
//		{
//			for (int j = 0; j < sum2; j++)
//			{
//				tmp += v[i][arr2[j]];
//			}
//			arr1[sum1] = i;
//			dfs(i + 1, sum1 + 1, sum2, cAns + tmp);
//		}
//		tmp = 0;
//		if (sum2 + 1 <= n)
//		{
//			for (int j = 0; j < sum1; j++)
//			{
//				tmp += v[arr1[j]][i];
//			}
//			arr2[sum2] = i;
//			dfs(i + 1, sum1, sum2 + 1, cAns + tmp);
//		}
//	}
//	
//}
//
//int main()
//{
//#ifndef ONLINE_JUDGE
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
//	int startTime = clock();
//#endif
//	scanf("%d", &n);
//	for (int i = 0; i < 2 * n; i++)
//	{
//		for (int j = 0; j < 2 * n; j++)
//		{
//			scanf("%d", &v[i][j]);
//		}
//	}
//	dfs();
//	printf("%lld\n", ans);
//
//#ifndef ONLINE_JUDGE
//	printf("Time = %dms\n", clock() - startTime);
//#endif
//	return 0;
//}
