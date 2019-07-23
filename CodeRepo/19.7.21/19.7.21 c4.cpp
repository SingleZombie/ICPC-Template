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
//const int MAXN = 1e5 + 5;
//const int MAXM = 1e2 + 5;
//
//int maxv[MAXM][MAXM];
//
//int arr[MAXN];
//
//int main()
//{
//#ifndef ONLINE_JUDGE
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
//	int startTime = clock();
//#endif
//	int n, m;
//	while (scanf("%d%d", &n, &m) != EOF)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			scanf("%d", &arr[i]);
//		}
//		for (int i = 1; i <= m; i++)
//		{
//			memset0(maxv[i]);
//		}
//		int ans = 1;
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= m; j++)
//			{
//				if (j == arr[i])
//				{
//					continue;
//				}
//				maxv[arr[i]][j] = maxv[j][arr[i]] + 1;
//				ans = max(ans, maxv[arr[i]][j]);
//			}
//		}
//		printf("%d\n", ans);
//	}
//
//
//#ifndef ONLINE_JUDGE
//	printf("Time = %dms\n", clock() - startTime);
//#endif
//	return 0;
//}
