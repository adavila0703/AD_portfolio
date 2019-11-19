/*
	EE Calculator
	This calculate will eventually be a hub for all Electrical Engineering and Phsycis equations, 
	all accessable with a menu that will alow you to navigate to what you are trying to calcualte.
*/

#include "pch.h"

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <math.h>

using namespace std;

int capcharge() {
	/*
	(C*V^2)/2
	Vc = Vs * e ^ -t/RC

	Charge time
	tau * 5
	*/
	float voltage, resistance, cap, timeconstant, voltattime, chargeuptime, calc;
	double e;
		cout << "Voltage?" << " ";
		cin >> voltage;
		cout << "Reistance?" << " ";
		cin >> resistance;
		cout << "Capacitance?" << " ";
		cin >> cap;
			timeconstant = resistance * cap;
			calc = cap * pow(voltage, 2) / 2;
			//timeconstnat multiplied by 5 tau gives you charge up time
				chargeuptime = timeconstant * 5;
				voltattime = voltage * pow(M_E, -timeconstant / resistance * cap);
		cout << "Capacitor energy is " << calc << "J" << endl;
		cout << "Capacitor timeconstant is " << timeconstant << "s" << endl;
		cout << voltattime << endl;
	system("PAUSE");
	return 0;
}
int motors() {
	//E = voltage, I = amps, W = watts, PF = power factor, Eff = efficiency, HP = horsepower
	system("PAUSE");
	return 0;
}
int ohmslaw(int input) {
	//v = voltage, i = amps, w = watts, r=resistance

	system("PAUSE");
	return 0;
}
int current() {
	//V/R
	float voltage, resistance, calc;
		cout << "Voltage?" << " ";
		cin >> voltage;
		cout << "Reistance?" << " ";
		cin >> resistance;
			calc = voltage / resistance;
		cout << "The current is " << calc << "A" << endl;
		system("PAUSE");
	return 0;
}
int voltage() {
	//Ω*I
	float resistance;
	float current;
	float calc;
		cout << "Reistance?" << " ";
		cin >> resistance;
		cout << "Current?" << " ";
		cin >> current;
			calc = resistance * current;
		cout << "The supplied voltage is " << calc << "V" << endl;
		system("PAUSE");
	return 0;
}
int resistance() {
	// V/I
	float voltage;
	float current;
	float calc;
		cout << "Voltage?" << " ";
		cin >> voltage;
		cout << "Current?" << " ";
		cin >> current;
			calc = voltage / current;
		cout << "The resistance value is " << calc << " Ohm's" << endl;
		system("PAUSE");
	return 0;
}
int power() {
	// V*A
	float voltage;
	float current;
	float calc;
		cout << "Voltage?" << " ";
		cin >> voltage;
		cout << "Current?" << " ";
			cin >> current;
		calc = voltage * current;
		cout << "The power value is " << calc << "W" << endl;
		system("PAUSE");
	return 0;
}

int powerdens() {

	//power density equations
	float outputpower;
	float gain;
	float distance;
	float calc;
		cout << "Output Power(mW)?" << " ";
		cin >> outputpower;
		cout << "Gain?" << " ";
		cin >> gain;
		cout << "Distancer(ft)?" << " ";
		cin >> distance;
			calc = (outputpower * gain) / ((4 * M_PI) * pow(distance, 2));
		cout << "Capacitor energy is " << calc << "W/m^2" << endl;
	system("PAUSE");
	return 0;
}
int main()
{

	int select = 0, select2 = 0, calcon = 1;
	string value[4] = { "\n1. Voltage" , "\n2. Resistance", "\n3. Current", "\n4. Power" };
	while (calcon == 1)
	{

		//menu
		system("CLS");
		cout << "EE Calculator. " << endl;
		cout << "1. Ohm's Law" << endl;
		cout << "2. Capacitor Charge Up" << endl;
		cout << "3. Power Density" << endl;
		cout << "4. Motors" << endl;
		cout << "9. Exit" << endl;
		cin >> select;

		switch (select)
		{
		case 1:
			/*For selecing ohms law.

			This is still under progress, but this will display an array, and depending on what you choose
			After you select a condition, it will create a new array without the unneeded selections.
			*/
			cout << "What would you like to find?" << endl;
			for (int i = 0; i < 4; i++)
			{
				cout << value[i] << endl;
			}
			cin >> select;
			system("PAUSE");
			break;
		case 2:
			capcharge();
			break;
		case 3:
			powerdens();
			break;
		case 4:
			cout << "What phase motor? \n1. Single Phase\n2. Three Phase" << endl;
			cin >> select;
				switch (select)
				{
				
				}
			break;
		case 9:
			calcon = 0;
			break;
		}
	}
	return 0;
}