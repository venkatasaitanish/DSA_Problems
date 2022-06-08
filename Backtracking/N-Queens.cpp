class Solution {
public:
    vector<vector<string>> ans;
    
    bool isSafe(int col, int row, int n, vector<string>& v){
        for(int i=0;i<row;i++){
            if(v[i][col]=='Q') return false;
        }
        
        int i=row,j=col;
        while(i>=0 && j>=0){
            if(v[i][j]=='Q') return false;
            i--,j--;
        }
        
        i=row,j=col;
        while(i>=0 && j<n){
            if(v[i][j]=='Q') return false;
            i--,j++;
        }
        return true;
    }
    
    void solve(int row, vector<string>& v, int n){
        if(row==n){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(i,row,n,v)){
                v[row][i] = 'Q';
                solve(row+1,v,n);
                v[row][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> v(n,string(n,'.'));
        solve(0,v,n);
        return ans;
    }
};

//https://leetcode.com/problems/n-queens/
