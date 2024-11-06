#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
using namespace std;

class MergeSort
{
private:
    vector<int> *num;

public:
    MergeSort(vector<int> *num);
    ~MergeSort();
    void sort();
    void recursiveSort(int left, int right);
};

#endif