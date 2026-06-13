//Name: Abdullah Ilyas
//Roll No: 25L-0826
// Q7
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
    if(TotalBill>=5000) cout<<"Target Achieved!";
    else cout<<"Target not achieved. Short by "<<5000-TotalBill;
    cout<<endl;
    system("pause");
    return 0;
}
