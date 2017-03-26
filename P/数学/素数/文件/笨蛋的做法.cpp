bool IsPrime(unsigned n){
     //小于2的数即不是合数也不是素数
    if(n < 2)throw 0;
    //和比它小的所有的数相除，如果都除不尽，证明素数
    for (unsigned i = 2; i < n; ++ i){
        //除尽了，则是合数
        if (n % i == 0)
            return false;
    }
    return true;
}

