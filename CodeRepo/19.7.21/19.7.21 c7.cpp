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
//const int MAXN = 2e3 + 5;
//bool vis[MAXN];
//int bs[MAXN];
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
//		memset0(vis);
//		for (int i = 0; i < n; i++)
//		{
//			int a;
//			scanf("%d", &a);
//			vis[a] = true;
//		}
//		for (int i = 0; i < m; i++)
//		{
//			scanf("%d", &bs[i]);
//		}
//		int ans = 1000;
//		for (int i = 0; i < 1000; i++)
//		{
//			bool yes = true;
//			for (int j = 0; j < m; j++)
//			{
//				if (vis[bs[j] + i])
//				{
//					yes = false;
//					break;
//				}
//			}
//			if (yes)
//			{
//				ans = i;
//				break;
//			}
//		}
//		printf("%d\n", ans);
//	}
//
//#ifndef ONLINE_JUDGE
//	printf("Time = %dms\n", clock() - startTime);
//#endif
//	return 0;
//}
