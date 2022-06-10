// Recursive Preorder
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        if(p->val!=q->val) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

// Iterative Preorder
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s1,s2;
        s1.push(p);
        s2.push(q);
        while(!s1.empty()){
            TreeNode* node1 = s1.top();
            s1.pop();
            TreeNode* node2 = s2.top();
            s2.pop();
            if(node1==NULL && node2==NULL) continue;
            if(node1==NULL || node2==NULL) return false;
            if(node1->val!=node2->val) return false;
            s1.push(node1->left);
            s2.push(node2->left);
            s1.push(node1->right);
            s2.push(node2->right);
        }
        return true;
    }
};

// Level Order Traversal
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1,q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty()){
            TreeNode* node1 = q1.front();
            q1.pop();
            TreeNode* node2 = q2.front();
            q2.pop();
            if(node1==NULL && node2==NULL) continue;
            if(node1==NULL || node2==NULL) return false;
            if(node1->val!=node2->val) return false;
            q1.push(node1->left);
            q2.push(node2->left);
            q1.push(node1->right);
            q2.push(node2->right);
        }
        return true;
    }
};

// https://leetcode.com/problems/same-tree/
