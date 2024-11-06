#include "mergeSort.hpp"
#include <iostream>

MergeSort::MergeSort(vector<int> *num)
{
    this->num = num;
}

MergeSort::~MergeSort() {}

void MergeSort::recursiveSort(int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;

    recursiveSort(left, mid);
    recursiveSort(mid + 1, right);

    vector<int> result;
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

void MergeSort::sort()
{
    if ((*num).empty())
    {
        return;
    }

    recursiveSort(0, (*num).size());

    for (int i = 0; i < (*num).size(); i++)
    {
        cout << (*num)[i] << endl;
    }
}
