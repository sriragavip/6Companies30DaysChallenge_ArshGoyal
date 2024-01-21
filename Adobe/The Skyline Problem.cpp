class Solution {
public:
    
    void exitAndAdd(vector<vector<int>> &ans, priority_queue<pair<int, int>> &pq, bool end, int x1 = -1, int h = -1, int x2 = -1){
        int x11 = 0, h11 = 0, x22 = 0, h22 = 0;
        while(!pq.empty()){
            
            //if curr is not ending then kept on removing the invalid buildings
            if(!end and pq.top().second >= x1)
                break;
            h11 = pq.top().first, x11 = pq.top().second;
            pq.pop();
            if(pq.empty()){
                ans.push_back({x11, 0});
            } else {
                while(!pq.empty() and pq.top().second <= x11){
                    pq.pop();
                }
                if(!pq.empty()){
                    h22 = pq.top().first, x22 = pq.top().second;
                    ans.push_back({x11, h22});
                    h11 = h22;
                    x11 = x22;
                } else {
                    ans.push_back({x11, 0});
                }
            }   
        }
         
        //if the buildings are not ended so keep on adding the prev ended according to next height
        if(!end){
            if(pq.empty()){
                if(ans.size()>0 and ans.back()[0] == x1)
                    ans.back()[1] = h;
                else
                    ans.push_back({x1, h});

                pq.push({h, x2});
            } else {
                if(pq.top().first < h){
                    if(ans.size()>0 and ans.back()[0] == x1)
                        ans.back()[1] =  max(pq.top().first, h);
                    else 
                        ans.push_back({x1, max(pq.top().first, h)});
                }
                pq.push({h, x2});
            }
        }
    }
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>> pq;
        for(int i=0; i < buildings.size(); i++){
            int x1 = buildings[i][0];
            int x2 = buildings[i][1];
            int h = buildings[i][2];
            
            if(pq.empty()){
                if(ans.size()>0 and ans.back()[0] == x1)
                    ans.back()[1] = h;
                else 
                    ans.push_back({x1, h});
                    
                pq.push({h, x2});
            } else {
   
                exitAndAdd(ans, pq, false, x1, h, x2);
            }
        }|
        exitAndAdd(ans, pq, true);
        return ans;
    }
};