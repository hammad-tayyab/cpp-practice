#include <iostream>
#include <string>
using namespace std;
//User defined data types
enum VehicleType {
	CAR,
	TRUCK,
	MOTORCYCLE
};
struct CarDetails {
	int numDoors;
	bool hasAirConditioning;
};
struct TruckDetails {
	float loadCapacity;
	int numAxles;
};
struct MotorcycleDetails {
	int engineCC;
	bool hasSidecar;
};
union VehicleInfo {
	CarDetails car;
	TruckDetails truck;
	MotorcycleDetails moto;
};
struct Vehicle {
	string model;
	int year;
	float price;
	VehicleType type;
	VehicleInfo info;
};
//func definations
void inputVehicle(Vehicle* v);
float calculateTax(Vehicle v);
void displayVehicle(Vehicle v);
void compareVehicles(Vehicle v1, Vehicle v2);
//main function,
int main() {
	Vehicle fleet[2];
	for (int i = 0; i < 2; i++) {
		inputVehicle(&fleet[i]);
	}
	for (int i = 0; i < 2; i++)
		displayVehicle(fleet[i]);
	compareVehicles(fleet[0], fleet[1]);
	return 0;
}
//function declaration
void inputVehicle(Vehicle* v) {
	cout << "\nEnter Model: ";
	cin>>v->model;
	cout << "Enter Year: ";
	cin >> v->year;
	cout << "Enter Price: ";
	cin >> v->price;

	int choice;
	cout << "Select Type (0: Car, 1: Truck, 2: Motorcycle): ";
	cin >> choice;
	v->type = static_cast<VehicleType>(choice);//as v is a diff variable so owe use static cast to give tht permission

	if(v->type == CAR) {

		cout << "Num Doors: ";
		cin >> v->info.car.numDoors;
		cout << "AC (1 for Yes, 0 for No): ";
		cin >> v->info.car.hasAirConditioning;

	} else if(v->type == TRUCK) {
		cout << "Load Capacity(): ";
		cin >> v->info.truck.loadCapacity;
		cout << "Num Axles: ";
		cin >> v->info.truck.numAxles;
	} else if(v->type == MOTORCYCLE) {
		cout << "Engine CC: ";
		cin >> v->info.moto.engineCC;
		cout << "Sidecar (1 for Yes, 0 for No): ";
		cin >> v->info.moto.hasSidecar;
	}
}

float calculateTax(Vehicle v) {
	float taxRate = 0;

	if (v.type == CAR) {
		taxRate = 0.08;
		if (!v.info.car.hasAirConditioning) {
			taxRate += 0.02;
		}
	} else if (v.type == TRUCK) {
		taxRate = 0.12;
		if (v.info.truck.numAxles > 2) {
			taxRate += (v.info.truck.numAxles - 2) * 0.01;
		}
	} else {
		taxRate = 0.05;
		if (v.info.moto.engineCC > 1000) {
			taxRate += 0.03;
		}
	}

	return v.price * taxRate;
}

void displayVehicle(Vehicle v) {
	float tax = calculateTax(v);
	cout << "Model: " << v.model << " | Total Price (inc. tax): " << v.price + tax << endl;
}

void compareVehicles(Vehicle v1, Vehicle v2) {
	float total1 = v1.price + calculateTax(v1);
	float total2 = v2.price + calculateTax(v2);
	if (total1 > total2) cout << "\n" << v1.model << " is more expensive.";
	else if (total2 > total1) cout << "\n" << v2.model << " is more expensive.";
	else cout << "\nBoth cost the same.";
}