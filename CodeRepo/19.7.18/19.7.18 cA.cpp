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
//int arr[2][MAXN];
//int lson[2][MAXN], rson[2][MAXN];
//
//void build(int n, int* arr, int* lson, int* rson)
//{
//	stack<int> sta;
//	
//	for (int i = 0; i < n; i++)
//	{
//		if (!sta.empty())
//		{
//			rson[i] = sta.top();
//		}
//		else
//		{
//			rson[i] = -1;
//		}
//		lson[i] = -1;
//		while (!sta.empty() && arr[sta.top()] > arr[i])
//		{
//			sta.pop();
//		}
//		if (!sta.empty())
//		{
//			lson[i] = sta.top();
//		}
//		
//		sta.push(i);
//	}
//}
//
//int main()
//{
//#ifndef ONLINE_JUDGE
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
//	int startTime = clock();
//#endif
//
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				scanf("%d", &arr[j][i]);
//			}
//		}
//		int l = 1, r = n;
//		int ans = 1;
//		while (r >= l)
//		{
//			int mid = (l + r) / 2;
//			build(mid, arr[0], lson[0], rson[0]);
//			build(mid, arr[1], lson[1], rson[1]);
//
//			bool yes = true;
//			for (int i = 0; i < mid; i++)
//			{
//				if (lson[0][i] != lson[1][i] || rson[0][i] != rson[1][i])
//				{
//					yes = false;
//					break;
//				}
//			}
//			if (yes)
//			{
//				l = mid + 1;
//				ans = mid;				
//			}
//			else
//			{
//				r = mid - 1;
//			}
//		}
//		printf("%d\n", ans);
//	}
//	
//
//
//#ifndef ONLINE_JUDGE
//	printf("Time = %dms\n", clock() - startTime);
//#endif
//	return 0;
//}
