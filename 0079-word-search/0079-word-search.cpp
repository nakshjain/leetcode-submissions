class Solution {
private:
    int n;
    int m;

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index){
        if(index==word.length()) return true;
        if(i<0 || i>=n ||
            j<0 || j>=m ||
            board[i][j]!=word[index]) return false;
        char tempWord = board[i][j];
        board[i][j]='#';

        bool check = dfs(board, word, i+1, j, index+1) ||
                    dfs(board, word, i, j+1, index+1) ||
                    dfs(board, word, i, j-1, index+1) ||
                    dfs(board, word, i-1, j, index+1);
        board[i][j]=tempWord;
        return check;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};