class Solution{
public:
   int *findTwoElement(int *a, int n) {
        int *answer=new int[2]{-1};
        int i=0;
        int value=0;
        int element=0;
        
        for(i=0; i<n;i++){
            value = abs(a[i]);
            element = a[value-1];
            if(element > 0) a[value-1] = -element;
            else answer[0]=value;
        }
        for(i=0;i<n;i++){
            if(a[i]>0){
                answer[1]=i+1;
                break;
            }
        }
        return answer;
    }
};