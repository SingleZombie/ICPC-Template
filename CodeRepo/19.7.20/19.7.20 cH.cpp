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
//using namespace std;
//
//const int maxn = 1e3 + 5;
//using namespace std;
//int h[maxn], l[maxn], r[maxn];
//
//int main()
//{
//#ifndef ONLINE_JUDGE
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
//	int startTime = clock();
//#endif
//
//	int n, m;
//	scanf("%d%d", &n, &m);
//	char ph;
//	memset(h, 0, sizeof(h));
//	int max1 = -1;
//	vector<int> ans;
//	ans.push_back(0);
//	ans.push_back(0);
//	for (int i = 1; i <= n; i++)
//	{
//		getchar();
//		for (int j = 1; j <= m; j++)
//		{
//			scanf("%c", &ph);
//			if (ph - '0' == 0)
//				h[j] = 0;
//			else
//				h[j]++;
//		}
//		stack<int> s;
//		for (int j = 1; j <= m; j++)
//		{
//			while (!s.empty() && h[s.top()] >= h[j]) s.pop();
//			if (s.empty()) l[j] = 0;
//			else l[j] = s.top();
//			s.push(j);
//		}
//		stack<int> p;
//		for (int j = m; j >= 1; j--)
//		{
//			while (!p.empty() && h[p.top()] >= h[j]) p.pop();
//			if (p.empty()) r[j] = m + 1;
//			else r[j] = p.top();
//			p.push(j);
//		}
//		set<pair<int, int>> vis;
//		for (int j = 1; j <= m; j++)
//		{
//			if (vis.count( { h[j], l[j] + 1 } ))
//			{
//				continue;
//			}
//			vis.insert({ h[j], l[j] + 1 });
//			ans.push_back(h[j] * (r[j] - l[j] - 1));
//			ans.push_back((h[j] - 1) * (r[j] - l[j] - 1));
//			ans.push_back(h[j] * (r[j] - l[j] - 2));
//		}
//	}
//	sort(ans.begin(), ans.end(), greater<int>());
//	printf("%d\n", ans[1]);
//	return 0;
//}