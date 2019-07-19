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
//using pii = pair<int, int>;
//using ll = long long;
//
//const int MAXN = 1e5 + 5;
//int n;
//
//struct point
//{
//	pii p;
//	int a, b, v;
//	void input()
//	{
//		scanf("%d%d%d%d", &p.first, &p.second, &a, &b);
//		v = b - a;
//	}
//	bool operator<(const point& pb)
//	{
//		if (p.first != pb.p.first)
//		{
//			return p.first < pb.p.first;
//		}
//		else
//		{
//			return p.second > pb.p.second;
//		}
//	}
//};
//point points[MAXN];
//
//int yNum[MAXN];
//int yLen;
//int getYId(int x)
//{
//	return lower_bound(yNum, yNum + yLen, x) - yNum;
//}
//
//struct node
//{
//	ll sumMark;
//	ll maxv;
//	node* rson, *lson;
//	node()
//	{
//		sumMark = maxv = 0;
//		lson = rson = nullptr;
//	}
//	node operator+(const node& nd)
//	{
//		node no = node();
//		no.maxv = max(maxv, nd.maxv);
//		return no;
//	}
//};
//node nodes[MAXN * 4];
//node* root;
//int nodeTot;
//node* newNode()
//{
//	nodes[nodeTot] = node();
//	return &nodes[nodeTot++];
//}
//void pushDown(node* nd)
//{
//	nd->maxv += nd->sumMark;
//	if (nd->sumMark && nd->lson)
//	{
//		nd->lson->sumMark += nd->sumMark;
//		nd->rson->sumMark += nd->sumMark;
//	}
//	nd->sumMark = 0;
//}
//void pushUp(node* nd)
//{
//	if (nd->lson)
//	{
//		pushDown(nd->lson);
//		pushDown(nd->rson);
//		nd->maxv = max(nd->lson->maxv, nd->rson->maxv);
//	}
//}
//void build(node* nd = root, int l = 1, int r = n)
//{
//	if (l == r)
//	{
//		
//	}
//	else
//	{
//		int mid = (l + r) / 2;
//		nd->lson = newNode();
//		nd->rson = newNode();
//		build(nd->lson, l, mid);
//		build(nd->rson, mid + 1, r);
//		pushUp(nd);
//	}
//	
//}
//void init(int n)
//{
//	nodeTot = 0;
//	root = newNode();
//	build(root, 1, n);
//}
//
//void setV(int l, ll v, node* nd = root, int cl = 1, int cr = n)
//{
//	int mid = (cl + cr) / 2;
//	pushDown(nd);
//	if (cl == cr)
//	{
//		nd->maxv = v;
//	}
//	else
//	{
//		if (l <= mid)
//		{
//			setV(l, v, nd->lson, cl, mid);
//		}
//		else
//		{
//			setV(l, v, nd->rson, mid + 1, cr);
//		}
//		pushUp(nd);
//	}
//}
//
//void addV(int l, int r, ll v, node* nd = root, int cl = 1, int cr = n)
//{
//	int mid = (cl + cr) / 2;
//	pushDown(nd);
//	if (cl == l && cr == r)
//	{
//		nd->sumMark += v;
//		pushDown(nd);
//	}
//	else
//	{
//		if (r <= mid)
//		{
//			addV(l, r, v, nd->lson, cl, mid);
//		}
//		else if (l > mid)
//		{
//			addV(l, r, v, nd->rson, mid + 1, cr);
//		}
//		else
//		{
//			addV(l, mid, v, nd->lson, cl, mid);
//			addV(mid + 1, r, v, nd->rson, mid + 1, cr);
//		}
//	}
//	pushUp(nd);
//}
//
//node queryNode(int l, int r, node* nd = root, int cl = 1, int cr = n)
//{
//	int mid = (cl + cr) / 2;
//	pushDown(nd);
//	if (cl == l && cr == r)
//	{
//		return *nd;
//	}
//	else
//	{
//		if (r <= mid)
//		{
//			return queryNode(l, r, nd->lson, cl, mid);
//		}
//		else if (l > mid)
//		{
//			return queryNode(l, r, nd->rson, mid + 1, cr);
//		}
//		else
//		{
//			return queryNode(l, mid, nd->lson, cl, mid) + queryNode(mid + 1, r, nd->rson, mid + 1, cr);
//		}
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
//	while (scanf("%d", &n) != EOF)
//	{
//		long long ans = 0;
//		for (int i = 0; i < n; i++)
//		{
//			points[i].input();
//			ans += points[i].a;
//			yNum[i] = points[i].p.second;
//		}
//		sort(yNum, yNum + n);
//		yLen = unique(yNum, yNum + n) - yNum;
//
//
//		sort(points, points + n);
//
//		init(yLen);
//		for (int i = 0; i < n; i++)
//		{
//			int yId = getYId(points[i].p.second) + 1;
//			node result = queryNode(1, yId, root, 1, yLen);
//			ll tmpV = max(result.maxv, 0ll);
//			setV(yId, tmpV, root, 1, yLen);
//			addV(yId, yLen, points[i].v, root, 1, yLen);
//		}
//		node tmpNode = queryNode(1, yLen, root, 1, yLen);
//		printf("%lld\n", ans + max(tmpNode.maxv, 0ll));
//	}
//	
//
//#ifndef ONLINE_JUDGE
//	printf("Time = %dms\n", clock() - startTime);
//#endif
//	return 0;
//}
