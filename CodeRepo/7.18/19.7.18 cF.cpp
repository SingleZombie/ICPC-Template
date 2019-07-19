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
//
//struct point
//{
//	long long x, y;
//	int input()
//	{
//		return scanf("%lld%lld", &x, &y);
//	}
//	point operator-(const point& b)
//	{
//		point p;
//		p.x = x - b.x;
//		p.y = y - b.y;
//		return p;
//	}
//	long long cross(const point& b)
//	{
//		return x * b.y - b.x * y;
//	}
//};
//
//int main()
//{
//#ifndef ONLINE_JUDGE
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
//	int startTime = clock();
//#endif
//	point a, b, c;
//	while (a.input() != EOF)
//	{
//		b.input();
//		c.input();
//		point ab = b - a;
//		point ac = c - a;
//		long long area = abs(ab.cross(ac)) * 11;
//		printf("%lld\n", area);
//	}
//	
//
//#ifndef ONLINE_JUDGE
//	printf("Time = %dms\n", clock() - startTime);
//#endif
//	return 0;
//}
