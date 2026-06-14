//Abdullah Ilyas
//25L-0826

#include<iostream>
using namespace std;

int input(char id[]);

int main()
{

    char id[11]={};

    int size=input(id);
    while(size!=10)
    {
        cout<<"Your Id must be of 10-characters.\n";
        size=input(id);
    }

    for(int i=0;i<size;i++)
    {
        if((i>=0&&i<=2)||i==9)
        {
            if(id[i]>='A'||id[i]<='Z') continue;
            else 
            {
                cout<<"Invalid Format. First 3 and last letters must be Uppercase.";
                exit(0);
            }
        }
        else if(i==3||i==8)
        {
            if(id[i]=='-') continue;
            else
            {
                cout<<"Wrong format. 4th and 9th character must be HYPHEN.\n";
                exit(0);
            }
        }
        else 
        {
            if(id[i]>='1'&&id[i]<='9') continue;
            else{
                cout<<"Invalid Format. 5th-8th characters must be Digits.\n";
                exit(0);
            }
        }
    }

    cout<<"Valid ID : "<<id;


    cout<<endl;
    system("pause");
    return 0;
}
int input(char id[])
{
    int size=0;
    cout<<"VALID ID :-\nFirst 3 characters : Uppercase Letters\n4th is HYPHEN\n5-8 are DIGITS\n9th is HYPHEN\n10th is UPPERCASE LETTER.\nEnter your id : ";
    cin.getline(id,11);

    for(int i=0;id[i]!='\0';i++) size++;

    return size;
}