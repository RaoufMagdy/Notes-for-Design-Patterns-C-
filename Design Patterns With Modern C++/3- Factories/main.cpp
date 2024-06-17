/**
 * \author Raouf Magdy (raoufma98@gmail.com)
 * 
 * \date   19/4/2024
 * 
*/

/**
 * \brief  The Factory Design Pattern is used when you want to encapsulate object creation and provide a centralized 
 *         way to instantiate objects without exposing the creation logic directly in client code.
 * 
 *         In other words Factory Design Pattern is used when we want to use a General-Usage Base class to make different functionalities.
 *         Each functionality will be represented as a Derived class from that Base class.
 *         The Factory Design Pattern aligns well with the Open-Closed Principle (OCP) from the SOLID principles as we can derive classes 
 *         from Base class to do different functionality for each derivative.
 *         
 *         The Factory Design Pattern is used to encapsulate object creation and provide a centralized mechanism for instantiating
 *         objects without exposing the creation logic directly in client code.
 */


#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <memory>
#include <fstream>


// Base class
class Car {
public:
    virtual void drive() = 0;
    virtual ~Car() {}
};

// Derived classes
class RaceCar : public Car {
public:
    void drive() override {
        std::cout << "Driving a race car!" << std::endl;
    }
};

class OffRoadCar : public Car {
public:
    void drive() override {
        std::cout << "Driving an off-road car!" << std::endl;
    }
};

class TownCar : public Car {
public:
    void drive() override {
        std::cout << "Driving a town car!" << std::endl;
    }
};

// Factory class
class CarFactory {
public:
    static std::unique_ptr<Car> createCar(const std::string& carType) {
        if (carType == "RaceCar") {
            return std::make_unique<RaceCar>();
        } else if (carType == "OffRoadCar") {
            return std::make_unique<OffRoadCar>();
        } else if (carType == "TownCar") {
            return std::make_unique<TownCar>();
        } else {
            return nullptr;  // Invalid car type
        } 
    }
};

int main() {
    std::unique_ptr<Car> myRaceCar = CarFactory::createCar("RaceCar");
    std::unique_ptr<Car> myOffRoadCar = CarFactory::createCar("OffRoadCar");
    std::unique_ptr<Car> myTownCar = CarFactory::createCar("TownCar");

    myRaceCar->drive();      // Output: Driving a race car!
    myOffRoadCar->drive();   // Output: Driving an off-road car!
    myTownCar->drive();      // Output: Driving a town car!

    Car* rawPtr1 = myRaceCar.release();
    Car* rawPtr2 = myOffRoadCar.release();
    Car* rawPtr3 = myTownCar.release();

    delete rawPtr1;
    delete rawPtr2;
    delete rawPtr3;

    getchar();
    return 0;
}


/**
 * \brief   Note that simple raw pointers can be used but uniqe_ptr<> is used just for memory safety.
 * 
*/




