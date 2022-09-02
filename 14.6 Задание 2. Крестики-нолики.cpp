#include <iostream>
#include <vector>
using namespace std;

void cout_field (vector<vector<char>>::iterator field);
bool check_Winner (vector<vector<char>>::iterator field, char sign);
bool check_PassOff (vector<vector<char>>::iterator field);
int check_Field (vector<vector<char>>::iterator field);
bool move_field (vector<vector<char>>::iterator field, int x, int y, char sign);

int main() {

    int x,y, result;
    vector<vector<char>> battleField{{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    auto iter = battleField.begin();

    do {
        cout_field(iter);
        do {
            cout << "\nПервый игрок ваш ход (ряд 1-3, колонка 1-3): ";
            cin >> x >> y;
        } while(move_field(iter, --x, --y,'X'));
        result = check_Field(iter);
        if (result == 1 || result == 0) break;

        cout_field(iter);
        do {
            cout << "\nВторой игрок ваш ход (ряд 1-3, колонка 1-3): ";
            cin >> x >> y;
        } while(move_field(iter, --x, --y,'O'));
        result = check_Field(iter);

    } while (result == -1);

    switch (result) {
        case 1: cout << "\nВыиграл 1-ый игрок\n"; break;
        case 2: cout << "\nВыиграл 2-ой игрок\n"; break;
        case 0: cout << "\nНичья"; break;
    }
    cout_field(iter);

    return 0;
}


bool check_Winner (vector<vector<char>>::iterator field, char sign) {
    for (int i = 0; i < 3; i++) {
        if (field[i][0] == sign && field[i][1] == sign && field[i][2] == sign) return true;
        if (field[0][i] == sign && field[1][i] == sign && field[2][i] == sign) return true;
    }
    if (field[0][0] == sign && field[1][1] == sign && field[2][2] == sign) return true;
    if (field[0][2] == sign && field[1][1] == sign && field[2][0] == sign) return true;
    return false;
}

bool check_PassOff (vector<vector<char>>::iterator field) {
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            if (field[x][y] == ' ') return false;
    return true;
}

int check_Field (vector<vector<char>>::iterator field) {
    if (check_PassOff(field)) return 0;
    if (check_Winner(field,'X')) return 1;
    if (check_Winner(field,'O')) return 2;
    return -1;
}

bool move_field (vector<vector<char>>::iterator field, int x, int y, char sign) {
    if (x < 0 || x > 2 || y < 0 || y > 2) {
        cout << "Координаты вне диапазона, повторите пожалуйста ввода\n";
        return true;
    }
    if (field[x][y] != ' ') {
        cout << "Клетка уже занята, повторите пожалуйста ввода\n";
        return true;
    }
    field[x][y] = sign;
    return false;
}

void cout_field (vector<vector<char>>::iterator field) {

    cout << "\n    1 2 3 \n";
    cout << "  ---------\n";
    for (int n = 0; n < 3; n++) {
        cout << n + 1 << " | ";
        for (int i = 0; i < 3; i++) cout << field[n][i] << " ";
        cout << "|\n";
    }
    cout << "  ---------\n";
}
