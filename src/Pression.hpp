/**
 * @author Gabriel_SCHWAB
 * @file Pression.hpp
 * @date 27/09/2021
 * @Brief Description :simulate a Sensor which capture the pressure inside the submarine
 */

//
//Define guards
#ifndef PRESSION_HPP
#define PRESSION_HPP

#include "Sensor.hpp"

class Pression : public Sensor<int>
{

public :

	Pression();
	/**
	 * @brief constructor which initialize the value of the attribute m_frequency given by the user
	 * @param frequency_p is the input of the user
	 */
	Pression(int frequency_p);
	Pression(const Pression& pression_p);
	~Pression();
	Pression& operator=(const Pression& pression_p);

private :

	/**
	 * @brief generate a random value to simulate the capture of data, we use uniform distribution
	 * @param pGenerator_p is a random engine
	 * @return the data generated
	 */
	int aleaGenVal(std::default_random_engine* pGenerator_p);

	int m_min, m_max;///< parameters for the uniform distribution

};


#endif /* PRESSION_HPP */
