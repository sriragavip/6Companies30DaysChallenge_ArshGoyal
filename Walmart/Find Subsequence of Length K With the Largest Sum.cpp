typedef pair<int,int> p;

class Solution {
public:
static bool cmp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
       priority_queue<p,vector<p>,greater<p>>pq;
       for(int i=0;i<nums.size();i++)
       pq.push({nums[i],i});
     vector<pair<int,int>>v1;

       while(pq.size()>0){
           if(pq.size()<=k)
         v1.push_back({pq.top().first,pq.top().second});
           pq.pop();
       }

       sort(v1.begin(),v1.end(),cmp);
       for(auto x:v1){
           ans.push_back(x.first);
       }
       return ans;

        
    }
};