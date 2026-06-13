#include<iostream>
#define Secret_Number 12
using namespace std;

int main()
{
    bool correct=false;

    for(int chance=1;chance<=5&&!correct;chance++)
    {
        int n;
        GetNum:
        cout<<"Guess the number : ";
        cin>>n;
        if(n<0||n>100)
        {
            cout<<"Guess Number between 0 and 100.\n";
            goto GetNum;
        }
        else if(n==Secret_Number)
        {
            cout<<"Correct! You Win.\n";
            correct=true;
        }
        else
        {
            if(chance!=5)
                cout<<"Wrong! Try Again.\n";
        }
        if(chance==5&&!correct) 
        {
            cout<<"Wrong!"<<endl<<"Game Over!";
        }
    }


    cout<<endl;
    system("pause");
    return 0;
}