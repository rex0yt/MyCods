bool IsPrime(unsigned n){
    //小于2的数即不是合数也不是素数
    if(n < 2)throw 0;
    // 和比它的一半小数相除，如果都除不尽，证明素数
    for(unsigned i = 2; i < n / 2 + 1; ++ i)
        if ( 0 == n % i )return false;

    return true;
}

