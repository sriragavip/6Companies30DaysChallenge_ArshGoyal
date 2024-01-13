class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> count(5001, 0);
        for(int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        int idx = count.size() - 1;
        for(int i = 1; i < nums.size(); i+=2) {
            while(count[idx] == 0) {
                idx--;
            }
            
            nums[i] = idx;
            count[idx]--;
        }
        for(int i =  0; i < nums.size(); i+=2) {
            while(count[idx] == 0) {
                idx--;
            }
            nums[i] = idx;
            count[idx]--;
        }
    }
};