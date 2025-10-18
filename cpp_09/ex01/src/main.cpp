
#include "../inc/RPN.hpp"

int main (int ac, char** av){
    if (ac != 2){
        std::cerr << RED << "Error. Usage: ./RPN <\"inverted Polish mathematical expression\">" << RES << std::endl;
        return 1;
    }

    RPN expression(av[1]);
    
    try{
         expression.performOperation();
         std::cout << expression.getResult() << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}