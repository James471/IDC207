#include<iostream>
#include<math.h>
#include "Util.h"
using namespace std;
class Primality
{
    Util obj;
    public:
        bool isPrimeByMRPT(long long a, long long N, bool wantDetails);
        bool step4AndBeyond(long long h, long long N, long long n, long long pw, bool wantDetails);
};