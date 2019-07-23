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
//using ll = long long;
//
//const ll MOD = 1e9 + 7;
//ll qpow(ll a, ll n)
//{
//	a %= MOD;
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
//ll inv(ll x)
//{
//	return qpow(x, MOD - 2);
//}
//const int MAXN = 1e6 + 5;
//ll tmp1s[MAXN], tmp2s[MAXN];
//
//int main()
//{
//#ifndef ONLINE_JUDGE
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
//	int startTime = clock();
//#endif
//	ll n;
//	while (cin >> n)
//	{
//		ll deno = 2 * n;
//		ll numer = 1 + n;
//		cout << numer * inv(deno) % MOD << endl;
//	}
//
//#ifndef ONLINE_JUDGE
//	printf("Time = %dms\n", clock() - startTime);
//#endif
//	return 0;
//}
