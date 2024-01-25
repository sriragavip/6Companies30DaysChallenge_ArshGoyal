class ThroneInheritance {
private:
    struct Tree{//Structure of N-ary Tree
        string name;//Storing names
        vector<Tree*> childrens;//storing childrens
    };
public:
    Tree* root;
    unordered_map<string,Tree*> mp;
    ThroneInheritance(string kingName) {
        root=new Tree();
        root->name=kingName;
        mp[kingName]=root;
    }
    
    void birth(string parentName, string childName) {
        Tree* child=new Tree();
        child->name=childName;
        mp[parentName]->childrens.push_back(child);
        mp[childName]=child;
    }
    
    void death(string name) {
        mp[name]=NULL;//Marking Dead peoples
    }
    void dfs(Tree* root,vector<string>& ans){
        if(mp[root->name]!=NULL)    ans.push_back(root->name);
        for(int i=0;i<root->childrens.size();i++){
            dfs(root->childrens[i],ans);
        }
        return;
    }
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(root,ans);
        return ans;
    }
};