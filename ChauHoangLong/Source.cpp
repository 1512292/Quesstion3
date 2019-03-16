#include <iostream>
#include <thread>
#include <mutex>
#include "IVehicle.h"

mutex mtx;
void run(IVehicle* vhc){
	mtx.lock();
	vhc->run();
	mtx.unlock();
}

void main() {

	IVehicle* bmw = new BMWCar();
	IVehicle* toyota = new ToyotaCar();

	std::thread toyotaThread(run, toyota);
	std::thread bmwThread(run, bmw);

	toyotaThread.join();
	bmwThread.join();

	delete bmw;
	delete toyota;
	system("pause");

}