#pragma once
#include <string>
using namespace std;

class Vehicle {
  int citympg;
  int combmpg;
  int hwaympg;
  string fuelType; // ex: diesel, premium
  int year;
  string make;
  string model;
  string driveTrain; // ex:awd
  string cylinders;
  string engLiters; // fuel capacity of engine in liters
  string transmission;
  string style;   // ex: Midsize, Subcompact
  string altFuel; // alternative fuel ex: hybrid
  bool isElectric;

public:
  Vehicle(int citympg, int combmpg, int hwaympg, string fuelType, int year,
          string make, string model, string driveTrain, string cylinders,
          string engLiters, string transmission, string style, string altFuel);
  
  Vehicle(const Vehicle& v);
  const Vehicle& operator=(const Vehicle& v);


  int getCitympg() const;
  int getCombmpg() const;
  int getHwaympg() const;
  const string &getFuelType() const;
  int getYear() const;
  const string &getMake() const;
  const string &getModel() const;
  const string &getDriveTrain() const;
  const string &getCylinders() const;
  const string &getEngLiters() const;
  const string &getTransmission() const;
  const string &getStyle() const;
  const string &getAltFuel() const;
  bool isEV();
  bool isGas();
};

Vehicle::Vehicle(int citympg, int combmpg, int hwaympg, string fuelType,
                 int year, string make, string model, string driveTrain,
                 string cylinders, string engLiters, string transmission,
                 string style, string altFuel) {
  this->citympg = citympg;
  this->combmpg = combmpg;
  this->hwaympg = hwaympg;
  this->fuelType = fuelType;
  this->year = year;
  this->make = make;
  this->model = model;
  this->driveTrain = driveTrain;
  this->cylinders = cylinders;
  this->engLiters = engLiters;
  this->transmission = transmission;
  this->style = style;
  this->altFuel = altFuel;

  if (fuelType == "Electricity")
    isElectric = true;
  else
    isElectric = false;
}

Vehicle::Vehicle(const Vehicle& v){
  this->citympg = v.citympg;
  this->combmpg = v.combmpg;
  this->hwaympg = v.hwaympg;
  this->fuelType = v.fuelType;
  this->year = v.year;
  this->make = v.make;
  this->model = v.model;
  this->driveTrain = v.driveTrain;
  this->cylinders = v.cylinders;
  this->engLiters = v.engLiters;
  this->transmission = v.transmission;
  this->style = v.style;
  this->altFuel = v.altFuel;
  this->isElectric = v.isElectric;
}

const Vehicle& Vehicle::operator=(const Vehicle& v){
  this->citympg = v.citympg;
  this->combmpg = v.combmpg;
  this->hwaympg = v.hwaympg;
  this->fuelType = v.fuelType;
  this->year = v.year;
  this->make = v.make;
  this->model = v.model;
  this->driveTrain = v.driveTrain;
  this->cylinders = v.cylinders;
  this->engLiters = v.engLiters;
  this->transmission = v.transmission;
  this->style = v.style;
  this->altFuel = v.altFuel;
  this->isElectric = v.isElectric;
  return *this;
}

int Vehicle::getCitympg() const { return citympg; }

int Vehicle::getCombmpg() const { return combmpg; }

int Vehicle::getHwaympg() const { return hwaympg; }

const string &Vehicle::getFuelType() const { return fuelType; }

int Vehicle::getYear() const { return year; }

const string &Vehicle::getMake() const { return make; }

const string &Vehicle::getModel() const { return model; }

const string &Vehicle::getDriveTrain() const { return driveTrain; }

const string &Vehicle::getCylinders() const { return cylinders; }

const string &Vehicle::getEngLiters() const { return engLiters; }

const string &Vehicle::getTransmission() const { return transmission; }

const string &Vehicle::getStyle() const { return style; }

const string &Vehicle::getAltFuel() const { return altFuel; }

bool Vehicle::isEV() { return isElectric; }

bool Vehicle::isGas() { return !isElectric; }