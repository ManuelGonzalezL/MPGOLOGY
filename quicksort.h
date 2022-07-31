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
    cout << a << endl;
    *b = temp;
}

int partition(vector<Vehicle> &arr, int low, int high) {
    int counter = low-1;
    Vehicle pivot = arr[high-1];
    for(int i = low; i < high-1; i++) {
        if (arr[i].getCombmpg() <= pivot.getCombmpg()) {
            counter++;
            swap(&arr[counter], &arr[i]);
        } 
    }
    swap(&arr[counter+1], &arr[high-1]);
    return counter+1;
}

void quickSort(vector<Vehicle>& arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }


}

void quickSortYear(vector<Vehicle> &vehicles, int n, int selectedYear) {
    set<int> set;
    unordered_map<int, vector<Vehicle>> map;
    for (auto &vehicle : vehicles) {
        map[vehicle.getYear()].push_back(vehicle);
        set.insert(vehicle.getYear());
    } 
    if (selectedYear > 0) {
        vector<Vehicle> cars = map[selectedYear];
        quickSort(cars, 0, cars.size() - 1);
        cout << cars[0].getModel() << " " << selectedYear << endl;
    } else {
        for (auto year : set) {
            vector<Vehicle> cars = map[year];
            quickSort(cars, 0, cars.size() - 1);
            cout << cars[0].getModel() << " " << year << endl;
        }
    }
    

    
}