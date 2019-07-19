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
//const ll MOD = 1e9 + 7;
//const int MAXN = 1e5 + 5;
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
//
//const int DIG = 63;
//struct LinearBase
//{
//	int sz;
//	ll arr[DIG];
//	LinearBase()
//	{
//		sz = 0;
//		memset0(arr);
//	}
//	bool insert(ll x)
//	{
//		for (int i = DIG - 1; i >= 0; i--)
//		{
//			if (x & (1ll << i))
//			{
//				if (!arr[i])
//				{
//					arr[i] = x;
//					sz++;
//					return true;
//				}
//				else
//				{
//					x ^= arr[i];
//				}
//			}
//			
//		}
//		return false;
//	}
//};
//
//ll arr[MAXN];
//bool inBase[MAXN];
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
//		LinearBase b1, b2;
//		vector<ll> records;
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%lld", &arr[i]);
//			if (b1.insert(arr[i]))
//			{
//				inBase[i] = true;
//				records.push_back(arr[i]);
//			}
//			else
//			{
//				b2.insert(arr[i]);
//				inBase[i] = false;
//			}
//		}
//		ll ans = 0;
//		for (int i = 0; i < n; i++)
//		{
//			if (!inBase[i])
//			{
//				ans = (ans + qpow(2, n - b1.sz - 1)) % MOD;
//			}
//			else
//			{
//				LinearBase b3 = b2;
//				for (auto num : records)
//				{
//					if (num != arr[i])
//					{
//						b3.insert(num);
//					}
//				}
//				if (!b3.insert(arr[i]))
//				{
//					ans = (ans + qpow(2, n - b1.sz - 1)) % MOD;
//				}
//			}
//		}
//		printf("%lld\n", ans);
//	}
//
//#ifndef ONLINE_JUDGE
//	printf("Time = %dms\n", clock() - startTime);
//#endif
//	return 0;
//}
