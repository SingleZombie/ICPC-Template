const char LEN = 26;
struct node
{
	int len;
	node* pre;
	node* next[LEN];
	node(int _len = 0) : len(_len)
	{
		memset0(next);
		pre = NULL;
	}
};
typedef node* SAM;
SAM root;
node *last;
void init(SAM* root, node** last)
{
	*root = new node();
	*last = *root;
}
void extend(SAM root, node** last, char ch)
{
	int id = ch - 'a';
	node* p = *last;
	node* np = new node(p->len + 1);
	while (p && p->next[id] == NULL)
	{
		p->next[id] = np;
		p = p->pre;
	}
	if (p == NULL)
	{
		np->pre = root;
	}
	else
	{
		node* q = p->next[id];
		if (p->len + 1 == q->len)
		{
			np->pre = q;
		}
		else
		{
			node* nq = new node(p->len + 1);
			memcpy(nq->next, q->next, sizeof(nq->next));
			nq->pre = q->pre;
			q->pre = nq;
			np->pre = nq;
			while (p && p->next[id] == q)
			{
				p->next[id] = nq;
				p = p->pre;
			}
		}
	}
	*last = np;
}