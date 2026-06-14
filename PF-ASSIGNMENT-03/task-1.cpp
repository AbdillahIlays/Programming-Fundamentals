//Abdullah Ilyas
//25L-0826

#include<iostream>
#include<cmath>
using namespace std;
double transform(double x);
double transform(double base, int power);
double transform(double values[], int size);

int main()
{

    double x,base;
    int power,size=0;
    double arr[100]={};

    cout<<"Equation is 3x^2-5x+12.\nEnter x : ";
    cin>>x;
    while(cin.fail()||x<0)
    {
        cin.clear();
        cin.ignore();
        cout<<"Invalid Input.\nEnter again x : ";
        cin>>x;
    }

    cout<<"Enter base : ";
    cin>>base;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<<"Invalid Input.\nEnter base again : ";
        cin>>base;
    }

    cout<<"Enetr Power : ";
    cin>>power;
    while(cin.fail()||power<0)
    {
        cin.clear();
        cin.ignore();
        cout<<"Invalid Input.\nEnter Power again : ";
        cin>>power;
    }

    cout<<"Enter number of elements of array (maximum 100) : ";
    cin>>size;
    while(cin.fail()||size<0||size>100)
    {
        cin.clear();
        cin.ignore();
        cout<<"Invalid Input.\nEnter number of elements again : ";
        cin>>size;
    }

    if(size==0) cout<<"You are not willing to enter array.";
    else 
    {
        cout<<"Enter array elements : ";
        for(int i=0;i<size;i++)
        {
            
            cin>>arr[i];
            while(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout<<"Invalid Input.\nEnter element again : ";
                cin>>arr[i];
            }
        }
    }
    
    cout<<"Expression Result : "<<transform(x)<<endl;

    cout<<"Base Power Result : "<<transform(base,power)<<endl;

    cout<<"Average Result : "<<transform(arr,size)<<endl;



    cout<<endl;
    system("pause");
    return 0;
}
double transform(double x)
{
    double answer=3*pow(x,2)-5*x + 12;
    return answer;
}
double transform(double base, int power)
{
    double answer=pow(base,power);
    return answer;
}
double transform(double values[], int size)
{
    double answer=0,sum=0;
    for(int i=0;i<size;i++) sum+=values[i];

    answer=sum/size;
    return answer;
}