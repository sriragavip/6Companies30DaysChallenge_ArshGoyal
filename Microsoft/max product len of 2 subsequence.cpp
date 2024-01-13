class Solution {
public:
    vector<vector<int>>ar;
    bool check(vector<int>&a,vector<int>&b){       
        for(int i=0;i<a.size();i++)
            for(int j=0;j<b.size();j++)
                if(a[i]==b[j]) return false;
        return true;
    }
    bool isPalin(string &s,vector<int>&ans){
        int a=0,b=ans.size()-1;
        while(a<=b){
            if(s[ans[a]]!=s[ans[b]]) return false;
            a++;
            b--;
        }
        return true;    
    }
    void calc(string &s,vector<int>&ans,int i){
        if(isPalin(s,ans))
           ar.push_back(ans);
        
        if(i>=s.length()) return;
        ans.push_back(i);
        calc(s,ans,i+1);
        ans.pop_back();
        calc(s,ans,i+1);
    }
    int maxProduct(string s) {
        int ans=0;
        vector<int>a;
        calc(s,a,0);
        for(int i=0;i<ar.size();i++){
            for(int j=i+1;j<ar.size();j++){              
                int x=(int)ar[i].size()*ar[j].size();
                if(x>ans&&check(ar[i],ar[j]))                   
                    ans=x;
            }
        }
        return ans;
    }
};