const int MAXE = 20005;
const int MAXN = 305;

struct Edge
{
	int from, to, flow, cost;
	Edge(int _f = 0, int _t = 0, int _fl = 0, int _co = 0) :
		from(_f), to(_t), flow(_fl), cost(_co)
	{

	}
};

int n, k, m;
int src, term;

Edge edges[2 * MAXE];
vector<int> graph[MAXN];
int tot = 0;

void init()
{
	for (int i = 0; i < MAXN; i++)
	{
		graph[i].clear();
	}
	tot = 0;
}

void addEdge(int u, int v, int flow, int cost)
{
	edges[tot] = Edge(u, v, flow, cost);
	edges[tot + 1] = Edge(v, u, 0, -cost);
	graph[u].push_back(tot);
	graph[v].push_back(tot + 1);

	tot += 2;
}

int pre[MAXN];
int dis[MAXN];
bool inQueue[MAXN];
queue<int> que;
bool spfa(int s = src, int t = term)
{
	memsetM1(pre);
	memset0(inQueue);
	while (!que.empty())
	{
		que.pop();
	}
	memsetINF(dis);

	que.push(s);
	pre[s] = -1;
	dis[s] = 0;
	inQueue[s] = true;
	while (!que.empty())
	{
		int u = que.front();
		que.pop();
		inQueue[u] = false;

		for (int i = 0; i < graph[u].size(); i++)
		{
			Edge e = edges[graph[u][i]];
			int v = e.to;

			if (e.flow && dis[v] > dis[u] + e.cost)
			{
				dis[v] = dis[u] + e.cost;
				pre[v] = graph[u][i];
				if (!inQueue[v])
				{
					inQueue[v] = true;
					que.push(v);
				}
			}
		}
	}

	return dis[t] < INF;
}

int minCostMaxFlow(int& maxFlow, int s = src, int t = term)
{
	maxFlow = 0;
	int minCost = 0;
	while (spfa(s, t))
	{
		int flow = INF;
		for (int i = pre[t]; i != -1; i = pre[edges[i].from])
		{
			flow = min(flow, edges[i].flow);
		}
		for (int i = pre[t]; i != -1; i = pre[edges[i].from])
		{
			edges[i].flow -= flow;
			edges[1 ^ i].flow += flow;
			minCost += edges[i].cost * flow;
		}
		maxFlow += flow;
	}

	return minCost;
}