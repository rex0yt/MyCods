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

bool IsPrime(unsigned n){

    // 小于2的数即不是合数也不是素数
    if ( n < 2 )throw 0;
    static unsigned aPrimeList[] = {
        2, 3, 5, 7, 11, 17, 19, 23, 29, 31, 41,
        43, 47, 53, 59, 67, 71, 73, 79, 83, 89, 97
    };
    const int nListNum = sizeof(aPrimeList) / sizeof(unsigned);
    // 按照素数表中的数对当前素数进行判断
    for (int i=0;i<nListNum;++i)
        if (1!=Montgomery(aPrimeList[i],n-1,n))
            return false;// 蒙格马利算法

    return true;
}

int main(){
    return 0;
}
