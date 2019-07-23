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
//const int MAXM = 26;
//int k;
//char str[MAXN];
//int minv[MAXM], maxv[MAXM];
//
//inline int toNum(char ch)
//{
//	return ch - 'a';
//}
//
//int cnt[MAXN][MAXM];
//int nxt[MAXN][MAXM];
//int cCnt[MAXM];
//char output[MAXN];
//
//int main()
//{
//#ifndef ONLINE_JUDGE
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
//	int startTime = clock();
//#endif
//	str[0] = 'z' + 1;
//	while (scanf("%s%d", str + 1, &k) != EOF)
//	{
//		int n = strlen(str + 1);
//		for (int i = 0; i < MAXM; i++)
//		{
//			scanf("%d%d", &minv[i], &maxv[i]);
//			nxt[n + 1][i] = n + 1;
//			cnt[n + 1][i] = 0;
//			cCnt[i] = 0;
//		}
//		for (int i = n; i >= 0; i--)
//		{
//			for (int j = 0; j < MAXM; j++)
//			{
//				cnt[i][j] = cnt[i + 1][j];
//				nxt[i][j] = nxt[i + 1][j];
//				if (toNum(str[i]) == j)
//				{
//					cnt[i][j]++;
//					nxt[i][j] = i;
//				}
//			}
//		}
//		bool haveAns = true;
//		output[k] = 0;
//		int crt = 0;
//		for (int i = 0; i < k; i++)
//		{
//			bool yes = false;
//			for (int j = 0; j < MAXM; j++)
//			{
//				int tmp = nxt[crt][j];
//				int sum = 0;
//				if (tmp == crt)
//				{
//					tmp = nxt[crt + 1][j];
//				}
//				if (cCnt[j] == maxv[j] || tmp > n)
//				{
//					continue;
//				}
//				bool ok = true;
//				for (int l = 0; l < MAXM; l++)
//				{
//					if (l == j)
//					{
//						sum += max(0, minv[l] - cCnt[l] - 1);
//					}
//					else
//					{
//						sum += max(0, minv[l] - cCnt[l]);
//					}
//					
//					if (cCnt[l] + cnt[tmp][l] < minv[l])
//					{
//						ok = false;
//						break;
//					}
//				}
//				if (sum + i + 1> k)
//				{
//					ok = false;
//				}
//				if (ok)
//				{
//					cCnt[j]++;
//					output[i] = j + 'a';
//					crt = tmp;
//					yes = true;
//					break;
//				}
//			}
//			if (!yes)
//			{
//				haveAns = false;
//			}
//		}
//		if (haveAns)
//		{
//			puts(output);
//		}
//		else
//		{
//			puts("-1");
//		}
//	}
//
//#ifndef ONLINE_JUDGE
//	printf("Time = %dms\n", clock() - startTime);
//#endif
//	return 0;
//}
