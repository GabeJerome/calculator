#pragma once
#include <cmath>
#include <cctype>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

//constant terms

const int TERMS = 10;

const double PI = atan( 1.0 ) * 4;

const double ERRORVALUE = .000000000001;

const int ITERATIONMAX = 5000;

const double ERRORTOLERANCE = .000001;


//prototypes

double mySqrt( double testVal );

double myCbrt( double testVal );

double myLog( double testVal, int base );

long long int myFact( int numTerms );

double mySin( double testVal );

double mySinD( double testVal );

double myCos( double testVal );

double myCosD( double testVal );

double myTan( double testVal );

double myTanD( double testVal );

void copyArray( double copyTo[], double source[], int size );

void initialArray( double initial[], int size, double initialTo );

double sumArray( double sumThis[], int size );

double averageArray( double average[], int size );

double minLocation( double array[], int size );

double minValue( double array[], int size );

double maxLocation( double array[], int size );

double maxValue( double array[], int size );

double countIf( double array[], int size, double item );

void mySort( double sort[], int size, string order );

double linearSearch( double search[], int size, double tgt );

double binarySearch( double search[], int size, double tgt );