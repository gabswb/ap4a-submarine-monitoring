/**
 * @author Gabriel_SCHWAB
 * @file Server.cpp
 * @date 27/09/2021
 *
 */

#include <iostream>
#include <fstream>
#include <ctime>

#include "Server.hpp"


Server::Server():
		m_consoleActivation(true), m_logActivation(true){}

Server::Server(bool consoleActivation_p, bool logActivation_p):
		m_consoleActivation(consoleActivation_p), m_logActivation(logActivation_p){}

Server::Server(const Server& server_p):
		m_consoleActivation(server_p.m_consoleActivation), m_logActivation(server_p.m_logActivation){}


Server::~Server(){}

Server& Server::operator=(const Server& server_p)
{
	this->m_consoleActivation=server_p.m_consoleActivation;
	this->m_logActivation=server_p.m_logActivation;

	return *this;
}

void Server::setConsoleActivation(bool consoleActivation_p)
{
	this->m_consoleActivation = consoleActivation_p;
}

void Server::setLogActivation(bool logActivation_p)
{
	this->m_logActivation = logActivation_p;
}

std::string Server::getTime()
{
	time_t now = time(0);///< current date/time based on current system
	std::string date = ctime(&now);///< convert now to string form
	date.pop_back();///<delete the "\n" at the end of the string

	return date;
}









