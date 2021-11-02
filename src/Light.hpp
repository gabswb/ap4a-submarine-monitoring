/**
 * @author Gabriel_SCHWAB
 * @file Light.hpp
 * @date 27/09/2021
 * @Brief Description :simulate a Sensor which capture the light inside the submarine
 */

//
//Define guards
#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <iostream>
#include "Sensor.hpp"

class Light : public Sensor<bool>
{

public :

	Light();
	/**
	 * @brief constructor which initialize the value of the attribute m_frequency given by the user
	 * @param frequency_p is the input of the user
	 */
	Light(int frequency_p);
	Light(const Light& light_p);
	~Light();
	Light& operator=(const Light& light_p);

private :

	/**
	 * @brief generate a random value to simulate the capture of data, we base it on the local hour of the system
	 * @param pGenerator_p is a random engine
	 * @return the data generated
	 */
	bool aleaGenVal(std::default_random_engine* pGenerator_p);

	float m_proba;

};



#endif /* LIGHT_HPP_ */
