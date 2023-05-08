#include <iostream>

int Irand(int num1, int num2) {
	return num1 + (rand() / (RAND_MAX / (num2 - num1)));
}
float Frand(float num1, float num2) {
	return ((num2 - num1) * ((float)rand() / RAND_MAX)) + num1;
}
double Drand(double num1, double num2) {
	return num1 + (rand() / (RAND_MAX / (num2 - num1)));
}
