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
//const int MAXN = 1e3 + 5;
//
//typedef long long ll;
//ll gcd(ll a, ll b)
//{
//	return b == 0 ? a : gcd(b, a % b);
//}
//
//int arr[MAXN];
//int main()
//{
//#ifndef ONLINE_JUDGE
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
//	int startTime = clock();
//#endif
//	ll n, m;
//	while (scanf("%lld%lld", &n, &m) != EOF)
//	{
//		ll lcm = 1;
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", &arr[i]);
//			lcm = lcm * arr[i] / gcd(lcm, arr[i]);
//		}
//		ll cnt = 0;
//		for (int i = 0; i < n; i++)
//		{
//			cnt += lcm / arr[i];
//		}
//		if (m % cnt != 0)
//		{
//			puts("No");
//		}
//		else
//		{
//			puts("Yes");
//			for (int i = 0; i < n; i++)
//			{
//				if (i > 0)
//				{
//					putchar(' ');
//				}
//				printf("%lld", lcm / arr[i] * (m / cnt));
//			}
//			putchar('\n');
//		}
//	}
//
//#ifndef ONLINE_JUDGE
//	printf("Time = %dms\n", clock() - startTime);
//#endif
//	return 0;
//}
