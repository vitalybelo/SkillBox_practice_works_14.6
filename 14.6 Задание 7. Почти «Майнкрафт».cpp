#include <iostream>
using namespace std;

int main() {

    int height;
    int xSize = 4;
    int ySize = 4;
    int zSize = 5;
    int array[xSize][ySize][zSize];

    cout << "Ландшафт состоит из " << xSize << "x" << ySize << " горизонтальных секторов\n";
    cout << "Введите высоту столбцов (<= " << zSize << " блоков) каждого сектора:\n";

    for (int x = 0; x < xSize; x++)
        for (int y = 0; y < ySize; y++) {
            cin >> height;
            for (int z = 0; z < zSize; z++)
                array[x][y][z] = (z < height) ? 1 : 0;
        }

    for (int i = 0; i < zSize; i++) {
        do {
            cout << "Введите высоту горизонтального среза\n";
            cout << "Значение должно быть от 1 до " << zSize << " = ";
            cin >> height;
        } while (height <= 0 || height > zSize);
        height--;

        cout << endl;
        for (int x = 0; x < xSize; x++) {
            for (int y = 0; y < ySize; y++) {
                cout << array[x][y][height] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
