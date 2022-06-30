class Node{
    public:
    Node* links[26];
};
class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }
    
    bool insert(string& word){
        Node* curr = root;
        bool ans = false;
        for(int i=0;i<word.length();i++){
            int c = word[i]-'a';
            if(curr->links[c]==NULL){
                ans = true;
                curr->links[c] = new Node();
            }
            curr = curr->links[c];
        }
        return ans;
    }
};

int countDistinctSubstrings(string &s)
{
    Trie obj;
    int n = s.length();
    int ans = 0;
    for(int i=0;i<n;i++){
        string temp = "";
        for(int j=i;j<n;j++){
            temp += s[j];
            if(obj.insert(temp)){
                ans++;
            }
        }
    }
    return (ans+1);
}

// https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292
