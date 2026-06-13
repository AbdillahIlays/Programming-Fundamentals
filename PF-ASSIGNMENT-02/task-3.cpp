#include<iostream>
using namespace std;

int main()
{
    int n;
    positive:
    cout<<"Enter n : ";
    cin>>n;
    if(n<=0)
    {
        cout<<"Invalid Input.Enter positive integer.\n";
        goto positive;
    }
    else
    {
        for(int table=1;table<=n;table++)
        {
            cout<<"Table of "<<table<<endl;
            for(int mul=1;mul<=10;mul++)
            {
                if((table*mul)%2==0) cout<<table<<" * "<<mul<<" = "<<table*mul<<endl; 
            
            }
            cout<<endl;
        }
    }

    cout<<endl;
    system("pause");
    return 0;
}
