class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues){
        int n=aliceValues.size(), bob=0, alice=0;
        vector<pair<int,int>> nums;
        for(int i=0;i<n;i++) nums.push_back({aliceValues[i]+bobValues[i],i});
        sort(nums.rbegin(),nums.rend());
        for(int i=0;i<n;i++){
            int index=nums[i].second;
            if(i%2) bob+=bobValues[index];
            else alice+=aliceValues[index];
        }   
        if(bob==alice) return 0;
        
    return alice>bob ? 1 : -1;        
    }
};