class Solution{   
public:
    string printMinNumberForPattern(string S){
       string ans = "";
       stack<string>st;
       int j=1;
       for(int i=0;i<S.length();i++) {
           if(S[i]=='D') {
               st.push(to_string(j));
               j++;
           }
           else {
               st.push(to_string(j));
               j++;
               while(!st.empty()) {
                   ans += st.top();
                   st.pop();
               }
           }
       } 
       st.push(to_string(j));
       while(!st.empty()) {
           ans+= st.top();
           st.pop();
       }
       return ans;
    }
};