/**
 * \author Raouf Magdy (raoufma98@gmail.com)
 * 
 * \date   12/4/2024
 * 
*/

/**
 * \brief "Interface Segregation Principle (ISP)" states that a client(e.g., The child class) should not be forced to depend on interfaces that it does not use. 
 *         In simpler terms, classes should not be compelled to implement interfaces they don't need. 
 *         Instead, interfaces should be specific to the requirements of the clients that use them.
 *         In other words, we don't want to foce the client to use unnecessary interfaces.
 */


#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>

/**
 * \brief The following example will demonstrate a violation for ISP concept, so make sure to read the example well before reading
 *        the conclusion.
 * 
 *         Conclusion: Note that client "Printer" and client "Scanner" are forced to use inapplicable interfaces as they 
 *                     inherited from a base class "Device" that contains a group of interfaces that they didn't need them all.
 *        
*/

/*

Example:
==========

// Interface for a generic device
class Device {
public:
    virtual void print() = 0;       // Print functionality
    virtual void scan() = 0;        // Scan functionality
    virtual void fax() = 0;         // Fax functionality
};

====> Violation
// Printer class implementing the Device interface
class Printer : public Device {
public:
    void print() override {
        std::cout << "Printing..." << std::endl;
    }

    void scan() override {
        // Not applicable for a printer, empty implementation
    }

    void fax() override {
        // Not applicable for a printer, empty implementation
    }
};

====> Violation
// Scanner class implementing the Device interface
class Scanner : public Device {
public:
    void print() override {
        // Not applicable for a scanner, empty implementation
    }

    void scan() override {
        std::cout << "Scanning..." << std::endl;
    }

    void fax() override {
        // Not applicable for a scanner, empty implementation
    }
};

int main() {
    Printer printer;
    Scanner scanner;

    printer.print();  // Output: Printing...
    scanner.scan();   // Output: Scanning...

    return 0;
}



*/


/**
 * \brief As I clarified earlier that we don't want to force the client to use useless interfaces, so, we can
 *        break a class that has a group of interfaces (methods) into more than one class each contains a method at least
 *        depending on the business needs. So, if a client want to use a specific group of the available interfaces it can
 *        inheret from one or more classes and keep the rest then it won't be forced to use any unnecessary interface.        
 *        
*/


//Example:
//=========

// Interface for printable devices (e.g., printers)
class Printable {
public:
    virtual void print() = 0;  // Print functionality
};

// Interface for scannable devices (e.g., scanners)
class Scannable {
public:
    virtual void scan() = 0;   // Scan functionality
};

// Interface for faxing devices (e.g., faxes)
class Faxable {
public:
    virtual void fax() = 0;   // Faxing functionality
};

// ====> Note that each client only uses the interface it needs by inheriting it.

// Printer class implementing the Printable interface
class Printer : public Printable {
public:
    void print() override {
        std::cout << "Printing..." << std::endl;
    }
};

// Scanner class implementing the Scannable interface
class Scanner : public Scannable {
public:
    void scan() override {
        std::cout << "Scanning..." << std::endl;
    }
};

// Fax class implementing the Scannable interface
class Fax : public Faxable {
public:
    void fax() override {
        std::cout << "Faxing..." << std::endl;
    }
};

// Fax class implementing the Scannable interface
class PrinterScanner : public Printable , public Faxable {
public:
    void fax() override {
        std::cout << "Faxing and Printing..." << std::endl;
    }

    void print() override {
        std::cout << "Printing and Faxing..." << std::endl;
    }
};



int main() {
    Printer printer;
    Scanner scanner;
    PrinterScanner DualMachine;

    printer.print();   // Output: Printing...
    scanner.scan();    // Output: Scanning...
    DualMachine.fax(); // Output: Faxing and Printing...

    getchar();
    return 0;
}


