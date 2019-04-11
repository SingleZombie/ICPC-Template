struct Edge
{
	int to, flow, next;
	Edge() {}
	Edge(int _n, int _t, int _f) : next(_n), to(_t), flow(_f) {}
};

const int MAXN = 150005;
int n, m, k;
int src, term;

Edge edges[3 * MAXN];
int tot = 0;

int graph[MAXN];

void addEdge(int u, int v, int f)
{
	edges[tot] = Edge(graph[u], v, f);
	edges[tot + 1] = Edge(graph[v], u, 0);
	graph[u] = tot;
	graph[v] = tot + 1;
	tot += 2;
}

void init()
{
	tot = 0;
	memsetM1(graph);
}

int level[MAXN];
queue<int> que;

bool bfs(int s = src, int t = term)
{
	while (!que.empty())
	{
		que.pop();
	}
	memset0(level);
	level[s] = 1;
	que.push(s);

	while (!que.empty())
	{
		int u = que.front();
		que.pop();
		for (int i = graph[u]; i != -1; i = edges[i].next)
		{
			Edge e = edges[i];
			int v = e.to;
			if (!level[v] && e.flow > 0)
			{
				level[v] = level[u] + 1;
				que.push(v);
			}
		}
	}

	return level[t] != 0;
}


int dfs(int u = src, int t = term, int flow = INF)
{
	if (u == t || flow == 0)
	{
		return flow;
	}
	int res = flow;
	for (int i = graph[u]; i != -1; i = edges[i].next)
	{
		Edge e = edges[i];
		int v = e.to;

		if (level[v] > level[u] && e.flow > 0)
		{
			int f = dfs(v, t, min(res, e.flow));
			if (f)
			{
				edges[i].flow -= f;
				edges[1 ^ i].flow += f;
				res -= f;
				if (res == 0)
				{
					return flow;
				}
			}
		}
	}
	return flow - res;
}

int dinic(int s = src, int t = term)
{
	int ans = 0;
	while (bfs(s, t))
	{
		int f;
		while (f = dfs(s, t))
		{
			ans += f;
		}
	}
	return ans;
}