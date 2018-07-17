#include<iostream>
#include<vector>

using namespace std;

long long quickmod(unsigned long long a, unsigned long long b, unsigned long long m)
{
	unsigned long long ans = 1;
	while (b)//��һ��ѭ�����ҵ������b�����ж�����λ
	{
		if (b & 1)//�жϴ�ʱb[i]�Ķ�����λ�Ƿ�Ϊ1
		{
			ans = (ans*a) % m;//�˵�����ϣ�����a��a^(2^i)%m
			b--;//�Ѹ�Ϊ��0
		}
		b /= 2;
		a = a * a%m;
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	vector<long long>ans_vec(1000010);
	while (T--)
	{
		unsigned long long a, b, n;
		long long mod;
		cin >> a >> b >> n;
		ans_vec[0] = 0;
		ans_vec[1] = 1;
		ans_vec[2] = 1;
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		for (int i(3); i < ans_vec.size(); i++) {
			ans_vec[i] = ((ans_vec[i - 1] + ans_vec[i - 2]) % n);
			if (ans_vec[i] == 1 && ans_vec[i - 1] == 1) {
				mod = i - 2;
				break;
			}

		}
		long long ans = quickmod(a%mod, b, mod);

		cout << ans_vec[ans] << endl;
	}
	return 0;
}