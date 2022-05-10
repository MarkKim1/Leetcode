class Solution {
public:
    template <typename T>
    void print(vector<vector<T>> &board){
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void dfs(vector<vector<char>> &board, int i, int j, vector<vector<bool>> & visited){
        if(visited[i][j])
            return;
        if(board[i][j]=='X')
            return;
        
        int m=board.size();
        int n=board[0].size();
        visited[i][j]=true;
        if(board[i][j]=='O')
            board[i][j]='D';
        for( int k = -1; k < 2; ++k )  {    
            int dx=i+k;
            int dy=j+k; 
                if(dx>=0 and dx<m){
                    if(!visited[dx][j])
                        dfs(board, dx, j, visited);
                }
                if(dy>=0 and dy<n){
                    if(!visited[i][dy])
                        dfs(board, i, dy, visited);
                }
        }
        return;
    }
    
    void call_dfs(vector<vector<char>> &board, int direction, vector<vector<bool>> &visited){
        int m=board.size();
        int n=board[0].size();
        int r, c;
        if(direction==1){
            r=0;
            for(c=0;c<n;c++){
               if(board[r][c]=='O')
                   dfs(board, r, c, visited);
            }
        }
        else if(direction==2){
            c=n-1;
            for(r=0;r<m;r++){
                if(board[r][c]=='O')
                    dfs(board, r, c, visited);
            }
            
        }else if(direction==3){
            r=m-1;
            for(c=n-1; c>=0;c--){
                if(board[r][c]=='O')
                {
                    
                    dfs(board, r, c, visited);
                }
            }
            
        }else if(direction==4){
            c=0;
            for(r=m-1;r>=0;r--){
                if(board[r][c]=='O')
                    dfs(board, r, c, visited);
            }
        }
    }
    void capture(vector<vector<char>> &board){
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='D')
                    board[i][j]='O';
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        int direction=1;
        call_dfs(board, direction, visited);
        // cout<<"board after dfs direction 1"<<endl;
        // print<char>(board);
        // print<bool>(visited);
        direction=2;
        call_dfs(board, direction, visited);
        // cout<<"board after dfs direction 2"<<endl;
        // print<char>(board);
        // print<bool>(visited);
        direction=3;
        call_dfs(board, direction, visited);
        // cout<<"board after dfs direction 3"<<endl;
        // print<char>(board);
        // print<bool>(visited);
        direction=4;
        call_dfs(board, direction, visited);
        // cout<<"board after dfs direction 4"<<endl;
        // print<char>(board);
        // print<bool>(visited);
        capture(board);
        // cout<<"final board"<<endl;
        // print<char>(board);
    
    }
};