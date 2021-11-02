/**
 * @author Gabriel_SCHWAB
 * @file Temperature.cpp
 * @date 27/09/2021
 * @Brief  Description :simulate a Sensor which capture the light inside the submarine
 */

#include <iostream>
#include <random>

#include "Temperature.hpp"



Temperature::Temperature():
		Sensor("temperature", "°C", 5000), m_mean(20.0), m_standartDerivation(0.5){}

Temperature::Temperature(int frequency_p):
		Sensor("temperature", "°C", frequency_p), m_mean(20.0), m_standartDerivation(0.5){}

Temperature::Temperature(const Temperature& temperature_p):
		Sensor(temperature_p.m_sensorType, temperature_p.m_unit, temperature_p.m_frequency), m_mean(temperature_p.m_mean), m_standartDerivation(temperature_p.m_standartDerivation){}


Temperature::~Temperature(){}

Temperature& Temperature::operator =(const Temperature& temperature_p)
{
	this->m_sensorType = temperature_p.m_sensorType;
	this->m_unit = temperature_p.m_unit;
	this->m_mean=temperature_p.m_mean;
	this->m_standartDerivation=temperature_p.m_standartDerivation;
	this->m_frequency=temperature_p.m_frequency;

	return *this;
}

float Temperature::aleaGenVal(std::default_random_engine* pGenerator_p)
{
	std::normal_distribution<> distrib{m_mean,m_standartDerivation};

	return distrib(*pGenerator_p);
}


