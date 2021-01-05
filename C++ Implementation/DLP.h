#include<iostream>
#include<list>
using namespace std;
class DLP
{
    static long long callsToAlgo;
    static long long callsToDiscreetLogBruteForce;
    public:
        long long dot(long long a, long long b, long long N);
        long long poweringAlgo(long long p, long long q, long long r, long long N, bool wantDetails);
        long long getPower(long long p, long long k, long long N, bool wantDetails=true);
        bool isGenerator(long long i, long long N);
        list<long long> getGenerator(long long Z, int num);
        long long discreetLogBruteForce(long long base, long long num, long long N, bool wantDetails);
};