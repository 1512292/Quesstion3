#pragma once
#include <iostream>
#include <fstream>

using namespace std;

#define loopTime 10
#define carWheels 4
#define carDoors 4
#define carSeats 5
#define ToyotaMaxSpeed 100
#define BMWMaxSpeed 200

class IVehicle
{
public:
	virtual void run() = 0;
	virtual void info() = 0;
protected:
	int wheels;
	int doors;
	int seats;
	int maxSpeed;
};

class Vehicle : public IVehicle
{
public:
	Vehicle(int wheels, int doors, int seats, int maxSpead) {
		this->wheels = wheels;
		this->doors = doors;
		this->seats = seats;
		this->maxSpeed = maxSpead;
	}
protected:
	virtual void run() override {
		ofstream fout("output.txt");
		for (int i = 0; i < loopTime; i++) {
			cout << maxSpeed << endl;
		}
	};

	virtual void info() override {
		cout << "Wheels: " << wheels << endl;
		cout << "Doors: " << doors << endl;
		cout << "Seats: " << seats << endl;
		cout << "MaxSpeed: " << maxSpeed << endl;
	};
};

class Car : public Vehicle
{
public: 
	Car(int maxSpeed) : Vehicle(carWheels,carDoors,carSeats,maxSpeed){};
};

class ToyotaCar : public Car
{
public:
	ToyotaCar() : Car(ToyotaMaxSpeed) {};
};

class BMWCar : public Car
{
public:
	BMWCar() : Car(BMWMaxSpeed) {};
};


