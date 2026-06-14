#include <iostream>
using namespace std;

int main() {
    int R, C;

    cin >> R;
    if (R < 1 || R > 100) {
        cout << "Invalid row count!" << endl;
        return 1;
    }

    cin >> C;
    if (C < 1 || C > 100) {
        cout << "Invalid column count!" << endl;
        return 1;
    }

    int matrix[100][100];

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!(cin >> matrix[i][j])) {
                cout << "Invalid input!" << endl;
                return 1;
            }
        }
    }

    int maxArea = 0;

    for (int startRow = 0; startRow < R; startRow++) {
        for (int startCol = 0; startCol < C; startCol++) {
            for (int endRow = startRow + 1; endRow < R; endRow++) {
                for (int endCol = startCol + 1; endCol < C; endCol++) {
                    int evenCount = 0, oddCount = 0;

                    for (int i = startRow; i <= endRow; i++) {
                        for (int j = startCol; j <= endCol; j++) {
                            if (matrix[i][j] % 2 == 0) {
                                evenCount++;
                            }
                            else {
                                oddCount++;
                            }
                        }
                    }

                    if (evenCount == oddCount) {
                        int rows = endRow - startRow + 1;
                        int cols = endCol - startCol + 1;
                        int area = rows * cols;

                        if (area > maxArea) {
                            maxArea = area;
                        }
                    }
                }
            }
        }
    }

    cout <<"Submatrix : " <<maxArea << endl;

    return 0;
}