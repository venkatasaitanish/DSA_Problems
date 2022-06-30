class Solution {
public:
    vector<int> v;
    
    void leftBoundary(Node* root){
        if(root==NULL) return;
        if(root->left){
            v.push_back(root->data);  
            leftBoundary(root->left);
        }
        else if(root->right){
            v.push_back(root->data);
            leftBoundary(root->right);
        }
        // if it doesn't have both left & right child, it is a leaf
        // it is considered in leaves
    }
    
    void rightBoundary(Node* root){
        if(root==NULL) return;
        if(root->right){
            rightBoundary(root->right);
            v.push_back(root->data);
        }
        else if(root->left){
            rightBoundary(root->left);
            v.push_back(root->data);
        }
        // if it doesn't have both left & right child, it is a leaf
        // it is considered in leaves
    }
    
    void leaves(Node* root){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            v.push_back(root->data);
        }
        leaves(root->left);
        leaves(root->right);
    }

    vector <int> boundary(Node *root)
    {
        v.clear();
        v.push_back(root->data);
        leftBoundary(root->left);
        leaves(root->left);
        leaves(root->right);
        rightBoundary(root->right);
        return v;
    }
};
