#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int row,int col,vector<vector<char>>&board,int n)
{
    int drow=row;
    int dcol=col;

    while(row>=0 && col>=0)
    {
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }

    row=drow;
    col=dcol;
    while(col>=0)
    {
        if(board[row][col]=='Q') return false;
        col--;
    }

    row=drow;
    col=dcol;
    while(row<n && col>=0)
    {
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }

    return true;

}

void solve(int col,vector<vector<char>>&board,vector<vector<string>>&ans,int n)
{
    if(col==n)
    {
        vector<string>temp;
        for(int i=0;i<n;i++)
        {
            string row(board[i].begin(),board[i].end());
            temp.push_back(row);
        }
        ans.push_back(temp);
        return;
    }

    for(int row=0;row<n;row++)
    {
        if(isSafe(row,col,board,n))
        {
            board[row][col]='Q';
            solve(col+1,board,ans,n);
            board[row][col]='.';
        }
    }
}

vector<vector<string>> solvequeen(int n)
{
    vector<vector<string>>ans;
    vector<vector<char>>board(n,vector<char>(n,'.'));

    solve(0,board,ans,n);
    return ans;
}

int main()
{
    cout<<"Enter no of queens:";
    int n;
    cin>>n;

    vector<vector<string>> res=solvequeen(n);

    for(auto &board:res)
    {
        for(auto &row:board)
        {
            cout<<row<<endl;
        }
        cout<<endl;
    }

    return 0;
}