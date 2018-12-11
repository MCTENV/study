#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void jiaoGu(int n) {
	int sum = 0;
	while (n != 1) {
		sum++;
		if (n % 2)
			n = n * 3 + 1;
		else
			n /= 2;
	}
	printf("%d\n", sum);
}

int partion(char* a, int s, int e) {
	char t = a[s];
	int i = s;
	int j = e - 1;
	while (i < j) {
		while (i<j && a[j] >= t) j--;
		if (i < j) {
			a[i] = a[j];
		}
		while (i < j && a[i] <= t) i++;
		if (i < j) {
			a[j] = a[i];
		}
	}
	a[i] = t;
	if (i < j) return i + 1;
	else return i;
}

/***********二〇一七年，二*************/
void sort(char* a, int s, int e) {
	if (s < e) {
		int k = partion(a, s, e);
		sort(a, s, k);
		sort(a, k + 1, e);
	}
}

int uniqueChar(char* s, int len) {
	int sum = 0;
	for (int i = 0; i < len; i++) {
		if (s[sum] != s[i]) {
			sum++;
			s[sum] = s[i];
		}
	}
	sum += 1;
	s[sum] = 0;
	return sum;
}

void print(char* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%c", a[i]);
	}
	printf("\n");
}

int* statistic(char* s, char* a, int &n) {
	int len = strlen(s);
	sort(a, 0, n);
	sort(s, 0, len);
	n = uniqueChar(a, n);
	int *sum;
	sum = (int*)malloc(sizeof(int) * (n - 1));
	for (int i = 0; i < n; i++) {
		sum[i] = 0;
	}
	int j = 0;
	for (int i = 0; i < len; i++) {
		if (j > n)
			break;
		if (s[i] == a[j]) {
			sum[j]++;
		}
		else sum[++j]++;
	}
	return sum;
}
/************************************/



int main() {
	//jiaoGu(20);
	char s[] = "abcdefdbcda";
	char a[] = { 'a', 'c', 'd', 'b', 'f' };
	int n = 5;
	int *sum = statistic(s, a, n);
	for (int i = 0; i < n; i++) {
		printf("%c:%d\n", a[i], sum[i]);
	}
	scanf_s("%s", a);
	return 0;
}