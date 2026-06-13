#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int n;
    integer:
    cout<<"Enter number of students : ";
    cin>>n;

    if(n<0)
    {
        cout<<"Invalid input. Enter a positive integer.\n";
        goto integer;
    }
    else if(n==0)
        cout<<"Class doesn't exist AS there is no student.";
    else
    {
        double marks[5]={0},avg[50]={0},total[50]={0};
        
        cout<<fixed<<setprecision(2)<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<"Student "<<i+1<<endl;
            for(int j=0;j<5;j++)
            {
                positive:
                cout<<"Enter marks in subject "<<j+1<<" : ";
                cin>>marks[j];
                if(marks[j]<0||marks[j]>100)
                {
                    cout<<"Invalid Input. Marks must lie between 0-100. Enter again.\n";
                    goto positive;
                }
                total[i]+=marks[j];
                
            }
            cout<<"Total marks of Student "<<i+1<<" : "<<total[i];
            avg[i]=total[i]/5;
            cout<<endl;
            cout<<"Average marks : "<<avg[i]<<endl;
            cout<<endl;
            
        }
        double Total_Avg=0;
        for(int sum_avg=0;sum_avg<n;sum_avg++)
        {
            Total_Avg+=avg[sum_avg];
        }
        double Class_Avg=Total_Avg/n;
        cout<<"Class Average : "<<Class_Avg<<endl;
        double Topp_Avg=avg[0];
        int Topper_Student=0;
        for(int top=0;top<n;top++)
        {
            if(avg[top]>Topp_Avg) 
            {
                Topp_Avg=avg[top];
                Topper_Student=top;
            }
        }
        cout<<"Topper : Student "<<Topper_Student+1<<" with Average "<<Topp_Avg;
    }


    cout<<endl;
    system("pause");
    return 0;
}