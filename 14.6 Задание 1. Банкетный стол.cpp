#include <iostream>
#include <vector>
using namespace std;


void print_serving (vector<vector<int>>::iterator cutlery,
                    vector<vector<int>>::iterator plates,
                    vector<vector<int>>::iterator chairs);

int main() {
    vector<vector<int>> cutlery {{4,3,3,3,3,3},{4,3,3,3,3,3}};
    vector<vector<int>> plates  {{3,2,2,2,2,2},{3,2,2,2,2,2}};
    vector<vector<int>> chairs  {{1,1,1,1,1,1},{1,1,1,1,1,1}};

    cout << "\nПеред началом банкета:";
    print_serving(cutlery.begin(),plates.begin(), chairs.begin());

    chairs[0][5] += 1;      // 1 ряд, 5 место - добавили стул для ребёнка
    cutlery[1][3] -= 1;     // 2 ряд, 3 место - сперли ложку
    cutlery[0][0] -= 1;     // первый VIP отдал свою ложку
    cutlery[1][3] += 1;     // 2 ряд, 3 место - принял от него ложку
    plates[0][0] -= 1;      // первый VIP остался без десертной тарелки

    cout << "\nПосле банкета:";
    print_serving(cutlery.begin(),plates.begin(), chairs.begin());


    return 0;
}


void print_serving (vector<vector<int>>::iterator cutlery,
                    vector<vector<int>>::iterator plates,
                    vector<vector<int>>::iterator chairs) {

    cout << "\nПриборы:\t";
    for (int n = 0; n < 2; n++) {
        cout << " [ ";
        for (int i = 0; i < cutlery[0].size(); i++) cout << cutlery[n][i] << " ";
        cout << "] ";
    }
    cout << "\nТарелки:\t";
    for (int n = 0; n < 2; n++) {
        cout << " [ ";
        for (int i = 0; i < plates[0].size(); i++) cout << plates[n][i] << " ";
        cout << "] ";
    }
    cout << "\nСтулья:\t\t";
    for (int n = 0; n < 2; n++) {
        cout << " [ ";
        for (int i = 0; i < chairs[0].size(); i++) cout << chairs[n][i] << " ";
        cout << "] ";
    }
    cout << endl;
}
