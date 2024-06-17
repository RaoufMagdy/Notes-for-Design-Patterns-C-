/**
 * \author Raouf Magdy (raoufma98@gmail.com)
 * 
 * \date   12/4/2024
 * 
*/

/**
 * \brief "Liskov Substitution Principle (LSP)" states that objects of a superclass should be replaceable with objects of its subclasses 
 *         >> without << affecting the correctness of the program.
 *        
 *        
 */


#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>

/**
 * \brief In the following example I am goint to violate the LSP concept and demonstrate how it affects the "correctness" of the program.
 *        So, please read the Example well and then read the conclusion.
 * 
 *        Conclusion: The Square class inherits from Rectangle but violates LSP by overriding the setWidth() and setLength() methods. 
 *                    In the context of a square, setting the width should automatically update the length (and vice versa) 
 *                    to maintain the square's properties. However, this contradicts the expected behavior defined by the Rectangle class.    
 *        
*/

/*

Example:
==========

// Base class representing a geometric shape
class Rectangle {
protected:
    double width;
    double length;

public:
    Rectangle(double w, double l) : width(w), length(l) {}

    virtual double getWidth() const {
        return width;
    }

    virtual double getLength() const {
        return length;
    }

    // Method to set the width of the rectangle
    void setWidth(double w) {
        width = w;
    }

    // Method to set the length of the rectangle
    void setLength(double l) {
        length = l;
    }

    // Method to calculate the area of the rectangle
    double area() const {
        return width * length;
    }
};

// Derived class for Square, violating LSP
class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}

    // Override getWidth() to maintain square properties (violates LSP)
    virtual double getWidth() const override {
        return width;
    }

    // Override getLength() to maintain square properties (violates LSP)
    virtual double getLength() const override {
        return length;
    }

=====> Violation:::
    // Override setWidth() to maintain square properties (violates LSP)
    void setWidth(double w) override {
        width = w;  <====- Both width and length should be set to "side", so that no undefined behavior can happen.
        length = w; // Maintain square properties by setting both width and length to the same value
    }

    // Override setLength() to maintain square properties (violates LSP)
    void setLength(double l) override {
        length = l;  <====- Both width and length should be set to "side", so that no undefined behavior can happen.
        width = l; // Maintain square properties by setting both width and length to the same value
    }
};

// Function to print area of a shape
void printArea(const Rectangle& shape) {
    std::cout << "Area: " << shape.area() << std::endl;
}

int main() {
    Rectangle rectangle(5.0, 3.0);
    Square square(4.0);

    // Print area of rectangle
    std::cout << "Area of rectangle: ";
    printArea(rectangle); // Output: Area: 15

    // Print area of square (violates LSP)
    std::cout << "Area of square: ";
    printArea(square); // Output: Area: 16 (should be 16 for a square, but violates LSP)

    // Attempt to modify the square's width (intended as a square)
    square.setWidth(6.0);
    
    // Print area of modified square (unexpected behavior due to LSP violation)
    std::cout << "Area of modified square: ";
    printArea(square); // Output: Area: 36 (should be 36 for a square, but violates LSP)

    /**
     *   \brief Note that the output is CORRECT, however, the structure of the code still violates the LSP concept.
     *          That means the output is not our only factor to decide the violation of our design pattern.
     *          To make that clear, if the length or width was a fixed value, then the setters of the square will output
     *          an unexpected value as it will be a (variable * fixed value) it will only be correct if that variable == the fixed value.
     * /

    return 0;
}

*/



/**
 * \brief To adhere to the Liskov Substitution Principle:
 * 
 *        - Avoid introducing behaviors or constraints in derived classes that are not applicable 
 *          to the base class without proper abstraction.
 *        - Ensure that objects of derived classes can seamlessly substitute objects of their base class
 *          in all contexts without altering the expected behavior or properties of the program.
*/


//Example:
//=========

// Base class representing a geometric shape
class Shape {
public:
    virtual double area() const = 0; // Pure virtual function for calculating area
};

// Derived class for Rectangle (a specific type of shape)
class Rectangle : public Shape {
protected:
    double width;
    double length;

public:
    Rectangle(double w, double l) : width(w), length(l) {}

    // Override area() method to calculate area of rectangle
    virtual double area() const override {
        return width * length;
    }

    double getWidth() const {
        return width;
    }

    double getLength() const {
        return length;
    }
};

// Derived class for Square (a specific type of rectangle)
class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}

    // Override setWidth() and setLength() to maintain square properties
    void setWidth(double side) {
        width = side;
        length = side;
    }

    void setLength(double side) {
        width = side;
        length = side;
    }
};

// Function to print area of a shape
void printArea(const Shape& shape) {
    std::cout << "Area: " << shape.area() << std::endl;
}

int main() {
    Rectangle rectangle(5.0, 3.0);
    Square square(4.0);

    printArea(rectangle); 
    printArea(square);   

    getchar();
    return 0;
}

