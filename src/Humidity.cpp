/**
 * @author Gabriel_SCHWAB
 * @file Humidity.cpp
 * @date 27/09/2021
 * @Brief Description :simulate a Sensor which capture the humidity inside the submarine
 */

#include <iostream>
#include <string>
#include<random>

#include "Humidity.hpp"

Humidity::Humidity():
		Sensor("humidity", "%", 5000), m_mean(50.0), m_standartDerivation(5){}

Humidity::Humidity(int frequency_p):
		Sensor("humidity", "%", frequency_p), m_mean(50.0), m_standartDerivation(5){}

Humidity::Humidity(const Humidity& humidity_p):
		Sensor(humidity_p.m_sensorType, humidity_p.m_unit, humidity_p.m_frequency), m_mean(humidity_p.m_mean), m_standartDerivation(humidity_p.m_standartDerivation){}

Humidity::~Humidity(){}

Humidity& Humidity::operator =(const Humidity& humidity_p)
{
	this->m_sensorType = humidity_p.m_sensorType;
	this->m_unit = humidity_p.m_unit;
	this->m_mean=humidity_p.m_mean;
	this->m_standartDerivation=humidity_p.m_standartDerivation;
	this->m_frequency=humidity_p.m_frequency;

	return *this;
}

float Humidity::aleaGenVal(std::default_random_engine* pGenerator_p)
{
	std::normal_distribution<> distrib{m_mean,m_standartDerivation};

	return distrib(*pGenerator_p);
}

