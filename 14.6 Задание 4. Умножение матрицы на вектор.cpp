#include <iostream>
#include <vector>
using namespace std;

int main() {

    float arrayA[4][4];
    vector<float> arrayB(4); // здесь 4 значения инициализированы = 0.0 и доступны по индексам
    vector<float> arrayC;       // здесь размер вектора = 0 и поэтому по индексам доступа нет !!!

    for (int i = 0; i < 4; i++) {
        cout << "Введите строку № " << i + 1 << " массива А (4 числа) = ";
        cin >> arrayA[i][0] >> arrayA[i][1];
        cin >> arrayA[i][2] >> arrayA[i][3];
    }
    cout << "\nВы ввели:\n";
    for (auto & x : arrayA) {
        cout << "{ ";
        for (float y : x) cout << y << " ";
        cout << "}\n";
    }

    cout << "\nВведите 4 значения вектора В = ";
    for (int i = 0; i < 4; i++) cin >> arrayB[i];

    cout << "\nВектор В:\n";
    cout << "{ ";
    for (float i : arrayB) cout << i << " ";
    cout << "}\n";

    // умножаем А[x][y] на В[y] - получаем 4х компонентный вектор = С
    // Вектор С у нас не инициализирован, поэтому сначала мы обнулим его
    // добавлением push_back(0.0) и индекс станет доступен, по этому индексу
    // можно обращаться к вектору как к обычному массиву.
    for (int x = 0; x < 4; x++) {
        arrayC.push_back(0.0);
        for (int y = 0; y < 4; y++) arrayC[x] += arrayA[x][y] * arrayB[y];
    }

    cout << "\nВектор С:\n";
    cout << "{ ";
    for (float i : arrayC) cout << i << " ";
    cout << "}\n";

    return 0;
}

