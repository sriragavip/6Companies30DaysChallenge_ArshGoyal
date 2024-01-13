class Solution {
public:
unordered_map<string,int>dp;
  int findAns(vector<int>& price, vector<vector<int>>& spe, vector<int>&arr)
  {
    bool br=true;
    for (int i = 0; i < arr.size(); i++) {
      if(arr[i]<0)return INT_MAX;
      if(arr[i]!=0){br=false;break;}
    }
    if(br)return 0;
    string s="";
    for(int i=0;i<arr.size();i++){
        s+=to_string(arr[i]);
    }
    if(dp.find(s)!=dp.end())return dp[s];
    int ans=INT_MAX;
    for(int k=0;k < spe.size();k++){
      bool flag=true;
      for (int i = 0; i < arr.size(); i++) {
        /* code */
        if(spe[k][i]>arr[i]){
          flag=false;
          break;
        }
      }
      int t_ans;
      if(!flag)continue;
      for (int i = 0; i < arr.size(); i++) {
        arr[i]-=spe[k][i];
      }
      t_ans=spe[k][arr.size()]+findAns(price,spe,arr);
      for (int i = 0; i < arr.size(); i++) {
        arr[i]+=spe[k][i];
      }
      ans=min(ans,t_ans);
      
    }
    int p_ans=0;
    for (int i = 0; i < price.size(); i++) {
      if(arr[i]>0){
        p_ans += price[i]*arr[i];
      }
    }
    
    ans=min(ans,p_ans);
    return dp[s]=ans;
  }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return findAns(price,special,needs);
    }
};