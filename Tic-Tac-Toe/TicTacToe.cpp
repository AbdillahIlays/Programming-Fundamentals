#include<iostream>
#include<string>
using namespace std;

int turnNumber = 1;
string n1, n2;
bool toss;
bool player_turn;

char a = '1', b = '2', c = '3',
d = '4', e = '5', f = '6',
g = '7', h = '8', i = '9';

void displayBoard();
void playerTurn();
bool win();
bool draw_condition();

int main()
{
    int choice;

    cout << "===== TIC TAC TOE =====\n";
    cout << "1. Instructions\n";
    cout << "2. Play Game\n";
    cout << "Enter choice: ";
    cin >> choice;

    while ((choice != 1 && choice != 2)||cin.fail())
    {

        cin.clear();
        cin.ignore(1000,'\n');

        cout << "Invalid.\n";
        cout << "1. Instructions\n";
        cout << "2. Play Game\n";
        cout << "Enter choice: ";
        cin >> choice;
    }
    

    if (choice == 1)
    {
        cout << "\nRULES:\n";
        cout << "Two players play (X and O)\n";
        cout << "First to get 3 in a row wins\n";
        cout << "Board is 3x3\n";
        cout << "If full → Draw\n";
        return 0;
    }

    cin.ignore();
    cout << "Enter player 1 name [X]: ";
    getline(cin, n1);
    cout << "Enter player 2 name [O]: ";
    getline(cin, n2);

    
    int t;
    cout << "Enter 0 or 1 for toss: ";
    cin >> t;

    while ((t!=0&&t!=1)||cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid. Enter Again: ";
        cin >> t;
    }
    toss = t % 2;

    if (toss)
    {
        cout << n1 << " wins and starts first!\n";
        player_turn = true;
    }
    else
    {
        cout << n2 << " wins and starts first!\n";
        player_turn = false;
    }

    cout << endl;
    system("pause");
    bool winner = false;

    do {
        displayBoard();
        playerTurn();
        winner = win();

        if (winner) break;

    } while (!draw_condition());

    displayBoard();

    if (winner)
    {
        if (!player_turn) cout << n1 << " wins!\n";
        else cout << n2 << " wins!\n";
    }
    else
    {
        cout << "Game Draw!\n";
    }

    return 0;
}

void displayBoard()
{
    system("cls");
    cout << "\n\t " << a << " | " << b << " | " << c << "\n";
    cout << "\t---|---|---\n";
    cout << "\t " << d << " | " << e << " | " << f << "\n";
    cout << "\t---|---|---\n";
    cout << "\t " << g << " | " << h << " | " << i << "\n";
}

void playerTurn()
{
    char symbol;
    char choice;

    if (player_turn)
    {
        symbol = 'X';
        cout << n1 << " turn: ";
    }
    else
    {
        symbol = 'O';
        cout << n2 << " turn: ";
    }

    bool valid = false;

    do {
        cin >> choice;

        if (choice == '1' && a == '1') { a = symbol; valid = true; }
        else if (choice == '2' && b == '2') { b = symbol; valid = true; }
        else if (choice == '3' && c == '3') { c = symbol; valid = true; }
        else if (choice == '4' && d == '4') { d = symbol; valid = true; }
        else if (choice == '5' && e == '5') { e = symbol; valid = true; }
        else if (choice == '6' && f == '6') { f = symbol; valid = true; }
        else if (choice == '7' && g == '7') { g = symbol; valid = true; }
        else if (choice == '8' && h == '8') { h = symbol; valid = true; }
        else if (choice == '9' && i == '9') { i = symbol; valid = true; }
        else
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid move, try again: ";
        }

    } while (!valid);

    player_turn = !player_turn;
    turnNumber++;
}

bool win()
{
    if ((a == b && b == c) || (d == e && e == f) || (g == h && h == i) ||
        (a == d && d == g) || (b == e && e == h) || (c == f && f == i) ||
        (a == e && e == i) || (c == e && e == g))
        return true;

    return false;
}

bool draw_condition()
{
    return (turnNumber > 9);
}