#include<iostream>
#include<string>
using namespace std;
void display(string& name1, string& name2)
{
    cout << "\t\t\t\t\t\t\tTic-Tac-Toe\n\n";
    cout << "Game Rules\n\n";
    cout << "Choose any number from [1 => 9] to put [X / O]\n\n";
    cout << "\t\t\t\t\t\t\tThe First Player\n\n";
    cout << "\t\t\t\t\t\t\tEnter your name => ";
    cin >> name1;
    cout << "\n\n\t\t\t\t\t\t\tThe Second Player\n\n";
    cout << "\t\t\t\t\t\t\tEnter your name => ";
    cin >> name2;
}
char player1_symbol = 'X', player2_symbol = 'O';
int player1_points = 0, player2_points = 0;
char game_numbers[] = { '1','2','3','4','5','6','7','8','9' };
int times = 1;
void gameStructure(string name1, string name2)
{
    system("cls");
    cout << "\t\t\t\t\t\t\t" << name1 << " => " << player1_symbol;
    cout << "\n\n\t\t\t\t\t\t\t" << name2 << " => " << player2_symbol;
    cout << "\n\n";
    cout << " " << game_numbers[0] << " | " << game_numbers[1] << " | " << game_numbers[2];
    cout << "\n___|___|___\n   |   |\n";
    cout << " " << game_numbers[3] << " | " << game_numbers[4] << " | " << game_numbers[5];
    cout << "\n___|___|___\n   |   |\n";
    cout << " " << game_numbers[6] << " | " << game_numbers[7] << " | " << game_numbers[8];
}
void points(string name1, string name2)
{
    cout << "\n\t\t\t\t\t\t\t" << name1 << " => " << player1_points;
    cout << "\n\t\t\t\t\t\t\t" << name2 << " => " << player2_points;
}
bool win(string name1, string name2)
{
    char win_symbol = ' ';
    if (game_numbers[0] == game_numbers[1] && game_numbers[1] == game_numbers[2])
    {
        win_symbol = game_numbers[0];
    }
    else if (game_numbers[3] == game_numbers[4] && game_numbers[3] == game_numbers[5])
    {
        win_symbol = game_numbers[3];
    }
    else if (game_numbers[6] == game_numbers[7] && game_numbers[6] == game_numbers[8])
    {
        win_symbol = game_numbers[6];
    }
    else if (game_numbers[2] == game_numbers[4] && game_numbers[2] == game_numbers[6])
    {
        win_symbol = game_numbers[2];
    }
    else if (game_numbers[0] == game_numbers[4] && game_numbers[0] == game_numbers[8])
    {
        win_symbol = game_numbers[0];
    }
    else if (game_numbers[0] == game_numbers[3] && game_numbers[0] == game_numbers[6])
    {
        win_symbol = game_numbers[0];
    }
    else if (game_numbers[1] == game_numbers[4] && game_numbers[1] == game_numbers[7])
    {
        win_symbol = game_numbers[1];
    }
    else if (game_numbers[2] == game_numbers[5] && game_numbers[2] == game_numbers[8])
    {
        win_symbol = game_numbers[2];
    }
    if (win_symbol != ' ')
    {
        system("cls");
        if (win_symbol == player1_symbol)
        {
            cout << "\t\t\t\t\t\t\t" << name1 << " Wins";
            player1_points++;
        }
        else
        {
            cout << "\t\t\t\t\t\t\t" << name2 << " Wins";
            player2_points++;
        }
        points(name1, name2);
        return true;
    }
    return false;
}
void check(int& n, string name1, string name2)
{
    if (times % 2 == 1)
    {
        while (game_numbers[n - 1] == 'X' || game_numbers[n - 1] == 'O' || n < 1 || n > 9)
        {

            gameStructure(name1, name2);
            cout << "\n\n" << name1 << " : Choose anther number => ";
            cin >> n;
        }
    }
    else
    {
        while (game_numbers[n - 1] == 'X' || game_numbers[n - 1] == 'O' || n < 1 || n > 9)
        {

            gameStructure(name1, name2);
            cout << "\n\n" << name2 << " : Choose anther number => ";
            cin >> n;
        }
    }
}
void game_logic(string name1, string name2)
{
    int num;
    while (win(name1, name2) == false)
    {
        if (times % 2 == 1)
        {
            cout << "\n\n" << name1 << " : Choose number => ";
            cin >> num;
            check(num, name1, name2);
            game_numbers[num - 1] = player1_symbol;
            times++;
            system("cls");
            gameStructure(name1, name2);
        }
        else
        {
            if (times == 10)
            {
                system("cls");
                cout << "\t\t\t\t\t\t\tDraw";
                break;
            }
            cout << "\n\n" << name2 << " : Choose number => ";
            cin >> num;
            check(num, name1, name2);
            game_numbers[num - 1] = player2_symbol;
            times++;
            system("cls");
            gameStructure(name1, name2);
        }
    }
}
bool play_again(string name1, string name2)
{
    string answer;
    cout << "\nDo you want to play again?\n";
    cin >> answer;
    for (int i = 0; i < answer.length(); i++)
    {
        answer[i] = tolower(answer[i]);
    }
    if (answer == "yes")
    {
        for (int i = 0; i < 9; i++)
        {
            game_numbers[i] = '0' + i + 1;
        }
        times = 1;
        swap(player1_symbol, player2_symbol);
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    // To increase (cin,cout) compilation process
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ///////////////////////////////
    string player1, player2;
    display(player1, player2);
    do
    {
        gameStructure(player1, player2);
        game_logic(player1, player2);
    } while (play_again(player1, player2));
    return 0;
}