#include<iostream>
#include<iterator>
#include<tuple>
#include "Util.h"
class RSA
{
    Util obj;
    public:
        long long getDecryptionKey(long long N, long long e, bool wantDetails);      
};