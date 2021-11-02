/**
 * @author gabriel_scwhab
 * @file InputCheck.hpp
 * @date 20/10/2021
 * @brief contain different functions to check the user's inputs in the console
 */

#include "InputCheck.hpp"

int inputCheck(int input_p, std::string instruction_p,int min_p, int max_p)
{
    while (true)
    {
        std::cout << instruction_p<<std::endl;
        if (std::cin >> input_p && input_p>=min_p && input_p<=max_p)
        {
            break;
        }
        else
        {
        	std::cin.clear(); ///< if the input is not correct we clear the buffer of error msg or '\n'
        	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return input_p;
}


char inputCheck(char input_p, std::string errorMsg_p, char c1_p)
{
    while (true)
    {
        if (std::cin >> input_p && input_p== c1_p)
        {
            break;
        }
        else
        {
        	std::cout << errorMsg_p<<std::endl;
        	std::cin.clear();
        	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return input_p;
}



char inputCheck(char input_p, std::string instruction_p, char c1_p, char c2_p, char c3_p, char c4_p, char c5_p, char c6_p)
{
    while (true)
    {
    	std::cout << instruction_p<<std::endl;
        if (std::cin >> input_p && (input_p== c1_p || input_p== c2_p || input_p== c3_p || input_p== c4_p || input_p== c5_p || input_p== c6_p))
        {
            break;
        }
        else
        {
        	std::cin.clear();
        	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return input_p;
}



