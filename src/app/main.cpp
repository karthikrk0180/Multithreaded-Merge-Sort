#include <iostream>
#include <vector>
#include <chrono>
#include "sorting/mergeSort.hpp"
#include "sorting/parallelMergeSort.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    const int SIZE = 10;
    vector<int> nums(SIZE);
    vector<int> nums1(SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        nums[i] = rand() % 10;
        nums1[i] = rand() % 10;
    }

    MergeSort *mergesort = new MergeSort(&nums);
    auto start = chrono::high_resolution_clock::now();
    mergesort->sort();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> mergesortDuration = end - start;
    cout << "MergeSort Algorithm time taken: " << mergesortDuration.count() << " seconds" << endl;
    delete mergesort;

    ParallelMergeSort *parallelMergesort = new ParallelMergeSort(&nums1);
    start = chrono::high_resolution_clock::now();
    parallelMergesort->sort();
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> parallelMergeSortDuration = end - start;
    cout << "Parallel MergeSort Algorithm time taken: " << parallelMergeSortDuration.count() << " seconds" << endl;
    delete parallelMergesort;

    return 0;
}
