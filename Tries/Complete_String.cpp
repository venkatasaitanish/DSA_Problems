// Longest Word With All Prefixes
class Node{
    public:
    Node* links[26]; 
    bool isEnd = false; 
}; 
class Trie{
    public:
    Node* root;
    Trie() {
        root = new Node(); 
    }

    void insert(string& word) {
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
    
    bool allPrefixExists(string& word) {
        Node* curr = root;
        for(int i=0;i<word.length();i++) {
            int c = word[i]-'a';
            if(curr->links[c]->isEnd==false){
                return false;
            }
            curr = curr->links[c];
        }
        return true; 
    }
};
string completeString(int n, vector<string> &a){
    Trie obj;
    for(int i=0;i<n;i++){
        obj.insert(a[i]);
    }
    string ans = "";
    for(int i=0;i<n;i++){
        if(obj.allPrefixExists(a[i])){
            if(a[i].length()>ans.length()){
                ans = a[i];
            }
            else if(a[i].length()==ans.length()){
                ans = min(ans,a[i]);
            }
        }
    }
    if(ans=="") return "None";
    return ans;
}

// https://www.codingninjas.com/codestudio/problems/complete-string_2687860
