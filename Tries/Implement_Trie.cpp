class Node{
    public:
    Node* links[26];
    bool isEnd = false;
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            int c = word[i]-'a';
            if(curr->links[c]==NULL){
                curr->links[c] = new Node();
            }
            curr = curr->links[c];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            int c = word[i]-'a';
            if(curr->links[c]==NULL){
                return false;
            }
            curr = curr->links[c];
        }
        return (curr->isEnd);
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i=0;i<prefix.length();i++){
            int c = prefix[i]-'a';
            if(curr->links[c]==NULL){
                return false;
            }
            curr = curr->links[c];
        }
        return true;
    }
};


// With Clear Functions
class Node{
    public:
    Node* links[26] = {};
    bool end = false;
    
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    void setEnd(){
        end =  true;
    }
    bool isEnd(){
        return end;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            if(curr->containsKey(word[i])==false){
                curr->put(word[i],new Node());
            }
            curr = curr->get(word[i]);
        }
        curr->setEnd();
    }
    
    bool search(string word) {
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            if(curr->containsKey(word[i])==false){
                return false;
            }
            curr = curr->get(word[i]);
        }
        return curr->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i=0;i<prefix.length();i++){
            if(curr->containsKey(prefix[i])==false){
                return false;
            }
            curr = curr->get(prefix[i]);
        }
        return true;
    }
};

// https://www.codingninjas.com/codestudio/problems/implement-trie_631356
// https://leetcode.com/problems/implement-trie-prefix-tree/
