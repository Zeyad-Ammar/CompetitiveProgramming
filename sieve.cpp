const int N=1e5+5;
vector<bool>isPrime(N,true);//can use it to check if a number less than N is prime or not
vector<int>p;//have all prime numbers less than N.
void linear_sieve()
{
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i<N;i++)
    {
        if(isPrime[i]==1) p.push_back(i);
        for(int o=0;o<p.size();o++)
        {
            if(i*p[o]>=N) break;
            isPrime[i*p[o]]=0;
            if(i%p[o]==0) break;
        }
    }
}
