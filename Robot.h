#include <Arduino.h>
#include <AFMotor.h>
#include <Ultrasonic.h>

class Robot
{

private:
	//Variables

	//Array with the pins of the colors sensors
	int pinoSensorEsquerda[5] = { 1,2,3,4,5 };
	int pinoSensorDireita[5] = { 6,7,8,9,10 };
	
	//Array with the motors
	AF_DCMotor motor[4] = {1,2,3,4};
	
	//Instance of Ultra
	Ultrasonic ultrassonic = { 12,13 };
	int minDistanceValue;
	
	//Value of the curve (degree)
	int curvaValue;

	//GET - Data of Sensors
	int* getDataColorEsquerda();
	int* getDataColorDireita();
	//validate
	bool validateGreen(char lado);
	//Get Raw Data
	int getRed(char lado);
	int getGreen(char lado);
	int getBlue(char lado);


public:

	//Init
	void init(int speed, int curva_degree, int distanceValue);
	
	//Sensor Cor Methods
	void setSensoresDeCorEsquerda();
	void setSensoresDeCorDireita();
	char getColorEsquerda();
	char getColorDireita();
	
	//Motor Methods
	void setMotores(int speed);
	void runForward(int time);
	void turn(int lado);
	void stop();
	AF_DCMotor getMotor(int index);

	//Sensor Ultra Methods
	double getDistance();

	//Follow line
	void followLine();
	
	//Dodge Obstacule
	void dodgeObstacule();
};