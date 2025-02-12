//
// Created by kmurphy on 5/1/2023.
//

#ifndef LOGITEM_H
#define LOGITEM_H
#include "Food.h"

class LogItem {
private:
    Food food_;
    int quantity_;

public:
    LogItem() : food_(), quantity_(0){}
    LogItem(Food, int);
    Food GetFood() const {return food_; }
    int GetQuantity() const { return quantity_; }

    int GetTotalCalories() const;
    double GetTotalGrams() const;
    double GetTotalOz() const;

    void SetFood(Food f);
    void SetQuantity(int quantity);
    void Print()const;
    friend std::ostream& operator<<(std::ostream & out, const LogItem & item);
    LogItem operator +(const LogItem &rhs)const;
    void operator += (const LogItem &rhs);
    LogItem operator + (int quantity) const;
    LogItem operator - (int quantity) const;
    friend LogItem operator+(int quantity, LogItem & rhs);
};


#endif //LOGITEM_H
