//Name: Abdullah Ilyas
//Roll No: 25L-0826
//Q6
#include<iostream>
using namespace std;
int main()
{
    int NoOfBurger,NoOfPizzaSlice,NoOfSandwich;
    const int burgercost=200,pizzacost=150,sandwichcost=100;
    int totalburgercost=0,totalpizzacost=0,totalsandwichcost=0;
    cout<<"Enter Burgers = ";
    cin>>NoOfBurger;
    cout<<"Enter PizzaSlices = ";
    cin>>NoOfPizzaSlice;
    cout<<"Enter sandwiches = ";
    cin>>NoOfSandwich;
    totalburgercost=NoOfBurger*burgercost;
    cout<<"Burgers Cost : "<<totalburgercost<<endl;
    totalpizzacost=NoOfPizzaSlice*pizzacost;
    cout<<"PizzaSlices Cost : "<<totalpizzacost<<endl;
    totalsandwichcost=NoOfSandwich*sandwichcost;
    cout<<"Sandwiches Cost : "<<totalsandwichcost<<endl;
    int min=totalburgercost;
    cout<<"Cheapest Item : ";
    if(totalburgercost==totalpizzacost && totalburgercost==totalsandwichcost)
        cout<<"Burger, Pizza Slice and Sandwich";
        else{
    if(totalpizzacost<min) min=totalpizzacost;
    if(totalsandwichcost<min) min=totalsandwichcost;
    if(min==totalburgercost)
    {
        if(min==totalpizzacost) cout<<"Burger and PizzaSlice";
        else if(min==totalsandwichcost) cout<<"Burger and Sandwich";
        else cout<<"Burger";
    }
    else if(min==totalpizzacost)
    {
        if(min==totalburgercost) cout<<"Burger and PizzaSlice";
        else if(min==totalsandwichcost) cout<<"PizzaSlice and Sandwich";
        else cout<<"PizzaSlice";
    }
    else{
        if(min==totalburgercost) cout<<"Sandwich and Burger";
        else if (min==totalpizzacost) cout<<"Sandwich and PizzaSlice";
        else cout<<"Sandwich";
    }}
    cout<<endl;
    system("pause");
    return 0;
}