#define ll long long
class Solution {
public:
    ll p=31;
    ll m=1000000009;
    int distinctEchoSubstrings(string text) {
        ll n=text.size();
        vector <ll> p_pow(n);
        p_pow[0]=1;
        for(ll i=1;i<n;i++)
            p_pow[i]=(p_pow[i-1]*p)%m;
        vector <ll> hash(n+1,0);
        for(ll i=0;i<n;i++)
        {
		   hash[i+1]= (hash[i] + (text[i]-'a'+1)*p_pow[i])%m; //dont forget the 1 here, or else "aa" and "aaa" will map to the same value
        }
        //for(int i=0;i<=n;i++)
           // cout<<hash[i]<< " ";
        unordered_map <ll ,ll > um;
        for(ll l=2;l<=n;l+=2)
        {
            for(ll i=0;i+l<=n;i++)
            {
                ll curr1= (hash[i+l/2]+m-hash[i])%m; // +m for ensuring +ve remainder
                curr1=(curr1*p_pow[n-i-1])%m; 
                ll curr2= (hash[i+ l] +m - hash[i+l/2])%m; 
                curr2=(curr2*p_pow[n-i-1-l/2])%m;
                //cout<<curr1<<" "<<curr2<<endl;
                if(curr1==curr2)
                {
                    um[curr1]++; //mark this substring's hash as visited
                }
            }
        }
        return um.size();
    }
};
