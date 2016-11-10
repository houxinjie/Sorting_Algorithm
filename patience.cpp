#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
template<typename T>
vector<T>& operator<<(vector<T>& vi, vector<T>& vx) {
    int len = vi.size();
    vi.resize(vi.size() + vx.size());
    for (int i = 0; i < (int) vx.size(); i++) {
        vi[i + len] = vx[i];
    }
    return vi;
}
template<typename T>
void reverse(vector<T>& arr) {
    int len = arr.size();
    for (int i = 0; i < len - 1 - i; i++) {
        swap(arr[i], arr[len - 1 - i]);
    }
}
template<typename T>
void patience_sort(vector<T>& arr) {
    int len = arr.size();
    if (len < 2) {
        return;
    }
    vector<vector<T> > piles;
    for (int i = 0; i < len; i++) {
        vector<T> new_pile = { arr[i] };
        int insert;
        for (insert = 0; insert < (int) piles.size(); insert++) {
            if (new_pile[0] < piles[insert][0]) {
                break;
            }
        }
        if (insert == (int) piles.size()) {
            piles.push_back(new_pile);
        } else {
            piles[insert].push_back(arr[i]);
        }
    }
    arr.clear();
    for (int j = 0; j < (int) piles.size(); j++) {
        reverse(piles[j]);
        patience_sort(piles[j]);
        arr << piles[j];
    }
}

template<typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    int len = v.size();
    for (int i = 0; i < len; cout << (++i == len ? "" : ",")) {
        os << v[i];
    }
    return os;
}

int main() {
    vector<int> arr = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    cout << arr << endl;
    patience_sort(arr);
    cout << arr << endl;
    return 0;
}
