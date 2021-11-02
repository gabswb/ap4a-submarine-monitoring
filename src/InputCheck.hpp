/**
 * @author gabriel_scwhab
 * @file InputCheck.cpp
 * @date 20/10/2021
 * @brief contain different functions to check the user's inputs in the console
 */

//
// Define guards
#ifndef INPUTCHECK_HPP
#define INPUTCHECK_HPP

#include <iostream>
#include <string>
#include <limits>

/**
 * @brief check the input of a int
 * @param input_p input of the user
 * @param instruction_p string to display
 * @param min_p is the minimum value of the input
 * @param max_p id the maximum value of the input
 * @return
 */
int inputCheck(int input_p, std::string instruction_p,int min_p, int max_p);

/**
 * @brief check the input of a char
 * @param input_p is the input of the user
 * @param instruction_p string to display in the console
 * @param c1_p the only char accepted for the input
 * @return
 */
char inputCheck(char input_p, std::string instruction_p, char c1_p);

/**
 * @brief check the input of a char
 * @param input_p is the input of the user
 * @param instruction_p is a string to display in the console
 * @param c1_p
 * @param c2_p
 * @param c3_p these are the only char accepted for the input
 * @param c4_p
 * @param c5_p
 * @param c6_p
 * @return
 */
char inputCheck(char input_p, std::string instruction_p, char c1_p, char c2_p, char c3_p, char c4_p, char c5_p, char c6_p);

#endif /* INPUTCHECK_HPP_ */
