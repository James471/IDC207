#include<iostream>
#include<list>
using namespace std;
class DLP
{
    static long long callsToAlgo;
    static long long callsToDiscreetLogBruteForce;
    public:
    long long dot(long long a, long long b, long long N)
    {
        return (a*b)%N;
    }

    long long poweringAlgo(long long p, long long q, long long r, long long N, bool wantDetails)
    {
        callsToAlgo++;
        if (r%2==1)
            q=dot(q,p,N);
        p=dot(p,p,N);
        r=r/2;
        if(wantDetails)
        {
            cout<<"p="<<p<<endl;
            cout<<"q="<<q<<endl;
            cout<<"r="<<r<<endl;
            cout<<"------------------------"<<endl;
        }
        if (r>0)
            return poweringAlgo(p,q,r,N,wantDetails);
        else
            return q;
    }

    long long getPower(long long p, long long k, long long N, bool wantDetails=true)
    {
        long long res = poweringAlgo(p,1,k,N,wantDetails);
        if(wantDetails)
        {
            cout<<"Number of calls to poweringAlgo="<<callsToAlgo<<endl;
        }
        return res;
    }

    bool isGenerator(long long i, long long N)
    {
        long long count = 1;
        long long a = i;
        while(true){
            a=(a*i)%N;
            count++;
            if(count==N-1){
                return true;
            }
            if(a==i){
                return false;
            }
        }
    }

    list<long long> getGenerator(long long Z, int num)
    {
        list <long long> generators;
        for(int i=Z-1; i>=2; i--)
        {
            if(isGenerator(i,Z))
            {
                cout<<i<<endl;
                generators.push_back(i);
                if(num==1)
                    return generators;
            }
        }
        return generators;
    }

    long long discreetLogBruteForce(long long base, long long num, long long N, bool wantDetails)
    {
        long long a = 1;
        long long temp = base;
        while(true)
        {
            callsToDiscreetLogBruteForce++;
            a++;
            temp = (temp*base)%N;
            if(temp == num)
            {
                if(wantDetails)
                    cout<<"Number of steps"<<callsToDiscreetLogBruteForce;
                return a;
            }
        }
    }

};
long long DLP::callsToAlgo = 0;
long long DLP::callsToDiscreetLogBruteForce = 0;