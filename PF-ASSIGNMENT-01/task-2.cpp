//Name: Abdullah Ilyas
//Roll No: 25L-0826
//Q2
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
    cout<<"Total Bill : "<<TotalBill;
    double discount=0;
    if(TotalBill>500 && TotalBill<=1000) discount=10;
    else if(TotalBill>1000) discount = 20;
    else discount=0;
    cout<<endl<<"Discount : "<<TotalBill*discount/100;
    int BillAfterDiscount=TotalBill*(1-discount/100);
    cout<<endl<<"Bill after discount : "<<BillAfterDiscount;
    cout<<endl;
    system("pause");
    return 0;
}
