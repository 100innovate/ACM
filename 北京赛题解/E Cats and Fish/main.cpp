#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct cat {
	int time;//è�����ʱ��
	int xtime;//è�����ʣ��ʱ��

	bool operator <(const cat &a) {
		return time < a.time;
	}
};


int main() {
	int flashnum, catnum, time;
	while (cin >> flashnum >> catnum >> time) {
		vector<cat>all;
		cat p;
		for (int i(0); i < catnum; i++) {
			cin >> p.time;
			p.xtime = 0;
			all.push_back(p);
		}//����è

		sort(all.begin(), all.end());
		//��è���ճ����ٶ�����

		for (int i(0); i < time; i++) {
			for (int j(0); j < catnum; j++) {
				if (all[j].xtime == 0&&flashnum!=0) {
					flashnum--;
					all[j].xtime = all[j].time;
				}
				
				if (all[j].xtime != 0)
					all[j].xtime--;
			}
		}
		//ģ�����

		int sum(0);
		for (int i(0); i < catnum; i++) {
			if (all[i].xtime != 0)sum++;
		}
		//ͳ��δ�������
		cout << flashnum << ' ' << sum << endl;
	}
}