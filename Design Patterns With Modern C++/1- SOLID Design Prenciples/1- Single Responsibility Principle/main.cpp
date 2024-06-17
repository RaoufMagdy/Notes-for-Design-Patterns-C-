/**
 * \author Raouf Magdy (raoufma98@gmail.com)
 * 
 * \date   10/4/2024
 * 
*/

/**
 * \brief The concept behind "Single Responsibility Principle (SRP)" is that if we have a class that does
 *        more than one job at a time, we should divide it into more than one class each of them is
 *        responsible for a single job only. 
 */


#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>

/**
 * \brief In the following example if we have a class called Library, we can implement it to be able
 *        to do many jobs, like contatining data, adding and removing books, managing library sections
 *        and so on.
 *        This is a really confusing implementation and makes the class complex to read and to deal with,
 *        even each time we want to add a feature it will require us to edit the class itself which is a 
 *        loss for time and effort.
*/

/*

Example:
==========

class Library
{
public:
    
    Library(const std::string& section) : Section(section) {}

    void add_book(Library& Lib, std::string& entry)
    {
        static int count = 0;
        Lib.entries.push_back(entry);
        count++;
    }

    void remove_last_book(Library& Lib)
    {
        if(&Lib)
        {
            Lib.entries.pop_back();
        }
    }

    void save(const Library& Lib, const std::string& fileName)
    {
        std::ofstream ofs(fileName);
        ofs<< Lib.Section << std::endl;
        for(auto& l : Lib.entries){
            ofs<< l << std::endl;
        }
    }

private:
    std::string Section;
    std::vector<std::string> entries;
};

*/



/**
 * \brief Note that "Library" class is doing it's job only which is being a data container.
*/
class Library
{
public:
    std::string Section;
    std::vector<std::string> entries;

    Library(const std::string& section) : Section(section) {}

};


/**
 * \brief Note that "LibraryManager" & "LibraryDataFileManager" classes are doing thier jobs only which is managing the Library class 
 *        and the output files. So, LibraryManager can manage a Lirary class, add books, remove books and LibraryDataFileManager 
 *        can save the data in a file. PLUS you can add more options to that manager easily or make another class that adds a whole
 *        new feature like deleting the whole libraries for example xD.
*/
class LibraryManager
{
public:

    LibraryManager(const std::string Manager_Name, const uint16_t Manager_ID){
         ManagerName = Manager_Name;
         ManagerID = Manager_ID;
    }

    void add_book(Library& Lib, const std::string BookName)
    {
        static int count = 0;
        Lib.entries.push_back(BookName);
        count++;
    }

    void remove_last_book(Library& Lib)
    {
        if(&Lib)
        {
            Lib.entries.pop_back();
        }
    }


private:
    std::string ManagerName;
    uint16_t ManagerID;
};

/**
 * \brief   Files managing class that is responsible for saving and updating the latest books in the Libraries
*/
class LibraryDataFileManager
{
public:
    LibraryDataFileManager(const uint16_t fileID) : FileID(fileID) {}

    void SaveFileData(const Library& Lib, const std::string LibraryName)
    {
        std::ofstream ofs(LibraryName);
        ofs<< Lib.Section << std::endl;
        for(auto& l : Lib.entries){
            ofs<< l << std::endl;
        }
    }
private:
    uint16_t FileID;
};


int main(){

//Example:
//=========

    //Creating 3 libraries for different science branches:
    Library BiologyLibrary{"Biology"};
    Library MechanicsLibrary{"Mechanics"};
    Library EgyptologyLibrary{"Egyptology"};


    //We can have more than one manager with different names and IDs.
    LibraryManager TheLibraryManager("Books & Sections Manager", 6969);

    LibraryDataFileManager FileManager((uint16_t)69);


    TheLibraryManager.add_book(BiologyLibrary, "Book 1 in Biology");
    TheLibraryManager.add_book(BiologyLibrary, "Book 2 in Biology");
    TheLibraryManager.add_book(BiologyLibrary, "Book 3 in Biology");

    TheLibraryManager.add_book(MechanicsLibrary, "Book 1 in Mechanics");
    TheLibraryManager.add_book(MechanicsLibrary, "Book 2 in Mechanics");
    TheLibraryManager.add_book(MechanicsLibrary, "Book 3 in Mechanics");

    TheLibraryManager.add_book(EgyptologyLibrary, "Book 1 in Egyptology");
    TheLibraryManager.add_book(EgyptologyLibrary, "Book 2 in Egyptology");
    TheLibraryManager.add_book(EgyptologyLibrary, "Book 3 in Egyptology");


    std::cout<<"There are "<<BiologyLibrary.entries.size()<<" books in Biology Library"<<std::endl;
    std::cout<<"There are "<<MechanicsLibrary.entries.size()<<" books in Mechanics Library"<<std::endl;
    std::cout<<"There are "<<EgyptologyLibrary.entries.size()<<" books in Egyptology Library"<<std::endl;

    //Saving data in the files:
    FileManager.SaveFileData(BiologyLibrary, "Biology Section.txt");
    FileManager.SaveFileData(MechanicsLibrary, "Mechanics Section.txt");
    FileManager.SaveFileData(EgyptologyLibrary, "Egyptology Section.txt");

    getchar();

    //Removing last books from specefic libraries.
    TheLibraryManager.remove_last_book(BiologyLibrary);
    TheLibraryManager.remove_last_book(EgyptologyLibrary);

    std::cout<<"There are "<<BiologyLibrary.entries.size()<<" books in Biology Library"<<std::endl;
    std::cout<<"There are "<<MechanicsLibrary.entries.size()<<" books in Mechanics Library"<<std::endl;
    std::cout<<"There are "<<EgyptologyLibrary.entries.size()<<" books in Egyptology Library"<<std::endl;

    //Saving the files with the updated data.
    FileManager.SaveFileData(BiologyLibrary, "Biology Section.txt");
    FileManager.SaveFileData(MechanicsLibrary, "Mechanics Section.txt");
    FileManager.SaveFileData(EgyptologyLibrary, "Egyptology Section.txt");

    getchar();

    return 0;
}
