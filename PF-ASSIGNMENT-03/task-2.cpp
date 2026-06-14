//Abdullah Ilyas
//25L-0826

#include<iostream>
#include<cmath>
using namespace std;
int input(double arr[]);
void Highest(double arr[],int n);
void Lowest(double arr[],int n);
double Avg(double arr[], int n);
void ST_Deviation(double arr[],int n,double avg);
void Above_Avg(double arr[],int n,double avg);
int main()
{

    double std[100];
    int n=input(std);
    Highest(std,n);
    cout<<endl;
    Lowest(std,n);
    cout<<endl;
    double avg=Avg(std,n);
    cout<<"Average : "<<avg<<endl;
    ST_Deviation(std,n,avg);
    cout<<endl;
    Above_Avg(std,n,avg);



    cout<<endl;
    system("pause");
    return 0;
}
int input(double arr[])
{
    int n;
    cout<<"How many marks you gonna enter? (must lie between 1-100) ";
    cin>>n;
    while(cin.fail()||n<1||n>100)
    {
        cin.clear();
        cin.ignore();
        cout<<"Invalid Input.\nEnter again : ";
        cin>>n;
    }

    cout<<"Enter marks : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        while(n<0||n>100||cin.fail())
        {
            cin.clear();
            cin.ignore();

            cout<<"Invalid Input.\nEnter again : ";
            cin>>arr[i];
        }
    }


    return n;

}
void Highest(double arr[],int n)
{
    double highest=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>highest) highest=arr[i];
    }
    cout<<"Highest : "<<highest;
}
void Lowest(double arr[],int n)
{
    double low=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]<low) low=arr[i];
    }
    cout<<"Lowest : "<<low;

}
double Avg(double arr[],int n)
{
    double sum=0,avg=0;

    for(int i=0;i<n;i++) sum+=arr[i];

    avg=sum/n;

    return avg;
}
void ST_Deviation(double arr[],int n,double avg)
{
    double std=0;

    for(int i=0;i<n;i++) std+=(arr[i]-avg)*(arr[i]-avg);

    std/=n;

    cout<<"Standard Deviation : "<<sqrt(std);
    
}
void Above_Avg(double arr[],int n,double avg)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>avg) count++;
    }
    cout<<"Above Average : "<<count;
 
}