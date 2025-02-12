//
// Created by kmurphy on 5/1/2023.
//

#include "LogItem.h"
#include <iostream>
#include <iomanip>

LogItem::LogItem(Food food, int quantity) {
    food_ = food;
    SetQuantity(quantity);

}

int LogItem::GetTotalCalories() const {
    return food_.GetCalories() * quantity_;
}

double LogItem::GetTotalGrams() const {
    return food_.GetGrams() * quantity_;
}

double LogItem::GetTotalOz() const {
    return food_.GetOz() * quantity_;
}



void LogItem::SetFood(Food f){
    food_ = f;
}
void LogItem::SetQuantity(int quantity){
    if(quantity < 0){
        quantity_ = 0;
    }
    else{
        quantity_ = quantity;
    }
}

void LogItem::Print()const{
    std::cout << "Food: " << food_.GetName() << " Qty: " << quantity_ << "  Total Cal: " << GetTotalCalories();
}

std::ostream& operator<<(std::ostream & out, const LogItem & logItem){
    out << std::left << std::setw(30) << logItem.food_.GetName();
    out << std::right << std::setw(2) << logItem.quantity_;
    out << std::left << std::setw(3) << "x";
    out << std::right << std::setw(5) << logItem.GetTotalCalories();

    return out;
}

LogItem LogItem::operator +(const LogItem &rhs)const{
    LogItem temp;
    temp.food_ = food_;
    if(food_ == rhs.food_){
        temp.quantity_ = quantity_ + rhs.quantity_;
    }
    else{
        throw "mismatching food items";
    }
    return temp;
}

void LogItem::operator += (const LogItem &rhs){

    if(food_ == rhs.food_){
        quantity_ = quantity_ + rhs.quantity_;
    }
    else{
        throw "mismatching food items";
    }

}

LogItem LogItem::operator + (int quantity) const{
    return LogItem(food_, quantity + quantity_);
}
LogItem LogItem:: operator - (int quantity) const{

    int amount = 0;
    if(quantity_ > quantity){
        amount = quantity_ + quantity;
    }
    else{
        throw "Cannot complete action";
    }
    return LogItem(food_, quantity_ - quantity);
}

LogItem operator+(int quantity, LogItem & rhs){
    return LogItem(rhs.food_, rhs.quantity_ + quantity);
}