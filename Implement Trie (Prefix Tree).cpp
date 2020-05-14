class Trie {
public:
    /** Initialize your data structure here. */
    class TrieNode{
        public:
        bool isEnd;
        TrieNode * children[26];
        TrieNode() {
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isEnd=false;
        }
    };
    TrieNode * root;
    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr=root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(curr->children[index]==NULL){
                curr->children[index]=new TrieNode();
            }
            curr=curr->children[index];
        }
        curr->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode * curr=root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(curr->children[index]==NULL){
                return false;
            }
            curr=curr->children[index];
        }
        if(curr->isEnd)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode * curr=root;
        for(int i=0;i<prefix.size();i++){
            int index=prefix[i]-'a';
            if(curr->children[index]==NULL){
                return false;
            }
            curr=curr->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
