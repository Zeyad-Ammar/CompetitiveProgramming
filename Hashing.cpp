struct Hashing{//convert the string to a hash value to easily compare them if not same or not.
private:
    int mod1=1e9+7,mod2=2e9+11;
    ll base1,base2,h1,h2,inv1,inv2,*pw1,*pw2,len;
    deque<char>d;
    ll power(ll a,ll b,ll m)
    {
        ll ans=1;
        while(b>0)
        {
            if(b&1)
            {
                ans=(ans*a)%m;
            }
            a=(a*a)%m;
            b>>=1;
        }
        return ans;
    }
public:
    Hashing(int sz,ll x=31,ll y=37){//pass the size of the string u want to hash
      //in case u will need to hash many object u can make this process
        base1=x;
        base2=y;
        h1=h2=len=0;
        inv1=power(x,mod1-2,mod1);
        inv2=power(y,mod2-2,mod2);
        pw1=new ll[sz+1];
        pw2=new ll[sz+1];
        pw1[0]=pw2[0]=1;
        for(int i=1;i<=sz;i++)
        {
            pw1[i]=(x*pw1[i-1])%mod1;
            pw2[i]=(y*pw2[i-1])%mod2;
        }
    }
    void push_back(char x)//push a character at the end of ur string u want to hash
    {
        x=x-'a'+1;
        h1=(h1*base1)%mod1;
        h1=(h1+x)%mod1;
        h2=(h2*base2)%mod2;
        h2=(h2+x)%mod2;
        len++;
        d.emplace_back(x);
    }
    void push_front(char x)//push a character to the begin of ur string u want to hash
    {
        x=x-'a'+1;
        h1=(h1+(x*pw1[len])%mod1)%mod1;
        h2=(h2+(x*pw2[len])%mod2)%mod2;
        len++;
        d.emplace_front(x);
    }
    void pop_back()//pop the last char of ur string
    {
        if(len==0)return;
        char x=d.back();
        d.pop_back();
        h1=(h1-x+mod1)%mod1;
        h1=(h1*inv1)%mod1;
        h2=(h2-x+mod2)%mod2;
        h2=(h2*inv2)%mod2;
        len--;
    }
    void pop_front()//pop the first char of ur string 
    {
        if(len==0)return;
        char x=d.front();
        d.pop_front();
        len--;
        h1=((h1-x*pw1[len]%mod1)+mod1)%mod1;
        h2=((h2-x*pw2[len]%mod2)+mod2)%mod2;
    }
    void clear()//clear the string u hash
    {
        h1=h2=len=0;
        d.clear();
    }
    bool operator==(const Hashing &H)const{
        return H.h1==h1&&H.h2==h2;
    }
    string GetString()
    {
        return string(d.begin(),d.end());
    }
    pair<int,int>GetHash()//return the hash value as pair
    {
        return {h1,h2};
    }
};
