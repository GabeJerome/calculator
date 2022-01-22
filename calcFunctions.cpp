#include "calculator.h"


double mySqrt( double testVal )
{
    double low = 0;     //lower boundary
    double high;        //upper boundary
    double mid;         //middle index to checked
    int i = 0;

    if (testVal >= 1)
        high = testVal;
    if (testVal < 1 && testVal > 0)
        high = 1;
    if (testVal <= 0)
        return 0;

    while (low <= high && i < ITERATIONMAX)
    {                    //stops loop when low is greater than high or i = 5000
        mid = (low + high) / 2.0;           //computes middle index to be checked

        if (abs( pow( mid, 2 ) - testVal ) <= ERRORVALUE)
            return mid;            //returns mid if its square equals the input
        else if (pow( mid, 2 ) < testVal)
            low = mid + ERRORVALUE;     //changes low boundary if mid^2 < input
        else
            high = mid - ERRORVALUE;   //changes high boundary if mid^2 > input

        i++;
    }

    return mid;
}



double myCbrt( double testVal )
{
    double low = 0;     //lower boundary
    double high;        //upper boundary
    double mid;         //middle index to checked
    int i = 0;

    if (testVal >= 1)
        high = testVal;
    if (testVal < 1 && testVal > 0)
        high = 1;
    if (testVal <= 0)
        return 0;

    while (low <= high && i < ITERATIONMAX)
    {                    //stops loop when low is greater than high or i = 5000
        mid = (low + high) / 2.0;           //computes middle index to be checked

        if (abs( pow( mid, 3 ) - testVal ) <= ERRORVALUE)
            return mid;            //returns mid if its square equals the input
        else if (pow( mid, 3 ) < testVal)
            low = mid + ERRORVALUE;     //changes low boundary if mid^3 < input
        else
            high = mid - ERRORVALUE;   //changes high boundary if mid^3 > input

        i++;
    }

    return mid;
}



double myLog( double testVal, int base )
{
    int i = 0;          //iterates to stop loop after 5000
    double high = 1;    //sets value for upper boundary
    double low;         //declares lower boundary
    double mid;         //declares middle index

    if (testVal == 1)    //log of 1 is always 0
        return 0.0;
    if (testVal < 1 || base < 1)     //log with base or input less than one DNE
        return -1.0;

    while (pow( base, high ) < testVal)    //sets value for high
        high++;                         //where base^high > the input

    if (abs( pow( base, high ) - testVal ) <= ERRORVALUE)
        return high;  //returns high if base^high is equal to the desired value

    low = high - 1; //sets low to high - 1 for small range to check

    while (low <= high && i < ITERATIONMAX)
    {                           //loop breaks when low > high or i > 5000
        mid = (low + high) / 2.0; //computes value between low and high

        if (abs( pow( base, mid ) - testVal ) <= ERRORVALUE)
            return mid;  //returns mid if base^mid is equal to desired value
        else if (pow( base, mid ) < testVal)
            low = mid + ERRORVALUE; //sets low boundary to a litle above mid
        else
            high = mid - ERRORVALUE; //sets high boundart to a little below mid

        i++;    //incraments i with max of 5000
    }

    return mid; //returns best guess for the correct value
}



long long int myFact( int numTerms )
{
    int i;
    long long int total = 1;

    if (numTerms == 0)   //factorial of 0 is eaqual to 1
        return 1;

    for (i = 1; i <= numTerms; i++)
        total = total * i;  //multiplies all numbers under input numTerms

    return total;   //returns final value after everything is multiplied
}



double mySin( double testVal )
{
    int i;
    double term;    //value to be computed and added to total each loop
    double j = 0;
    double result = 0;

    for (i = 1; i <= TERMS * 2; i += 2)//TERMS * 2 because i is incremented by 2
    {
        term = (pow( testVal, i ) / myFact( i )) * pow( (-1), j++ ); //taylor series
        result += term;         //running total of each term
    }

    return result;      //returns the sine of the input
}



double mySinD( double testVal )
{
    int i;
    double term;    //value to be computed and added to total each loop
    double j = 0;
    double result = 0;

    testVal = testVal * (PI / 180);   //convert radians to degrees

    for (i = 1; i <= TERMS * 2; i += 2)
    {
        term = (pow( testVal, i ) / myFact( i )) * pow( (-1), j++ ); //taylor series
        result += term;         //running total of each term
    }
    return result;      //returns the sine of the input
}



double myCos( double testVal )
{
    int i;
    double term;    //value to be computed and added to total each loop
    double j = 0;
    double result = 0;

    for (i = 0; i <= TERMS * 2; i += 2)
    {
        term = (pow( testVal, i ) / myFact( i )) * pow( (-1), j++ ); //taylor series
        result += term;         //running total of each term
    }

    return result;      //returns the cosine of the input
}



double myCosD( double testVal )
{
    int i;
    double term;    //value to be computed and added to total each loop
    double j = 0;
    double result = 0;

    testVal = testVal * (PI / 180);   //convert radians to degrees

    for (i = 0; i <= TERMS * 2; i += 2)
    {
        term = (pow( testVal, i ) / myFact( i )) * pow( (-1), j++ ); //taylor series
        result += term;         //running total of each term
    }
    return result;      //returns the cosine of the input
}



double myTan( double testVal )
{
    double result;  //declare return value

    result = mySin( testVal ) / myCos( testVal );   //tan is equal to sin/cos 

    return result;  //return computed result
}



