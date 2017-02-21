#include <vector>
#include <iostream>
using namespace std;

int binsearchL(vector<int> A, int left, int right, int key)
{
    int end = right;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (A[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    if (right < 0) right = 0;
    if (left >= end) left = end - 1;
    if (A[left] == key) return left;
    if (A[right] == key) return right;
    return -1;

}

int binsearchR(vector<int> A, int left, int right, int key)
{
    int end = right;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (A[mid] <= key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    if (right < 0) right = 0;
    if (left >= end) left = end - 1;
    if (A[right] == key) return right;
    if (A[left] == key) return left;
    return -1;

}


int main()
{
    vector<int> a = { 0, 1, 1, 3, 3, 3, 8, 8};
    cout << "Left\n";
    cout << binsearchL(a, 0, a.size(), 3) << "\n";
    cout << binsearchL(a, 0, a.size(), 8) << "\n";
    cout << binsearchL(a, 0, a.size(), 1) << "\n";
    cout << binsearchL(a, 0, a.size(), 0) << "\n";
    cout << binsearchL(a, 0, a.size(), 4) << "\n";

    cout << "Right\n";

    cout << binsearchR(a, 0, a.size(), 3) << "\n";
    cout << binsearchR(a, 0, a.size(), 8) << "\n";
    cout << binsearchR(a, 0, a.size(), 1) << "\n";
    cout << binsearchR(a, 0, a.size(), 0) << "\n";
    cout << binsearchR(a, 0, a.size(), 4) << "\n";
}
