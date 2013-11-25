#include <iostream>
#include <string>

#define ulong unsigned int

using namespace std;

string MD5(string);
string append(string);
string HexStr(ulong);

ulong F(ulong, ulong, ulong);
ulong G(ulong, ulong, ulong);
ulong H(ulong, ulong, ulong);
ulong I(ulong, ulong, ulong);

ulong FF(ulong &, ulong, ulong, ulong, ulong, int, ulong);
ulong GG(ulong &, ulong, ulong, ulong, ulong, int, ulong);
ulong HH(ulong &, ulong, ulong, ulong, ulong, int, ulong);
ulong II(ulong &, ulong, ulong, ulong, ulong, int, ulong);

ulong reverse(ulong);




int main(void)
{
	string origin;
	while(1)
	{
		cout<<"Source string: ";
		getline(cin,origin);
		cout<<"Message digest: ";
		cout<<MD5(origin)<<endl<<endl;
	}

    return 0;
}




string MD5(string origin)
{
	ulong x[16], a, b, c, d , A, B, C, D;
	A = 0x67452301;
	B = 0xefcdab89;
	C = 0x98badcfe;
	D = 0x10325476;

	string appended_str = append(origin);

	int times = appended_str.length() / 64;

	for (int i = 0; i < times; i++)
	{

		for (int j = 0; j < 16; j++)
		{
			x[j] = 0;
			for (int k = 0; k < 4; k++)
			{
				x[j] += (unsigned char)((int)appended_str[i*64 + j*4 + k]) << (k * 8);
			}
		}

		a = A;
		b = B;
		c = C;
		d = D;

        FF(a, b, c, d, x[ 0],  7, 0xd76aa478);
		FF(d, a, b, c, x[ 1], 12, 0xe8c7b756);
		FF(c, d, a, b, x[ 2], 17, 0x242070db);
		FF(b, c, d, a, x[ 3], 22, 0xc1bdceee);
		FF(a, b, c, d, x[ 4],  7, 0xf57c0faf);
		FF(d, a, b, c, x[ 5], 12, 0x4787c62a);
		FF(c, d, a, b, x[ 6], 17, 0xa8304613);
		FF(b, c, d, a, x[ 7], 22, 0xfd469501);
		FF(a, b, c, d, x[ 8],  7, 0x698098d8);
		FF(d, a, b, c, x[ 9], 12, 0x8b44f7af);
		FF(c, d, a, b, x[10], 17, 0xffff5bb1);
		FF(b, c, d, a, x[11], 22, 0x895cd7be);
		FF(a, b, c, d, x[12],  7, 0x6b901122);
		FF(d, a, b, c, x[13], 12, 0xfd987193);
		FF(c, d, a, b, x[14], 17, 0xa679438e);
		FF(b, c, d, a, x[15], 22, 0x49b40821);

        GG(a, b, c, d, x[ 1],  5, 0xf61e2562);
		GG(d, a, b, c, x[ 6],  9, 0xc040b340);
		GG(c, d, a, b, x[11], 14, 0x265e5a51);
		GG(b, c, d, a, x[ 0], 20, 0xe9b6c7aa);
		GG(a, b, c, d, x[ 5],  5, 0xd62f105d);
		GG(d, a, b, c, x[10],  9, 0x02441453);
		GG(c, d, a, b, x[15], 14, 0xd8a1e681);
		GG(b, c, d, a, x[ 4], 20, 0xe7d3fbc8);
		GG(a, b, c, d, x[ 9],  5, 0x21e1cde6);
		GG(d, a, b, c, x[14],  9, 0xc33707d6);
		GG(c, d, a, b, x[ 3], 14, 0xf4d50d87);
		GG(b, c, d, a, x[ 8], 20, 0x455a14ed);
		GG(a, b, c, d, x[13],  5, 0xa9e3e905);
		GG(d, a, b, c, x[ 2],  9, 0xfcefa3f8);
		GG(c, d, a, b, x[ 7], 14, 0x676f02d9);
		GG(b, c, d, a, x[12], 20, 0x8d2a4c8a);

        HH(a, b, c, d, x[ 5],  4, 0xfffa3942);
		HH(d, a, b, c, x[ 8], 11, 0x8771f681);
		HH(c, d, a, b, x[11], 16, 0x6d9d6122);
		HH(b, c, d, a, x[14], 23, 0xfde5380c);
		HH(a, b, c, d, x[ 1],  4, 0xa4beea44);
		HH(d, a, b, c, x[ 4], 11, 0x4bdecfa9);
		HH(c, d, a, b, x[ 7], 16, 0xf6bb4b60);
		HH(b, c, d, a, x[10], 23, 0xbebfbc70);
		HH(a, b, c, d, x[13],  4, 0x289b7ec6);
		HH(d, a, b, c, x[ 0], 11, 0xeaa127fa);
		HH(c, d, a, b, x[ 3], 16, 0xd4ef3085);
		HH(b, c, d, a, x[ 6], 23, 0x04881d05);
		HH(a, b, c, d, x[ 9],  4, 0xd9d4d039);
		HH(d, a, b, c, x[12], 11, 0xe6db99e5);
		HH(c, d, a, b, x[15], 16, 0x1fa27cf8);
		HH(b, c, d, a, x[ 2], 23, 0xc4ac5665);

        II(a, b, c, d, x[ 0],  6, 0xf4292244);
		II(d, a, b, c, x[ 7], 10, 0x432aff97);
		II(c, d, a, b, x[14], 15, 0xab9423a7);
		II(b, c, d, a, x[ 5], 21, 0xfc93a039);
		II(a, b, c, d, x[12],  6, 0x655b59c3);
		II(d, a, b, c, x[ 3], 10, 0x8f0ccc92);
		II(c, d, a, b, x[10], 15, 0xffeff47d);
		II(b, c, d, a, x[ 1], 21, 0x85845dd1);
		II(a, b, c, d, x[ 8],  6, 0x6fa87e4f);
		II(d, a, b, c, x[15], 10, 0xfe2ce6e0);
		II(c, d, a, b, x[ 6], 15, 0xa3014314);
		II(b, c, d, a, x[13], 21, 0x4e0811a1);
		II(a, b, c, d, x[ 4],  6, 0xf7537e82);
		II(d, a, b, c, x[11], 10, 0xbd3af235);
		II(c, d, a, b, x[ 2], 15, 0x2ad7d2bb);
		II(b, c, d, a, x[ 9], 21, 0xeb86d391);

        A = A + a;
		B = B + b;
		C = C + c;
		D = D + d;
	}

	string final =  HexStr(reverse(A)) + HexStr(reverse(B)) + HexStr(reverse(C)) + HexStr(reverse(D));
	while (final.length() < 32) final = "0" + final;
	return final;
}





