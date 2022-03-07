/**
 * @author Gabriel_SCHWAB
 * @file Scheduler.cpp
 * @date 27/09/2021
 * @Brief Description : define the frequency at which the data from the sensors will be retrieved to be transmitted to the server
 */

#include <iostream>
#include <chrono>
#include <thread>
#include <limits>

#include "Scheduler.hpp"
#include "InputCheck.hpp"

Scheduler::Scheduler() : m_pGenerator(nullptr),
						 m_temperatureSensor(5000), m_humiditySensor(5000), m_pressionSensor(5000), m_lightSensor(5000),
						 m_server(),
						 m_serverRun(true), m_schedulerRun(true) {}

Scheduler::Scheduler(std::default_random_engine *pGenerator_p, int tempFrq_p, int humiFrq_p, int pressFrq_p, int lightFrq_p, bool consoleActivation_p, bool logActivation_p) : m_pGenerator(pGenerator_p),
																																											   m_temperatureSensor(tempFrq_p), m_humiditySensor(humiFrq_p), m_pressionSensor(pressFrq_p), m_lightSensor(lightFrq_p),
																																											   m_server(consoleActivation_p, logActivation_p),
																																											   m_serverRun(true), m_schedulerRun(true) {}

Scheduler::Scheduler(const Scheduler &scheduler_p) : m_pGenerator(scheduler_p.m_pGenerator),
													 m_temperatureSensor(scheduler_p.m_temperatureSensor), m_humiditySensor(scheduler_p.m_humiditySensor), m_pressionSensor(scheduler_p.m_pressionSensor), m_lightSensor(scheduler_p.m_lightSensor),
													 m_server(),
													 m_serverRun(scheduler_p.m_serverRun), m_schedulerRun(scheduler_p.m_schedulerRun) {}

Scheduler::~Scheduler() {}

Scheduler &Scheduler::operator=(const Scheduler &scheduler_p)
{
	m_pGenerator = scheduler_p.m_pGenerator;

	m_temperatureSensor = scheduler_p.m_temperatureSensor;
	m_humiditySensor = scheduler_p.m_humiditySensor;
	m_pressionSensor = scheduler_p.m_pressionSensor;
	m_lightSensor = scheduler_p.m_lightSensor;

	m_serverRun = scheduler_p.m_serverRun;
	m_schedulerRun = scheduler_p.m_schedulerRun;

	return *this;
}

void Scheduler::run()
{
	std::thread m_threadDispTemp(&Scheduler::displayData<float>, this, std::ref(m_temperatureSensor));
	std::thread m_threadDispHumi(&Scheduler::displayData<float>, this, std::ref(m_humiditySensor));
	std::thread m_threadDispPress(&Scheduler::displayData<int>, this, std::ref(m_pressionSensor));
	std::thread m_threadDispLight(&Scheduler::displayData<bool>, this, std::ref(m_lightSensor));

	while (m_schedulerRun) ///< the user can enter input to pause or quit the program
	{
		char userInput;

		userInput = inputCheck(userInput, "Unknown command line", 'p');

		m_serverRun = false;

		while (!m_serverRun) ///< while the user didn't press 'r' to restart the servers, he can change the options
		{
			userInput = inputCheck(userInput, "Servers in pause, press :\n"
											  "- 'a' to activate the display of the data in the console\n"
											  "- 'b' to deactivate the display of the data in the console\n"
											  "- 'c' to activate the log of the data in the files\n"
											  "- 'd' to deactivate the log of the data in the files\n"
											  "- 'r' to restart the servers\n"
											  "- 'q' to quit the program",
								   'a', 'b', 'c', 'd', 'r', 'q');

			switch (userInput)
			{
			case 'q':
			{
				m_schedulerRun = false; ///< to stop the thread running and then be able to join them
				m_serverRun = true;		///< to exit the while loop above

				m_threadDispTemp.join();
				m_threadDispHumi.join();
				m_threadDispPress.join();
				m_threadDispLight.join();
			}
			break;
			case 'r':
			{
				m_serverRun = true;
			}
			break;
			case 'a':
			{
				m_server.setConsoleActivation(true);
				std::cout << "Console display activated" << std::endl;
			}
			break;
			case 'b':
			{
				m_server.setConsoleActivation(false);
				std::cout << "Console display deactivated" << std::endl;
			}
			break;
			case 'c':
			{
				m_server.setLogActivation(true);
				std::cout << "log of data activated" << std::endl;
			}
			break;
			case 'd':
			{
				m_server.setLogActivation(false);
				std::cout << "log of data deactivated" << std::endl;
			}
			break;
			default:
			{
				std::cerr << "error" << std::endl;
			}
			}
		}
	}
}
