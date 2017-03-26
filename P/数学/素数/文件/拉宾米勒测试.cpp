#include <iostream>
#include <cstdlib>

using namespace std;

static unsigned g_aPrimeList[] = { // 素数表
        1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
        43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 113,
        193, 241, 257, 337, 353, 401, 433, 449, 577, 593, 641,
        673, 769, 881, 929, 977, 1009, 1153, 1201, 1217, 1249,
        1297,1361, 1409, 1489, 1553, 1601, 1697, 1777, 1873,
        1889, 2017, 2081, 2113, 2129, 2161, 2273, 2417, 2593,
        2609, 2657, 2689, 2753, 2801, 2833, 2897, 3041, 3089,
        3121, 3137, 3169, 3217, 3313, 3329, 3361, 3457, 3617,
        3697, 3761, 3793, 3889, 4001, 4049, 4129, 4177, 4241,
        4273, 4289, 4337, 4481, 4513, 4561, 4657, 4673, 4721,
        4801, 4817, 4993, 5009, 5153, 5233, 5281, 5297, 5393,
        5441, 5521, 5569, 5857, 5953, 6113, 6257, 6337, 6353,
        6449, 6481, 6529, 6577, 6673, 6689, 6737, 6833, 6961,
        6977, 7057, 7121, 7297, 7393, 7457, 7489, 7537, 7649,
        7681, 7793, 7841, 7873, 7937, 8017, 8081, 8161, 8209,
        8273, 8353, 8369, 8513, 8609, 8641, 8689, 8737, 8753,
        8849, 8929, 9041, 9137, 9281, 9377, 9473, 9521, 9601,
        9649, 9697, 9857
};

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


bool RabbinMillerTest(unsigned n){
    // 小于2的数即不是合数也不是素数
    if (n<2)throw 0;
    //求素数表元素个数
    const unsigned nPrimeListSize=sizeof(g_aPrimeList)/sizeof(unsigned);
    // 按照素数表中的数对当前素数进行判断
    for(int i=0;i<nPrimeListSize;++i){
        // 如果已经小于当前素数表的数，则一定是素数
        if (n/2+1<=g_aPrimeList[i]) return true;
        // 余数为0则说明一定不是素数
        if (0==n%g_aPrimeList[i]) return false;
    }
    // 找到r和m，使得n = 2^r * m + 1;
    int r = 0, m = n - 1; // ( n - 1 ) 一定是合数
    while ( 0 == ( m & 1 ) ){
        m >>= 1; // 右移一位
        r++; // 统计右移的次数
    }
    const unsigned nTestCnt = 8; // 表示进行测试的次数
    // 利用随机数进行测试，
    for (unsigned i = 0; i < nTestCnt; ++ i){
        int a = g_aPrimeList[rand() % nPrimeListSize];
        if ( 1 != Montgomery(a, m, n) ){
            int j = 0;
            int e = 1;
            for ( ; j < r; ++j ){
                if ( n - 1 == Montgomery( a, m * e, n ) )break;
                e <<= 1;
            }
            if (j == r)return false;
        }
    }
    return true;
}

int main(){
    int val_test;

    cin >> val_test;
    cout << RabbinMillerTest(val_test) << endl;

    return 0;
}