string append(string origin)
{
	ulong length = origin.length();
	int k = length % 64;

	origin += (char)0x80;

	int times;
	if (k < 55) {times = 55-k;}
	else if (k == 55) {times = 119;}
	else {times = 119-k;}

	for (int i = 0; i < times; i++)
	{
		origin += (char)0x00;
	}

	ulong bits = length << 3;

	for (int i = 0; i < 4; i++)
	{
		origin += (bits >> (i << 3)) & 0xff;
	}

	for (int i = 0; i < 4; i++)
	{
		origin += char(0x00);
	}

    return origin;
}

string HexStr(ulong hex)
{
    int i = 0, j;
    char hex_char[9], tmp;
    while (hex != 0) {
        hex_char[i++] = hex%16 > 9 ? hex%16 + 39 + '0' : hex%16 + '0';
        hex = hex / 16;
    }
    hex_char[i--] = '\0';
    for (j = 0; j <= i/2; j++) {
        tmp = hex_char[j];
        hex_char[j] = hex_char[i-j];
        hex_char[i-j] = tmp;
    }

    string hex_str(hex_char);
	return hex_str;
}


/********************
F, G, H, I function
********************/
ulong F(ulong x, ulong y, ulong z)
{
	return x&y | ~x&z;
}

ulong G(ulong x, ulong y, ulong z)
{
	return x&z | y&~z;
}

ulong H(ulong x, ulong y, ulong z)
{
	return x^y^z;
}

ulong I(ulong x, ulong y, ulong z)
{
	return y^(x|~z);
}


/***********************
FF, GG, HH, II function
***********************/
ulong FF(ulong &a, ulong b, ulong c, ulong d, ulong mj, int s, ulong ti)
{
	//a = b + ((a + (F(b,c,d) + x[j] + ti) <<< s)
	a = b + (((a + F(b,c,d) + mj + ti) << s) | ((a + F(b,c,d) + mj + ti) >> (32-s)));
	return a;
}

ulong GG(ulong &a, ulong b, ulong c, ulong d, ulong mj, int s, ulong ti)
{
	a = b + (((a + G(b,c,d) + mj + ti) << s) | ((a + G(b,c,d) + mj + ti) >> (32-s)));
	return a;
}

ulong HH(ulong &a, ulong b, ulong c, ulong d, ulong mj, int s, ulong ti)
{
	a = b + (((a + H(b,c,d) + mj + ti) << s) | ((a + H(b,c,d) + mj + ti) >> (32-s)));
	return a;
}

ulong II(ulong &a, ulong b, ulong c, ulong d, ulong mj, int s, ulong ti)
{
	a = b + (((a + I(b,c,d) + mj + ti) << s) | ((a + I(b,c,d) + mj + ti) >> (32-s)));
	return a;
}


/***********************
 		reverse
***********************/
ulong reverse(ulong input)
{
	ulong output = 0;
	for (int i = 0; i < 4; i++)
	{
		output = output << 8 | (input >> (i * 8) & 0xff);
	}
	return output;
}