#pragma once
namespace singleton
{
	class ISensor
	{
	public:
		virtual bool init() = 0;
		virtual float readMeasurement() = 0;
	};

	class MLX90393_Sensor : public ISensor
	{
	private:
		static MLX90393_Sensor _mlx90393_sensor; // The only existing object of this class
		MLX90393_Sensor() {};
	public:
		MLX90393_Sensor(MLX90393_Sensor& other) = delete; // It shouldnt be possible to copy object
		MLX90393_Sensor& operator=(MLX90393_Sensor& other) = delete; // It shouldnt be possible to assign object
		static MLX90393_Sensor* getInstance(); // Method that returns pointer to the existing object

		bool init() override { return true; };
		float readMeasurement() override { return 0.0; };
	};

	MLX90393_Sensor MLX90393_Sensor::_mlx90393_sensor; // Using static memory allocation

	MLX90393_Sensor* MLX90393_Sensor::getInstance()
	{
		return &_mlx90393_sensor; 
	}
}
