#include <thread>
#include "parallelMergeSort.hpp"
#include <iostream>
#include <vector>
#include <algorithm>


const int SIZE_THRESHOLD = 5000;

ParallelMergeSort::ParallelMergeSort(vector<int> *num)
    : num(num) {}

ParallelMergeSort::~ParallelMergeSort() {}

void ParallelMergeSort::recursiveSort(int left, int right)
{
    

    if (right - left < SIZE_THRESHOLD) {
        std::sort(nums->begin() + left, nums->begin() + right + 1);
        return;
    }

    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;

    std::thread thread_1([this, left, mid]
                    { this->recursiveSort(left, mid); });
    std::thread thread_2([this, mid, right]
                    { this->recursiveSort(mid + 1, right); });
    thread_1.join();
    thread_2.join();

    std::vector<int> result;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if ((*num)[i] <= (*num)[j])
        {
            result.push_back((*num)[i]);
            i++;
        }
        else
        {
            result.push_back((*num)[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        result.push_back((*num)[i]);
        i++;
    }

    while (j <= right)
    {
        result.push_back((*num)[j]);
        j++;
    }

    for (int k = 0; k < result.size(); k++)
    {
        (*num)[left + k] = result[k];
    }
}

void ParallelMergeSort::sort()
{
    if ((*num).size() == 0)
    {
        return;
    }

    thread thread_1([this]
                    { this->recursiveSort(0, (*num).size() - 1); });
    thread_1.join();

    // for (int i = 0; i < (*num).size(); i++)
    // {
    //     cout << (*num)[i] << endl;
    // }

    // comment it for large number or else 💥
}
