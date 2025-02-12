#include "Logger.h"
#include <array>
#include <iostream>
#include <fstream>
// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
//for floating point numbers
using namespace Catch::Matchers::Floating;

TEST_CASE("Checking Items in the list")
{
    INFO("Checks that the Logger class has the operator[] and that it returns the correct file information")
    Logger l("../../tests/DailyIntakeTest.csv");
    bool check = false;
    Food f1("Salmon", 412, 198);
    Food f2("Rice", 206, 158);
    Food f3("Broccoli", 50, 148);
    Food f4("Butter", 102, 14);
    check = l[0]->GetFood() == f1;
    CHECK( check == true);
    check = l[1]->GetFood() == f2;
    CHECK( check == true);
    check = l[2]->GetFood() == f3;
    CHECK( check == true);
    check = l[3]->GetFood() == f4;
    CHECK( check == true);
    check = false;

}


TEST_CASE("Checking the exception")
{
    INFO("Checks that the [] throws an exception when a given value is larger than the size, or smaller than 0")
    Logger l("../../tests/DailyIntakeTest.csv");
    bool check = false;

    try{
        l[4]->GetFood();
    }
    catch(std::exception &e){
        check = true;
    }
    CHECK( check == true);
}


TEST_CASE("Checking the Calorie Count")
{
    INFO("Checks that an email has the characters @ and . and the @ comes first in the string")
    Logger l("../../tests/DailyIntakeTest.csv");
    int calories = l.GetCalorieCount();
    bool check = (calories == 922);


    CHECK( check == true);
}