double myTanD( double testVal )
{
    double result;  //declare return value

    result = mySinD( testVal ) / myCosD( testVal ); //use degree funcitons for tanD

    return result;  //return computed result with degree input
}



void copyArray( double copyTo[], double source[], int size )
{
    int i;  //declare incrementing value

    for (i = 0; i < size; i++)
        copyTo[i] = source[i];  //copy corresponding elements to array
}



void initialArray( double initial[], int size, double initialTo )
{
    int i;  //declare incrementing value

    for (i = 0; i < size; i++)   //stops loop when i passes the max array index
        initial[i] = initialTo; //sets array at the index equal to the input
}



double sumArray( double sumThis[], int size )
{
    int i;
    double total = 0;

    for (i = 0; i < size; i++)   //stops loop when i passes the max array index
        total += sumThis[i];    //running total of each index in the array

    return total;               //return the final total
}


double averageArray( double average[], int size )
{
    double sum;
    double avg;

    sum = sumArray( average, size );  //call sumArray function to get the sum
    avg = sum / size;       //divide the sum by the size to get the average

    return avg;     //return computed average value
}



double minLocation( double array[], int size )
{
    int i;
    int minLoc;
    double minValue;

    minValue = array[0]; //current minimum value is set to the first value
    minLoc = 0;         //location of the minimum value is set to 0

    for (i = 1; i < size; i++)   //stops loop when i passes the max array index
    {
        if (array[i] < minValue)     //compares each index of the array to
        {                               //the current minimum value
            minLoc = i;   //sets current index to minimum location
            minValue = array[i];    //sets current array value to the minimum
        }
    }

    return minLoc;  //returns the location of the minimum value in the array
}



double minValue( double array[], int size )
{
    double minVal;
    int minLoc;

    minLoc = minLocation( array, size );  //calls minLoc function to
                                        //find the index of the minimum value
    minVal = array[minLoc]; //sets minVal to the found index of the given array

    return minVal;  //returns the minimum value
}



double maxLocation( double array[], int size )
{
    int i;
    int maxLoc;
    double maxValue;

    maxValue = array[0]; //current maximum value is set to the first value
    maxLoc = 0;         //location of the maximum value is set to 0

    for (i = 1; i < size; i++)   //stops loop when i passes the max array index
    {
        if (array[i] > maxValue)     //compares each index of the array to
        {                               //the current maximum value
            maxLoc = i;   //sets current index to maximum location
            maxValue = array[i];    //sets current array value to the maximum
        }
    }

    return maxLoc;  //returns the location of the maximum value
}



double maxValue( double array[], int size )
{
    double maxVal;
    int maxLoc;

    maxLoc = maxLocation( array, size );  //calls maxLoc function to
                                        //find the index of the maximum value
    maxVal = array[maxLoc]; //sets maxVal to the found index of the given array

    return maxVal;  //returns the maximum value
}



double countIf( double array[], int size, double item )
{
    int i;
    double total = 0;

    for (i = 0; i < size; i++)
    {
        if (array[i] == item)    //stops loop when i passes the max array index
            total += 1;  //adds one to counter if the value meets credentials
    }

    return total;   //returns final value of the counter
}



void mySort( double sort[], int size, string order )
{
    int i, j;   //i is for outer loop, j is for inner loop
    bool swapMade = true;   //false if no swaps were made and breaks loop

    if (order == "ASC") //runs bubble sort in ascending order if order = "ASC"
    {
        for (i = 0; i < size - 1 && swapMade == true; i++)
        {   //require swapMade = true, size - 1 to not overstep boundaries
            swapMade = false;   //sets swapMade to false to break loop

            for (j = 0; j < size - 1 - i; j++)
            {   //size - 1 - i to not compare terms we know are in order
                if (sort[j] > sort[j + 1]) //compares one value to the next
                {
                    swap( sort[j], sort[j + 1] );//swaps if left index is greater
                    swapMade = true;  //sets swapMade to true to continue loop
                }
            }
        }
    }
    else if (order == "DSC") //sorts in descending order if order = "DSC"
    {
        for (i = 0; i < size - 1 && swapMade == true; i++)
        {   //same code as ascending order except if statement
            swapMade = false;

            for (j = 0; j < size - 1 - i; j++)
            {
                if (sort[j] < sort[j + 1])   //requires left index to be smaller
                {
                    swap( sort[j], sort[j + 1] );
                    swapMade = true;
                }
            }
        }
    }
}



double linearSearch( double search[], int size, double tgt )
{
    int i;

    for (i = 0; i < size; i++)   //stops loop when i passes the max array index
    {
        if (search[i] == tgt)
            return i;           //returns index if its value = target value
    }

    return -1;  //returns -1 if target value is not found in the array
}



double binarySearch( double search[], int size, double tgt )
{
    int left = 0;   //left boundary is set to the beginning of array
    int right = size - 1;   //right boundary is set to the end of array
    int mid;

    mySort( search, size, "ASC" );    //binary search requires a sorted array

    while (left <= right) //breaks loop when left boundary is greater than right
    {
        mid = (left + right) / 2;   //compute middle index between boundaries

        if (search[mid] == tgt)
            return mid;         //returns middle index if its equal to target
        else if (search[mid] < tgt)
            left = mid + 1;     //sets left = mid + 1 if tgt > mid index
        else
            right = mid - 1;    //sets right = mid - 1 if tgt < mid index
    }

    return -1;  //returns -1 if target value is not found in the array
}