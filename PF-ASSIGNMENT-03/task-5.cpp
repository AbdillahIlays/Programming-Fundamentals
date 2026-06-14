//Abdullah Ilyas
//25L-0826

#include<iostream>
using namespace std;
void Union(int A[],int n,int B[],int m);
void Inter(int A[],int n,int B[],int M);
void Diff(int A[],int n,int B[],int m);
int main()
{

    int A[6]={1,1,2,2,3,3},B[4]={7,1,3,8};

    Union(A,6,B,4);

    Inter(A,6,B,4);

    Diff(A,6,B,4);
 
    cout<<endl;
    system("pause");
    return 0;
}
void Union(int A[],int n,int B[],int m)
{
    int z = 0;

    int U[10];
    for (int i = 0; i < n; i++)
        U[z++] = A[i];

    for (int i = 0; i < m; i++)
        U[z++] = B[i];

    int setUnion[20];
    int k = 0;

    for (int i = 0; i < z; i++) {

        bool exists = false;
        for (int j = 0; j < k; j++) 
        {
            if (setUnion[j] == U[i]) 
            {
                exists = true;
               break;
            }
        }

        if (!exists)
            setUnion[k++] = U[i];
    }

    cout << "Union: ";
    for (int i = 0; i < k; i++)
        cout << setUnion[i] << " ";
    cout << endl;
}

void Inter(int A[],int n,int B[],int M)
{
    int z=0;
    int I[10];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(A[i]==B[j]) I[z++]=A[i];
        }
    }

    int intersection[10],k=0;
    for(int i=0;i<z;i++)
    {
        bool exist=false;
        for(int j=0;j<k;j++)
        {
            if(intersection[j]==I[i])
            {
                exist =true;
                break;
            }
        }
        if(!exist) intersection[k++]=I[i];
    }

    cout<<"Intersection : ";
    for(int i=0;i<k;i++) cout<<intersection[i]<<" ";

    cout<<endl;
}
void Diff(int A[], int n, int B[], int m)
{
    int z = 0;
    int D[10];

    for(int i = 0; i < n; i++)
    {
        bool found = false;

        for(int j = 0; j < m; j++)
        {
            if(A[i] == B[j])
            {
                found = true;
                break;
            }
        }

        if(!found)
            D[z++] = A[i];
    }

    int difference[20], k = 0;

    for(int i = 0; i < z; i++)
    {
        bool exist = false;

        for(int j = 0; j < k; j++)
        {
            if(difference[j] == D[i])
            {
                exist = true;
                break;
            }
        }

        if(!exist)
            difference[k++] = D[i];
    }

    cout << "Difference (A - B): ";
    for(int i = 0; i < k; i++)
        cout << difference[i] << " ";
    cout << endl;
}
