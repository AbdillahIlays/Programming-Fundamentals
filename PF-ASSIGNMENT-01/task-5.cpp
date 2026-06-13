//Name: Abdullah Ilyas
//Roll No: 25L-0826
//Q5
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
    TotalBill+=NoOfBurgers*Burger;
    cout<<"Enter Pizza Slices : ";
    cin>>NoOfPizzaslices;
    TotalBill+=NoOfPizzaslices*PizzaSlice;
    cout<<"Enter Sandwiches : ";
    cin>>NoOfSandwiches;
    TotalBill+=NoOfSandwiches*Sandwich;
    cout<<"Total Bill : "<<TotalBill<<endl;
    int points=TotalBill/100;
    cout<<"Loyalty Points : "<<points<<endl;
    if(NoOfSandwiches>5) points+=2;
    if(TotalBill==1000) points--;
    cout<<"Points after adjustment : "<<points;
    
    cout<<endl;
    system("pause");
    return 0;
}
