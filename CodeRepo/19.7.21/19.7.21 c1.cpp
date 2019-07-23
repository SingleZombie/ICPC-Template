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
//vector<int> graph[MAXN];
//
//int n;
//int fa[MAXN];
//void init()
//{
//	for (int i = 0; i <= n; i++)
//	{
//		fa[i] = i;
//	}
//}
//int findRoot(int x)
//{
//	if (fa[x] == x)
//	{
//		return x;
//	}
//	return fa[x] = findRoot(fa[x]);
//}
//void unite(int a, int b)
//{
//	int ra = findRoot(a);
//	int rb = findRoot(b);
//	fa[rb] = ra;
//}
//
//long long disU;
//int sons[MAXN];
//int layer[MAXN];
//void calSonsDFS(int u, int pre = -1)
//{
//	disU += layer[u];
//	sons[u] = 1;
//	for (int i = 0; i < graph[u].size(); i++)
//	{
//		int v = graph[u][i];
//		if (v == pre)
//		{
//			continue;
//		}
//
//		layer[v] = layer[u] + 1;
//		calSonsDFS(v, u);
//		sons[u] += sons[v];
//	}
//}
//void calSons(int u)
//{
//	disU = 0;
//	layer[u] = 0;
//	calSonsDFS(u);
//}
//long long disSum;
//
//
//int treeSize;
//long long nodeDis[MAXN];
//int center;
//void findCenterDFS(int u, int pre)
//{
//	if (nodeDis[u] < nodeDis[center])
//	{
//		center = u;
//	}
//	disSum += nodeDis[u];
//	for (int i = 0; i < graph[u].size(); i++)
//	{
//		int v = graph[u][i];
//		if (v == pre)
//		{
//			continue;
//		}
//
//		nodeDis[v] = nodeDis[u] + treeSize - sons[v] - sons[v];
//		findCenterDFS(v, u);
//	}
//}
//int findCenter(int u, int sz)
//{
//	disSum = 0;
//	treeSize = sz;
//	center = u;
//
//	calSons(u);
//
//	nodeDis[u] = disU;
//
//	findCenterDFS(u, -1);
//
//	return center;
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
//	while (scanf("%d", &n) != EOF)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			graph[i].clear();
//		}
//		init();
//		for (int i = 0; i < n - 2; i++)
//		{
//			int u, v;
//			scanf("%d%d", &u, &v);
//			graph[u].push_back(v);
//			graph[v].push_back(u);
//			unite(u, v);
//		}
//		int root1 = findRoot(1);
//		int sz1 = 0, sz2 = 0;
//		int root2;
//		for (int i = 1; i <= n; i++)
//		{
//			int tmp = findRoot(i);
//			if (tmp != root1)
//			{
//				root2 = tmp;
//				sz2++;
//			}
//			else
//			{
//				sz1++;
//			}
//		}
//
//		int p1 = findCenter(root1, sz1);
//		int p2 = findCenter(root2, sz2);
//		graph[p1].push_back(p2);
//		graph[p2].push_back(p1);
//		findCenter(p1, sz1 + sz2);
//		printf("%lld\n", disSum / 2);
//	}
//
//#ifndef ONLINE_JUDGE
//	printf("Time = %dms\n", clock() - startTime);
//#endif
//	return 0;
//}
