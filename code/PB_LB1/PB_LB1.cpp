#include <iostream>
using namespace std;

//Finding area's number by using point's coordinates
int firstField(double x, double y) {
	if (x < 0 && x > -1 && (((x + 1) * (x + 1) + (y - 1) * (y - 1) < 1) && (x * x + (y - 1) * (y - 1) < 1) && ((x + 1) * (x + 1) + y * y > 1)))
		return 1;
	else return 0;

}
int secondField(double x, double y) {
	if (x > 0 && y > 0 && (x * x + y * y > 1) && (x * x + (y - 1) * (y - 1) < 1) && (y * y + (x - 1) * (x - 1) < 1))
		return 2;
	else return 0;
}
int thirdField(double x, double y) {
	if (x > 1 && x < 2 && y > 0 && (y * y + (x - 1) * (x - 1) < 1) && ((x - 1) * (x - 1) + (y - 1) * (y - 1) > 1))
		return 3;
	else return 0;

}
int fourthField(double x, double y) {
	if (y < 0 && x < -1 && ((x + 1) * (x + 1) + (y + 1) * (y + 1) < 1) && (y * y + (x + 1) * (x + 1) > 1))
		return 4;
	else return 0;

}
int fifthField(double x, double y) {
	if (x > 0 && y < 0 && ((x - 1) * (x - 1) + (y + 1) * (y + 1) < 1) && ((x - 1) * (x - 1) + y * y > 1))
		return 5;
	else return 0;

}

//Main function for finding area under graph (takes another function as parameter to specify function for every equation)
//All left and right border values are hardcoded for writing less code and using less var's 
double findIntegral(double (*findY)(double), double leftBorder, double rightBorder) {
	double dx, summaryY = 0;
	int step = 25; //Step value can be different, but bigger step's value increases integral accuracy
	dx = (rightBorder - leftBorder) / step;
	summaryY += findY(rightBorder) + findY(leftBorder);
	for (int i = 1; i < step; i++) { summaryY += 2 * (findY(leftBorder + dx * i)); }
	double integral = (rightBorder - leftBorder) / (2 * step) * summaryY;
	return integral;
}

//Functions that present graph's functionals parts
//Some functions for different areas may repeat
//FIRST AREA-----------------------
double firstArea_FindY1(double x) {
	return sqrt(1 - x*x) + 1;
}
double firstArea_FindY2(double x) {
	return sqrt(1 - (x + 1) * (x + 1)) + 1;
}
double firstArea_FindY3(double x) {
	return sqrt(1 - (x + 1) * (x + 1));
}
double firstArea_FindY4(double x) {
	return - sqrt(1 - (x + 1) * (x + 1)) + 1;
}
//---------------------------------
//SECOND AREA----------------------
double secondArea_FindY1(double x) {
	return sqrt(1 - (x - 1) * (x - 1));
}
double secondArea_FindY2(double x) {
	return -sqrt(1 - x * x) + 1;
}
double secondArea_FindY3(double x) {
	return sqrt(1 - x * x);
}
//---------------------------------
//THIRD AREA----------------------
double thirdArea_FindY1(double x) {
	return -sqrt(1 - (x - 1) * (x - 1)) + 1;
}
double thirdArea_FindY2(double x) {
	return sqrt(1 - (x - 1) * (x - 1));
}
//---------------------------------
//FOURTH AREA----------------------
double fourthArea_FindY1(double x) {
	return sqrt(1 - (x + 1) * (x + 1)) - 1;
}
double fourthArea_FindY2(double x) {
	return -sqrt(1 - (x + 1) * (x + 1));
}
double fourthArea_FindY3(double x) {
	return -sqrt(1 - (x + 1) * (x + 1)) - 1;
}
//---------------------------------
//FIFTH AREA----------------------
double fifthArea_FindY1(double x) {
	return sqrt(1 - (x - 1) * (x - 1)) - 1;
}
double fifthArea_FindY2(double x) {
	return -sqrt(1 - (x - 1) * (x - 1));
}
double fifthArea_FindY3(double x) {
	return -sqrt(1 - (x - 1) * (x - 1)) - 1;
}
//---------------------------------


int main()
{
	setlocale(LC_ALL, "RU");

	double x, y, dy;
	cin >> x >> y;
	
	int fieldNumber = 0;
	fieldNumber = firstField(x, y) + secondField(x, y) + thirdField(x, y) + fourthField(x, y) + fifthField(x, y);

	switch (fieldNumber)
	{
	case 1: {
		cout << "Точка принадлежит 1 области" << endl;
		cout << "Площадь равна: " << findIntegral(firstArea_FindY1, -1, -0.5) + findIntegral(firstArea_FindY2, -0.5, 0) - findIntegral (firstArea_FindY3, -1, -1 + sqrt(3.) / 2) - findIntegral(firstArea_FindY4, -1 + sqrt(3.) / 2, 0);
		break;
	}
	case 2: {
		cout << "Точка принадлежит 2 области" << endl;
		cout << "Площадь равна: " << findIntegral(secondArea_FindY1, 0.5, 1) - findIntegral(secondArea_FindY2, sqrt(3) / 2, 1) - findIntegral(secondArea_FindY3, 0.5, sqrt(3) / 2);
		break;
	}
	case 3: {
		cout << "Точка принадлежит 3 области" << endl;
		cout << "Площадь равна: " << findIntegral(thirdArea_FindY1, 1, 1 + sqrt(3) / 2) + findIntegral(thirdArea_FindY2, 1 + sqrt(3) / 2, 2);
		break;
	}
	case 4: {
		cout << "Точка принадлежит 4 области" << endl;
		cout << "Площадь равна: " << findIntegral(fourthArea_FindY1, -2, -1 - sqrt(3) / 2) + findIntegral(fourthArea_FindY2, -1 - sqrt(3) / 2, -1) - findIntegral(fourthArea_FindY3, -2, -1);
		break;
	}
	case 5: {
		cout << "Точка принадлежит 5 области" << endl;
		cout << "Площадь равна: " << 2 * (findIntegral(fifthArea_FindY1, 0, 1 - sqrt(3) / 2) + findIntegral(fifthArea_FindY2, 1 - sqrt(3) / 2, 1) - findIntegral(fifthArea_FindY3, 0, 1));
		break;
	}
	default:
		cout << "Точка не принадлежит ни одной выделенной области!";
		break;
	}
}
