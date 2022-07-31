#pragma once
#include <vector>
using namespace std;
#include "helper.h"

// Code from 6.1a Module 5 Stepik Solution (Min-heap)
void heapifyYear(vector<Vehicle> &arr, int n, int i)  
{  
    int smallest = i; // Initialize smallest as root  
    int l = 2 * i + 1; // left = 2*i + 1  
    int r = 2 * i + 2; // right = 2*i + 2  
   
    // If left child is smaller than root  
    if (l < n && arr[l].getYear() < arr[smallest].getYear())  
        smallest = l;  
   
    // If right child is smaller than smallest so far  
    if (r < n && arr[r].getYear() < arr[smallest].getYear())  
        smallest = r;  
   
    // If smallest is not root  
    if (smallest != i) {  
        swap(arr[smallest], arr[i]);
   
        // Recursively heapify the affected sub-tree  
        heapifyYear(arr, n, smallest);  
    }  
}

// Code from 6.1a Module 5 Stepik Solution (Min-heap)
void heapifyCombmpg(vector<Vehicle> &arr, int n, int i)  
{  
    int smallest = i; // Initialize smallest as root  
    int l = 2 * i + 1; // left = 2*i + 1  
    int r = 2 * i + 2; // right = 2*i + 2  
   
    // If left child is smaller than root  
    if (l < n && arr[l].getCombmpg() < arr[smallest].getCombmpg())  
        smallest = l;  
   
    // If right child is smaller than smallest so far  
    if (r < n && arr[r].getCombmpg() < arr[smallest].getCombmpg())  
        smallest = r;  
   
    // If smallest is not root  
    if (smallest != i) {  
        swap(arr[smallest], arr[i]);
   
        // Recursively heapify the affected sub-tree  
        heapifyCombmpg(arr, n, smallest);  
    }  
} 

// Code taken from "Discussion 7 - Heaps & Priority Queues" PowerPoint from Module 5
void buildHeapYear(vector<Vehicle> &arr, int n) { 
    int startIdx = (n / 2) - 1;  // Index of last internal node 
    // Perform reverse level order traversal from last internal node and heapify
    for (int i = startIdx; i >= 0; i--) { 
        heapifyYear(arr, n, i); 
    } 
} 

// Code taken from "Discussion 7 - Heaps & Priority Queues" PowerPoint from Module 5
void buildHeapCombmpg(vector<Vehicle> &arr, int n) { 
    int startIdx = (n / 2) - 1;  // Index of last internal node 
    // Perform reverse level order traversal from last internal node and heapify
    for (int i = startIdx; i >= 0; i--) { 
        heapifyCombmpg(arr, n, i); 
    } 
} 

void heapSortYear(vector<Vehicle> &arr, int n)
{
    // Build the heap
    buildHeapYear(arr, n);

    // Heap gets smaller until whole array ends up sorted
    for(int i = n - 1; i >= 0; i--)
    {
        // Swap root of heap with last element of heap
        swap(arr[0], arr[i]);
        // Heapify from the root (since root is no longer smallest element)
        heapifyYear(arr, i, 0);
    }
}

void heapSortCombmpg(vector<Vehicle> &arr, int n)
{
    // Build the heap
    buildHeapCombmpg(arr, n);

    // Heap gets smaller until whole array ends up sorted
    for(int i = n - 1; i >= 0; i--)
    {
        // Swap root of heap with last element of heap
        swap(arr[0], arr[i]);
        // Heapify from the root (since root is no longer smallest element)
        heapifyCombmpg(arr, i, 0);
    }
}