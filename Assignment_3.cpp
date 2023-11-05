#include<iostream>
#include<vector>
using namespace std;

void init(vector<vector<int>> &board, int N)
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            board[i][j] = 0;    
        }
    }
}

bool isSafe(vector<vector<int>> &board, int N, int row, int col)
{
    // Same row
    for(int i=0; i<col; i++)
        if(board[row][i])
            return false;
    
    // Lower Diagonal
    for(int i=row, j=col; i>=0 && j>=0; i--, j--)
        if(board[i][j])
            return false;
    
    // Upper Diagonal
    for(int i=row, j=col; i<N && j>=0; i++, j--)
        if(board[i][j])
            return false;
    
    return true;
}

void printMatix(vector<vector<int>> &board, int N)
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool solveRec(vector<vector<int>> &board, int N, int col)
{
    if(col == N)
        return true;
    
    for(int i=0; i<N; i++)
    {
        if(isSafe(board, N, i, col))
        {
            board[i][col] = 1;
            if(solveRec(board, N, col+1))
                return true;

            board[i][col] = 0;
        }
    }
    return false;
}

bool solve(vector<vector<int>> &board, int N)
{
    init(board, N);
    
    if(solveRec(board, N, 0) == false)
        return false;
    else
    {
        printMatix(board, N);
        return true;
    }
}

int main()
{
    int n;
    cout<<"Enter N for the problem : ";
    cin>>n;

    vector<vector<int>> board(n, vector<int>(n));

    bool solved = solve(board, n);

    if(solved == false)
        cout<<"There does not exist a solution for given value of N"<<endl;

    return 0;
}
