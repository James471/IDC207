#include<iostream>
#include<math.h>
#include "Util.CPP"
class CRT
{
    Util obj;
    public:
    long long getA(long long a1, long long a2, long long N1, long long N2)
    {
        long long* ar = obj.egcd(N1, N2);
        long long e1 = (ar[2]*N2) % (N1*N2);
        long long e2 = (ar[1]*N1) % (N1*N2);
        long long a = (a1*e1 + a2*e2) % (N1*N2);
        return a;
    }

    long long getPower(long long a, long long h)
    {
        long long k = 1;
        while (true)
        {
            if(int(pow(a,k)) == h)
            {
                return k;
            }
            k++;
        }
        
    }

    long long getLog(long long g1, long long g2, long long h1, long long h2, bool wantDetails)
    {
        long long k1 = getPower(g1, h1);
        long long k2 = getPower(g2, h2);
        long long M1 = getPower(g1, 1);
        long long M2 = getPower(g2, 1);
        long long m = obj.gcd(M1, M2);
        long long kprime = k1%m;
        long long n1 = (k1 - kprime)/m;
        long long n2 = (k2 - kprime)/m;
        long long n = getA(n1, n2, M1/m, M2/m);
        long long k = (n*m + kprime)%(M1*M2);
        if (wantDetails)
        {
            cout<<"k1="<<k1<<endl<<"k2="<<k2<<endl<<"M1="<<M1<<endl<<"M2="<<M2<<endl<<"m="<<m<<"k\'="<<kprime<<endl;
            cout<<"n1="<<n1<<endl<<"n2="<<n2<<endl<<"n="<<n<<endl<<"k="<<k;
        }
        return k;
    }
};