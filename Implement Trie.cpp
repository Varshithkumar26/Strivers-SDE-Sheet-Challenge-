/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */


class Trie {

public:

    /** Initialize your data structure here. */
    class Node{
        public:
        Node* links[26];
        bool isend=false;
    };
    Node* root;
    Trie() {
        root=new Node();

    }

    /** Inserts a word into the trie. */
    void insert(string word) {

        int n=word.length();
        Node* cur=root;
        for(int i=0;i<n;i++)
        {
            char ch=word[i];
            if(cur->links[ch-'a']==NULL)
              cur->links[ch-'a']=new Node();
            cur=cur->links[ch-'a'];
        }
        cur->isend=true;

    }

    /** Returns if the word is in the trie. */
    bool search(string word) {

        int n=word.length();
        Node* cur=root;
        for(int i=0;i<n;i++)
        {
            char ch=word[i];
            if(cur->links[ch-'a']==NULL)
              return false;
            cur=cur->links[ch-'a'];
        }
        return cur->isend;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {

        int n=prefix.length();
        Node* cur=root;
        for(int i=0;i<n;i++)
        {
            char ch=prefix[i];
            if(cur->links[ch-'a']==NULL)
              return false;
            cur=cur->links[ch-'a'];
        }
        return true;
    }
};
