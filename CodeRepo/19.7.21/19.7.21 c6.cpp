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
//int cnt[256];
//
//int gcd(int a, int b)
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
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		char str[1005];
//		scanf("%s", str);
//		memset0(cnt);
//		for (int i = 0; i < n; i++)
//		{
//			cnt[str[i]]++;
//		}
//		int numer = cnt['a'] * cnt['v'] * cnt['i'] * cnt['n'];
//		int deno = n * n * n * n;
//		int g = gcd(numer, deno);
//		numer /= g;
//		deno /= g;
//		printf("%d/%d\n", numer, deno);
//	}
//
//
//#ifndef ONLINE_JUDGE
//	printf("Time = %dms\n", clock() - startTime);
//#endif
//	return 0;
//}
