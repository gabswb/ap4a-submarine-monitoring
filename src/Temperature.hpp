/**
 * @author Gabriel_SCHWAB
 * @file Temperature.hpp
 * @date 27/09/2021
 * @Brief  Description :simulate a Sensor which capture the light inside the submarine
 */

//
//Define guards
#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP

#include <random>
#include "Sensor.hpp"

class Temperature : public Sensor<float>
{

public :

	Temperature();
	/**
	 * @brief constructor which initialize the value of the attribute m_frequency given by the user
	 * @param frequency_p is the input of the user
	 */
	Temperature(int frequency_p);
	Temperature(const Temperature& temperature_p);
	~Temperature();
	Temperature& operator=(const Temperature& temperature_p);

private :

	/**
	 * @brief generate a random value to simulate the capture of data, we use a normal distribution
	 * @param pGenerator_p is a random engine
	 * @return the data generated
	 */
	float aleaGenVal(std::default_random_engine* pGenerator_p);

	float m_mean, m_standartDerivation;///< parameters for the normal distribution

};



#endif /* TEMPERATURE_HPP */
