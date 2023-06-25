#include <iostream>

static inline int Irand(int num1, int num2) {
	return num1 + (rand() / (RAND_MAX / (num2 - num1)));
}
static inline float Frand(float num1, float num2) {
	return ((num2 - num1) * ((float)rand() / RAND_MAX)) + num1;
}
static inline double Drand(double num1, double num2) {
	return num1 + (rand() / (RAND_MAX / (num2 - num1)));
}
