#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;
#include "vehicle.h"

// get data from the csv
void readData(string filePath, vector<Vehicle> &Vehicles) {
  ifstream inFile(filePath);
  if (inFile.is_open()) {
    // heading
    string line;
    getline(inFile, line);

    while (getline(inFile, line)) {
      istringstream stream(line);

      int citympg;
      int combmpg;
      int hwaympg;
      string fuelType; // ex: diesel, premium
      int year;
      string make;
      string model;
      string driveTrain; // ex:awd
      string cylinders;
      string engLiters;
      string transmission;
      string style; // ex: Midsize, Subcompact
      string altFuel;

      string temp;

      getline(stream, temp, ',');
      citympg = stoi(temp);

      getline(stream, temp, ',');
      combmpg = stoi(temp);

      getline(stream, cylinders, ',');
      getline(stream, engLiters, ',');
      getline(stream, driveTrain, ',');
      getline(stream, fuelType, ',');

      getline(stream, temp, ',');
      hwaympg = stoi(temp);

      getline(stream, make, ',');
      getline(stream, model, ',');
      getline(stream, transmission, ',');
      getline(stream, style, ',');

      getline(stream, temp, ',');
      year = stoi(temp);

      getline(stream, altFuel, ',');

      Vehicle v(citympg, combmpg, hwaympg, fuelType, year, make, model,
                driveTrain, cylinders, engLiters, transmission, style, altFuel);
      Vehicles.push_back(v);
    }
  }
}
//builds map for main
void buildMap(unordered_map<int, vector<Vehicle>> &map, set<int> &set,
              vector<Vehicle> &v) {
  for (auto &vehicle : v) {
    map[vehicle.getYear()].push_back(vehicle);
    set.insert(vehicle.getYear());
  }
}
// print top 10 exluding Evs and combining years
void printTop10(vector<Vehicle> &v) {
  int count = 0;
  int i = 0;
  map<pair<string, int>, set<int>> model;
  vector<Vehicle> c;
  while (c.size() < 15) {
    if (v[i].isGas() &&
        model.count({v[i].getModel(), v[i].getCombmpg()}) == 0) {
      c.push_back(v[i]);
    }
    model[{v[i].getModel(), v[i].getCombmpg()}].insert(v[i].getYear());
    i++;
  }
  for (auto d : c) {
    if (count > 9) {
      break;
    }
    cout << count + 1 << ". " << d.getMake() << " " << d.getModel() << " ";
    if (model[{d.getModel(), d.getCombmpg()}].size() > 1)
      for (auto j : model[{d.getModel(), d.getCombmpg()}]) {
        cout << j << ", ";
      }
    else {
      cout << d.getYear() << " ";
    }
    cout << "MPG: " << d.getCombmpg() << endl;
    count++;
  }
}
  //prints top car
void printTop(vector<Vehicle> &v) {
  int i = 0;
  int count = 0;
  while (count < 1) {
    if (v[i].isGas()) {
      cout << v[i].getYear() << ": " << v[i].getMake() << " " << v[i].getModel()
           << " "
           << "MPG: " << v[i].getCombmpg() << endl;
      count++;
    }
    i++;
  }
}
// returns a new array with the given year doing binary search
void getYearHelper(vector<Vehicle> &v, vector<Vehicle> &y, int mid, int input, int temp) {
  if (v[mid].getYear() == input) {
    for (unsigned int i = mid; i < v.size(); i++) {
      if (v[i].getYear() < input) {
        break;
      }
      y.push_back(v[i]);
    }
    for (unsigned int j = mid - 1; j >= 0; j--) {
      if (v[j].getYear() > input) {
        break;
      }
      y.push_back(v[j]);
    }
  } else if (v[mid].getYear() < input) {
    mid = temp;
    temp = temp / 2;
    getYearHelper(v, y, mid, input, temp);
  } else {
    mid = mid + temp;
    temp = temp / 2;
    getYearHelper(v, y, mid, input, temp);
  }
}
vector<Vehicle> getYear(vector<Vehicle> &v, int input) {
  vector<Vehicle> y; // new array with just the years
  int mid = v.size() / 2;
  int temp = mid / 2;
  getYearHelper(v, y, mid, input, temp);
  return y;
}