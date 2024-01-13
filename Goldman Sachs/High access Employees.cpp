class Solution {
    static bool cmp(vector<string> a, vector<string> b)
    {
        if(a[0] == b[0])
            return a[1] <= b[1];
        return a[0] <= b[0];
    }
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& arr) {
        if(arr.size() < 3)
            return {};
        sort(arr.begin(), arr.end(), cmp);
        vector<string> ans;
        int i = 0;
        while(i < arr.size() - 2)
        {
            string k = arr[i][0];
            if(arr[i + 1][0] == k and stoi(arr[i + 1][1]) < 100 + stoi(arr[i][1]) and arr[i + 2][0] == k and stoi(arr[i + 2][1]) < 100 + stoi(arr[i][1]))
            {
                ans.push_back(k);
                while(i < arr.size() - 2 and arr[i][0] == k)
                    i++;
            }
            else
                i++;
        }
        return ans;
    }
};