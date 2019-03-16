#include <iostream>
#include<stdio.h>
#define ll long long
using namespace std;
int main(int argc, const char * argv[]) {
    int i;
    cin>>i;
    while(i--)
    {   ll n;
        ll result;
        cin>>n;
        if(n>=2017)
            result=0;
        else
        {
            result=1;
            for(ll i=2;i<=n;i++)
                result=result%2017*i%2017;
        }
        printf("%lld\n",result);
    }
    return 0;
}

