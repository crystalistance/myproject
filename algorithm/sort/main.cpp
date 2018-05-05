#include  <iostream>
#include <vector>

using namespace std;

void BubbleSort(vector<int> &v) {
    int size = v.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <  n - 1 - i; j++) {
            if (v[j] < v[j+1]) {
                int tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }
}


void Show(vector<int> v) {
    for (auto item : v) {
        cout << item << ",";

    cout << endl;
}

int main() {

    vector<int> v = {1,3,2,4,5,9,7,8}
    BubbleSort(v);
    Show(v);
    return 0;
}
