int bitOr(int x, int y) {
	return ~((~x)&(~y));
}

int bitAnd(int x, int y) {
	
	return ~((~x)|(~y));
}

int bitXor(int x, int y) {
  return ~((~((~x)&y))&(~((~y)&x)));
}

int isNotEqual(int x, int y) {
  return !!(x^y);
}

int copyLSB(int x) {
	return (x<<31)>>31;  //根据题目存储器用4个字节存储int得出的左移31 右移31
}

int specialBits(void) {
    return ~(0xD7 << 14);　　／／0xFFCA3FFF=1111 1111 1100 1010 00 1111 1111 1111
}

int conditional(int x, int y, int z) {
	int n=~(!x)+1;  //+1的原因是0001取反后是1110需要增加1才是1111，0000取反后是1111，+1后为10000，实际是0000
	return (y&~n)|(z&n);
}

int bitParity(int x) {
	x^=(x>>16);
	x^=(x>>8);
	x^=(x>>4);
	x^=(x>>2);
	x^=(x>>1);
	return (x & 1);
}

int minusOne(void) {
  return ~0x0;
}

int tmax(void) {
  return ~(0x1<<31);
}

int negate(int x) {
  return (~x)+1;
}

int isNegative(int x) {
  return x>>31;
}

int isPositive(int x) {
  return (!(x>>31))&(!!x);
}

int bang(int x) {
	x|=(x>>16);
	x|=(x>>8);
	x|=(x>>4);
	x|=(x>>2);
	x|=(x>>1);
  return (~x)&1;
}

int addOK(int x, int y) {
  int sum=x+y;
  int x_sign=x>>31;
  int y_sign=y>>31;
  int sum_sign=sum>>31;
  return !((~(x_sign^y_sign))&(x_sign^sum_sign));
}

int twosComp2SignMag(int x) {
	int negative=(~x+1)+(x>>31)<<31;  //如果x为负数这么处理,负数的有符号数
	int sign=~((x>>31)<<31)+1;   //如果x为整数就1111111111(32个1)，否则000000000（32个0）
	return  (x&sign)|(negative&~sign
}
 
 

int byteSwap(int x, int n, int m) {
	int num = 0;
	n = n<<3; // n == n*3
	m = m<<3; //m == n*3
	num = 0xff & ((x>>n) ^ (x>>m)); // 1111 1111
	x = x ^ (num<<n); 
	x = x ^ (num<<m);
	return x;
 /*12345678
 0001'0010'0011'0100'0101'0110'0111'1000
   1    2    3    4   5     6    7    8
 
 0101'0110'0011'0100'0001'0010'0111'1000
   5    6     3   4   1     2    7    8
 0000'0000'0000'0000'0000'0000'0000'1000
 8
 0000'0000'0000'0000'0000'0000'0001'1000
 18*/
}
int bitCount(int x) {   
	int mask = 0x11 + (0x11 << 8) + (0x11 << 16) + (0x11 << 24);
	int count = x & mask;
x   0000'0000'0000'0000'0000'0000'0001'1010
	0011'0011'0011'0011'0011'0011'0011'0011
	
	0000'0000'0000'0000'0000'0000'0011'0001
	
	0000'0000'0000'0000'0000'0000'0000'1111
	int total = 0;
	int addMask = 0x0F;
	x = x >> 1;
	count += x & mask;
	x = x >> 1;
	count += x & mask;
	x = x >> 1;
	count += x & mask;
	total += (count & addMask) + ((count >> 4) & addMask)
      + ((count >> 8) & addMask) + ((count >> 12) & addMask)
      + ((count >> 16) & addMask) + ((count >> 20) & addMask)
      + ((count >> 24) & addMask) + ((count >> 28) & addMask);
	return total;
}


int logicalShift(int x, int n) {
  return return (x >> n) & (~(0x80 << 24) >> (n + ~0x00));
}

