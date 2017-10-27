#include "stdafx.h"
#include <ctime>
#include <random>
#include <vector>
#include <functional>
#include "MyVector.h"

#define PI 3.1415926535

using namespace std;

void set_seed() {
	srand(time(NULL));
}
double unifrnd(double a = 0.0, double b = 1.0) {
	return a + (b - a)*((double)rand()) / ((double)RAND_MAX);
}
MyVector<double> unifrnd(int n, double a = 0.0, double b = 1.0) {
	MyVector<double> vec;
	for (int i = 0; i < n; i++) {
		vec.v.push_back(unifrnd(a, b));
	}
	return vec;
}

double normrnd(double mu = 0.0, double sigma = 1.0) {
	return mu+sigma*sqrt(-2.0*log(unifrnd()))*cos(2.0*PI*unifrnd());
}

MyVector<double> normrnd(int n, double mu = 0.0, double sigma = 1.0) {
	MyVector<double> vec;
	for (int i = 0; i < n; i++) {
		vec.v.push_back(normrnd(mu, sigma));
	}
	return vec;
}