#include "Food.h"
#include <iostream>

const double Food::GRAMS_IN_OZ = 28.3495;

/*
 * @brief general constructor, accepts user given name, calories, & grams
 * @remark uses setters for numerical values to  guard member variables from unusable parameters
 */
Food::Food(std::string name, int calories, double grams)
{
    name_ = name;
    SetCalories(calories);
    SetGrams(grams);
}

/*
 * @brief set the member variable name_ to user chosen value
 */
void Food::SetName(std::string name)
{
    name_ = name;
}

/*
 * @brief set the member variable calories_ to user chosen value
 * @remark does not allow the user to input a value less than 0
 * @param integer user chosen number of calories
 */
void Food::SetCalories(int calories)
{
    if(calories < 0)
        calories_ = 0;
    else
        calories_ = calories;
}

/*
 * @brief set the member variable grams_ to user chosen value
 * @remark does not allow the user to input a value less than 0
 *      then sets the oz_ member variable
 * @param double user chosen amount in grams
 */
void Food::SetGrams(double grams)
{
    if(grams < 0)
        grams_ = 0;
    else
        grams_ = grams;

    SetOz();
}

/*
 * @brief set the member variable oz_ to user chosen value
 * @remark does not allow the user to input a value less than 0
 */
void Food::SetOz()
{
    if(grams_ <= 0)
        oz_ = 0;
    else
        oz_ = grams_ / GRAMS_IN_OZ;
}

/*
 * @brief Prints member variables
 */
void Food::Print() const
{
    std::cout << "Name: " << name_ << " Grams: " << grams_ << " Oz: " << oz_ << " Calories: " << calories_ << std::endl;
}

/*
 * @brief checks for equality of each member variable
 * @param Food reference
 */
bool Food::operator==(const Food &rhs) const
{
    return name_ == rhs.name_ && calories_ == rhs.calories_ && grams_ == rhs.grams_;
}

/*
 * @brief uses ostream to print member variables
 * @param ostream reference
 * @param Food reference
 */
std::ostream& operator<<(std::ostream &out, Food &food)
{
    out << "Name: " << food.name_ << " Grams: " << food.grams_ << " Oz: " << food.oz_ << " Calories: " << food.calories_ << std::endl;
    return out;
}

/*
 * @brief uses istream to set member variables
 * @param istream reference
 * @param Food reference
 */
std::istream& operator>>(std::istream &in, Food &food)
{
    std::cout << "Name:";
    in >> food.name_;
    std::cout << "Calories:";
    in >> food.calories_;
    std::cout << "Grams:";
    in >> food.grams_;
    food.SetOz();

    return in;
}
