// 快速计算(n ^ e) % m的值，与power算法极类似
unsigned Montgomery(unsigned n, unsigned p, unsigned m){
    unsigned r = n % m; // 这里的r可不能省
    unsigned k = 1;
    while (p > 1){
        if ((p & 1)!=0)k = (k * r) % m; // 直接取模
        r = (r * r) % m; // 同上
        p /= 2;
    }
    return (r * k) % m; // 还是同上
}

int main(){
    return 0;
}
