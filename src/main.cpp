//============================================================================
// Name        : schwab_gabriel_project.cpp
// Author      : Gabriel Schwab
// Version     : intermediate return
// Copyright   :
// Description : IOT environment simulator
//============================================================================

#include <iostream>
#include <random>
#include "Scheduler.hpp"
#include "InputCheck.hpp"


int main() {

	std::random_device randomDevice;
	unsigned seed = randomDevice();
	std::default_random_engine generator(seed);

	int tempFrq=0, humiFrq=0, pressFrq=0, lightFrq=0;///< frequencies for the call of the method consoleWrite and fileWrite for each sensor

	bool consoleActivation, logActivation;

	int input=0;


	std::cout <<"**************************************\n"
				"*                                    *\n"
				"*  Submarine environment monitoring  *\n"
				"*                                    *\n"
				"**************************************\n\n"
				"(enter 'p' to pause the program when he is running)\n\n"

				"Please define the frequency (in ms) of the following captors :"<< std::endl;

	tempFrq = inputCheck(tempFrq,"1. Temperature sensor frequency : \n",1000,60000);
	humiFrq = inputCheck(humiFrq,"2. Humidity sensor frequency : \n",1000,60000 );
	pressFrq = inputCheck(pressFrq,"3. Pressure sensor frequency : \n",1000,60000 );
	lightFrq = inputCheck(lightFrq,"4. Light sensor frequency : \n",1000,60000 );


	input = inputCheck(input,"Do you want to display the data in the console ?\nPress '0' for no or '1' for yes",0,1);

	if(input)
		consoleActivation=true;
	else
		consoleActivation=false;


	input = inputCheck(input,"Do you want to log the data in a file ?\nPress '0' for no or '1' for yes",0,1);

	if(input)
		logActivation=true;
	else
		logActivation=false;



	Scheduler scheduler(&generator, tempFrq, humiFrq, pressFrq, lightFrq, consoleActivation, logActivation);
	scheduler.run();

	return 0;
}





