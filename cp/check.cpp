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
	ifstream fin; // �Ȳ����ļ�, �ȴ�����
	scanf("%s ",name1);
	cin>>name2;
	file.open(name1,ios::in);
	fin.open(name2,ios::in); // fstream��open����������һ���ļ�
	if(!file||!fin)
	cout<<"�򿪴���"<<endl;
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
