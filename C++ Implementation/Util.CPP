#include<iostream>
#include<list>
#include<tuple>
#include<math.h>
using namespace std;
class Util
{
    public:
    bool isPrime(long long N)
    {
        long long root = int(sqrt(N)) + 1;
        for(long long i = 0; i <= root; i++)
        {
            if(N%i==0)
                return false;
        }
        return true;
    }

    long long gcd(long long a, long long b)
    {
        if(b==0)
            return a;
        return gcd(b,a%b);
    }

    long long lcm(long long a, long long b)
    {
        return (a*b)/gcd(a,b);
    }
    
    long long getPower(long long p, long long r, long long N, long long q=1)
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

    list<tuple<long long, long long>> factorize(long long N)
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

};