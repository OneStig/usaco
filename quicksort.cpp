#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> in = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 25};
  
    cout << binarySearch(in, 11, 0, in.size() - 1) << endl;

    return 0;
}

int binarySearch(vector<int> &a, int b, int left, int right) {
    if (left > right) {
        return -1;
    }

    int mid = (left + right) / 2;

    if (a[mid] == b) {
        return mid;
    }

    if (a[mid] > b) {
        return binarySearch(a, b, left, mid - 1);
    }

    if (a[mid] < b) {
        return binarySearch(a, b, mid + 1, right);
    }   
}