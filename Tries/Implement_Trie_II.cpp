class Node{
    public:
    Node* links[26];
    int cntPrefix = 0;
    int cntEndWith = 0;
};

class Trie{

    public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            int c = word[i]-'a';
            if(curr->links[c]==NULL){
                curr->links[c] = new Node();
            }
            curr = curr->links[c];
            curr->cntPrefix++;
        }
        curr->cntEndWith++;
    }

    int countWordsEqualTo(string &word){
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            int c = word[i]-'a';
            if(curr->links[c]==NULL){
                return 0;
            }
            curr = curr->links[c];
        }
        return curr->cntEndWith;
    }

    int countWordsStartingWith(string &word){
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            int c = word[i]-'a';
            if(curr->links[c]==NULL){
                return 0;
            }
            curr = curr->links[c];
        }
        return curr->cntPrefix;
    }

    void erase(string &word){
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            int c = word[i]-'a';
            if(curr->links[c]==NULL){
                return;
            }
            curr = curr->links[c];
            curr->cntPrefix--;
        }
        curr->cntEndWith--;
    }
};

// With Clear Functions
class Node{
    public:
    Node* links[26];
    int cntPrefix = 0;
    int cntEndWith = 0;
    
    bool containsKey(char ch){
        if(links[ch-'a']!=NULL) return true;
        return false;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    int getEnd(){
        return cntEndWith;
    }
    int getPrefix(){
        return cntPrefix;
    }
    int increaseEnd(){
        cntEndWith++;
    }
    int decreaseEnd(){
        cntEndWith--;
    }
    int increasePrefix(){
        cntPrefix++;
    }
    int decreasePrefix(){
        cntPrefix--;
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            if(curr->containsKey(word[i])==false){
                curr->put(word[i],new Node());
            }
            curr = curr->get(word[i]);
            curr->increasePrefix();
        }
        curr->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            if(curr->containsKey(word[i])==false){
                return 0;
            }
            curr = curr->get(word[i]);
        }
        return curr->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            if(curr->containsKey(word[i])==false){
                return 0;
            }
            curr = curr->get(word[i]);
        }
        return curr->getPrefix();
    }

    void erase(string &word){
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            if(curr->containsKey(word[i])==false){
                return;
            }
            curr = curr->get(word[i]);
            curr->decreasePrefix();
        }
        curr->decreaseEnd();
    }
};

// https://www.codingninjas.com/codestudio/problems/implement-trie_1387095
