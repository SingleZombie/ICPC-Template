//const double EPS = 1e-8;
//const double PI = acos(-1);
//
//int sgn(double x)
//{
//	if (abs(x) < EPS)
//	{
//		return 0;
//	}
//	return x > 0 ? 1 : -1;
//}
//
//struct Point;
//typedef Point Vec2;
//struct Point
//{
//	static Point null;
//	static Point origin;
//
//	double x, y;
//	Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
//
//	void input()
//	{
//		scanf("%lf%lf", &x, &y);
//	}
//	bool operator==(const Point& b) const
//	{
//		return abs(x - b.x) < EPS && abs(y - b.y) < EPS;
//	}
//	Point operator+(const Point& b) const
//	{
//		return Point(x + b.x, y + b.y);
//	}
//	Point operator-(const Point& b) const
//	{
//		return Point(x - b.x, y - b.y);
//	}
//	Point operator*(double n) const
//	{
//		return Point(n * x, n * y);
//	}
//	friend Point operator*(double n, Point a)
//	{
//		return Point(n * a.x, n * a.y);
//	}
//	Point operator/(double n) const
//	{
//		return Point(x / n, y / n);
//	}
//	double dot(const Point& b)
//	{
//		return x * b.x + y * b.y;
//	}
//	double cross(const Point& b)
//	{
//		return x * b.y - y * b.x;
//	}
//	void unit()
//	{
//		double l = len();
//		x /= l, y /= l;
//	}
//	double len()
//	{
//		return sqrt(x * x + y * y);
//	}
//	double len2()
//	{
//		return x * x + y * y;
//	}
//	double dis(const Point& b)
//	{
//		return (b - *this).len();
//	}
//	double arc(Vec2 b)
//	{
//		double as = asin(cross(b) / len() / b.len());
//		if (sgn(dot(b)) < 0)
//		{
//			if (sgn(as) < 0)
//			{
//				as = -PI - as;
//			}
//			else
//			{
//				as = PI - as;
//			}
//		}
//		return as;
//	}
//	Point rotate(double arcv)
//	{
//		double sin0 = sin(arcv);
//		double cos0 = cos(arcv);
//		double x1 = x * cos0 - y * sin0;
//		double y1 = x * sin0 + y * cos0;
//		return Point(x1, y1);
//	}
//	static bool arrive(Point pa, Vec2 dir, Point pb)
//	{
//		Vec2 ba = pb - pa;
//		return abs(ba.dot(dir) - ba.len() * dir.len()) < EPS;
//	}
//
//};
//bool cmpDegree(const Point& p1, const Point& p2)
//{
//	return sgn((p1 - Point::origin).cross(p2 - Point::origin)) > 0;
//}
//bool cmpX(const Point& p1, const Point& p2)
//{
//	if (p1.x != p2.x)
//	{
//		return p1.x < p2.x;
//	}
//	return p1.y < p2.y;
//}
//bool cmpY(const Point& p1, const Point& p2)
//{
//	if (p1.y != p2.y)
//	{
//		return p1.y < p2.y;
//	}
//	return p1.x < p2.x;
//}
//
//Point Point::origin = Point(0, 0);
//Point Point::null = Point(9999999999, 9999999999);
//
//void graHam(vector<Point>& points, int n, vector<Point>& res)
//{
//	res.clear();
//	sort(points.begin(), points.begin() + n, cmpY);
//	Point::origin = points[0];
//	sort(points.begin() + 1, points.begin() + n, cmpDegree);
//	res.push_back(points[0]);
//
//	int sz = n;
//	for (int i = 1; i < sz; i++)
//	{
//		while (true)
//		{
//			if (res.size() == 1)
//			{
//				res.push_back(points[i]);
//				break;
//			}
//			else
//			{
//				Point top1 = res.back();
//				Point top2 = res[res.size() - 2];
//
//				Vec2 v1 = top1 - top2;
//				Vec2 v2 = points[i] - top1;
//				if (v1.cross(v2) >= 0)
//				{
//					res.push_back(points[i]);
//					break;
//				}
//				else
//				{
//					res.pop_back();
//				}
//			}
//		}
//	}
//
//}
//
//struct Line
//{
//	double A, B, C;
//	Line(double a, double b, double c) : A(a), B(b), C(c) {}
//	Line(Point a, Point b)
//	{
//		A = a.y - b.y;
//		B = b.x - a.x;
//		C = a.cross(b);
//	}
//	bool onLine(Point p)
//	{
//		return sgn(A * p.x + B * p.y + C) == 0;
//	}
//	double dis(Point p)
//	{
//		return abs(A * p.x + B * p.y + C) / Point(A, B).len();
//	}
//
//	Point getPoint()
//	{
//		if (sgn(A))
//		{
//			return Point(-C / A, 0);
//		}
//		else
//		{
//			return Point(0, -C / B);
//		}
//	}
//	Vec2 getDirection()
//	{
//		return Vec2(B, -A);
//	}
//
//	Point projection(Point p1)
//	{
//		Point p2 = getPoint();
//		Point p3 = p2 + getDirection();
//		Vec2 dir = getDirection();
//		Vec2 v12 = p1 - p2;
//		return p2 + v12.dot(dir) / dir.len2() * dir;
//	}
//
//	Point symmetry(Point p1)
//	{
//		Point p = projection(p1);
//		Vec2 v = p - p1;
//		return p1 + v + v;
//	}
//
//	Point getIntersection(const Line& l)
//	{
//		double deno = Point(A, B).cross(Point(l.A, l.B));
//		if (sgn(deno) == 0)
//		{
//			return Point::null;
//		}
//		double x1 = -Point(B, -C).cross(Point(l.B, -l.C)) / deno;
//		double y1 = Point(A, -C).cross(Point(l.A, -l.C)) / deno;
//		return Point(x1, y1);
//	}
//};
//
//struct Triangle
//{
//	Point a, b, c;
//	Triangle(Point _a, Point _b, Point _c) : a(_a), b(_b), c(_c) {}
//	void input()
//	{
//		a.input(); b.input(); c.input();
//	}
//	double areaABC()
//	{
//		Vec2 ab = b - a;
//		Vec2 ac = c - a;
//		return ab.cross(ac) / 2;
//	}
//	double area()
//	{
//		return abs(areaABC());
//	}
//	Point circumCenter()
//	{
//		Point res;
//		Point mab = (a + b) / 2, mac = (a + c) / 2;
//		Vec2 v1 = (b - a).rotate(PI / 2);
//		Vec2 v2 = (c - a).rotate(PI / 2);
//		Line l1(mab, mab + v1), l2(mac, mac + v2);
//		res = l1.getIntersection(l2);
//		if (res == Point::null)
//		{
//			Point p1 = a, p2 = b;
//			if (b.dis(c) > p1.dis(p2) + EPS)
//			{
//				p1 = b;
//				p2 = c;
//			}
//			if (a.dis(c) > p1.dis(p2) + EPS)
//			{
//				p1 = a;
//				p2 = c;
//			}
//			res = (p1 + p2) / 2;
//		}
//		return res;
//	}
//};
//
//struct Circle
//{
//	double r;
//	Point p;
//	void input()
//	{
//		scanf("%lf%lf%lf", &p.x, &p.y, &r);
//	}
//	Circle(double _x = 0, double _y = 0, double _r = 1)
//		: p(_x, _y), r(_r) {}
//	Circle(Point _p, double _r) : p(_p), r(_r) {}
//	Circle(Point a, Point b)
//	{
//		p = (a + b) / 2;
//		r = a.dis(b) / 2;
//	}
//	Circle(Triangle t)
//	{
//		p = t.circumCenter();
//		r = max(t.a.dis(p), max(t.b.dis(p), t.c.dis(p)));
//	}
//	Circle(Point a, Point b, Point c)
//	{
//		Triangle t(a, b, c);
//		p = t.circumCenter();
//		r = max(t.a.dis(p), max(t.b.dis(p), t.c.dis(p)));
//	}
//
//	double getArea()
//	{
//		return PI * r * r;
//	}
//	double chordArea(Point a, Point b)
//	{
//		Vec2 oa = a - p;
//		Vec2 ob = b - p;
//		double arc = oa.arc(ob);
//		double res = arc / 2 * r * r;
//		return res;
//	}
//	bool onCircle(Point p1)
//	{
//		return abs((p1 - p).len2() - r * r) < EPS;
//	}
//	bool inCircle(Point p1)
//	{
//		return (p1 - p).len2() + EPS < r * r;
//	}
//	bool inOnCircle(Point p1)
//	{
//		return (p1 - p).len2() < r * r + EPS;
//	}
//
//	pair<Point, Point> getIntersetion(Line l)
//	{
//		Point p0 = l.getPoint() - p;
//		Point v = l.getDirection();
//		double A = v.len2();
//		double B = 2 * p0.dot(v);
//		double C = p0.len2() - r * r;
//		double delta = B * B - 4 * A * C;
//		if (sgn(delta) < 0)
//		{
//			return make_pair(Point::null, Point::null);
//		}
//		else
//		{
//			delta = sqrt(delta);
//			double t1 = (-B - delta) / (2 * A);
//			double t2 = (-B + delta) / (2 * A);
//			return make_pair(p0 + v * t1 + p, p0 + v * t2 + p);
//		}
//	}
//
//};