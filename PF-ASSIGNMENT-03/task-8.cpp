//Abdullah Ilyas
//25L-0826

#include <iostream>
using namespace std;

void rotateRight(int arr[], int n, int k);
void rotateLeft(int arr[], int n, int k);
void removeAt(int arr[], int &n, int index);
void insertAt(int arr[], int &n, int index, int value);
void printArray(const int arr[], int n);

int main() {
    int N;
    int shelf[200];

    cout << "Enter size of shelf: ";
    cin >> N;

    while(N<0||N>200)
    {
        cout<<"Invalid Input.\n";
        cout << "Enter size of shelf: ";
        cin >> N;
    }

    cout << "Enter " << N << " items:\n";

    for (int i = 0; i < N; i++)
        cin >> shelf[i];

    int k;
    cout << "\nEnter number for Right Rotation: ";
    cin >> k;

    rotateRight(shelf, N, k);
    cout << "After Right Rotation: ";
    printArray(shelf, N);

    int index, value;
    cout << "\nEnter value to insert: ";
    cin >> value;
    cout << "Enter index to insert at: ";
    cin >> index;

    insertAt(shelf, N, index, value);
    cout << "After Insert: ";
    printArray(shelf, N);

    int remIndex;
    cout << "\nEnter index to remove: ";
    cin >> remIndex;

    removeAt(shelf, N, remIndex);
    cout << "After Removal: ";
    printArray(shelf, N);

    return 0;
}

void rotateRight(int arr[], int n, int k) {
    k %= n;
    while (k--) {
        int last = arr[n - 1];
        for (int i = n - 1; i > 0; i--)
            arr[i] = arr[i - 1];
        arr[0] = last;
    }
}

void rotateLeft(int arr[], int n, int k) {
    k %= n;
    while (k--) {
        int first = arr[0];
        for (int i = 0; i < n - 1; i++)
            arr[i] = arr[i + 1];
        arr[n - 1] = first;
    }
}

void removeAt(int arr[], int &n, int index) {
    if (index < 0 || index >= n) {
        cout << "Invalid index for removal!\n";
        return;
    }
    for (int i = index; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

void insertAt(int arr[], int &n, int index, int value) {
    if (index < 0 || index > n) {
        cout << "Invalid index for insertion!\n";
        return;
    }
    for (int i = n; i > index; i--)
        arr[i] = arr[i - 1];
    arr[index] = value;
    n++;
}

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
