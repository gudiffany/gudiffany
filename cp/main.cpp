#include <iostream>
#include <fstream>
#include "x.h"
using namespace std;

int main() {
	char name1[50];
	char name2[50];
	ifstream file;
	ifstream fin; // 先不打开文件, 等待输入
	scanf("%s ",name1);
	cin>>name2;
	file.open(name1,ios::in);
	fin.open(name2,ios::in); // fstream的open函数用来打开一个文件
	if(!file||!fin)
	cout<<"打开错误"<<endl;
	
	long long int num1[10001], num2[10001], num3[10001], num4[10001], num5[10001];//rule的分点十进制原ip
	long long int num11[10001], num21[10001], num31[10001], num41[10001], num51[10001];//rule的分点十进制终ip
	int duan1[10001], duan2[10001], duan3[10001], duan4[10001];//端点
	char ds1[10001], ds2[10001], ds3[10001], ds4[10001];//十六进制
	int dp1[10001], dp2[10001], dp3[10001], dp4[10001];
	long long int ip11[10001], ip21[10001], ip1[10001], ip2[10001]; //十进制ip
	int sum1[10001], sum2[10001];//0x转化为十进制

	char s;//除去字符
	int s1;//除去字符
	int len = 0;
	long long int x;


	ofstream fout;
	fout.open("res4.txt");
	
	while (!file.eof()) {
		file >> s >> num1[len] >> s >> num2[len] >> s >> num3[len] >> s >> num4[len] >> s >> num5[len];
		file >> num11[len] >> s >> num21[len] >> s >> num31[len] >> s >> num41[len] >> s >> num51[len];
		file >> duan1[len] >> s >> duan2[len] >> duan3[len] >> s >> duan4[len];
		file >> s1 >> s >> ds1[len] >> ds2[len] >> s >> s1 >> s >> ds3[len] >> ds4[len];
		/*输入数据对rule进行处理*/

		ip1[len] = IP(num1[len], num2[len], num3[len], num4[len], num5[len], len, 1);
		ip11[len] = IP(num1[len], num2[len], num3[len], num4[len], num5[len], len, 0);
		ip2[len] = IP(num11[len], num21[len], num31[len], num41[len], num51[len], len, 1);
		ip21[len] = IP(num11[len], num21[len], num31[len], num41[len], num51[len], len, 0);
		
		if(ip1[len]>ip11[len])
		{
			x=ip1[len];
			ip1[len]=ip11[len];
			ip11[len]=x;
		} 
		
		if(ip2[len]>ip21[len])
		{
			x=ip2[len];
			ip2[len]=ip21[len];
			ip21[len]=x;
		}
	
		dp1[len] = duan(ds1[len]);
		dp2[len] = duan(ds2[len]);
		dp3[len] = duan(ds3[len]);
		dp4[len] = duan(ds4[len]);

		sum1[len] = 16 * dp1[len] + dp2[len];
		sum2[len] = 16 * dp3[len] + dp4[len];
		/*十六进制处理*/
		len++;
	}
	
	long long int ans1, ans2, ans3, ans4, ans5;
	int flag = 0;
	len--;
	flag = 0;

	while (!fin.eof()) {
		ans1=-1;
		fin >> ans1 >> ans2 >> ans3 >> ans4 >> ans5;
		if(ans1!=-1) {
			for (int j = 0; j < len; j++) {
			if (ans3 >= duan1[j] && ans3 <= duan2[j] && ans4 >= duan3[j]
				&& ans4 <= duan4[j]) {
				if ((sum2[j] != 255) || (sum1[j] == ans5 && sum2[j] == 255)) {
					if (ans1 >= ip1[j] && ans2 >= ip2[j]&&ans1 <= ip11[j] && ans2 <= ip21[j]) {
						flag = 1;
						fout << j << "\n";
						break;
					}
				}
			}
		}
		if (flag == 0)
			fout << -1 << "\n";
		}
		
	}
	return 0;
}
