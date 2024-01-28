struct Node{
    Node* links[26];
    bool flg = false;

    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    void putChar(char ch,Node* node)
    {
        links[ch-'a'] = node;
    }
    Node* getChar(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flg = true;
    }
    bool search(Node* root,string& word)
    {
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            char ch = word[i];
            if(ch=='.')
            {
                for(auto j:node->links)
                {
                    string tmp = word.substr(i+1);
                    if(j && j->search(j,tmp))
                    return true;
                }
                return false;
            }
            else if(!node->containsKey(word[i]))
            return false;
            node = node->getChar(word[i]);
        }
        if(node->flg)
        return true;
        return false;
    }
};
class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
                node->putChar(word[i],new Node());
            node = node->getChar(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        return node->search(node,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */