#include<iostream>
#include<iterator>
#include<tuple>
#include "Util.CPP"
class RSA
{
    Util obj;
    public:
    long long getDecryptionKey(long long N, long long e, bool wantDetails)
    {
        list<tuple<long long, long long>> factors = obj.factorize(N);
        int flag = 1;
        long long facts[2];
        if(factors.size()==2)
        {
            list<tuple<long long, long long>> :: iterator it;
            int i=0;
            for(it=factors.begin(); it!=factors.end(); ++it)
            {
                if(get<1>(*it)!=1)
                    flag=0;
                else
                    facts[i]=get<0>(*it);
                i++;
            }
            if(flag==1)
            {
                long long LCM = obj.lcm(facts[0]-1,facts[1]-1);
                e = e % LCM;
                for(long long x = 1; x < LCM; x++)
                {
                    if((e * x) % LCM == 1)
                    {
                        cout<<"Decryption Key="<<x<<endl;
                        return x;
                    }
                }
                cout<<"Decryption Key=1"<<endl;
                return 1;
            }
            else
            {
                cout<<"Invalid input"<<endl;
            }
            
        }
    }
};