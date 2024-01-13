class NodeData{
private:
    int mini;
    int maxi;
    int sum;
    int maxSum;
public:
    NodeData(int mini, int maxi, int sum, int maxSum){
        this->mini=mini;
        this->maxi=maxi;
        this->sum=sum;
        this->maxSum=maxSum;
    }
    int getsum(){
        return sum;
    }
    int getmaxi(){
        return maxi;
    }
    int getmini(){
        return mini;
    }
    int getmaxSum(){
        return maxSum;
    }
};

class Solution {
public:
    NodeData maxBST(TreeNode* root){
        if(!root) return NodeData(INT_MAX,INT_MIN,0,INT_MIN);
        
        NodeData left = maxBST(root->left);
        NodeData right = maxBST(root->right);
        
        if(left.getmaxi() < root->val && right.getmini() > root->val){
            
            return NodeData(min(left.getmini(), root->val), max(right.getmaxi(), root->val), root->val + left.getsum() + right.getsum(), max(max(left.getmaxSum(), right.getmaxSum()), root->val + left.getsum() + right.getsum()));
            
        }
        return NodeData(INT_MIN, INT_MAX, max(left.getsum(), right.getsum()), max(left.getmaxSum(),right.getmaxSum()));
        
    }
    int maxSumBST(TreeNode* root) {
        int ans = maxBST(root).getmaxSum();
        return ans>=0?ans:0;
    }
};