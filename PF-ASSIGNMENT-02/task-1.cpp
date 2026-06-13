#include<iostream>
using namespace std;

int main()
{
    int n;
    int TotalBurgers=0,TotalSandwiches=0,TotalDrinks=0;
    std:
    cout<<"Enter number of students : ";
    cin>>n;

    if(n<0)
    {
        cout<<"Invalid Input. Enter valid number of students.\n";
        goto std;
    }
    else if(n==0)
        cout<<"No student bought anything";
    else
    {
        for(int stds=0;stds<n;stds++)
        {
            int burgers,sandwiches,drinks;
            cout<<"STUDENT "<<stds+1<<endl;

            brg:
            cout<<"BURGERS : ";
            cin>>burgers;
            if(burgers<0)
            { 
                cout<<"Invalid Input. Enter >= 0\n";
                goto brg;
            }
            else TotalBurgers+=burgers;

            sdw:
            cout<<"SANDWICHES : ";
            cin>>sandwiches;
            if(sandwiches<0) 
            {
                cout<<"Invalid Input. Enter >= 0\n";
                goto sdw;
            } 
            else TotalSandwiches+=sandwiches;

            drink:
            cout<<"DRINKS : ";
            cin>>drinks;
            if(drinks<0) 
            {
                cout<<"Invalid Input. Enter >= 0\n";
                goto drink;
            }
            else TotalDrinks+=drinks;

        }

        cout<<"Total Burgers sold : "<<TotalBurgers<<endl;
        cout<<"Total Sandwiches sold : "<<TotalSandwiches<<endl;
        cout<<"Total Drinks sold : "<<TotalDrinks<<endl;

        cout<<"Most Sold Item : ";
        if(TotalBurgers==TotalDrinks&&TotalBurgers==TotalSandwiches)
            cout<<"Burgers and Sandwiches and Drinks (tie).";
        else if(TotalBurgers==TotalDrinks)
            cout<<"Burgers and Drinks (tie).";
        else if(TotalBurgers==TotalSandwiches)
            cout<<"Burgers and Sandwiches (tie).";
        else if(TotalSandwiches==TotalDrinks)
            cout<<"Sandwiches and Drinks (tie).";
        else if(TotalBurgers>TotalSandwiches && TotalBurgers>TotalDrinks)
            cout<<"Burgers.";
        else if(TotalDrinks>TotalBurgers&&TotalDrinks>TotalSandwiches)
            cout<<"Drinks.";
        else 
            cout<<"Sandwiches.";

    }



    cout<<endl;
    system("pause");
    return 0;
}
