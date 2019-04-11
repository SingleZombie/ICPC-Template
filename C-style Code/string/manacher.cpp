int setStr(char* str, char* src, int n = -1)
{
	if (n == -1)
	{
		n = strlen(src);
	}

	int index = 0;
	str[index++] = '$';
	for (int i = 0; i < n; i++)
	{
		str[index++] = '#';
		str[index++] = src[i];
	}
	str[index++] = '#';
	return index;
}
int manacher(char* str, char* src, int* lens, int n = -1)
{
	int m = setStr(str, src, n);

	int mx = 0, id = 0;
	for (int i = 1; i < m; i++)
	{
		if (mx > i)
		{
			lens[i] = min(lens[2 * id - i], mx - i);
		}
		else
		{
			lens[i] = 1;	
		}
		while (str[i + lens[i]] == str[i - lens[i]])
		{
			lens[i]++;
		}
		if (lens[i] + i > mx)
		{
			mx = lens[i] + i;
			id = i;
		}
	}

	return m;
}