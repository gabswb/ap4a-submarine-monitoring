/**
 * @author Gabriel_SCHWAB
 * @file Server.hpp
 * @date 27/09/2021
 * @Brief simulate a server which write and save the data received
 */

//
// Define guards
#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <fstream>
#include <mutex>

#include "Sensor.hpp"

class Server
{

public:
	Server();
	/**
	 * @brief constructor which provide user's choices for console and log activation
	 * @param consoleActivation_p
	 * @param logActivation_p
	 */
	Server(bool consoleActivation_p, bool logActivation_p);
	Server(const Server &server);
	virtual ~Server();
	Server &operator=(const Server &server);

	/**
	 * @brief set the activation of the console writing
	 * @param consoleActivation_p
	 */
	void setConsoleActivation(bool consoleActivation_p);
	/**
	 * @brief set the activation of the file writing
	 * @param logActivation_p
	 */
	void setLogActivation(bool logActivation_p);
	/**
	 * @brief write in the console the data received in parameter
	 * @param sensorType_p type of the sensor which send the data
	 * @param data_p
	 * @param unit_p unit of the data
	 */
	template <typename T>
	void consoleWrite(std::string sensorType_p, T data_p, std::string unit_p)
	{
		if (m_consoleActivation)
		{
			int nbOfSpace = 12 - sensorType_p.length(); ///< calculate the number of space needed to align the display of the different sensors (just for esthetic)

			m_locker.lock(); ///< lock the console writing in order to prevent different threads to write in it at the same time
			std::cout << getTime() << "     " << sensorType_p << std::string(nbOfSpace, ' ') << "  :  " << std::boolalpha << data_p << " " << unit_p << std::endl;
			m_locker.unlock();
		}
	}

	/**
	 * @brief write in the right file the data received in parameter
	 * the data from the same sensor are written in the same file
	 * @param sensorType_p type of the sensor which send the data
	 * @param data_p
	 * @param unit_p unit of the data
	 */
	template <typename T>
	void fileWrite(std::string sensorType_p, T data_p, std::string unit_p)
	{
		if (m_logActivation)
		{
			m_locker.lock();

			std::string filePath = "logs/" + sensorType_p + ".txt";
			std::ofstream file;
			file.open(filePath, std::ios::app);

			if (file) ///< test if the file is correctly open
			{
				file << getTime() << "         " << sensorType_p << "  :  " << std::boolalpha << data_p << " " << unit_p << std::endl;
			}
			else
			{
				std::cout << "file errror, couldn't open the right file" << std::endl;
			}

			file.close();

			m_locker.unlock();
		}
	}

private:
	bool m_consoleActivation, m_logActivation;

	std::mutex m_locker;
	/**
	 * @brief get the time of the system
	 * @return current time of the system
	 */
	std::string getTime();
};

#endif // SERVER_HPP
