// RandomForest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include <random>
#include <vector>
#include <functional>
#include <iostream>
#include <numeric>
#include <algorithm>
#include "MyVector.h"
#include "RandomStuff.h"

using namespace std;

double Gini(MyVector<double> X, MyVector<double> Y, double s) {
	MyVector<double> classes = X;
	transform(X.v.begin(), X.v.end(), Y.v.begin(), classes.v.begin(), [&s](double x, double y) {
		if (x <= s) {
			return 0.0;
		}else{
			return 1.0;
		}});
	vector<vector<int>> pmk(2); pmk[0] = { 0,0 }; pmk[1] = { 0,0 };
	MyVector<MyVector<double>> Z = Zip<double>(Y, classes);
	pmk = accumulate(Z.v.begin(), Z.v.end(), pmk, [](vector<vector<int>>p, MyVector<double> z) {
		if (z.v[1] < 0.5) {
			if (z.v[0] < 0.5) {
				p[0][0] += 1;
			}
			else {
				p[0][1] += 1;
			}
			}else{
			if (z.v[0] < 0.5) {
				p[1][0] += 1;
			}else{
				p[1][1] += 1;
			}
		}
		return p;
	});
	vector<vector<double>> PMK(2);
	PMK[0] = { ((double)pmk[0][0]) / ((double)pmk[0][0] + pmk[0][1]),((double)pmk[0][1]) / ((double)pmk[0][0] + pmk[0][1]) };
	PMK[1] = { ((double)pmk[1][0]) / ((double)pmk[1][0] + pmk[1][1]),((double)pmk[1][1]) / ((double)pmk[1][0] + pmk[1][1]) };
	return PMK[0][0] * (1.0 - PMK[0][0]) + PMK[0][1] * (1.0 - PMK[0][1]) + PMK[1][0] * (1.0 - PMK[1][0]) + PMK[1][1] * (1.0 - PMK[1][1]);
}
	
double OptimalSplit(MyVector<double> X, MyVector<double> Y) {
	vector<double> svec(X.v.size());
	transform(X.v.begin(), X.v.end(), svec.begin(), [&Y, &X](double x) {
		return Gini(X, Y, x);
	});
	return X.v[min_element(svec.begin(), svec.end()) - svec.begin()];
}


int main()
{
	set_seed();
	// data generation
	MyVector<double> X = unifrnd(100, 0.0, 1.0);
	MyVector<double> Y = X;
	transform(X.v.begin(), X.v.end(), Y.v.begin(), [](double d) {
		if (d < 0.7) {
			return 0.0;
		}else{
			return 1.0;
		}
	});
	// tree split
	cout << OptimalSplit(X, Y);
	system("pause");
    return 0;
}

