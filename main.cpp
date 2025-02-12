//Declare header files
//Declare namespaces
#include <iostream>
#include "Logger.h"
#include "Food.h"
#include "LogItem.h"
/*
 * @file main.cpp
 * @brief Practice using Pointers
 * @author Jaden Burks
 * @date 02/10/25
*/
using namespace std;
int main()
{
    string FILE;  //creating variable for the file

    cout << "Hello, What file would you like to calculate?" << endl; //asking for said file name
    cin >> FILE;  //putting that info into the variable
    Logger Logger(FILE);  //activating the logger function that has the loaddata and the total calories functions

    cout << "Items for the day:" << endl;
    cout << Logger; //listing the items

    cout << "Calorie count: " << Logger.GetCalorieCount() << endl; //listing total calorie count

    return 0;
}
