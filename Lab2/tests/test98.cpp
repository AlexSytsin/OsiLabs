#include <gtest/gtest.h>
#include <windows.h>
#include <vector>
#include <cmath>
#include <iostream>

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

TEST(ThreadTest98, MinMaxTest) {
    arr.clear();
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);
    minEl = 0;
    maxEl = 0;

    HANDLE hMinMax = CreateThread(NULL, 0, min_max, NULL, 0, NULL);

    WaitForSingleObject(hMinMax, INFINITE);

    EXPECT_EQ(arr[minEl], 10);    
    EXPECT_EQ(arr[maxEl], 50); 
    CloseHandle(hMinMax);
}

TEST(ThreadTest98, AverageTest) {
    arr.clear();
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);
    average = 0;

    HANDLE hAverage = CreateThread(NULL, 0, average_thread, NULL, 0, NULL); 
    WaitForSingleObject(hAverage, INFINITE);

    EXPECT_EQ(average, 30); 
    CloseHandle(hAverage);
}

TEST(ThreadTest98, ReplaceMinMaxTest) {
    arr.clear();
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);
    minEl = 0;
    maxEl = 4;
    average = 30;

    arr[minEl] = static_cast<int>(round(average));
    arr[maxEl] = static_cast<int>(round(average));

    EXPECT_EQ(arr[0], 30);     
    EXPECT_EQ(arr[4], 30); }

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}