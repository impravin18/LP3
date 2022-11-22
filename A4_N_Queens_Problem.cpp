#include <bits/stdc++.h>

using namespace std;


int N;


bool is_valid(int row, int col, vector<vector<char>>& board)
{
    int i, j;
  
    /* Check the column (above and below of [row,col]) */
    for(int i=0; i<N; i++)
        if(board[i][col] == 'Q')
            return false;
  
    /* Check backward slash(\) or upper diagonal on left side */
    for(i=row, j=col; i>=0 && j>=0; i--, j--)
        if(board[i][j] == 'Q')
            return false;
  
    /* Check backward slash(\) diagonal only in below direction*/
    for(i=row, j=col; i<N && j<N; i++, j++)
        if(board[i][j] == 'Q')
            return false;
    
    /* Check forward slash(/) diagonal only in above direction*/
    for(i=row, j=col; i>=0 && j<N; i--, j++)
        if(board[i][j] == 'Q')
            return false;

    /* Check forward slash(/) or lower diagonal on left side */
    for(i=row, j=col; i<N && j>=0; i++, j--)
        if(board[i][j] == 'Q')
            return false;
  
    return true;
}


bool solve_n_queens(int row, vector<vector<char>>& board)
{
    if(row == N)
        return true;
    
    for(int i=0; i<N; i++)
        if(board[row][i] == 'Q')
            return solve_n_queens(row+1, board);

    for(int col=0; col<N; col++)
        if(is_valid(row, col, board))
        {
            board[row][col] = 'Q';
            if(solve_n_queens(row+1, board))
                return true;
            board[row][col] = '_';             // Backtrack
        }
    
    return false;
}


void print_board(vector<vector<char>>& board)
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            cout<<board[i][j]<<" ";
        cout<<"\n";
    }
}


int main()
{
    cout<<"\nEnter the no. of Queens (N) : ";
    cin>>N;

    int x,y;
    cout<<"\nEnter coordinates for first Queen : ";
    cin>>x>>y;

    vector<vector<char>> board(N, vector<char>(N,'_'));
    board[x][y] = 'Q';
    print_board(board);

    if(!solve_n_queens(0, board))
        cout<<"\n\nSolution doesn't exist!\n";
    else
    {
        cout<<"\n\nSolution exists!\n";
        print_board(board);
    }

    cout<<"\n";

    return 0;
}