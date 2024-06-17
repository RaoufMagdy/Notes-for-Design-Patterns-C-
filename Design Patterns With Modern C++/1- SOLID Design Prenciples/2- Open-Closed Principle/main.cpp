/**
 * \author Raouf Magdy (raoufma98@gmail.com)
 * 
 * \date   10/4/2024
 * 
*/

/**
 * \brief "Open-Closed Principle (OCP)" states that software entities (such as classes, modules, functions) should be
 *        OPEN for EXTENSION but CLOSED for MODIFICATION. This means that you should be able to extend the behavior
 *        of a system without modifying its existing codebase.             
 */


#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>

/**
 * \brief In the following example I will violate the OCP and we will see how we will need to change the class implementation whenever we want
 *        to extend its features. (Read the following example before reading the conclusion).
 *        
 *        ===> Conclusion: After looking at the example Let's say that I want to add a feature that sets and gets the Vehicle's price then, 
 *        I will need to add an element to the class Vehicle and add setter and getter functions which is a modofication for the
 *        parent class "Vehicle".
*/

/*
Example:
==========

class Vehicle{
private:
    std::string Model;
    std::string Color;

public:
     Vehicle(std::string& model, std::string& color) : Model(model), Color(color) {}
     
     void Car(void)
     {
        std::cout<<"This is a Car of model "<<Model<<" and of color "<<Color<<std::endl;
     }

     void Bus(void)
     {
        std::cout<<"This is a Bus of model "<<Model<<" and of color "<<Color<<std::endl;
     }

     ~Vehicle() = default;

};

int main(void){
    
    std::string modelBMW = "BMW";
    std::string modelToyota = "Toyota";
    std::string Color1 = "Red";
    std::string Color2 = "Yellow";
    
    Vehicle X(modelBMW, Color1);
    Vehicle Y(modelToyota, Color2);
    
    X.Car(); 
    Y.Bus();

    getchar();
    return 0;
}


*/



/**
 * \brief Note that methods in "Vehicle" - the base class - should be pure virtual functions in order to be able to
 *        override them. However, it is not a must to use pure virtual functions but it is considered as an easy way
 *        to achieve the OCP, and this can be achieved through various design strategies and patterns depending on the
 *        specific requirements and constraints of the system.
*/

//Example:
//=========

// Base class representing a model of vehicle
class Vehicle {
protected:
    std::string Model; // model of vehicle (e.g., "Car", "Bus", "Truck")
    std::string Color;

public:
    Vehicle(const std::string& model, const std::string& color) : Model(model), Color(color) {}

    // ====> Virtual method to get vehicle description
    virtual std::string getDescription() const {
        return Color + " " + Model + " Vehicle";
    }

    // ====> Virtual method to get vehicle model
    virtual std::string getModel() const {
        return Model;
    }

    virtual ~Vehicle() = default;
};

// Class representing price information
class Price {
private:
    double amount; // Price amount in USD

public:
    Price(double amount) : amount(amount) {}

    double getAmount() const {
        return amount;
    }
};

// Derived class for Car vehicle model
class Car : public Vehicle {
private:
    Price price;

public:
    Car(const std::string& color, double priceAmount)
        : Vehicle("BMW", color), price(priceAmount) {}

    // Override getDescription() method for Car
    virtual std::string getDescription() const override {
       return Color + " BMW" +
        "\nCar Price: $" + std::to_string(price.getAmount()) + "\n";
    }

    // Override getModel() method for Car
    virtual std::string getModel() const override {
        return "BMW";
    }

    // Method to get car price
    double getPrice() const {
        return price.getAmount();
    }
};

// Derived class for Bus vehicle model
class Bus : public Vehicle {
private:
    Price price;

public:
    Bus(const std::string& color, double priceAmount)
        : Vehicle("Toyota", color), price(priceAmount) {}

    // Override getDescription() method for Bus
    virtual std::string getDescription() const override {
        return Color + " Toyota" +
        "\nBus Price: $" + std::to_string(price.getAmount()) + "\n";
    }

    // Override getModel() method for Bus
    virtual std::string getModel() const override {
        return "Toyota";
    }

    // Method to get bus price
    double getPrice() const {
        return price.getAmount();
    }
};

// Derived class for Truck vehicle model
class Truck : public Vehicle {
private:
    double payloadCapacity; // Payload capacity in tons
    Price price;

public:
    Truck(const std::string& color, double payloadCapacity, double priceAmount)
        : Vehicle("Volvo", color), payloadCapacity(payloadCapacity), price(priceAmount) {}

    // Override getDescription() method for Truck
    virtual std::string getDescription() const override {
        //return Color + " Truck (Payload: " + std::to_string(payloadCapacity) + " tons)";

        return Color + " Truck of Payload Capacity: " + std::to_string(payloadCapacity) + " Tons " + 
               "\nTruck Price: $" + std::to_string(price.getAmount()) + "\n";
    }

    // Override getModel() method for Truck
    virtual std::string getModel() const override {
        return "Volvo";
    }

    // Method to get truck price
    double getPrice() const {
        return price.getAmount();
    }
};

// Function to display vehicle details including price
void displayVehicleDetails(const Vehicle& vehicle) {
    std::cout << "Model: " << vehicle.getModel() << std::endl;
    std::cout << "Description: " << vehicle.getDescription() << std::endl;
}

// Main function to demonstrate usage
int main() {
    // Create instances of Car, Bus, and Truck with prices and payload capacity
    Car myCar("Blue", 25000.0);
    Bus myBus("Yellow", 80000.0);
    Truck myTruck("Red", 5.0, 100000.0); // Payload capacity of 5.0 tons

    // Display details of Car including price
    std::cout << "Details of Car:" << std::endl;
    displayVehicleDetails(myCar);
    std::cout << std::endl;

    // Display details of Bus including price
    std::cout << "Details of Bus:" << std::endl;
    displayVehicleDetails(myBus);
    std::cout << std::endl;

    // Display details of Truck including payload capacity
    std::cout << "Details of Truck:" << std::endl;
    displayVehicleDetails(myTruck);
    std::cout << std::endl;

    getchar();
    return 0;
}
