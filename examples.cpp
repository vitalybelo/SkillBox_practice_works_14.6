#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<vector<int>> data2Base {{1,1,1,1,1},
                                   {2,2,2,2,2,2,2,2},
                                   {3,3,3,3,}};

    cout << data2Base.size() << endl;
    cout << data2Base[2].size() << endl;
    data2Base.pop_back();
    cout << data2Base.size() << endl;

//    for (int x = 0; x < serving.size(); x++) {
//        for (int i : serving[x]) cout << " " << i;
//        cout << endl;
//    }
    for (auto & x : data2Base) {
        for (int i : x) cout << " " << i;
        cout << endl;
    }

    return 0;
}
