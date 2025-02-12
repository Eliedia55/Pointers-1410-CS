#ifndef FOOD_H
#define FOOD_H
#include <string>

class Food {

private:
    static const double GRAMS_IN_OZ;

    std::string name_;
    int calories_;
    double grams_;
    double oz_;

public:
    //Default constructor
    Food() : name_("no name"), calories_(0), grams_(0), oz_(0) {}
    //General constructor
    Food(std::string name, int calories, double grams = 0);

    //Setters
    void SetName(std::string name);
    void SetCalories(int);
    void SetGrams(double);

    //Getters
    std::string GetName() const { return name_; }
    int GetCalories() const { return calories_; }
    double GetGrams() const { return grams_; }
    double GetOz() const { return oz_; }

    //other methods
    void Print() const;

private:
    void SetOz();

public:
    bool operator==(const Food &rhs) const;

    //inserter & extractor
    friend std::ostream& operator<<(std::ostream &out, Food &food);
    friend std::istream& operator>>(std::istream &out, Food &food);

};

#endif