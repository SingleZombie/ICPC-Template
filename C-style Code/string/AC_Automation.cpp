const int LEN = 26;
struct node
{
	node()
	{
		cnt = 0;
		memset0(nxt);
		fail = NULL;
	}
	int cnt;
	node* nxt[LEN];
	node* fail;
};
struct Trie
{
	node* root;
	Trie()
	{
		root = new node();
	}
	void deleteNode(node* n)
	{
		for (int i = 0; i < LEN; i++)
		{
			if (n->nxt[i])
			{
				deleteNode(n->nxt[i]);
			}
		}
		delete n;
	}
	~Trie()
	{
		deleteNode(root);
	}
	void insert(const string& str)
	{
		node* np = root;
		int sz = str.size();
		for (int i = 0; i < sz; i++)
		{
			int id = str[i] - 'a';
			if (!np->nxt[id])
			{
				np->nxt[id] = new node();
			}
			np = np->nxt[id];
		}
		np->cnt++;
	}
	void build()
	{
		queue<node* > que;
		que.push(root);
		root->fail = root;
		while (!que.empty())
		{
			node* p = que.front();
			que.pop();
			for (int i = 0; i < LEN; i++)
			{
				if (p->nxt[i])
				{
					if (p == root)
					{
						p->nxt[i]->fail = root;
					}
					else
					{
						p->nxt[i]->fail = p->fail->nxt[i];
					}
					que.push(p->nxt[i]);	
				}
				else
				{
					if (p == root)
					{
						p->nxt[i] = root;
					}
					else
					{
						p->nxt[i] = p->fail->nxt[i];
					}
				}
			}
		}	
	}
	int work(const string& str)
	{
		int sz = str.size();
		int res = 0;
		node* p = root;
		for (int i = 0; i < sz; i++)
		{
			int id = str[i] - 'a';
			p = p->nxt[id];
			for (node* tmp = p; tmp != root; tmp = tmp->fail)
			{
				if (tmp->cnt)
				{
					res += tmp->cnt;
					tmp->cnt = 0;
				}
			}
		}
		return res;
	}
};
Trie* trie;