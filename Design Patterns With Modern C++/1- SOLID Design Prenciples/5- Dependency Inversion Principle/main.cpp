/**
 * \author Raouf Magdy (raoufma98@gmail.com)
 * 
 * \date   ../../2024
 * 
*/

/**
 * \brief "Dependency Inversion Principle (DIP)" states that high-level modules should not depend on low-level modules 
 *         but instead both should depend on abstractions. Additionally, abstractions should not depend on details; 
 *         instead, details should depend on abstractions.
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
 *         Conclusion: This direct dependency between "BusinessLogic" and "Database" makes it difficult to change the Database 
 *                     implementation or use a different storage mechanism without modifying the BusinessLogic class. 
*/

/*

Example:
==========

// Low-level module: Database (Concrete implementation)
class Database {
public:
    void saveData(const std::string& data) {
        std::cout << "Saving data to database: " << data << std::endl;
    }
};

// High-level module: BusinessLogic (Depends directly on Database)
class BusinessLogic {
private:
    Database database;

public:
    void processData(const std::string& data) {
        // Perform business logic
        std::cout << "Processing data: " << data << std::endl;

        // Save processed data to database (direct dependency on Database)
        database.saveData(data);
    }
};

int main() {
    BusinessLogic businessLogic;
    businessLogic.processData("Hello, World!");

    return 0;
}



*/

/**
 * \brief As we need we can make an abstraction layer (abstraction class in this case) so we can use it to solve that problem.
 *        In my humble point of view "Dependency Inversion Principle" is almost the same as "Single Responsibility Principle"
 *        so, DIP can be applied also along side with SRP that each abstracted module is also doing only one thing as SRP states
 *        and both concepts will enforce each other and make your code easier to debug and even cleaner! ;)
*/


//Example:
//=========

// Abstract interface for database operations
class DatabaseInterface {
public:
    virtual void saveData(const std::string& data) = 0;
    virtual ~DatabaseInterface() = default;
};

// Low-level module: Concrete Database implementation
class Database : public DatabaseInterface {
public:
    void saveData(const std::string& data) override {
        std::cout << "Saving data to database: " << data << std::endl;
    }
};

// High-level module: BusinessLogic (Depends on DatabaseInterface via Dependency Injection)
class BusinessLogic {
private:
    DatabaseInterface* database; //Using a shared pointer will be much better, but I used a raw pointer for simpleness.
                                 // std::shared_ptr<DatabaseInterface> database;

public:
    // Constructor injection of DatabaseInterface
    BusinessLogic(DatabaseInterface* db) : database(db) {}

    void processData(const std::string& data) {
        // Perform business logic
        std::cout << "Processing data: " << data << std::endl;

        // Save processed data using DatabaseInterface (abstraction)
        database->saveData(data);
    }
};

int main() {
    // Create Database instance (Concrete implementation)
    Database concreteDatabase;

    // Create BusinessLogic instance and inject DatabaseInterface
    BusinessLogic businessLogic(&concreteDatabase);

    // Use BusinessLogic to process and save data
    businessLogic.processData("Hello, World!");

    getchar();
    return 0;
}



