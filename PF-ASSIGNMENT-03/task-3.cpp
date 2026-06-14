//Abdullah Ilyas
//25L-0826

#include <iostream>
using namespace std;

int inputDistances(float arr[], int N);
int longestIncreasing(float arr[], int n);
int longestDecreasing(float arr[], int n);
float totalFuelCost(float arr[], int n);
int daysAbove20Percent(float arr[], int n);

int main()
{
    int N;
    float distances[200];

    cout << "Enter number of days (1 to 200): ";
    cin >> N;

    while (N < 1 || N > 200) {
        cout << "Invalid! Enter again: ";
        cin >> N;
    }

    inputDistances(distances, N);

    cout << "\n----- Results -----\n";
    cout << "Longest Increasing Streak: " << longestIncreasing(distances, N) << " days\n";
    cout << "Longest Decreasing Streak: " << longestDecreasing(distances, N) << " days\n";
    cout << "Total Fuel Cost: Rs. " << totalFuelCost(distances, N) << "\n";
    cout << "Days above 20% of average: " << daysAbove20Percent(distances, N) << "\n";

    return 0;
}


int inputDistances(float arr[], int N)
{
    for (int i = 0; i < N; i++) {
        cout << "Enter distance for day " << i + 1 << ": ";
        cin >> arr[i];

        while (arr[i] < 0) {
            cout << "Distance cannot be negative! Enter again: ";
            cin >> arr[i];
        }
    }
    return 0;
}

int longestIncreasing(float arr[], int n)
{
    int maxStreak = 0, streak = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            streak++;
        } else {
            streak = 0;
        }
        if (streak > maxStreak)
            maxStreak = streak;
    }
    return maxStreak;
}

int longestDecreasing(float arr[], int n)
{
    int maxStreak = 0, streak = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            streak++;
        } else {
            streak = 0;
        }
        if (streak > maxStreak)
            maxStreak = streak;
    }
    return maxStreak;
}

float totalFuelCost(float arr[], int n)
{
    float total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];

    return total * 270;
}

int daysAbove20Percent(float arr[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    float avg = sum / n;
    float threshold = avg * 1.20; 

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= threshold)
            count++;
    }

    return count;
}
