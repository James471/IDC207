#include<iostream>
#include<conio.h>

#include "DLP.h"
#include "Util.h"
#include "Primality.h"
#include "RSA.h"
#include "CRT.h"

using namespace std;

void main()
{
    Util util;
    DLP dlp;
    Primality primality;
    RSA rsa;
    CRT crt;
    int choice=0;
    cout<<"This is a repository of several algorithms from IDC207 course."<<endl;
    cout<<"1.Discreet log and powers in multiplicative group"<<endl;
    cout<<"2.Primality"<<endl;
    cout<<"3.RSA"<<endl;
    cout<<"4.CRT"<<endl;
    cin>>choice;
    switch (choice)
    {
        case 1:
            cout<<"1. Check if the given number is a generator"<<endl<<"2. Find the generator"<<endl<<"3. Get power"<<endl<<"4. Get Discreet Log"<<endl;
            cin>>choice;
            switch (choice)
            {
                case 1:
                    long long num = 0;
                    long long N = 0;
                    cout<<"Enter the possible generator:";
                    cin>>num;                    
                    cout<<"Enter the value of N:";
                    cin>>N;
                    bool isGen = dlp.isGenerator(num, N);
                    if(isGen)
                    {
                        cout<<"It is a generator.";
                    }
                    else
                    {
                        cout<<"It is not a generator.";
                    }
                    break;
                
                case 2:
                    cout<<"Enter the value of N:";
                    long long N = 0;
                    cin>>N;
                    cout<<"Enter 1 if you want 1 generator else all generators will be returned:";
                    int num = 0;
                    cin>>num;
                    list<long long> gens;
                    gens = dlp.getGenerator(N, num);
                    for (auto it = gens.begin(); it != gens.end(); ++it)
                        cout<< *it<<endl;
                    break;

                case 3:
                    long long p = 0;
                    long long k = 0;
                    long long N = 0;
                    bool wantDetails = false;
                    cout<<"Enter the value of base:";
                    cin>>p;
                    cout<<"Enter the power:";
                    cin>>k;
                    cout<<"Enter the value of N:";
                    cin>>N;
                    cout<<"Enter 1 if you want details:";
                    int num = 0;
                    cin>>num;
                    if(num == 1)
                        wantDetails = true;
                    cout<<dlp.getPower(p,k,N,wantDetails);
                    break;

                case 4:
                    long long base = 0;
                    long long num = 0;
                    long long N = 0;
                    bool wantDetails = false;
                    cout<<"Enter the value of base:";
                    cin>>base;
                    cout<<"Enter the number whose log you wish to find:";
                    cin>>num;
                    cout<<"Enter the value of N:";
                    cin>>N;
                    cout<<"Enter 1 if you want details:";
                    int num = 0;
                    cin>>num;
                    if(num == 1)
                        wantDetails = true;
                    cout<<dlp.discreetLogBruteForce(base,num,N,wantDetails);
                    break;

                default:
                    break;
            }
            break;
        case 2:
            cout<<"1. Check primality by brute force"<<endl<<"2. Get Prime Factors"<<"3. Miller-Rabin Primality Test"<<endl;
            cin>>choice;
            switch (choice)
            {
                case 1:
                    long long a = 0;
                    cout<<"Enter the number:";
                    cin>>a;
                    bool isPrime = util.isPrime(a);
                    if(isPrime)
                    {
                        cout<<"It's a prime number";
                    }
                    else
                    {
                        cout<<"It's not a prime number";
                    }
                    break;
                
                case 2:
                    long long a = 0;
                    cout<<"Enter the number:";
                    cin>>a;
                    list<tuple<long long, long long>> factors = util.factorize(a);
                    list<tuple<long long, long long>> :: iterator it;
                    for(it=factors.begin(); it!=factors.end(); ++it)
                    {
                        cout<<get<0>(*it)<<"^"<<get<1>(*it)<<endl;
                    }
                    break;
                
                case 3:
                    long long N = 0;
                    long long a = 0;
                    bool wantDetails = false;
                    cout<<"Enter the number:";
                    cin>>N;
                    cout<<"Enter the value of the witness:";
                    cin>>a;
                    cout<<"Enter 1 if you want details:";
                    int num = 0;
                    cin>>num;
                    if(num == 1)
                        wantDetails = true;
                    bool isPrimeByMRPT = primality.isPrimeByMRPT(a, N, wantDetails);
                    break;

                default:
                    break;
            }
            break;

        case 3:
            cout<<"As of now, this only supports the feature for obtaining decryption key"<<endl;
            long long N = 0;
            long long e = 0;
            bool wantDetails = false;
            cout<<"Enter the value of N:";
            cin>>N;
            cout<<"Enter the value of e:";
            cin>>e;
            cout<<rsa.getDecryptionKey(N, e, wantDetails);
            break;
        
        case 4:
            long long g1 = 0;
            long long g2 = 0;
            long long h1 = 0;
            long long h2 = 0;
            cout<<"Enter the value of g1:";
            cin>>g1;
            cout<<"Enter the value of g2:";
            cin>>g2;
            cout<<"Enter the value of h1:";
            cin>>h1;
            cout<<"Enter the value of h2:";
            cin>>h2;
            int num = 0;
            cin>>num;
            bool wantDetails;
            if(num == 1)
                wantDetails = true;
            cout<<crt.getLog(g1,g2,h1,h2,wantDetails);
            break;
        
        default:
            break;
    }
    getch();
}