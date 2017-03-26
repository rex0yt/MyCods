//快速计算(n^e)%m的值
unsigned Montgomery(unsigned n,unsigned p,unsigned m){
    unsigned k=1;
    n%=m;
    while(p != 1){
        if(0 != (p&1)) k = (k * n) % m;
        n = (n * n) % m;
        p >>= 1;
    }
    return ( n * k ) % m;
}
