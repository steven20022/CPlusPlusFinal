#include <iostream>
#include <stdexcept> // needed to throw exceptions
#include <iomanip>   // needed to format output
#include "Calculator.h"

// use C++ standard libary namespace
using namespace std;

// The BMI class includes methods that calculate
// body mass index (BMI) for a person using the person's height
// in inches and weight in pounds.
class BMI : Calculator
{
    private:
        // Field is used to store the person's height.
        double height;
        // Field is used to store the person's weight.
        double weight;
        // Field is used to store the person's BMI.
        double bmi;
    public:
        // This constructor sets height, weight and 
        // bmi to zero.
        BMI();
        // This constructor sets height to the specified double
        // and weight to the specified double and it calculates
        // bmi. 
        // This constructor throws an exception if the specified
        // height or weight is less than or equal to zero.
        BMI(double, double);
        // This method sets height to the specified double and
        // it calculates bmi.
        // This method throws an exception if the specified
        // height is less than or equal to zero.
        void setHeight(double);
        // This method sets weight to the specified double and
        // it calculates bmi.
        // This method throws an exception if the specified
        // weight is less than or equal to zero.
        void setWeight(double);
        // This method returns the height, weight, and bmi by assigning
        // their values to the specified double numbers.
        void getBMI(double&, double&, double&) const;
        // This method calculates BMI and assigns the calculated value to bmi.
        // The formula to calculate BMI is:
        // (weight / (height * height)) * 703
        // where weight is in pounds and height is in inches.
        void calculate() override;
        // This method displays the height, weight, and bmi fields to
        // stdout formatted as weight=NNN.NNN, height=NNN.NNN, BMI=NNN.NNN.
        void printBMI() const;
        // This method returns 1 if this BMI is equal to
        // the specified BMI, else it returns 0
        bool equalBMI(const BMI&) const;
};

BMI::BMI(){
    height = 0;
    weight = 0;
    bmi = 0;
}

BMI::BMI(double height, double weight){
    if (height < 0)
    {
        throw invalid_argument("Height must be greater than zero");
    }
    if (weight < 0)
    {
        throw invalid_argument("Weight must be greater than zero");
    }
    this->height = height;
    this->weight = weight;
    calculate();
}

void BMI::setHeight(double height){
    if (height < 0)
    {
        throw invalid_argument("Height must be greater than zero");
    }
    this->height = height;
    calculate();
}
void BMI::setWeight(double weight){
    if (weight < 0)
    {
        throw invalid_argument("Weight must be greater than zero");
    }
    this->weight = weight;
    calculate();
}
void BMI::getBMI(double& height, double& weight, double& bmi) const{
    height = this->height;
    weight = this->weight;
    bmi = this->bmi;
}
void BMI::calculate() {
    bmi = (weight / (height * height)) * 703;
}
void BMI::printBMI() const{
    cout << fixed << showpoint;
    cout << setprecision(3);
    cout << "height = " << height << ", weight = " << weight << ", bmi = " << bmi << endl;
}
bool BMI::equalBMI(const BMI& otherBMI) const{
    return ((height == otherBMI.height) && (weight == otherBMI.weight) && (bmi == otherBMI.bmi));
}
