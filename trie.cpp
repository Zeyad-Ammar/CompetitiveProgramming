struct Trie{
    struct Node{
        Node*child[26];
        int IsEnd,Prefix;
        Node(){
            memset(child,0,sizeof child);
            IsEnd=Prefix=0;
        }
    };
    Node*root=new Node();
    void insert(string &s)//add the string u want to make ur trie on it.
    {
        Node*cur=root;
        for(auto it:s)
        {
            int idx=it-'a';
            if(cur->child[idx]==0)
            {
                cur->child[idx]=new Node();
            }
            cur=cur->child[idx];
            cur->Prefix++;
        }
        cur->IsEnd++;
    }
    bool SearchWord(string &s)//is this string exist or not
    {
        Node*cur=root;
        for(auto it:s)
        {
            int idx=it-'a';
            if(cur->child[idx]==0)return 0;
            cur=cur->child[idx];
        }
        return cur->IsEnd;
    }
    int CountWord(string &s)//return the number of string have this word
    {
        Node*cur=root;
        for(auto it:s)
        {
            int idx=it-'a';
            if(cur->child[idx]==0)return 0;
            cur=cur->child[idx];
        }
        return cur->IsEnd;
    }
    int CountPrefix(string &s)//return the number of strings have this prefix
    {
        Node*cur=root;
        for(auto it:s)
        {
            int idx=it-'a';
            if(cur->child[idx]==0)return 0;
            cur=cur->child[idx];
        }
        return cur->Prefix;
    }
};
