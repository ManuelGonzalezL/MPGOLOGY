#pragma once
#include <vector>
using namespace std;
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include "helper.h"

void swap(Vehicle *a, Vehicle *b) {
    Vehicle temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<Vehicle>& nums, int p, int r)
{
    Vehicle x = nums[r];
    int i = p-1;
    for (int j = p; j < r; j++)
    {
        if (nums[j].getCombmpg() > x.getCombmpg())
        {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i+1], nums[r]);
    return i+1;
}

void quickSort(vector<Vehicle> &nums, int p, int r)
{
    if (p<r)
    {
        int q = partition(nums, p, r);
        quickSort(nums,p , q-1);
        quickSort(nums, q+1, r);    
    }
    
}


