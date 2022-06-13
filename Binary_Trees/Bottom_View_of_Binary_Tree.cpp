// Iterative using map
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        queue<pair<Node*,int>> q;
        map<int,int> m;
        q.push({root,0});
        while(!q.empty()){
            Node* curr = q.front().first;
            int pos = q.front().second;
            q.pop();
            m[pos] = curr->data;
            if(curr->left) q.push({curr->left,pos-1});
            if(curr->right) q.push({curr->right,pos+1});
        }
        vector<int> ans;
        for(auto& i: m){
            ans.push_back(i.second);
        }
        return ans;
    }
};

// Iterative using unordered map
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        queue<pair<Node*,int>> q;
        unordered_map<int,int> m;
        q.push({root,0});
        int minPos = 0;
        while(!q.empty()){
            Node* curr = q.front().first;
            int pos = q.front().second;
            minPos = min(minPos,pos);
            q.pop();
            m[pos] = curr->data;
            if(curr->left) q.push({curr->left,pos-1});
            if(curr->right) q.push({curr->right,pos+1});
        }
        vector<int> ans;
        while(true){
            if(m.find(minPos)!=m.end()){
                ans.push_back(m[minPos]);
                minPos++;
            }
            else break;
        }
        return ans;
    }
};

// Recursive using map
class Solution {
  public:
    void solve(Node* root, int pos, int level, map<int,pair<int,int>>& m){
        if(root==NULL) return;
        if(m.find(pos)==m.end()) m[pos] = {root->data,level};
        else{
            if(level>=m[pos].second){
                m[pos] = {root->data,level};
            }
        }
        solve(root->left,pos-1,level+1,m);
        solve(root->right,pos+1,level+1,m);
    }
  
    vector<int> bottomView(Node *root) {
        map<int,pair<int,int>> m;
        solve(root,0,0,m);
        vector<int> ans;
        for(auto& i: m){
            ans.push_back(i.second.first);
        }
        return ans;
    }
};

// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
