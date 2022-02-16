#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int a, b;
	int flag = 0;
	int i=1;
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
	while ( ! fin.eof() ) {
		file >> a;
		fin >> b;
		if (a != b) {
			flag++;
			cout << i << "\n";
		}
		if(flag>10)
		break;
		i++;
	}
	cout << flag ;
	system("pause");
	return 0;

}
