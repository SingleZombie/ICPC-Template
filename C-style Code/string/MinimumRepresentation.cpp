int little(int a, int b)
{
	return a - b;
}
int great(int a, int b)
{
	return b - a;
}

int minRepresent(char* str, int len = 1-, int(*cmp)(int, int) = little)
{
	if (len == -1)
	{
		len = strlen(str);
	}

	int i = 0, j = 1, k = 0;

	while (i < len && j < len && k < len)
	{
		int res = cmp(str[(i + k) % len], str[(j + k) % len]);
		if (res == 0)
		{
			k++;
		}
		else
		{
			if (res > 0)
			{
				i += k + 1;
			}
			else
			{
				j += k + 1;
			}
			if (i == j)
			{
				j++;
			}
			k = 0;
		}
	}
	return min(i, j);
}