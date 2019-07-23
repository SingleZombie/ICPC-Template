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
//const int MAXN = 1e6 + 5;
//const int DIG = 30;
//
//int nums[MAXN];
//int b[MAXN][DIG], p[MAXN][DIG];
//
//void add(int x, int k, int r) {
//	for (int i = DIG - 1; i >= 0; i--)
//		if ((x >> i) & 1) {
//			if (!b[r][i]) {
//				b[r][i] = x;
//				p[r][i] = k;
//				return;
//			}
//			if (p[r][i] < k) {
//				swap(p[r][i], k);
//				swap(x, b[r][i]);
//			}
//			x ^= b[r][i];
//		}
//}
//
//int work(int l, int r) {
//	int ans = 0;
//	for (int i = DIG - 1; i >= 0; i--)
//		if (p[r][i] >= l) ans = max(ans, ans ^ b[r][i]);
//	return ans;
//}
//
//int main()
//{
//#ifndef ONLINE_JUDGE
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
//	int startTime = clock();
//#endif
//	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int n, m;
//		scanf("%d%d", &n, &m);
//
//		for (int i = 1; i <= n; i++)
//		{
//			scanf("%d", &nums[i]);
//			memcpy(b[i], b[i - 1], sizeof(b[i]));
//			memcpy(p[i], p[i - 1], sizeof(p[i]));
//			add(nums[i], i, i);
//		}
//		int nm = n + m;
//		int cIndex = n;
//		
//		int lastAns = 0;
//		while (m--)
//		{
//			int op;
//			scanf("%d", &op);
//			if (op == 0)
//			{
//				int l, r;
//				scanf("%d%d", &l, &r);
//				l = (l ^ lastAns) % cIndex + 1;
//				r = (r ^ lastAns) % cIndex + 1;
//				if (l > r)
//				{
//					swap(l, r);
//				}
//				lastAns = work(l, r);
//				
//				printf("%d\n", lastAns);
//			}
//			else
//			{
//				int x;
//				scanf("%d", &x);
//				x ^= lastAns;
//
//				cIndex++;
//				int i = cIndex;
//				memcpy(b[i], b[i - 1], sizeof(b[i]));
//				memcpy(p[i], p[i - 1], sizeof(p[i]));
//				add(x, i, i);
//			}
//
//			
//		}
//	}
//
//
//#ifndef ONLINE_JUDGE
//	printf("Time = %dms\n", clock() - startTime);
//#endif
//	return 0;
//}
