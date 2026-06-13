#include<iostream>
using namespace std;

int main()
{
    int n,Scholar=0,Regular=0,Weak=0;

    std:
    cout<<"Enter number of students : ";
    cin>>n;

    if(n<0) 
    {
        cout<<"Enter valid number of students.\n";
        goto std;
    }
    else if(n==0)
        cout<<"The class doesn't exist AS there is no student!";
    else
    {
        for(int student=1;student<=n;student++)
        {
            double Attendence;
            double marks;

            cout<<"Student "<<student<<endl;

            att:
            cout<<"Attendence : ";
            cin>>Attendence;
            if(Attendence<0||Attendence>30)
            {
                cout<<"Invalid Input. Attendence should lie between 0-30.\n"<<endl;
                goto att;
            }
            
            mks:
            cout<<"Enter Marks : ";
            cin>>marks;
            if(marks<0||marks>100)
            {
                cout<<"Invalid Input. Marks should lie between 0-100.\n"<<endl;
                goto mks;
            }

            if(Attendence >=27 && marks >= 80) Scholar++;
            else if(Attendence>=20 && ( marks>=60 && marks<=79)) Regular++;
            else Weak++;

        }
        cout<<"Scholars : "<<Scholar<<endl;
        cout<<"Regular : "<<Regular<<endl;
        cout<<"Weak : "<<Weak;
    }

    cout<<endl;
    system("pause");
    return 0;
}
