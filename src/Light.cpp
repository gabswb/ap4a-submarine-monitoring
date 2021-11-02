/**
 * @author Gabriel_SCHWAB
 * @file Light.cpp
 * @date 27/09/2021
 * @Brief Description :simulate a Sensor which capture the light inside the submarine
 */

#include <iostream>
#include <string>
#include <random>
#include <chrono>

#include "Light.hpp"

Light::Light():
		Sensor("light", "", 5000), m_proba(0.5){}

Light::Light(int frequency_p):
		Sensor("light", "", frequency_p), m_proba(0.5){}

Light::Light(const Light& light_p):
		Sensor(light_p.m_sensorType, light_p.m_unit, light_p.m_frequency), m_proba(light_p.m_proba){}

Light::~Light(){}

Light& Light::operator =(const Light& light_p)
{
	this->m_sensorType = light_p.m_sensorType;
	this->m_proba=light_p.m_proba;
	this->m_frequency=light_p.m_frequency;

	return *this;
}

bool Light::aleaGenVal(std::default_random_engine* pGenerator_p)
{

	 std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	 time_t tt = std::chrono::system_clock::to_time_t(now);
	 tm local_tm = *localtime(&tt);

	 int hour = local_tm.tm_hour;

	if(8<hour && hour<20)
	{
		return true;
	}
	else
	{
		return false;
	}
}



