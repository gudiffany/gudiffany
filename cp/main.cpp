#include <iostream>
#include <fstream>
#include "x.h"
#define GU 10001
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
	{
		cout<<"打开错误"<<endl;
		return 0;
	} 
	
	long long int num1[GU], num2[GU], num3[GU], num4[GU], num5[GU];//rule的分点十进制原ip
	long long int num11[GU], num21[GU], num31[GU], num41[GU], num51[GU];//rule的分点十进制终ip
	int duan1[GU], duan2[GU], duan3[GU], duan4[GU];//端点
	char ds1[GU], ds2[GU], ds3[GU], ds4[GU];//十六进制
	int dp1[GU], dp2[GU], dp3[GU], dp4[GU];
	long long int ip11[GU], ip21[GU], ip1[GU], ip2[GU]; //十进制ip
	int sum1[GU], sum2[GU];//0x转化为十进制

	char s;//除去字符
	int s1;//除去字符
	int len = 0;
	long long int x;


	ofstream fout;
	fout.open("res.txt");
	
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
	system("pause"); 
	return 0;
}
