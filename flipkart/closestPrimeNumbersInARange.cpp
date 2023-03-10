class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
         vector<int> ans(2,-1);
        if(left==right)return ans;
        vector<int> prime(right+1,1);
        prime[0]=0;
        prime[1]=0;
        for(long i=2;i<=right;i++){
            if(prime[i]==1){
               for(long j=i*i;j<=right;j+=i)
                prime[j]=0;}
        }
        vector<int> v;
        for(int i=left;i<=right;i++){
            if(prime[i]==1){
                v.push_back(i);
            }
        }
        if(v.size()<2)return ans;
        int d=INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            if(d>v[i+1]-v[i]){
                d=v[i+1]-v[i];
                ans[0]=v[i];
                ans[1]=v[i+1];
            }
            else continue;
        }
    return ans;
    }
};
