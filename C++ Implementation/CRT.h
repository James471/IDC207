#include<iostream>
#include<math.h>
#include "Util.h"
class CRT
{
    Util obj;
    public:
        long long getA(long long a1, long long a2, long long N1, long long N2);
        long long getPower(long long a, long long h);
        long long getLog(long long g1, long long g2, long long h1, long long h2, bool wantDetails);
};