/****
Contest:2015, Samara SAU ACM ICPC Quarterfinal Qualification Contest
Problem L


We want to find two numbers a,b such that:
1- a is multiple of m(a=n*x for an x)
2- b is multiple of n(b=m*y for an y)
3- a) a-b=0
   b) a-b=1
   c) b-a=1
4- max(a,b) is minimum

so we can find the answer for 3 cases then find the minimum of them
a) for first case a=b then we need a number that is multiple of n and m and minimum
    which is lcm(a,b)
b,c) Actually we don't need to calculate cases b and c unless gcd(n,m)=1 because
    according to diophantine equation theres is no solution if the difference is not multiple of gcd(n,m)
    (her difference =1 which have no solution if gcd(n,m)!=1 )
    Actually if gcd(n,m)=1 the minimum answer will be by case 2,3
    To solve equation in case 2,3 we can solve by extended_gcd which gives x,y for n*x+m*y=1
    Then we print max(a->n*x,b->m*y);
    
Note:
-extended_gcd give solution where x or y is the minimum positive number in all possible solutions and the other term(x or y) is negative (Bézout's identity)(say a-b)
-to get the minimum positive of the other term(let's say y) the new solution will be (x-m,y+n) (Bézout's identity) (to get b-a)
-You should handle corner case when n==1 or m==1

*/














#include <bits/stdc++.h>
#define int long long
using namespace std;

int ext_gcd(int a,int b,int &x,int &y){

    if(b==0){
        x=1,y=0;
        return a;
    }

    int x1,y1;
    int g=ext_gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*x;

    return g;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();        cout.tie(0);

    int n,m;
    cin>>n>>m;
    if(n==1&&m==1)cout<<1;
    else if(n==1||m==1)cout<<2;
    else if(__gcd(n,m)!=1)cout<<n*m/__gcd(n,m);
    else{
        int x,y;
        int g=ext_gcd(n,m,x,y);

        cout<<min({max(n*x,m*y),max(n*(x+m/g),m*(y-n/g)),max(n*(x-m/g),m*(y+n/g))})<<'\n';

    }

    return 0;
}
