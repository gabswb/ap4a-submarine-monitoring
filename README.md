# ap4a-submarine-monitoring
Project carried out as part of the subject ap4a (object oriented programming in C++) at the UTBM.

This project aims to build an IOT environment simulator.
It models an ecosystem of sensors designed to monitor the environment
inside a diving submarine.
This ecosystem is based on four different types of sensors to monitor the
temperature, light, humidity and pressure in the submarine. These sensors communicate with a server on which the data transmitted is displayed and/or stored.

## Installation and usage

To compile this project, you will need:

- [cmake](https://cmake.org) (version 3.10 or higher)
- [GNU make](https://www.gnu.org/software/make/) 
- a C++ compiler, e.g. GNU g++

###Get source files

```sh
git clone https://github.com/gabswb/ap4a-submarine-monitoring.git
cd ap4a-submarine-monitoring
```
###Compile and run

```sh
mkdir build && cd build
cmake .. && make 
./ap4a-project 
```