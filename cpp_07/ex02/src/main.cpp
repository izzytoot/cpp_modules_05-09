#include <Array.hpp>

#define MAX_VAL 5

int main(){
	std::cout << std::endl << BCYA << "********* TEST 1 - EMPTY ARRAY *********" << RES << std::endl;

	Array<int> Array_1;
	std::cout << "Array_1 is " << Array_1.size() << " slots long." << std::endl;
	
	std::cout << std::endl << BCYA << "********* TEST 2 - ARRAY WITH SLOTS *********" << RES << std::endl;
	Array<int> Array_2(5);
	std::cout << "Array_2 is " << Array_2.size() << " slots long." << std::endl;
	for (unsigned int i = 0; i < Array_2.size(); i++){
		std::cout << "Array_2[" << i << "] = " << Array_2[i] << std::endl;
	}

	std::cout << std::endl << BCYA << "* value attribution *" << RES << std::endl;
	int n = 0;
	for (unsigned int i = 0; i < Array_2.size(); i++){
		Array_2[i] =  n++;
		std::cout << "Array_2[" << i << "] = " << Array_2[i] << std::endl;
	}

	std::cout << std::endl << BCYA << "********* TEST 3 - CALL ARRAY ELEMENT *********" << RES << std::endl;
	std::cout << BCYA << "* within bounds *" << RES << std::endl;
	try{
		int n = Array_2[4];
		std::cout << GRN << "Element is \"" << n << "\"." << RES << std::endl;
	}catch(std::out_of_range& e){
		std::cout << RES << "Error! " << e.what() << RES << std::endl;
	}

	std::cout << std::endl << BCYA << "* out of bounds *" << RES << std::endl;

	try{
		int n = Array_2[10];
		std::cout << GRN << "Element is \"" << n << "\"." << RES << std::endl;
	}catch(std::out_of_range& e){
		std::cout << RED << "Error! " << e.what() << RES << std::endl;
	}

	std::cout << std::endl << BCYA << "********* TEST 4 - COPY ASSIGNMENT OPERATOR *********" << RES << std::endl;
	std::cout << std::endl << BCYA << "* are the values the same? *" << RES << std::endl;

	Array<int> Array_3 = Array_2;
	for (unsigned int i = 0; i < Array_2.size(); i++){
		std::cout << "Array_2[" << i << "] = " << Array_2[i] << std::endl;
	}
	std::cout << std::endl;
	for (unsigned int i = 0; i < Array_3.size(); i++){
		std::cout << "Array_3[" << i << "] = " << Array_3[i] << std::endl;
	}

	std::cout << std::endl << BCYA << "* let's change Array_3[1] to \"10\" *" << RES << std::endl;
	Array_3[1] = 10;
	std::cout << "Array_3[1] = " << Array_3[1] << std::endl;
	std::cout << std::endl << BCYA << "* did Array_2[1] change too? *" << RES << std::endl;
	std::cout << "Array_2[1] = " << Array_2[1] << std::endl;

	std::cout << std::endl << BCYA << "********* TEST 5 - ARRAY OF STRINGS *********" << RES << std::endl;

	Array<std::string> stringArray_1(4);
	stringArray_1[0] = "My";
	stringArray_1[1] = "name";
	stringArray_1[2] = "is";
	stringArray_1[3] = "Isabel";

	std::cout << "stringArray_1 is composed by the following words: ";
	for (unsigned int i = 0; i < stringArray_1.size(); i++){
		std::cout << stringArray_1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl << BCYA << "* copying stringArray_1 into stringArray_2 *" << RES << std::endl;
	Array<std::string>stringArray_2(stringArray_1);
	std::cout << "stringArray_2 is composed by the following words: ";
	for (unsigned int i = 0; i < stringArray_1.size(); i++){
		std::cout << stringArray_2[i] << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl << BCYA << "* changing the name int stringArray_2 *" << RES << std::endl;
	stringArray_2[3] = "Filipe";
	std::cout << "stringArray_2 is composed by the following words: ";
	for (unsigned int i = 0; i < stringArray_1.size(); i++){
		std::cout << stringArray_2[i] << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl << BCYA << "* but keeping the original stringArray_1 *" << RES << std::endl;
	std::cout << "stringArray_1 is composed by the following words: ";
	for (unsigned int i = 0; i < stringArray_1.size(); i++){
		std::cout << stringArray_1[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
// 		std::cout << "numbers[i]: " << numbers[i] << std::endl;
//         mirror[i] = value;
// 		std::cout << "mirror[i]: " << mirror[i] << std::endl;
//     }
// 	std::cout << std::endl;
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
// 	try
//     {
//         numbers[3] = 0;
// 		std::cout << "numbers[3] is now " << numbers[3] << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
// 	std::cout << std::endl;
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
// 	std::cout << std::endl;
//     try
//     {
//         numbers[MAX_VAL - 1] = 0;
// 		std::cout << "numbers[MAX_VAL - 1] is now " << numbers[3] << std::endl;

// 	}
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
// 	std::cout << std::endl;
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
// 		std::cout << "numbers[i] is now " << numbers[i] << std::endl;
//     }
// 	std::cout << std::endl;
//     delete [] mirror;//
//     return 0;
// }