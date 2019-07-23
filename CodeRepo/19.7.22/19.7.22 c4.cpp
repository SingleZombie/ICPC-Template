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
//int lens[MAXN], stop[MAXN], vs[MAXN];
//
//int main()
//{
//#ifndef ONLINE_JUDGE
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
//	int startTime = clock();
//#endif
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		n++;
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", &lens[i]);
//		}
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", &stop[i]);
//		}
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", &vs[i]);
//		}
//		double ans = 0;
//		long long sum = 0;
//		for (int i = 0; i < n; i++)
//		{
//			if (i > 0)
//			{
//				sum += lens[i];
//			}
//			ans = max(ans, (sum + stop[i]) * 1.0 / vs[i]);
//		}
//		printf("%.10lf\n", ans);
//	}
//
//#ifndef ONLINE_JUDGE
//	printf("Time = %dms\n", clock() - startTime);
//#endif
//	return 0;
//}
