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
//using ll = long long;
//const ll MOD = 1e9 + 7;
//ll arr[MAXN];
//ll numer[MAXN];
//ll qpow(ll a, ll n)
//{
//	ll res = 1;
//	for (; n; n >>= 1)
//	{
//		if (n & 1)
//		{
//			res = res * a % MOD;
//		}
//		a = a * a % MOD;
//	}
//	return res;
//}
//ll inv(ll a)
//{
//	return qpow(a, MOD - 2);
//}
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
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", &arr[i]);
//		}
//		ll ans = 0;
//		for (int i = 0; i < n; i++)
//		{
//			numer[i] = arr[i];
//			for (int j = 0; j < n; j++)
//			{
//				if (i == j)
//				{
//					continue;
//				}
//				ll tmp = arr[j] * arr[j] % MOD - arr[i] * arr[i] % MOD;
//				numer[i] = (numer[i] * (tmp + MOD) % MOD) % MOD;
//			}
//			ans = (ans + inv(numer[i] % MOD)) % MOD;
//		}
//		ans = ans * inv(2) % MOD;
//		printf("%lld\n", ans);
//	}
//
//#ifndef ONLINE_JUDGE
//	printf("Time = %dms\n", clock() - startTime);
//#endif
//	return 0;
//}
