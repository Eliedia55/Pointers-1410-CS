
#ifndef LOGGER_H
#define LOGGER_H
#include<iostream>
#include<memory>
#include <vector>
#include <fstream>
#include "LogItem.h"


class Logger {
private:
    std::vector<std::shared_ptr <LogItem>> items_;
    int totalCalories_;

public:
    Logger(std::string fileName);
    void LoadData(const std::string& fileName);
    std::shared_ptr<LogItem> operator[](int index);
    int GetCalorieCount();

    friend std::ostream& operator<<(std::ostream& out, Logger& write);
};

#endif  //LOGGER_H
