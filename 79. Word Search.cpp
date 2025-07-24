class Solution {
public:
    int m, n;
    vector<pair<int, int>> m_v = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int widx){
        if(widx == word.size()){
            return true;
        }

        if(r < 0 || r >= m ||c < 0 || c >= n){
            return false;
        }

        if(board[r][c] == ' ' || board[r][c] != word[widx]){
            return false;
        }
        
        char ch = board[r][c];
        board[r][c] = ' ';

        // dfs call

        for(int i = 0; i < 4; i++){
            int cr = r + m_v[i].first;
            int cc = c + m_v[i].second;
            if(dfs(board, word, cr, cc, widx+1)){
                return true;
            }
        }

        board[r][c] = ch;
        return false;




    }
    bool exist(vector<vector<char>>& board, string word) {
         m = board.size();
         n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    bool found = dfs(board, word, i, j, 0);
                    if(found) return true;
                }
            }
        }

        return false;
    }
};