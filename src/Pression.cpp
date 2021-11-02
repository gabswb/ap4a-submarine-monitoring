/**
 * @author Gabriel_SCHWAB
 * @file Pression.cpp
 * @date 27/09/2021
 * @Brief Description :simulate a Sensor which capture the pressure inside the submarine
 */

#include <iostream>
#include <string>
#include <random>

#include "Pression.hpp"

Pression::Pression():
		Sensor("pression", "mb", 5000), m_min(1010), m_max(1015){}

Pression::Pression(int frequency_p):
		Sensor("pression", "mb", frequency_p), m_min(1010), m_max(1015){}

Pression::Pression(const Pression& pression_p):
		Sensor(pression_p.m_sensorType, pression_p.m_unit, pression_p.m_frequency), m_min(pression_p.m_min), m_max(pression_p.m_max){}

Pression::~Pression(){}

Pression& Pression::operator =(const Pression& pression_p)
{
	this->m_sensorType = pression_p.m_sensorType;
	this->m_unit = pression_p.m_unit;
	this->m_min=pression_p.m_min;
	this->m_min=pression_p.m_max;
	this->m_frequency=pression_p.m_frequency;


	return *this;
}

int Pression::aleaGenVal(std::default_random_engine* pGenerator_p)
{
	std::uniform_int_distribution<> distrib(m_min,m_max);

	return distrib(*pGenerator_p);
}
