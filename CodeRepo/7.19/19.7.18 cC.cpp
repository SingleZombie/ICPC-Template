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
//const int MAXN = 1e4 + 5;
//int n, m;
//using ll = long long;
//ll arr[MAXN];
//
//ll gcd(ll a, ll b)
//{
//	return b == 0 ? a : gcd(b, a % b);
//}
//
//int main()
//{
//#ifndef ONLINE_JUDGE
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
//	int startTime = clock();
//#endif
//	while (scanf("%d%d", &n, &m) != EOF)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%lld", &arr[i]);
//		}
//		sort(arr, arr + n, greater<ll>());
//
//		ll lft = m;
//		ll lastI = 0;
//		ll deno = m * m;
//		ll numer = 0;
//		for (int i = 1; i < n; i++)
//		{
//			ll need = i * (arr[i - 1] - arr[i]);
//			if (lft >= need)
//			{
//				lft -= need;
//				lastI++;
//			}
//			else
//			{
//				break;
//			}
//		}
//		ll v = arr[lastI];
//		numer = lft * lft - 2 * lft * v * (lastI + 1) + v * v * (lastI + 1) * (lastI + 1);
//		deno *= (lastI + 1);
//		for (int i = lastI + 1; i < n; i++)
//		{
//			numer += arr[i] * arr[i] * (lastI + 1);
//		}
//
//		ll g = gcd(numer, deno);
//		deno /= g;
//		numer /= g;
//		printf("%lld", numer);
//		if (deno != 1 && numer != 0)
//		{
//			printf("/%lld", deno);
//		}
//		putchar('\n');
//	}
//
//
//#ifndef ONLINE_JUDGE
//	printf("Time = %dms\n", clock() - startTime);
//#endif
//	return 0;
//}
