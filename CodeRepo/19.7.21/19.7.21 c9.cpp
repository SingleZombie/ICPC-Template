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
//const int MAXN = 1005;
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
//		long long ans = 0;
//		for (int i = 0; i < n; i++)
//		{
//			long long a, b;
//			scanf("%lld.%lld", &a, &b);
//			if (b % 10 >= 5)
//			{
//				ans += 10 - b % 10;
//			}
//			else
//			{
//				ans -= b % 10;
//			}
//		}
//		if (ans < 0)
//		{
//			putchar('-');
//			ans = -ans;
//		}
//		printf("%lld.%03lld\n", ans / 1000, ans % 1000);
//	}
//
//
//#ifndef ONLINE_JUDGE
//	printf("Time = %dms\n", clock() - startTime);
//#endif
//	return 0;
//}
