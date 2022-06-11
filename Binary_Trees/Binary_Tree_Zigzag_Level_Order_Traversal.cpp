// Normal Level Order with reversal
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        int dir = 0;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> level;
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(dir==1) reverse(level.begin(),level.end());
            dir = dir^1;
            ans.push_back(level);
        }
        return ans;
    }
};

// Level order Without reversal
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        int dir = 0;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> level(sz);
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                int ind = (dir==0) ? i : (sz-i-1);
                level[ind] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            dir = dir^1;
            ans.push_back(level);
        }
        return ans;
    }
};

// 2 stacks
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> s1,s2;
        s1.push(root);
        while(!s1.empty()){
            vector<int> level;
            while(!s1.empty()){
                TreeNode* node = s1.top();
                s1.pop();
                level.push_back(node->val);
                if(node->left) s2.push(node->left);
                if(node->right) s2.push(node->right);
            }
            ans.push_back(level);
            level.clear();
            while(!s2.empty()){
                TreeNode* node = s2.top();
                s2.pop();
                level.push_back(node->val);
                if(node->right) s1.push(node->right);
                if(node->left) s1.push(node->left);
            }
            if(!level.empty()) ans.push_back(level);
        }
        return ans;
    }
};

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
