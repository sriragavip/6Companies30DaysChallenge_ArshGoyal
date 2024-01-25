class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
     sort(v.begin(),v.end());
        int hh=0;
        int cnt=1;
        for(int i=0;i<h.size()-1;i++){
            if(h[i+1]==h[i] + 1){
                cnt++;
                hh = max(hh,cnt);
            }   
            else{
                cnt=1;
            }
        }
        hh = max(hh,cnt);
        cout<<hh<<endl;
        int cntt=1; int vv=0;
         for(int i=0;i<v.size()-1;i++){
            if(v[i+1]==v[i] + 1){
                cntt++;
                vv = max(vv,cntt);
            }   
            else{
                cntt=1;
            }
        }
         vv = max(vv,cntt);
        cout<<vv<<endl;
        
        int as=min(hh,vv)+1;
        return (as*as);

    }
};