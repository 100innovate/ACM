#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<stdio.h>
using namespace std;

long long a[100005], b[100005], sum[100005], ans[100005];
int flag[100005];
int main(void)
{
	int n, l, r, m;
	scanf("%d", &n);
	for (int i(1); i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i(1); i <= n; i++)
	{
		scanf("%lld", &b[i]);
		sum[i] = sum[i - 1] + b[i];
	}
	for (int i(1); i <= n; i++)
	{
		l = i, r = n + 1;
		while (l<r)			//���ֲ���ѩ�ڻ����ʱ��
		{
			m = (l + r) / 2;
			if (sum[m] - sum[i - 1]<a[i])
				l = m + 1;
			else
				r = m;
		}
		ans[r] += a[i] - (sum[r - 1] - sum[i - 1]);
		flag[i]++, flag[r]--;
	}
	int num = 0;
	for (int i(1); i <= n; i++)
	{
		num += flag[i];		//���������¼��ǰ�ж��ٶ�ѩ��ȫ�ڻ�
		cout << b[i] * num + ans[i] << endl;
	}
	cout << endl;
	return 0;
}