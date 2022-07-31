#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
#include "vehicle.h"
using namespace std;

//get data from the csv
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
//print top 10
void printTop10(vector<Vehicle> &v){
  int count =0;
  int i = 0;
  while (count < 10)
  {
    if(v[i].isGas()){
      cout << count+1 << ". "<< v[i].getMake() << " " << v[i].getModel() << " " << v[i].getYear() << " " << v[i].getCombmpg() << " " << endl;
      count++;
      }
    i++;
  }
}
//returns a new array with the given year
void getYearHelper(vector<Vehicle> &v,vector<Vehicle> &y, int mid, int input){
  if(v[mid].getYear() == input){
    for (unsigned int i =mid; i<v.size(); i++){
      if (v[i].getYear() < input){
        break;
      }
      y.push_back(v[i]);
    }
    for (unsigned int j =mid-1; j >= 0; j--){
      if (v[j].getYear() > input){
        break;
      }
      y.push_back(v[j]);
    }
  }
  else if (v[mid].getYear() < input){
    getYearHelper(v, y, mid/2, input);
  }
  else{
    getYearHelper(v, y, mid + (mid/2), input);
  }
}
vector<Vehicle> getYear(vector<Vehicle> &v, int input){
  vector<Vehicle> y; //new array with just the years
  int mid = v.size()/2;
  getYearHelper(v, y, mid, input);
  return y;  
}

