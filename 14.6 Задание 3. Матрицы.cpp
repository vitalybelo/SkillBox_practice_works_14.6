#include <iostream>
using namespace std;

bool matrix_equals (int m1[][4], int m2[][4]);
void matrix_print (int m1[][4], int m2[][4]);

int main() {

    int matrix1[4][4] {{1,2,3,4},
                       {5,6,7,8},
                       {9,8,7,6},
                       {5,4,3,2}};
    int matrix2[4][4] {{2,1,1,1},
                       {1,2,1,1},
                       {1,1,2,1},
                       {1,1,1,2}};
    int matrix3[4][4] {{1,2,3,4},
                       {5,6,7,8},
                       {9,8,7,6},
                       {5,4,3,2}};

    cout << ((matrix_equals(matrix1, matrix2)) ?
             "\nМатрицы 1 и 2 равны\n" : "\nМатрицы 1 и 2 не равны\n");
    matrix_print(matrix1, matrix2);

    cout << ((matrix_equals(matrix1, matrix3)) ?
             "\nМатрицы 1 и 3 равны\n" : "\nМатрицы 1 и 3 не равны\n");
    matrix_print(matrix1, matrix3);

    cout << "\nПреобразуем матрицу 1 в диагональную\n\n";
    for (int x = 0; x < 4; x++){
        cout << "[ ";
        for (int y = 0; y < 4; y++) {
            if (x != y) matrix1[x][y] = 0;
            cout << matrix1[x][y] << " ";
        }
        cout <<"]\n";
    }

    return 0;
}

bool matrix_equals (int m1[][4], int m2[][4]) {
    for (int x = 0; x < 4; x++)
        for (int y = 0; y < 4; y++)
            if (m1[x][y] != m2[x][y]) return false;
    return true;
}

void matrix_print (int m1[][4], int m2[][4]) {
    for (int x = 0; x < 4; x++) {
        cout << endl << " [ ";
        for (int y = 0; y < 4; y++) cout << m1[x][y] << " ";
        cout << "] :: [ ";
        for (int y = 0; y < 4; y++) cout << m2[x][y] << " ";
        cout << "]";
    }
    cout << endl;
}
