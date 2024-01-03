#pragma once
#include <string>
#include <iostream>

namespace adapter
{
	class IController
	{
	public:
		virtual void sendData(char* _data) = 0;
	};

	class SerialOutput
	{
	public:
		void sendOutputData(std::string _data) {std::cout << _data << std::endl;}
	};

	class Adapter : public IController
	{
	private:
		SerialOutput* serial;
	public:
		Adapter(SerialOutput* _serial) : serial {_serial} {}
		void sendData(char* _data) override
		{
			std::string s = _data; // Convert data type
			serial->sendOutputData(s);
		}
	};
}