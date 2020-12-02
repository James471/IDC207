#include<iostream>
#include<math.h>
#include "Util.CPP"
using namespace std;
class Primality
{
    Util obj;
    public:
    bool isPrimeByMRPT(long long a, long long N, bool wantDetails)
    {
        long long n = 0;
        long long temp = N-1;
        long long pw = 0;
        while(temp>0)
        {
            temp=temp/2;
            pw++;
        }
        long long r = (N-1)/(pow(2,pw));
        long long s = (r-1)/2;
        if(wantDetails)
        {
            cout<<N<<"= 1 + (2^"<<pw<<")*(2*"<<s<<"+1)"<<endl;
            cout<<"k+1="<<pw<<endl;
            cout<<"r="<<r<<endl;
            cout<<"This completes step 1"<<endl;
            cout<<"-------------------------------"<<endl;
            long long h = obj.getPower(a,r,N);
            cout<<"h="<<h;
            cout<<"This completes step 2"<<endl;
            if(h==1)
            {
                cout<<"N is probably prime. This completes step 3 where we have to check if h=1"<<endl;
                return true;
            }
            else 
            {
                cout<<"h is not equal to 1. This completes step 3 where we have to check if h=1"<<endl;
                step4AndBeyond(h,N,n,pw,wantDetails);
            }
        }
    }

    bool step4AndBeyond(long long h, long long N, long long n, long long pw, bool wantDetails)
    {
        if(wantDetails)
        {
            cout<<"In the beginning of step 4-"<<endl;
            cout<<"h="<<h<<endl;
            cout<<"n="<<n<<endl;
        }
        long long gcd = obj.gcd(h-1,N);
        if(wantDetails)
            cout<<"gcd="<<gcd;
        if(gcd!=1)
        {
            cout<<"N is composite"<<endl;
            return false;
        }
        else if(h==N-1)
        {
            cout<<"N is probably prime"<<endl;
            return true;
        }
        else
        {
            h=obj.getPower(h,2,N);
            n+=1;
            if(wantDetails)
            {
                cout<<"At the end of step 4"<<endl;
                cout<<"h="<<h<<endl;
                cout<<"n="<<n<<endl;
            }
            if(n==pw)
            {
                cout<<"N is composite"<<endl;
                return false;
            }
            else
            {
                cout<<"Will have to go back to step 4"<<endl;
                cout<<"-------------------------------"<<endl;
                step4AndBeyond(h,N,n,pw,wantDetails);
            }
            
        }    
    }

};