#ifndef __UTIL_H__
#define __UTIL_H__

#include<iostream>
#include<list>
#include<tuple>
#include<math.h>

using namespace std;

class Util
{
    public:
        bool isPrime(long long N);
        long long gcd(long long a, long long b);
        long long* egcd(long long a, long long b);
        long long lcm(long long a, long long b);
        long long getPower(long long p, long long r, long long N, long long q=1);
        list<tuple<long long, long long>> factorize(long long N);
};

#endif // __UTIL_H__