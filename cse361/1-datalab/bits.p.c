#line 168 "bits.c"
int bitAnd(int x, int y) {
   int x1=  ~x;
 int y1=  ~y;
 int temp=  x1|y1;
 return ~temp;
}
#line 182
int leastBitPos(int x) {
   int mask1= ~x+1;
 int mask=  mask1&x;
 return mask;
}
#line 196
int replaceByte(int x, int n, int c) {
 int shift=  n <<3;
 int mask=  ~(0xFF<<shift);
 x = x& mask;
 c = c <<shift;
 return x|c;

}
#line 211
int conditional(int x, int y, int z) {
 int part1=( ~!!x)+1;
  int part2=( ~!x)+1;

 int q=  part1 & y;
 int p=  part2 & z;
  return q+p;

}
#line 227
int bitParity(int x) {
  x=( x>>16)^x;
  x=( x>>8)^x;
  x=( x>>4)^x;
  x=( x>>2)^x;
  x=( x>>1)^x;
  return x&1;
}
#line 244
int fitsBits(int x, int n) {
    int m=  n +(  ~0);

  int sign=(   x >> 31)  & 1;


  int mask=  ~(sign + ~0);


  x = x ^ mask;


  x = x >>( m);


  return !x;
}
#line 268
int isPositive(int x) {
  int y=(  x>>31)+1;
  int z=  !!x;
  int p=  z &y;
  return p;
}
#line 281
int isLess(int x, int y) {
  int case0=  x +( ~y+1);
  int case1=  x &( ~y);
  int case2=(   ~(x^y))&case0;
  int answer=(  case1|case2)>>31;
  answer = answer&1;
  return answer;
}
#line 300
int satMul3(int x) {
    return 2;
}
#line 311
int absVal(int x) {
  return 2;
}
#line 325
unsigned float_neg(unsigned uf) {
 return 2;
}
#line 339
unsigned float_half(unsigned uf) {
  return 2;
}
