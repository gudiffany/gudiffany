#include <iostream>
#include <fstream>
using namespace std;

int main() {
	long long int num1[10001], num2[10001], num3[10001], num4[10001], num5[10001];//rule�ķֵ�ʮ����ԭip
	long long int num11[10001], num21[10001], num31[10001], num41[10001], num51[10001];//rule�ķֵ�ʮ������ip
	int duan1[10001], duan2[10001], duan3[10001], duan4[10001];//�˵�
	char ds1[10001], ds2[10001], ds3[10001], ds4[10001];//ʮ������
	int dp1[10001], dp2[10001], dp3[10001], dp4[10001];
	long long int ip11[10001], ip21[10001], ip1[10001], ip2[10001]; //ʮ����ip
	int sum1[10001], sum2[10001];//0xת��Ϊʮ����
	int zw1[50], zw2[50], zw3[50], zw4[50];

	char s, l, k;//��ȥ�ַ�
	int s1;//��ȥ�ַ�
	int len = 0;


	ifstream file("text.txt");
	while ( ! file.eof() ) {
		file >> s >> num1[len] >> s >> num2[len] >> s >> num3[len] >> s >> num4[len] >> s >> num5[len];
		file >> num11[len] >> s >> num21[len] >> s >> num31[len] >> s >> num41[len] >> s >> num51[len];
		file >> duan1[len] >> s >> duan2[len] >> duan3[len] >> s >> duan4[len];
		file >> s1 >> s >> ds1[len] >> ds2[len] >> l >> s1 >> k >> ds3[len] >> ds4[len];
		/*��������*/

		/*ipת��*/
		for (int i = 7; i >= 0; i--) {
			zw1[i] = num1[len] % 2;
			num1[len] /= 2;
		}
		for (int i = 15; i >= 8; i--) {
			zw1[i] = num2[len] % 2;
			num2[len] /= 2;
		}
		for (int i = 23; i >= 16; i--) {
			zw1[i] = num3[len] % 2;
			num3[len] /= 2;
		}
		for (int i = 31; i >= 24; i--) {
			zw1[i] = num4[len] % 2;
			num4[len] /= 2;
		}
		//��ַת��
		for (int i = 0; i < num5[len]; i++) {
			zw2[i] = 1;
		}
		for (int i = 0; i <= 31; i++) {
			zw3[i] = zw1[i] & zw2[i];
			zw4[i] = zw3[i];
		}
		for (int i = num5[len]; i < 32; i++) {
			zw4[i] = 1;
		}

		//���¸�ֵ
		int ss = 0, sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			num1[len] += zw3[i] * sss;
			sss /= 2;
		}
		ss += 8;
		sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			num2[len] += zw3[i] * sss;
			sss /= 2;
		}
		ss += 8;
		sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			num3[len] += zw3[i] * sss;
			sss /= 2;
		}
		ss += 8;
		sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			num4[len] += zw3[i] * sss;
			sss /= 2;
		}
		ip1[len] = 16777216 * num1[len] + 65536 * num2[len] + 256 * num3[len] + num4[len];
		num1[len] = 0;
		num2[len] = 0;
		num3[len] = 0;
		num4[len] = 0;
		ss = 0;
		sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			num1[len] += zw4[i] * sss;
			sss /= 2;
		}
		ss += 8;
		sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			num2[len] += zw4[i] * sss;
			sss /= 2;
		}
		ss += 8;
		sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			num3[len] += zw4[i] * sss;
			sss /= 2;
		}
		ss += 8;
		sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			num4[len] += zw4[i] * sss;
			sss /= 2;
		}
		ip11[len] = 16777216 * num1[len] + 65536 * num2[len] + 256 * num3[len] + num4[len];
		/***************************************************************/

		for (int i = 7; i >= 0; i--) {
			zw1[i] = num11[len] % 2;
			num11[len] /= 2;
		}
		for (int i = 15; i >= 8; i--) {
			zw1[i] = num21[len] % 2;
			num21[len] /= 2;
		}
		for (int i = 23; i >= 16; i--) {
			zw1[i] = num31[len] % 2;
			num31[len] /= 2;
		}
		for (int i = 31; i >= 24; i--) {
			zw1[i] = num41[len] % 2;
			num41[len] /= 2;
		}
		//��ַת��
		for (int i = 0; i < num51[len]; i++) {
			zw2[i] = 1;
		}
		for (int i = 0; i <= 31; i++) {
			zw3[i] = zw1[i] & zw2[i];
			zw4[i] = zw3[i];
		}
		for (int i = num51[len]; i < 32; i++) {
			zw4[i] = 1;
		}

		//���¸�ֵ
		ss = 0, sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			num11[len] += zw3[i] * sss;
			sss /= 2;
		}
		ss += 8;
		sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			num21[len] += zw3[i] * sss;
			sss /= 2;
		}
		ss += 8;
		sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			num31[len] += zw3[i] * sss;
			sss /= 2;
		}
		ss += 8;
		sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			num41[len] += zw3[i] * sss;
			sss /= 2;
		}
		ip2[len] = 16777216 * num11[len] + 65536 * num21[len] + 256 * num31[len] + num41[len];
		num11[len] = 0;
		num21[len] = 0;
		num31[len] = 0;
		num41[len] = 0;
		ss = 0;
		sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			num11[len] += zw4[i] * sss;
			sss /= 2;
		}
		ss += 8;
		sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			num21[len] += zw4[i] * sss;
			sss /= 2;
		}
		ss += 8;
		sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			num31[len] += zw4[i] * sss;
			sss /= 2;
		}
		ss += 8;
		sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			num41[len] += zw4[i] * sss;
			sss /= 2;
		}
		ip21[len] = 16777216 * num11[len] + 65536 * num21[len] + 256 * num31[len] + num41[len];
		switch (ds1[len]) {
			case 'A':
				dp1[len] = ds1[len] - 55;
				break;
			case 'B':
				dp1[len] = ds1[len] - 55;
				break;
			case 'C':
				dp1[len] = ds1[len] - 55;
				break;
			case 'D':
				dp1[len] = ds1[len] - 55;
				break;
			case 'E':
				dp1[len] = ds1[len] - 55;
				break;
			case 'F':
				dp1[len] = ds1[len] - 55;
				break;
			default:
				dp1[len] = ds1[len] - 48;
		}
		switch (ds2[len]) {
			case 'A':
				dp2[len] = ds2[len] - 55;
				break;
			case 'B':
				dp2[len] = ds2[len] - 55;
				break;
			case 'C':
				dp2[len] = ds2[len] - 55;
				break;
			case 'D':
				dp2[len] = ds2[len] - 55;
				break;
			case 'E':
				dp2[len] = ds2[len] - 55;
				break;
			case 'F':
				dp2[len] = ds2[len] - 55;
				break;
			default:
				dp2[len] = ds2[len] - 48;
		}
		switch (ds3[len]) {
			case 'A':
				dp3[len] = ds3[len] - 55;
				break;
			case 'B':
				dp3[len] = ds3[len] - 55;
				break;
			case 'C':
				dp3[len] = ds3[len] - 55;
				break;
			case 'D':
				dp3[len] = ds3[len] - 55;
				break;
			case 'E':
				dp3[len] = ds3[len] - 55;
				break;
			case 'F':
				dp3[len] = ds3[len] - 55;
				break;
			default:
				dp3[len] = ds3[len] - 48;
		}
		switch (ds4[len]) {
			case 'A':
				dp4[len] = ds4[len] - 55;
				break;
			case 'B':
				dp4[len] = ds4[len] - 55;
				break;
			case 'C':
				dp4[len] = ds4[len] - 55;
				break;
			case 'D':
				dp4[len] = ds4[len] - 55;
				break;
			case 'E':
				dp4[len] = ds4[len] - 55;
				break;
			case 'F':
				dp4[len] = ds4[len] - 55;
				break;
			default:
				dp4[len] = ds4[len] - 48;
		}
		sum1[len] = 16 * dp1[len] + dp2[len];
		sum2[len] = 16 * dp3[len] + dp4[len];
		/*ʮ�����ƴ���*/
		len++;
	}
	long long int ans1[10001], ans2[10001], ans3[10001], ans4[10001], ans5[10001];
	int packlen = 0;
	int flag = 0;
	ifstream fin("pack.txt");
	while ( ! fin.eof() ) {
		fin >> ans1[packlen] >> ans2[packlen] >> ans3[packlen] >> ans4[packlen] >> ans5[packlen];
		packlen++;
	}
	len--;
	ofstream fout;
	fout.open("output.txt");
	for (int i = 0; i < packlen; i++) {
		flag = 0;
		for (int j = 0; j < len; j++) {
			if ( ans3[i] >= duan1[j] && ans3[i] <= duan2[j] && ans4[i] >= duan3[j]
			        && ans4[i] <= duan4[j]) {
				if ((ans5[i] >= sum1[j] && ans5[i] <= sum2[j]) || (sum1[j] == 0 && sum2[j] == 0)) {


					if (num5[j] == 32 && num51[j] == 32 && ans1[i] == ip1[j] && ans2[i] == ip2[j]) {
						flag = 1;
						fout << j << "\n";
						break;
					}
					if (num5[j] == 32 && num51[j] == 31 && ans1[i] == ip1[j] && (ans2[i] == ip2[j] || ans2[i] == ip2[j] + 1)) {
						flag = 1;
						fout << j << "\n";
						break;
					}
					if (num5[j] == 32 && num51[j] < 31) {
						if (ans1[i] == ip1[j] && ans2[i] >= ip2[j] && ans2[i] <= ip21[j]) {
							flag = 1;
							fout << j << "\n";
							break;
						}

					}
					if (num5[j] == 31 && num51[j] == 32 && ans2[i] == ip2[j] && (ans1[i] == ip1[j] || ans1[i] == ip1[j] + 1)) {
						flag = 1;
						fout << j << "\n";
						break;

					}
					if (num5[j] == 31 && num51[j] == 31 && (ans2[i] == ip2[j] || ans2[i] == ip2[j] + 1) && (ans1[i] == ip1[j]
					        || ans1[i] == ip1[j] + 1)) {
						flag = 1;
						fout << j << "\n";
						break;

					}

					if (num5[j] == 31 && num51[j] < 31) {
						if ((ans1[i] == ip1[j] || ans1[i] == ip1[j] + 1) && ans2[i] >= ip2[j]  && ans2[i] <= ip21[j] ) {
							flag = 1;
							fout << j << "\n";
							break;
						}

					}
					if (num5[j] < 31 && num51[j] == 32) {
						if (ans2[i] == ip2[j] && ans1[i] >= ip1[j]  && ans1[i] <= ip11[j] ) {
							flag = 1;
							fout << j << "\n";
							break;
						}


					}
					if (num5[j] < 31 && num51[j] == 31) {
						if (ans1[i] >= ip1[j] && ans1[i] <= ip11[j] && (ans2[i] == ip2[j] || ans2[i] == ip21[j] + 1)) {
							flag = 1;
							fout << j << "\n";
							break;
						}

					}
					if (num5[j] < 31 && num51[j] < 31) {
						if (ans2[i] >= ip2[j] && ans2[i] <= ip21[j] && ans1[i] >= ip1[j] && ans1[i] <= ip11[j]) {
							flag = 1;
							fout << j << "\n";
							break;
						}

					}
				}

			}

		}
		if (flag == 0)
			fout << -1 << "\n";
	}
	return 0;
}







