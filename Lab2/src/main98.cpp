#include <windows.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


vector<int> arr;
int minEl = 0, maxEl = 0;
double average = 0;

DWORD WINAPI min_max(LPVOID lpParam) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[minEl]) {
            minEl = i;
        }
        Sleep(7);

        if (arr[i] > arr[maxEl]) {
            maxEl = i;
        }
        Sleep(7);
    }
    cout << "Min element: " << arr[minEl] << endl;
    cout << "Max element: " << arr[maxEl] << endl;
    return 0;
}

DWORD WINAPI average_thread(LPVOID lpParam) {
    double sum = 0;
    for (int num : arr) {
        sum += num;
        Sleep(12);
    }
    average = sum / arr.size();
    cout << "Average value: " << average << endl;
    return 0;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        arr.push_back(element);
    }

    HANDLE hMinMax = CreateThread(NULL, 0, min_max, NULL, 0, NULL);
    HANDLE hAverage = CreateThread(NULL, 0, average_thread, NULL, 0, NULL);

    WaitForSingleObject(hMinMax, INFINITE);
    WaitForSingleObject(hAverage, INFINITE);

    arr[minEl] = round(average);
    arr[maxEl] = round(average);

    cout << "Modified array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    CloseHandle(hMinMax);
    CloseHandle(hAverage);

    return 0;
}