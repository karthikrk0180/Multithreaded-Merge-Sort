#ifndef PARALLELMERGESORT_H
#define PARALLELMERGESORT_H

#include <vector>
#include <thread>
#include <mutex>

using namespace std;

class ParallelMergeSort
{
private:
    vector<int> *num;

public:
    ParallelMergeSort(vector<int> *num);
    ~ParallelMergeSort();
    void sort();
    void recursiveSort(int left, int right);
};

#endif