#ifndef __X_H__
#define __X_H__
	long long int IP(long long a, long long b, long long c, long long d, long long e, int len, int flag);
	int duan(int ds);
int duan(int ds){
	int dp;
	switch (ds) {
			case 'A':
				dp = ds - 55;
				break;
			case 'B':
				dp = ds - 55;
				break;
			case 'C':
				dp = ds - 55;
				break;
			case 'D':
				dp = ds - 55;
				break;
			case 'E':
				dp = ds - 55;
				break;
			case 'F':
				dp = ds - 55;
				break;
			default:
				dp = ds - 48;
		}
	return dp;
}
long long int IP(long long a,long long b,long long c,long long d,long long e,int len,int flag)
{
	int zw1[50], zw2[50], zw3[50], zw4[50];
	for (int i = 7; i >= 0; i--) {
			zw1[i] = a % 2;
			a /= 2;
		}
		for (int i = 15; i >= 8; i--) {
			zw1[i] = b % 2;
			b /= 2;
		}
		for (int i = 23; i >= 16; i--) {
			zw1[i] = c % 2;
			c /= 2;
		}
		for (int i = 31; i >= 24; i--) {
			zw1[i] = d % 2;
			d /= 2;
		}
		//网址转化
		for (int i = 0; i < e; i++) {
			zw2[i] = 1;
		}
		for (int i = 0; i <= 31; i++) {
			zw3[i] = zw1[i] & zw2[i];
			zw4[i] = zw3[i];
		}
		for (int i = e; i < 32; i++) {
			zw4[i] = 1;
		}

		//重新赋值
		int ss = 0, sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			a += zw3[i] * sss;
			sss /= 2;
		}
		ss += 8;
		sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			b += zw3[i] * sss;
			sss /= 2;
		}
		ss += 8;
		sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			c += zw3[i] * sss;
			sss /= 2;
		}
		ss += 8;
		sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			d += zw3[i] * sss;
			sss /= 2;
		}
		
		if(flag==1)
		return  16777216 * a + 65536 * b + 256 * c + d;
		else
		{
			a = 0;
			b = 0;
			c = 0;
			d = 0;
			ss = 0;
			sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			a += zw4[i] * sss;
			sss /= 2;
		}
		ss += 8;
		sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			b += zw4[i] * sss;
			sss /= 2;
		}
		ss += 8;
		sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			c += zw4[i] * sss;
			sss /= 2;
		}
		ss += 8;
		sss = 128;
		for (int i = ss; i <= ss + 7; i++) {
			d += zw4[i] * sss;
			sss /= 2;
		}
		return 16777216 * a + 65536 * b + 256 * c + d;
		}
} 
#endif
