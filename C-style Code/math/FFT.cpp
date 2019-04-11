const double PI = acos(-1.0);

#define complex complex<double>

void change(complex y[], int n)
{
	for (int i = 1, j = n >> 1; i < n - 1; i++)
	{
		if (i<j)	swap(y[i], y[j]);
		int k = n / 2;
		while (j >= k)
		{
			j -= k;
			k >>= 1;
		}
		if (j<k)	j += k;
	}
}

//sgn == -1 : Inverse
void fft(complex y[], int n, int sgn = 1)
{
	change(y, n);
	for (int h = 2; h <= n; h <<= 1)
	{
		complex wn(cos(-sgn * 2 * PI / h), sin(-sgn * 2 * PI / h));
		for (int j = 0; j < n; j += h)
		{
			complex w(1, 0);
			for (int k = j; k < j + h / 2; k++)
			{
				complex u = y[k];
				complex t = w * y[k + h / 2];
				y[k] = u + t;
				y[k + h / 2] = u - t;
				w = w * wn;
			}
		}
	}

	if (sgn == -1)
		for (int i = 0; i < n; i++)
			y[i].real(y[i].real() / n);
}