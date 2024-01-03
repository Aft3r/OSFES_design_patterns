#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "Singleton.h"
#include "State.h"
#include "Command.h"
#include "Adapter.h"

/* This is a part of Command Design Pattern Demo*/
typedef enum
{
	READ_DATA = 0,
	SET_PARAMETER = 1,
	RESET = 2
}TEST_CASE;

int main()
{
	/* SINGLETON DESIGN PATTERN */
	/*
	singleton::MLX90393_Sensor* sensor = singleton::MLX90393_Sensor::getInstance();
	singleton::MLX90393_Sensor* sensor2 = singleton::MLX90393_Sensor::getInstance();
	//*sensor2 = *sensor; // Check if it is possible to assign class object
	//singleton::MLX90393_Sensor sensor_1(*s); // Check if it is possible to use copy contructor
	*/

	/* STATE DESIGN PATTERN */
	/*
	state::IDLE idle;
	state::HEATING heating;
	state::INACTIVE inactive;
	state::ERROR error;
	state::HeatingController controller;
	controller.setState(&idle);
	std::cout << "Current state: " + controller.buttonUp() << std::endl;
	std::cout << "Switching state to HEATING..." << std::endl;
	controller.setState(&heating);
	std::cout << "Current state: " + controller.buttonUp() << std::endl;
	std::cout << "Switching state to IDLE..." << std::endl;
	controller.setState(&idle);
	std::cout << "Current state: " + controller.buttonDown() << std::endl;
	*/

	/* COMMAND DESIGN PATTERN */
	/*
	command::Controller controller;
	command::SerialPortModule serialPort(&controller);
	controller.setSerialPort(&serialPort);
	std::cout << "Received ReadData command from PC" << std::endl;
	serialPort.receiveData(1000, READ_DATA);
	std::cout << "Received SetParameter command from PC" << std::endl;
	serialPort.receiveData(1000, SET_PARAMETER);
	std::cout << "Received Reset command from PC" << std::endl;
	serialPort.receiveData(1000, RESET);
	*/

	/* ADAPTER DESIGN PATTERN */
	/*
	adapter::SerialOutput serial;
	adapter::Adapter adapter(&serial);
	char message[] = "Char type message send by string data type required function";
	adapter.sendData(message);
	*/

	std::cout << "Hello world" << std::endl;

}