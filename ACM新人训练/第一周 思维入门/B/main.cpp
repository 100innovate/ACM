#include<iostream>
#include<algorithm>

using namespace std;

int count1[10];//ԭ�ַ�������
int count2[10];//���ַ�������

int input1[1000];//ԭ�ַ���
int input2[1000];//�Ƚ��ַ���
int n;

int main() {
	int T = 0;
	while (cin>>n && n)//��n==0ʱ�˳�
	{
		cout << "Game " << ++T << ':' << endl;
		for (int i(0); i < 10; i++)count1[i] = 0;//��ʼ���������ò����������ú�������
		for (int i(0); i < n; i++) {
			cin >> input1[i];
			count1[input1[i]]++;
		}

		while (1)
		{
			for (int i(0); i < 10; i++)count2[i] = 0;//��ʼ���������ò����������ú�������
			for (int i(0); i < n; i++) {
				cin >> input2[i];
				count2[input2[i]]++;
			}
			if (input2[0] == 0)break;

			int ans1(0), ans2(0);
			for (int i(0); i < n; i++) {
				if (input1[i] == input2[i])ans1++;
			}
			for (int i(0); i < 10; i++) {
				ans2 += min(count1[i], count2[i]);
			}
			ans2 -= ans1;
			cout << "    (" << ans1 << ',' << ans2 << ')' << endl;
		}
	}
}