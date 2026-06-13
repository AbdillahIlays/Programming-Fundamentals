#include<iostream>
using namespace std;

int main()
{
    int Rows,Cols;
    get:
    cout<<"Enter number of rows : ";
    cin>>Rows;
    cout<<"Enetr Columns : ";
    cin>>Cols;
    if(Rows<=0||Cols<=0)
    {
        cout<<"Invalid Input. Rows and Columns must be greater than 0.\n";
        goto get;
    }

    const int Max=50;
    int Seats[Max][Max]={0};
    
    int No_Of_Reserved_Seats;
    rs:
    cout<<"Enter number of reserved seats (at least 1) : ";
    cin>>No_Of_Reserved_Seats;
    
    if(No_Of_Reserved_Seats<1)
    {
        cout<<"Invalid Input.\n";
        goto rs;
    }
    
    for(int i=1;i<=No_Of_Reserved_Seats;i++)
    {
        int r,c;
        take:
        cout<<"Reserved Seat "<<i<<endl<<"Enter Row : ";
        cin>>r;
        cout<<"Enter column : ";
        cin>>c;
        if(r<=0||c<=0||r>Rows||c>Cols)
        {
            cout<<"Invalid Input.\n";
            goto take;
        }
        Seats[r-1][c-1]=char('X');
    }

    for(int row=0;row<Rows;row++)
    {
        for(int col=0;col<Cols;col++)
        {
            if(Seats[row][col]=='X') cout<<"[X]\t";
            else cout<<"["<<row+1<<","<<col+1<<"]\t";
        }
        cout<<endl;
    }
    cout<<endl;
    system("pause");
    return 0;
}