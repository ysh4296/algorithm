bool miller_rabin(ll N,ll a) { // is N prime? calculate with nature number a
    if(a % N == 0) return true;
    ll k = N-1; // k means N-1
    while(1) {
        ll temp = modular(a, k, N); // a^k mod N
        //a^N-1 (mod N) == 1 is Fermat's little Theorem
        if(temp == N-1) return true; // a^k = -1 (mod N)
        if (k % 2) return (temp == 1 || temp == N-1); a^(2*d + 1) = 1,-1(mod N)
        k /= 2;
    }
}
