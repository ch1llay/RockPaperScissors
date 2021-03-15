#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
using namespace std;

string phigures[] = { "камень", "ножницы", "бумага" };
int results[6][3] = { {0, 1, 1}, {0, 2, 0}, {1, 2, 1}, {1, 0, 0}, {2, 0, 1}, {2, 1, 0} };

int getWinner(int user_phigure, int phigure) {
    for (int i = 0; i < 6; i++) {
        if (user_phigure == results[i][0] && phigure == results[i][1])
            return results[i][2];
        else if (user_phigure == phigure)
            return -1;
    }
}

template <typename T>
int getIndex(string s, T m[], int size = 3) {
    for (int i = 0; i < size; i++) {
        if (s == m[i])
            return i;
    }
    return -1;
}

int main(int argc, char const* argv[])
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string s;
    int phigure;
    srand(clock());
    while (1) {
        cout << "Введите фигуру " << endl;
        cin >> s;
        int user_phigure = getIndex(s, phigures);
        if (user_phigure != -1) {
            phigure = rand() % 3;
            cout << phigures[phigure] << endl;

            int winner = getWinner(user_phigure, phigure);
            switch (winner) {
            case 1:
                cout << "Вы победили!" << endl;
                break;
            case 0:
                cout << "Вы проиграли." << endl;
                break;
            case -1:
                cout << "Ничья!" << endl;
                break;
            }
        }



        if (s == "stop")
            break;

    }
    system("pause");
    return 0;
}

