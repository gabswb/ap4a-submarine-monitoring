/**
 * @author Gabriel_SCHWAB
 * @file Scheduler.hpp
 * @date 27/09/2021
 * @Brief Description : define the frequency at which the data from the sensors will be retrieved to be transmitted to the server
 */

//
//Define guards
#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <thread>
#include <random>
#include <string>
#include <vector>

#include "Server.hpp"
#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Pression.hpp"
#include "Light.hpp"
#include "Sensor.hpp"

class Scheduler
{

public :

	Scheduler();
	/**
	 * @brief constructor which provide a random engine and frequencies for the sensor
	 * @param generator_p is the random engine
	 * @param tempFrq_p frequency of the sensor temperature
	 * @param humiFrq_p	 frequency of the sensor humidity
	 * @param pressFrq_p frequency of the sensor pression
	 * @param lightFrq_p frequency of the sensor light
	 * @param consoleActivation_p is a boolean which allow or not the consoleWrite method to write data
	 * @param logActivation_p is a boolean which allow or not the fileWrite method to log data
	 */
	Scheduler(std::default_random_engine* pPenerator_p, int tempFrq_p, int humiFrq_p, int pressFrq_p, int lightFrq_p, bool consoleActivation_p, bool logActivation_p);
	Scheduler(const Scheduler& scheduler_p);
	virtual ~Scheduler();
	Scheduler& operator =(const Scheduler& scheduler_p);

	/**
	 * @brief contain all the instructions that make the scheduler run
	 */
	void run();

private :

	std::default_random_engine* m_pGenerator;

	Temperature m_temperatureSensor;
	Humidity m_humiditySensor;
	Pression m_pressionSensor;
	Light m_lightSensor;

	Server m_server;

	bool m_serverRun;///< allow or not the call of the methods consoleWrite and fileWrite from the class @Server in the different threads
	bool m_schedulerRun;///< while this boolean is true, the threads will run, if it is false, the threads will end.


	/**
	 * @brief Template method, call consoleWrite and fileWrite method from Server class
	 * @tparam T is the different sensor type (int, float, bool)
	 * @param sensor_p is the sensor from which we receive data
	 */
	template <class T>
	void displayData(Sensor<T>& sensor_p)
	{
		while(m_schedulerRun)///< the threads are running while the user did not decide to quit the program
		{
			if(m_serverRun)///< the user can stop the file and console writing
			{
				this->m_server.consoleWrite(sensor_p.getSensorType(),sensor_p.getData(m_pGenerator), sensor_p.getUnit());
				this->m_server.fileWrite(sensor_p.getSensorType(),  sensor_p.getData(m_pGenerator), sensor_p.getUnit());

				std::this_thread::sleep_for(std::chrono::milliseconds(sensor_p.getFrequency()));
			}
		}
	}

};

template void Scheduler::displayData(Sensor<int>& sensor_p);
template void Scheduler::displayData(Sensor<float>& sensor_p);
template void Scheduler::displayData(Sensor<bool>& sensor_p);

#endif /* SCHEDULER_HPP_ */
