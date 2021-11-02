/**
 * @author Gabriel_SCHWAB
 * @file Humidity.hpp
 * @date 27/09/2021
 * @Brief Description :simulate a Sensor which capture the humidity inside the submarine
 */

//
//Define guards
#ifndef HUMIDITY_HPP
#define HUMIDITY_HPP

#include "Sensor.hpp"

class Humidity : public Sensor<float>
{

public :

	Humidity();
	/**
	 * @brief constructor which initialize the value of the attribute m_frequency given by the user
	 * @param frequency_p is the input of the user
	 */
	Humidity(int frequency_p);
	Humidity(const Humidity& humidityv_p);
	~Humidity();
	Humidity& operator =(const Humidity& humidity_p);

private :

	/**
	 * @brief generate a random value to simulate the capture of data, we use a normal distribution
	 * @param pGenerator_p is a random engine
	 * @return the data generated
	 */
	float aleaGenVal(std::default_random_engine* pGenerator_p);

	float m_mean, m_standartDerivation;///< parameters for the normal distribution

};

#endif /* HUMIDITY_HPP */



