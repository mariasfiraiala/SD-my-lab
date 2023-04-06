#include <stdio.h>

void myqsort(int begin, int end, int *v)
{
	int b = begin, e = end, pivot;

	pivot = v[(begin + end) / 2];

	while (v[b] < pivot)
		++b;

	while (v[e] > pivot)
		--e;

	while (b < e) {
		int aux = v[b];
		v[b] = v[e];
		v[e] = aux;

		do
			++b;
		while (v[b] < pivot);

		do
			--e;
		while (v[e] > pivot);
	}

	if (begin < e)
		myqsort(begin, e, v);
	if (e + 1 < end)
		myqsort(e + 1, end, v);
}

int main(void)
{
	int v[] = {4, 3, 2, 1};

	myqsort(0, 3, v);

	for (int i = 0; i < 4; ++i)
		printf("%d\n", v[i]);

	return 0;
}
