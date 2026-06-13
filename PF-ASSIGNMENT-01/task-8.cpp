//25L-0826
//Abdullah Ilyas
//Q8
#include<iostream>
using namespace std;
int main()
{
    const int Burger = 200;
    const int PizzaSlice = 150;
    const int Sandwich = 100;
    int TotalBill=0;
    int NoOfBurgers,NoOfPizzaslices,NoOfSandwiches;
    cout<<"Enter burgers : ";
    cin>>NoOfBurgers;
    cout<<"Enter Pizza Slices : ";
    cin>>NoOfPizzaslices;
    cout<<"Enter Sandwiches : ";
    cin>>NoOfSandwiches;
    if(NoOfBurgers==1 && NoOfSandwiches==1 && NoOfPizzaslices==1) 
    {
        cout<<"Combo Deal Applied!"<<endl;
        cout<<"Final Bill : "<<400;
    }
    else{
        TotalBill+=NoOfBurgers*Burger;
        TotalBill+=NoOfSandwiches*Sandwich;
        TotalBill+=NoOfPizzaslices*PizzaSlice;
    cout<<"Total Bill : "<<TotalBill<<endl;
    }
    cout<<endl;
    system("pause");
    return 0;
} 
