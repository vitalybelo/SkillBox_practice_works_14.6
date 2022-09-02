#include <iostream>
#include <cstdlib>
using namespace std;

void clearNavyMap (char navyMap[][10]);
void showNavyMap (char navyMapOne[][10], char navyMapTwo[][10]);
bool checkLocationSpace (char navyMap[][10], int &x, int &y, int direction, int shipSize);
void autoLocationNavy (char navyMap[][10], int countShips, int shipSize);
bool checkNavyMap (char navyMap[][10], int shootX, int shootY, int player);

int main() {
    setlocale(LC_ALL,"Russian_Russia.1251");
    srand(time(0));

    bool playerOneWin;
    bool playerTwoWin;
    char playerOne[10][10];
    char playerTwo[10][10];
    clearNavyMap(playerOne);
    clearNavyMap(playerTwo);

    autoLocationNavy(playerOne, 4, 1);
    autoLocationNavy(playerOne, 3, 2);
    autoLocationNavy(playerOne, 2, 3);
    autoLocationNavy(playerOne, 1, 4);
    autoLocationNavy(playerTwo, 4, 1);
    autoLocationNavy(playerTwo, 3, 2);
    autoLocationNavy(playerTwo, 2, 3);
    autoLocationNavy(playerTwo, 1, 4);

    int playerX, playerY;
    int machineX, machineY;

    do {
        showNavyMap(playerOne, playerTwo);

        cout << "SHOOT ( X,Y ) = ";
        cin >> playerX >> playerY;
        playerOneWin = checkNavyMap(playerTwo,playerX,playerY,1);
        if (playerOneWin) {
            cout << "PLAYER WIN\n";
            break;
        }

        machineX = rand() % 10;
        machineY = rand() % 10;
        playerTwoWin = checkNavyMap(playerOne,machineX,machineY,0);
        if (playerTwoWin) {
            cout << "MACHINE WIN\n";
            break;
        }

    } while (true);

    showNavyMap(playerOne, playerTwo);


    return 0;
}

/**
 * Чистит игровое поле
 * @param navyMap - массив игрового поля
 */
void clearNavyMap (char navyMap[][10]) {
    for (int y = 0; y < 10; y++)
        for (int x = 0; x < 10; x++) navyMap[y][x] = ' ';
}

/**
 * Отображает игровое поле на консоли
 */
void showNavyMap (char navyMapOne[][10], char navyMapTwo[][10]) {
    cout << "\n X = 0 1 2 3 4 5 6 7 8 9      X = 0 1 2 3 4 5 6 7 8 9\n";
    cout << "Y  -----------------------   Y  -----------------------\n";
    for (int y = 0; y < 10; y++) {
        cout << y << ": | ";
        for (int x = 0; x < 10; x++)
            cout << navyMapOne[y][x] << ' ';
        cout << "|   ";
        cout << y << ": | ";
        for (int x = 0; x < 10; x++)
            if (navyMapTwo[y][x] == 'X' || navyMapTwo[y][x] == '*')
                 cout << navyMapTwo[y][x] << ' '; else cout << "  ";
        cout << "|\n";
    }
    cout << "   -----------------------      -----------------------\n";
}

/**
 * Проверяет насколько успешный дыл сделан ход на клетку X , Y
 * меняет содержимое клетки на 'Х' если попал, на '*' если промах.
 * Проверяет все поле на конец игры.
 * @param navyMap - массив игрового поля
 * @param shootX - координата выстрела по горизонтали
 * @param shootY - координата выстрела по вертикали
 * @param player - равно 1 для игрока и 0 для машины
 * @return - возвращает истину если игра закончена
 */
bool checkNavyMap (char navyMap[][10], int shootX, int shootY, int player) {

    if (shootX < 0 || shootX > 9 || shootY < 0 || shootY > 9) return false;
    if (navyMap[shootY][shootX] >= '1' && navyMap[shootY][shootX] <= '4') {
        cout << ((player == 1) ? "PLAYER " : "MACHINE ");
        cout << "SHOOT SUCCESS !\n";
        navyMap[shootY][shootX] = 'X';
    } else {
        navyMap[shootY][shootX] = '*';
    }

    for (int y = 0; y < 9; y++)
        for (int x = 0; x < 9; x++)
            if (navyMap[y][x] >= '1' && navyMap[y][x] <= '4') return false;
    return true;
}

/**
 * Проверяет можно ли в точке поставить корабль определенной длины и в нужном
 * направлении. Проверяет периметр вокруг, на соприкосновение с другими кораблями.
 * @param navyMap - массив игрового поля
 * @param x - координата по горизонтали
 * @param y - координата по вертикали
 * @param direction - направление = 0 горизонталь, 1 - вертикаль
 * @param shipSize - размер судна (от 1 до 4 клеток на поле)
 * @return - истина если размещение в этой точке допустимо по правилам игры
 */
bool checkLocationSpace (char navyMap[][10], int &x, int &y, int direction, int shipSize) {

    int x1, x2, y1, y2;
    switch (direction) {
        case 0:
            if (x + shipSize > 9) x = 9 - shipSize;
            x1 = (x == 0) ? x : x - 1;
            y1 = (y == 0) ? y : y - 1;
            x2 = x + shipSize + 1;
            y2 = y + 1;
            break;
        case 1:
            if (y + shipSize > 9) y = 9 - shipSize;
            x1 = (x == 0) ? x : x - 1;
            y1 = (y == 0) ? y : y - 1;
            y2 = y + shipSize + 1;
            x2 = x + 1;
            break;
        default:
            return false;
    }
    if (x2 > 9) x2 = 9;
    if (y2 > 9) y2 = 9;

    for (int i = y1; i <= y2; i++)
        for (int j = x1; j <= x2; j++)
            if (navyMap[i][j] != ' ') return false;

    return true;
}

/**
 * Инициализирует флот. 4 одно-палубных, 3 двух-палубных, 2-трех-палубных
 * и 1 четырех-палубный корабль. Учитывается что корабли не могут стоять впритык.
 * Минимальное расстояние между суднами - 1 клетка по периметру.
 * @param navyMap - игровое поле
 * @param countShips - количество кораблей для размещения (от 4 до 1)
 * @param shipSize - размер корабля (палубы от 1 до 4)
 */
void autoLocationNavy (char navyMap[][10], int countShips, int shipSize) {

    shipSize--;
    bool found;
    int x, y, direction;

    for (int i = 0; i < countShips; i++)
    {
        do {
            found = true;
            x = rand() % 10;
            y = rand() % 10;
            direction = rand() % 2;
            found = checkLocationSpace(navyMap,x,y,direction,shipSize);

            if (found)
                if (direction == 0) {
                    for (int j = 0; j <= shipSize; j++)
                        navyMap[y][x + j] = (char) shipSize + '1';
                } else {
                    for (int j = 0; j <= shipSize; j++)
                        navyMap[y + j][x] = (char) shipSize + '1';
                }
        } while (!found);
    }
}
