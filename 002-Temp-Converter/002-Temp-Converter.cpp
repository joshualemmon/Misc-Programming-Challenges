//002 Temperature Converter

#include <cstdio>
#include <iostream>

using namespace std;

void start();
void celsiusConvert(double temp);
void farenheitConvert(double temp);
void kelvinConvert(double temp);

int main()
{
	start();
	return 0;
}

void start()
{
	printf("Enter the temperature you wish to convert: ");
	double temp;
	char type;
	cin >> temp;
	printf("Farenheit(F), Celsius(C) or Kelvin(K)? ");
	cin >> type;

	if(type == 'F' || type == 'f') {farenheitConvert(temp);}
	else if(type == 'C' || type == 'c') {celsiusConvert(temp);}
	else if(type == 'K'|| type == 'k') {kelvinConvert(temp);}
	else
	{
		printf("Incorrect input.");
		start();
	}
}

void celsiusConvert(double temp)
{
	double fTemp = 1.8*temp + 32;
	double kelTemp = temp + 273.15;
	printf("%.2fC in Kelvin is %.2fK \n",temp,kelTemp);
	printf("%.2fC in Farenheit is %.2fF \n", temp, fTemp);
}

void farenheitConvert(double temp)
{
	double cTemp = (temp - 32)/1.8;
	double kelTemp = cTemp + 273.15;
	printf("%.2fF in Kelvin is %.2f K \n",temp,kelTemp);
	printf("%.2fF in Celsius is %.2f C \n", temp, cTemp);
}

void kelvinConvert(double temp)
{
	double cTemp = temp - 273.15;
	double fTemp = 1.8*cTemp + 32;
	printf("%.2fK in Celcius is %.2f C \n",temp,cTemp);
	printf("%.2fK in Farenheit is %.2f F \n", temp, fTemp);
}