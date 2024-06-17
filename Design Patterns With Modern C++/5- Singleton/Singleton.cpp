/**
 * \author Raouf Magdy (raoufma98@gmail.com)
 * 
 * \date   20/4/2024
 * 
*/

/**
 * \brief   SingleTon-like Implementation:           
 */


#include <iostream>
#define ERROR_404 404


class SingleTon {
public:
    SingleTon() : elem1(0), elem2(0) {
        Instances++;
        try {
                if (Instances > 1) {
                    std::cerr << "Error: Only one instance of SingleTon is allowed." << std::endl;
                    throw ERROR_404;
                } else {
                    std::cout << "Instance created. Instances: " << Instances << std::endl;
                }
        } catch(const int) {
                this-> ~SingleTon();
                exit(69);
        } 
    }

    ~SingleTon() {
        std::cout << "Instance destroyed." << std::endl;
        Instances--;
    }

    void Set_1(int val) {
        this->elem1 = val;
    }

    void Set_2(int val) {
        this->elem2 = val;
    }

    void Get_1() const {
        std::cout << "elem1 = " << this->elem1 << std::endl;
    }

    void Get_2() const {
        std::cout << "elem2 = " << this->elem2 << std::endl;
    }

    void Get_ctr() const {
        std::cout << "Instances = " << Instances << std::endl;
    }

private:
    int elem1;
    int elem2;
    static int Instances;
};

int SingleTon::Instances = 0;

int main() {
    SingleTon first;
    first.Get_1();
    first.Get_2();
    
    std::cout<<"Before Exception"<<std::endl;
    getchar();
    
    SingleTon second;  // This should fail due to the SingleTonton constraint ===> Code exits here with error code 69 as given
    second.Get_1();
    second.Get_2();

    std::cout<<"After Exception"<<std::endl;

    getchar();
    return 0;
}
