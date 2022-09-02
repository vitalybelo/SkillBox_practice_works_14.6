#include <iostream>
#include <vector>
using namespace std;

void showBubbleMap (bool bubbleWrap[][12]);
bool gameOver (bool bubbleWrap[][12]);
bool popupBubbleMap (bool bubbleWrap[][12],int x1, int y1, int x2, int y2);

int main() {

    int x1, y1, x2, y2;
    bool bubbleWrap[12][12];
    for (auto &x: bubbleWrap)
        for (bool &y: x) y = 'true';

    do {
        showBubbleMap(bubbleWrap);
        cout << "Введите координаты X1,Y1 - X2,Y2 (от 1 до 12) :: ";
        cin >> x1 >> y1 >> x2 >> y2;
    } while (popupBubbleMap(bubbleWrap,--x1,--y1,--x2,--y2));

    cout << "\nGAME OVER\n";
    showBubbleMap(bubbleWrap);

    return 0;
}

/**
 * Отображает вид пузырчатой пленки
 * @param bubbleWrap - массив значений клеток пленки
 */
void showBubbleMap (bool bubbleWrap[][12]) {
    cout << "\nX =  1 2 3 4 5 6 7 8 9 0 1 2\n";
    cout << "Y  ---------------------------\n";
    for (int x = 0; x < 12; x++) {
        cout << (x + 1) % 10 << ": | ";
        for (int y = 0; y < 12; y++)
            cout << (bubbleWrap[x][y] ? "o " : "* ");
        cout << "|\n";
    }
    cout << "   ---------------------------\n";
}
/**
 * Возвращает истину если все клетки лопнули (нет пузыриков)
 * @param bubbleWrap - массив клеток пленки
 * @return - true если протыкана каждая клетка
 */
bool gameOver (bool bubbleWrap[][12]) {
    for (int x = 0; x < 12; x++)
        for (int y = 0; y < 12; y++) if (bubbleWrap[x][y]) return false;
    return true;
}
/**
 * В заданном координатами прямоугольнике уничтожает все пузырьки
 * @param bubbleWrap - массив клеток пузырьков
 * @param x1 - координата Х - левого угла
 * @param y1 - координата Y - левого угла
 * @param x2 - координата Х - правого угла
 * @param y2 - координата Y - правого угла
 * @return - истину если акт депузыризации выполнен, но пузырьки еще есть
 * или если введены кривые координаты и нужно ввести их заново.
 * В общем понимании - истину пока нужно, чтобы крутился цикл игры.
 */
bool popupBubbleMap (bool bubbleWrap[][12],int x1, int y1, int x2, int y2) {

    if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 ||
        x1 > 11 || x2 > 11 || y1 > 11 || y2 > 11) {
        cerr << "Координаты не корректные, повторите пожалуйста ввод\n";
        return true;
    }

    if (x1 > x2) swap (x1,x2);
    if (y1 > y2) swap (y1,y2);

    for (int y = y1; y <= y2; y++)
        for (int x = x1; x <= x2; x++)
            if (bubbleWrap[y][x]) {
                cout << "! pop !" << endl;
                bubbleWrap[y][x] = false;
            }
    return !gameOver(bubbleWrap);
}
