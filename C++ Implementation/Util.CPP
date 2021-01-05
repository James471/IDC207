#include "Util.h"

bool Util::isPrime(long long N) 
{
    long long root = int(sqrt(N)) + 1;
    if(N==2)
        return true;
    for(long long i = 2; i <= root; i++)
    {
        if(N%i==0)
            return false;
    }
    return true;
}

long long Util::gcd(long long a, long long b) 
{
    if(b==0)
        return a;
    return gcd(b,a%b);   
}

long long* Util::egcd(long long a, long long b) 
{
    // Source- https://web.iisermohali.ac.in/moodle/mod/page/view.php?id=8554
    long long a0, b0, x0, y0, x1, y1, p, q;
    long long ar[6];
    if(a >= b)
    {
        a0 = a;
        b0 = b;
        x0 = 1;
        x1 = 0;
        y0 = 0;
        y1 = 1;
        p = 1;
    }
    else
    {
        a0 = b;
        b0 = a;
        x0 = 1;
        x1 = 0;
        y0 = 0;
        y1 = 1;
        p = 0;
    }
    while (b0 != 0)
    {
        q = a0/b0;
        a0 = b0;
        b0 = a0 % b0;
        x0 = q*x0 + x1;
        x1 = x0;
        y0 = q*y0 + y1;
        y1 = y0;
        p = 1 - p;
    }
    if (p == 1)
    {
        ar[0] = a0;
        ar[1] = y1;
        ar[2] = x1;
        ar[3] = a*y0;
        ar[4] = y0;
        ar[5] = x0;
    }
    else
    {
        ar[0] = a0;
        ar[1] = y0 - y1;
        ar[2] = x0 - x1;
        ar[3] = a*y0;
        ar[4] = y0;
        ar[5] = x0;
    }
    cout<<ar[1]<<"*"<<a<<ar[2]<<"*"<<b<<"=gcd("<<a<<","<<b<<")="<<ar[0];
    return ar;
}

long long Util::lcm(long long a, long long b) 
{
    return (a*b)/gcd(a,b);
}

long long Util::getPower(long long p, long long r, long long N, long long q) 
{
    if (r%2==1)
        q=(q*p)%N;
    p=(p*p)%N;
    r=r/2;
    if (r>0)
        return getPower(p,r,N,q);
    else
        return q;
}

list<tuple<long long, long long>> Util::factorize(long long N) 
{
    list<tuple<long long, long long>> factors;
    long long i = 2;
    while(N>0)
    {
        long long power = 0;
        while(N%i==0)
        {
            power++;
            N=N/i;
        }
        if(power!=0)
            factors.push_back(make_tuple(i, power));
    }
    return factors;
}
