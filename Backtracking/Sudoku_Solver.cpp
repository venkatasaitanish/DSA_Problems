class Solution {
public:
    
    bool check(int i, int j, char k, vector<vector<char>>& v){
        for(int x=0;x<9;x++){
            if(v[x][j]==k) return false;
        }
        for(int y=0;y<9;y++){
            if(v[i][y]==k) return false;
        }
        i = i-(i%3);
        j = j-(j%3);
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                int a = x+i;
                int b = y+j;
                if(v[a][b]==k) return false;
            }
        }
        return true;
    }
    
    bool solve(int i, int j, vector<vector<char>>& v){
        if(i==9) return true;
        if(j==9) return solve(i+1,0,v);
        if(v[i][j]!='.') return solve(i,j+1,v);
        for(char k='1';k<='9';k++){
            if(check(i,j,k,v)){
                v[i][j] = k;
                if(solve(i,j+1,v)) return true;
                v[i][j] = '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& v) {
        solve(0,0,v);
    }
};

//https://leetcode.com/problems/sudoku-solver/
