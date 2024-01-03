#pragma once
#include <string>

namespace state
{
	class IState
	{
	public:
		virtual std::string buttonUp() = 0;
		virtual std::string buttonDown() = 0;
		virtual std::string buttonEnter() = 0;
		virtual int serveSensorData() = 0;
		virtual bool conductSelfCheck() = 0;
	};

	class IDLE : public IState
	{
	public:
		std::string buttonUp() override { return "IDLE - Button Up"; }
		std::string buttonDown() override { return "IDLE - Button Down"; }
		std::string buttonEnter() override { return "IDLE - Button Enter"; }
		int serveSensorData() override { return 1; }
		bool conductSelfCheck() override { return true; }
	};

	class HEATING : public IState
	{
	public:
		std::string buttonUp() override { return "HEATING - Button Up"; }
		std::string buttonDown() override { return "HEATING - Button Down"; }
		std::string buttonEnter() override { return "HEATING - Button Enter"; }
		int serveSensorData() override { return 1; }
		bool conductSelfCheck() override { return true; }
	};

	class INACTIVE : public IState
	{
	public:
		std::string buttonUp() override { return "INACTIVE - Button Up"; }
		std::string buttonDown() override { return "INACTIVE - Button Down"; }
		std::string buttonEnter() override { return "INACTIVE - Button Enter"; }
		int serveSensorData() override { return 0; }
		bool conductSelfCheck() override { return true; }
	};

	class ERROR : public IState
	{
	public:
		std::string buttonUp() override { return "ERROR - Button Up"; }
		std::string buttonDown() override { return "ERROR - Button Down"; }
		std::string buttonEnter() override { return "ERROR - Button Enter"; }
		int serveSensorData() override { return 0; }
		bool conductSelfCheck() override { return true; }
	};

	class HeatingController
	{
	private:
		IState* currentState = nullptr;
	public:
		HeatingController() {};
		void setState(IState* _newState) 
		{ 
			if (_newState != nullptr)
			{
				currentState = _newState;
			}
		};
		std::string buttonUp()
		{ 
			if(currentState != nullptr)
			{
				return currentState->buttonUp();
			}
			return "INVALID CALLBACK";
		}
		std::string buttonDown()
		{
			if (currentState != nullptr)
			{
				return currentState->buttonDown();
			}
			return "INVALID CALLBACK";
		}
		std::string buttonEnter()
		{
			if (currentState != nullptr)
			{
				return currentState->buttonEnter();
			}
			return "INVALID CALLBACK";
		}
		int serveSensorData()
		{
			if (currentState != nullptr)
			{
				currentState->serveSensorData();
			}
			return -1;
		}
		bool conductSelfCheck()
		{
			if (currentState != nullptr)
			{
				currentState->conductSelfCheck();
			}
			return false;
		}
	};
}