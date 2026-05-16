#include <iostream>
using namespace std;

int board[10][10], n;

bool isSafe(int row, int col)
{
    for(int i=0;i<row;i++)
    {
        if(board[i][col]==1)
            return false;
    }

    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
    {
        if(board[i][j]==1)
            return false;
    }

    for(int i=row,j=col;i>=0&&j<n;i--,j++)
    {
        if(board[i][j]==1)
            return false;
    }

    return true;
}

bool solve(int row)
{
    if(row==n)
        return true;

    for(int col=0;col<n;col++)
    {
        if(isSafe(row,col))
        {
            board[row][col]=1;

            if(solve(row+1))
                return true;

            board[row][col]=0;
        }
    }

    return false;
}

void display()
{
    cout<<"\nSolution:\n";

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]==1)
                cout<<"Q ";
            else
                cout<<". ";
        }

        cout<<endl;
    }
}

int main()
{
    int choice = 0;

    while(choice != 2)
    {
        cout<<"\n--- N Queen Menu ---";
        cout<<"\n1. Solve N Queen";
        cout<<"\n2. Exit";
        cout<<"\nEnter choice: ";

        cin>>choice;

        switch(choice)
        {
            case 1:

                cout<<"Enter number of queens: ";
                cin>>n;

                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        board[i][j]=0;
                    }
                }

                if(solve(0))
                    display();
                else
                    cout<<"Solution not possible!";

                break;

            case 2:

                cout<<"Program Ended";
                break;

            default:

                cout<<"Invalid Choice!";
        }
    }

    return 0;
}