#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cmath>

using namespace std;


vector<int> arr;
int minEl = 0, maxEl = 0;
double average = 0; 


void min_max() {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[minEl]) {
            minEl = i;
        }
        this_thread::sleep_for(chrono::milliseconds(7));

        if (arr[i] > arr[maxEl]) {
            maxEl = i; 
        }
        this_thread::sleep_for(chrono::milliseconds(7)); 
    }
    cout << "Min element: " << arr[minEl] << endl;
    cout << "Max element: " << arr[maxEl] << endl;
}

void average_thread() {
    double sum = 0;
    for (int num : arr) {
        sum += num; 
        this_thread::sleep_for(chrono::milliseconds(12));
    }
    average = sum / arr.size(); 
    cout << "Average value: " << average << endl;
}

int main() {
    // Ввод массива
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        arr.push_back(element);
    }

    thread t1(min_max);
    thread t2(average_thread);

    t1.join();
    t2.join();

    arr[minEl] = round(average);
    arr[maxEl] = round(average);

    cout << "Modified array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}