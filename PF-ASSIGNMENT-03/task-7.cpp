//Abdullah Ilyas
//25L-0826

#include <iostream>
using namespace std;

const int MAX = 5;

void inputMatrix(int mat[][MAX], int r, int c);
void printMatrix(int mat[][MAX], int r, int c);
void addMatrix(int A[][MAX], int B[][MAX], int C[][MAX], int r, int c);
void multiplyMatrix(int A[][MAX], int B[][MAX], int C[][MAX], int r1, int c1, int r2, int c2);
void transposeMatrix(int A[][MAX], int T[][MAX], int r, int c);

int main() {
    int r1, c1, r2, c2;

    cout << "Enter rows and columns of Matrix A (max 5x5): ";
    cin >> r1 >> c1;

    while(r1<1||c1<0||r1>5||c1>5)
    {
        cout<<"Invalid Input.\n";
        cout << "Enter rows and columns of Matrix A (max 5x5): ";
        cin >> r1 >> c1;

    }

    cout << "Enter rows and columns of Matrix B (max 5x5): ";
    cin >> r2 >> c2;

    while(r2<1||c2<0||r2>5||c2>5)
    {
        cout<<"Invalid Input.\n";
        cout << "Enter rows and columns of Matrix A (max 5x5): ";
        cin >> r1 >> c1;

    }

    int A[MAX][MAX], B[MAX][MAX];
    int Add[MAX][MAX], Mul[MAX][MAX], Trans[MAX][MAX];

    cout << "\nEnter Matrix A:\n";
    inputMatrix(A, r1, c1);

    cout << "\nEnter Matrix B:\n";
    inputMatrix(B, r2, c2);

    cout << "\n--- Matrix A ---\n";
    printMatrix(A, r1, c1);

    cout << "\n--- Matrix B ---\n";
    printMatrix(B, r2, c2);

    if (r1 == r2 && c1 == c2) {
        addMatrix(A, B, Add, r1, c1);
        cout << "\n--- A + B ---\n";
        printMatrix(Add, r1, c1);
    } else {
        cout << "\nAddition NOT possible (dimensions mismatch)\n";
    }

    
    if (c1 == r2) {
        multiplyMatrix(A, B, Mul, r1, c1, r2, c2);
        cout << "\n--- A x B ---\n";
        printMatrix(Mul, r1, c2);
    } else {
        cout << "\nMultiplication NOT possible (A columns != B rows)\n";
    }

    
    transposeMatrix(A, Trans, r1, c1);
    cout << "\n--- Transpose of A ---\n";
    printMatrix(Trans, c1, r1);

    return 0;
}

void inputMatrix(int mat[][MAX], int r, int c) 
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            cout << "Element [" << i+1 << "][" << j+1 << "]: ";
            cin >> mat[i][j];
        }
}

void printMatrix(int mat[][MAX], int r, int c) 
{
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

void addMatrix(int A[][MAX], int B[][MAX], int C[][MAX], int r, int c) 
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void multiplyMatrix(int A[][MAX], int B[][MAX], int C[][MAX], int r1, int c1, int r2, int c2) 
{
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            C[i][j] = 0;

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
}

void transposeMatrix(int A[][MAX], int T[][MAX], int r, int c) 
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            T[j][i] = A[i][j];
}
