
//Declare header files
//Declare namespaces, if any
//Function definitions go in this file

#include <algorithm>
#include "Logger.h"
#include "Food.h"
#include "LogItem.h"
#include <sstream>

using namespace std;

Logger::Logger(std::string fileName) {
    LoadData(fileName);
    totalCalories_ = GetCalorieCount();
}

/**
 * reads and organizes data from a selected file
 * @param fileName gets the name of file we are reading from
 */
void Logger::LoadData(const std::string& fileName) {
    ifstream file(fileName);
    string temp;

    while(getline(file, temp)) {
        stringstream ss(temp);
        string foodName;
        int calories;
        int grams;
        int servings;

        getline(ss, foodName, ',');
        getline(ss, temp, ','); //calories
        calories = stoi(temp);

        getline(ss, temp, ','); //grams
        grams = stoi(temp);

        getline(ss, temp); //servings
        servings = stoi(temp);

        Food food(foodName, calories, grams);
        auto ItemLogged = make_shared<LogItem>(food, servings);
        items_.push_back(ItemLogged);
    }//end of while loop
    file.close();
}

/**
 *  return value at a given position
 * @param index  that represents the position in the list to be retrieved.
 * @return   return the given position in the vector.
 * It will throw an std::out_of_range() error if the parameter given is not within the bounds of the vector.
 */
shared_ptr<LogItem> Logger::operator[](int index) {
    if (index < 0 || index >= items_.size()) {
        throw out_of_range("index out of range");
    }
    return items_[index];
}

int Logger::GetCalorieCount() {
    int total = 0;
    for (const auto& ItemLogged : items_) {
        total += ItemLogged->GetTotalCalories();
    }
    return total;
}

ostream& operator<<(ostream& out, Logger& write) {
    for (auto& ItemLogged : write.items_) {
        out << ItemLogged->GetFood().GetName()
        << '\t' << ItemLogged->GetQuantity()
        << ItemLogged->GetTotalCalories() << '\n';
    }
    return out;
}

