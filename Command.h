#pragma once
#include <cstring>
#include <iostream>

namespace command
{
	class ICommand
	{
	public:
		virtual bool job() = 0;
	};

	class ReadData : public ICommand
	{
	private:
		int sensorData = 0;
	public:
		bool job() override { std::cout << "Reading data..." << std::endl; return true; }
		int getData() { return sensorData; }
	};

	class SetParameter : public ICommand
	{
	private:
		int parameterValue = 0;
	public:
		bool job() override { std::cout << "Setting parameter..." << std::endl;return true; }
		void updateParameter(int _param) {  parameterValue = _param; }
	};

	class Reset : public ICommand
	{
		bool job() override { std::cout << "Reset device..." << std::endl; return true; }
	};

	/* STATIC ALLOCATION */
	Reset reset;
	ReadData read_data;
	SetParameter set_parameter;

	class SerialPortModule; // Forward declaration

	class Controller
	{
	private:
		SerialPortModule* serialPort;
		ICommand* _command = nullptr;
		ICommand* commandsList[3] = {  &read_data, &set_parameter, &reset };
	public:
		void setSerialPort(SerialPortModule* _serialPort) { serialPort = _serialPort; }
		void setCommand(int _commandIndex) { _command = commandsList[_commandIndex]; };
		bool executeCommand() { return _command->job(); }
	};

	class SerialPortModule
	{
	private:
		Controller* controller = nullptr;
		const char commandsCharList[3][16] = { "ReadData" ,  "SetParameter" ,  "Reset" };
		char currentCommand[16];
	public:
		SerialPortModule(Controller* _controller) : controller{ _controller } {};
		void receiveData(int _timeout, int _testCase) // _testCase is for testing reasons only
		{
			/* This switch-case statement is emulating real serial port*/
			switch (_testCase)
			{
			case 0:
				strcpy_s(currentCommand, "ReadData");
				break;
			case 1:
				strcpy_s(currentCommand, "SetParameter");
				break;
			case 2:
				strcpy_s(currentCommand, "Reset");
				break;
			}
			
			for (int i = 0; i < 3; i++)
			{
				if (strcmp(currentCommand, commandsCharList[i]) == 0)
				{
					controller->setCommand(i);
					controller->executeCommand();
					break;
				}
			}
		}
	};
}