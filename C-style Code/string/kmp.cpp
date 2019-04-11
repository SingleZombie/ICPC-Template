void getNext(int *nxt, char * str, int m = -1)
{
	if (m == -1)
	{
		m = strlen(str);
	}
	
	int k = 0;
	nxt[0] = 0;
	int i = 1;
	while (i < m)
	{
		if (str[i] == str[k])
		{
			nxt[i++] = ++k;
		}
		else
		{
			if (k == 0)
			{
				nxt[i++] = 0;
			}
			else
			{
				k = nxt[k - 1];
			}

		}
	}
}
int kmp(char* str1, char* str2, int* nxt, int n = -1, int m = -1)
{
	if (n == -1)
	{
		n = strlen(str1);
	}
	if (m == -1)
	{
		m = strlen(str2);
	}
	
	getNext(nxt, str2);

	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (str1[i] == str2[j])
		{
			i++, j++;
		}
		else
		{
			if (j == 0)
			{
				i++;
			}
			else
			{
				j = nxt[j - 1];
			}
		}
	}
	return j;
}