class Solution {
public:
      int dist (vector<int>& a, vector<int>& b) //aux function 
    {
        return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    }
    int numberOfBoomerangs(vector<vector<int>>& pts) 
    {
        int n = pts.size(),ans=0;
        unordered_map<int,int> s;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
                s[dist(pts[i],pts[j])]++; //get cnt of all the distances from this node
            for (auto x:s)
                ans+=(x.second)*(x.second-1); // count total boomerangs we can made from the node
            s.clear(); // clear map for next node 
        }
        return ans;

    }
};
