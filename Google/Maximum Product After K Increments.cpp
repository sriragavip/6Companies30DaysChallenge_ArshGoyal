class Solution {
    using ll = long long;
    int mod = 1e9 + 7;
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(k>0){
            int ans = pq.top();
            pq.pop();
            ans++;
            pq.push(ans);
            k--;
        }
        ll pro = 1;
        while(pq.empty() == false){
            pro*=pq.top();
            pro=pro%mod;
            pq.pop();
        }
        return pro;
    }
};