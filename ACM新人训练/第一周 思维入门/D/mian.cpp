#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--)
	{
		string a;
		cin >> a;
		a += a;
		int ans(0);
		for(int i(0);i<a.size()/2;i++){
			for (int j(i), l(ans), t(0); t < a.size()/2; t++, j++, l++) {
				if (a[j] < a[l])ans = i;
				else if (a[j] > a[l])break;
			}
		}
		//������forѭ���� t�����жϳ��ȣ�ans������С�ֵ������㣬jΪ��ǰ��������㡣
		for (int i(ans), t(0); t < a.size() / 2; t++, i++) {
			cout << a[i];
		}
		cout << endl;
	}
}