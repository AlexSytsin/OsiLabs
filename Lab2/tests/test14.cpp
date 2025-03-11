#include <gtest/gtest.h>
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

TEST(ThreadTest, MinMaxTest) {
    arr = { 10, 20, 30, 40, 50 };
    minEl = 0;
    maxEl = 0;

    thread t1(min_max);
    t1.join();

    EXPECT_EQ(arr[minEl], 10);     
    EXPECT_EQ(arr[maxEl], 50); }

TEST(ThreadTest, AverageTest) {
    arr = { 10, 20, 30, 40, 50 };
    average = 0;

    thread t2(average_thread);
    t2.join();

    EXPECT_EQ(average, 30); }

TEST(ThreadTest, ReplaceMinMaxTest) {
    arr = { 10, 20, 30, 40, 50 };
    minEl = 0;
    maxEl = 4;
    average = 30;

    arr[minEl] = round(average);
    arr[maxEl] = round(average);

    EXPECT_EQ(arr[0], 30);     
    EXPECT_EQ(arr[4], 30); }

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}