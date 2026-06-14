//Abdullah Ilyas
//25L-0826

#include <iostream>
using namespace std;

void inputMatrix(int arr[][20], int students, int quizzes);
void studentStats(int arr[][20], int students, int quizzes);
void quizStats(int arr[][20], int students, int quizzes);
void highestTotalStudents(int arr[][20], int students, int quizzes);

int main()
{
    int students, quizzes;
    int marks[50][20];   // max 50 students, 20 quizz

    cout << "Enter number of students: ";
    cin >> students;

    cout << "Enter number of quizzes: ";
    cin >> quizzes;

    while(students<0||students>50||quizzes<0||quizzes>20)
    {
        cout<<"Invalid Input.\n";
        
        cout << "Enter number of students: ";
        cin >> students;

        cout << "Enter number of quizzes: ";
        cin >> quizzes;
    }

    inputMatrix(marks, students, quizzes);

    studentStats(marks, students, quizzes);

    quizStats(marks, students, quizzes);

    highestTotalStudents(marks, students, quizzes);

    return 0;
}

void inputMatrix(int arr[][20], int students, int quizzes)
{
    for (int i = 0; i < students; i++) {
        cout << "\nEnter marks for Student " << i + 1 << ":\n";
        for (int j = 0; j < quizzes; j++) {
            cout << "Quiz " << j + 1 << " (0-10) : ";
            cin >> arr[i][j];
            while (arr[i][j] < 0||arr[i][j]>10) {
                cout << "Invalid! Enter again: ";
                cin >> arr[i][j];
            }
        }
    }
}

void studentStats(int arr[][20], int students, int quizzes)
{
    for (int i = 0; i < students; i++) {

        int mn = arr[i][0];
        int mx = arr[i][0];
        int sum = 0;

        for (int j = 0; j < quizzes; j++) {
            if (arr[i][j] < mn) mn = arr[i][j];
            if (arr[i][j] > mx) mx = arr[i][j];
            sum += arr[i][j];
        }

        float avg = sum / (float)quizzes;

        cout << "Student " << i + 1 << " -> Min: " << mn << ", Max: " << mx << ", Avg: " << avg << endl;
    }
}

void quizStats(int arr[][20], int students, int quizzes)
{
    for (int j = 0; j < quizzes; j++) {

        int mn = arr[0][j];
        int mx = arr[0][j];

        for (int i = 1; i < students; i++) {
            if (arr[i][j] < mn) mn = arr[i][j];
            if (arr[i][j] > mx) mx = arr[i][j];
        }

        cout << "Quiz " << j + 1 << " -> Lowest: " << mn << ", Highest: " << mx << endl;
    }
}

void highestTotalStudents(int arr[][20], int students, int quizzes)
{
    int maxTotal = -1;
    
    // First pass: find the maximum total score
    for (int i = 0; i < students; i++) {
        int sum = 0;
        for (int j = 0; j < quizzes; j++)
            sum += arr[i][j];
        
        if (sum > maxTotal) {
            maxTotal = sum;
        }
    }
    
    cout << "\nStudent(s) with Highest Total Score (" << maxTotal << "): ";
    bool first = true;
    
    for (int i = 0; i < students; i++) {
        int sum = 0;
        for (int j = 0; j < quizzes; j++)
            sum += arr[i][j];
        
        if (sum == maxTotal) {
            if (!first) {
                cout << ", ";
            }
            cout << "Student " << i + 1;
            first = false;
        }
    }
    cout << endl;
}