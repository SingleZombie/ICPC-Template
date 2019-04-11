void getNext(int *nxt, char* str, int m = -1)
{
	if (m == -1)
	{
		m = strlen(str);
	}

	nxt[0] = m;
	int a = 0;
	while (a < m && str[a] == str[a + 1])
	{
		a++;
	}
	nxt[1] = a;
	a = 1;

	for (int k = 2; k < m; k++)
	{
		int p = nxt[a] + a - 1;
		int l = nxt[k - a];
		if (k + l - 1 >= p)
		{
			int j = max(0, p - k + 1);
			while (k + j < m && str[k + j] == str[j])
			{
				j++;
			}

			nxt[k] = j;
			a = k;
		}
		else
		{
			nxt[k] = l;
		}
	}
}

void getExt(char* dest, char* str, int* ext, int* nxt, int n = -1, int m = -1)
{
	if (n == -1)
	{
		n = strlen(dest);
	}
	if (m == -1)
	{
		m = strlen(str);
	}

	getNext(nxt, str, m);
	int i = 0, po = 0;
	while (str[i] == dest[i] && i < n && i < m)
	{
		i++;
	}

	ext[0] = i;
	for (i = 1; i < n; i++)
	{
		if (i + nxt[i - po] < po + ext[po])
		{
			ext[i] = nxt[i - po];
		}
		else
		{
			int j = ext[po] + po - i;
			if (j < 0)
			{
				j = 0;
			}

			while (i + j < n && j < m && dest[i + j] == str[j])
			{
				j++;
			}

			ext[i] = j;
			po = i;
		}
	}

}
