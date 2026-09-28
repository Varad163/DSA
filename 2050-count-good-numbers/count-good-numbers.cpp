class Solution {
public:
    long long mod=1e9+7;

    long long power(long long a,long long b){
        if(b==0)
            return 1;

        long long x=power(a,b/2);

        x=(x*x)%mod;


        if(b%2)
            x=(x*a)%mod;

        return x;


    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;

        return (power(5,even)*power(4,odd))%mod;
    }
};