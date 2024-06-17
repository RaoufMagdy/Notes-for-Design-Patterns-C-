/**
 * \author Raouf Magdy (raoufma98@gmail.com)
 * 
 * \date   13/4/2024
 * 
*/


#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>


/**
 * \brief  The Builder pattern is a powerful design pattern for constructing complex objects with multiple configuration options.
 *         It promotes separation of concerns, code reusability, and flexibility in object creation.
 *         The pattern allows for the creation of different representations of the same complex object using a unified construction process.
 * 
 *         Note: I will directly give an example about the "Fluent Builder" as from my point of view it is the easiest, the most effecient
 *               way, the easiest to read type of builders.
 * 
 *         The Complex class mainly consists of private elements which are the elements that will be built by the Builder class, and a Setter method for each
 *         of these elements.
 * 
 *         The Complex class may contain a descriptor to display the elements configurations if needed.
 *    
*/



// Product: Car class representing the complex object to be built
class Car {
public:

    // Elements Setters:
    void setMake(const std::string& make) { make_ = make; }
    void setModel(const std::string& model) { model_ = model; }
    void setYear(int year) { year_ = year; }
    void setColor(const std::string& color) { color_ = color; }

    void describe() const {
        std::cout << "Car Details:" << std::endl;
        std::cout << "Make: " << make_ << std::endl;
        std::cout << "Model: " << model_ << std::endl;
        std::cout << "Year: " << year_ << std::endl;
        std::cout << "Color: " << color_ << std::endl;
    }

private:
    // These are the elements that will be configuered (built) by the builder class.
    std::string make_;
    std::string model_;
    int year_ = 0;
    std::string color_;
};

// Fluent Builder: Provides a fluent interface for configuring a Car object
class CarBuilder {
public:
    CarBuilder& setMake(const std::string& make) {
        car_.setMake(make);
        return *this; // Return a reference to the current builder
    }

    CarBuilder& setModel(const std::string& model) {
        car_.setModel(model);
        return *this;
    }

    CarBuilder& setYear(int year) {
        car_.setYear(year);
        return *this;
    }

    CarBuilder& setColor(const std::string& color) {
        car_.setColor(color);
        return *this;
    }

    Car build() {
        return car_; // Return the constructed Car object
    }

private:
    Car car_; // The Car object being constructed
};



/**
 *  \brief   The Fluent Builder class will use the complex class methods. The Fluent Builder class that enables method chaining for configuring a Car object. 
 *           Each setter method returns a reference to the current builder (*this), allowing subsequent method calls to be ">>chained<<" together.
 *           
 *           Note: Please jumb to line 120 if you do not know what "chaining" means.
*/

void main_chain();

int main() {
    // Create a Car using the Fluent Builder
    Car car1 = CarBuilder()
                    .setMake("Toyota")
                    .setModel("Camry")
                    .setYear(2023)
                    .setColor("Blue")
                    .build();

    Car car2 = CarBuilder()
                    .setMake("BMW")
                    .setModel("X6")
                    .setYear(2024)
                    .setColor("Black")
                    .build();

    // Describe the constructed car
    car1.describe();
    car2.describe();

    main_chain();

    getchar();

    return 0;
}


/**
 *  \brief   Note: if you found chaining is confusing for you, here is a simple example that explains chaining concept in C++:
 * 
 *           In C++, chaining refers to the practice of invoking multiple member function calls on the same 
 *           object in a single statement, where each function call returns a reference to the object itself. 
 * 
 *           This technique is often used to achieve a fluent and concise syntax, making the code more readable 
 * 
*/

class Person {
public:
    Person& setName(const std::string& name) {
        Name = name;
        return *this;  // Return a reference to the current object
    }

    Person& setAge(int age) {
        Age = age;
        return *this;  // Return a reference to the current object
    }

    Person& setAddress(const std::string& address) {
        Address = address;
        return *this;  // Return a reference to the current object
    }

    void discribe() const {
        std::cout << "Name: " << Name << std::endl;
        std::cout << "Age: " << Age << std::endl;
        std::cout << "Address: " << Address << std::endl;
    }

private:
    std::string Name;
    int Age;
    std::string Address;
};

void main_chain() {
    // Create a Person object and use chaining to set attributes
    Person person;
    person.setName("Ahmad")
          .setAge(25)
          .setAddress("123 Main St, Anytown");

    // Display the person's information
    person.discribe();
}

