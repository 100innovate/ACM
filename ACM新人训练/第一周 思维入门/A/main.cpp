#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

map<char, char> Charlist;

bool is_palindrome(string a) {
	bool ans = true;
	for (int i(0); i <= a.size() / 2; i++) {
		if (a[i] != a[a.size() - 1 - i]) {
			ans = false;
			break;
		}
	}
	return ans;
}

bool is_mirrored(string a) {
	bool ans = true;
	for (int i(0); i <= a.size() / 2; i++) {
		if(Charlist[a[i]]!= a[a.size() - 1 - i]) {
			ans = false;
			break;
		}
	}
	return ans;
}

//map����ֱ��ӳ������Ԫ�أ�ǰ��Ϊkeyֵ������ֵ������Ϊ��ֵ��Ӧ�Ķ���
//���� map<string,string> xx ;  string a= ͯ����   xx[a]=����; 
//��ʱ  xx["ͯ����"] == "����"  xx[a]== "����"
void init() {
	Charlist['A'] = 'A';Charlist['B'] = ' ';Charlist['C'] = ' ';Charlist['D'] = ' ';Charlist['E'] = '3';Charlist['F'] = ' ';
	Charlist['G'] = ' ';Charlist['H'] = 'H';Charlist['I'] = 'I';Charlist['J'] = 'L';Charlist['K'] = ' ';Charlist['L'] = 'J';
	Charlist['M'] = 'M';Charlist['N'] = ' ';Charlist['O'] = 'O';Charlist['P'] = ' ';Charlist['Q'] = ' ';Charlist['R'] = ' ';
	Charlist['S'] = '2';Charlist['T'] = 'T';Charlist['U'] = 'U';Charlist['V'] = 'V';Charlist['W'] = 'W';Charlist['X'] = 'X';
	Charlist['Y'] = 'Y';Charlist['Z'] = '5';Charlist['1'] = '1';Charlist['2'] = 'S';Charlist['3'] = 'E';Charlist['4'] = ' ';
	Charlist['5'] = 'Z';Charlist['6'] = ' ';Charlist['7'] = ' ';Charlist['8'] = '8';Charlist['9'] = ' ';
}
//������Ӧ������ʹ������  char x =['A',' '......] Ȼ�� ��Ӧʱ�����ֺ���ĸ ����ascii��  x[char-'A'] ȥ��ȡ����ĸ��Ӧ����ĸ 
int main() {
	init();
	string ans1 = " -- is not a palindrome.\n";
	string ans2 = " -- is a regular palindrome.\n";
	string ans3 = " -- is a mirrored string.\n";
	string ans4 = " -- is a mirrored palindrome.\n";
	int count(0);
	string p;
	while (cin>>p)
	{
		bool x = is_palindrome(p), y = is_mirrored(p);
		if (x&&y)
			cout << p << ans4 << endl;
		else if (x)
			cout << p << ans2 << endl;
		else if (y)
			cout << p << ans3 << endl;
		else
			cout << p << ans1 << endl;
	}
	return 0;
}