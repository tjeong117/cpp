#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int right) {
    int mid = (left + right) / 2;
    vector<int> temp(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, right);
}

void printVector(vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr;
    arr.push_back(12);
    arr.push_back(11);
    arr.push_back(13);
    arr.push_back(12);
    arr.push_back(4);
    arr.push_back(32);
    arr.push_back(6);
    arr.push_back(783);
    arr.push_back(2);
    arr.push_back(4);

    cout << "Original array: ";
    printVector(arr);

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    printVector(arr);

    return 0;
}
