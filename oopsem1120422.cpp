// oopsem1120422.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Date {
private:
    unsigned int mYear;
    unsigned char mMonth;
    unsigned char mDay;

public:
    Date() : mYear(0), mMonth(0), mDay(0) {}
    
    Date(unsigned int year, unsigned char month, unsigned char day) : mYear(year), mMonth(month), mDay(day) {}

    Date add(unsigned int year) {
        return Date(mYear + year, mMonth, mDay);
    }

    Date operator+(unsigned int year) {
        return Date(mYear + year, mMonth, mDay);
    }

    Date operator-(unsigned int year) {
        return Date(mYear - year, mMonth, mDay);
    }

    friend std::ostream& operator<<(std::ostream& outputStream, const Date& date);
    friend istream& operator>>(istream& inputStream, Date& date);
};

std::ostream& operator<<(std::ostream& outputStream, const Date& date) {
    outputStream << date.mYear << "." << static_cast<unsigned int>(date.mMonth) << "." << static_cast<unsigned int>(date.mDay) << std::endl;
    return outputStream;
}

istream& operator>>(istream& inputStream, Date& date) {
    inputStream >> date.mYear >> date.mMonth >> date.mDay;
    return inputStream;
}

enum PlaneType {
    FIGHTER,
    AIRLINER
};

class Plane {
private:
    unsigned int mSerialNumber;
    Date mProductionDate;
    PlaneType mPlaneType;

public:
    Plane() : mSerialNumber(0), mProductionDate(Date()), mPlaneType(FIGHTER) {}
    
    Plane(unsigned int serialNumber, const Date& productionDate, PlaneType planeType) :
        mSerialNumber(serialNumber), mProductionDate(productionDate), mPlaneType(planeType) {}

    friend ostream& operator<<(ostream& outputStream, const Plane& plane);
    friend istream& operator>>(istream& inputStream, Plane& plane);
};

ostream& operator<<(ostream& outputStream, const Plane& plane) {
    outputStream << "Plane: " << ((plane.mPlaneType == FIGHTER) ? "Fighter" : "Airliner") << "\nPrduction Date: " << plane.mProductionDate << "\nSerial Number: " << plane.mSerialNumber << endl;
    return outputStream;
}

istream& operator>>(istream& inputStream, Plane& plane) {
    inputStream >> plane.mPlaneType >> plane.mProductionDate >> plane.mSerialNumber;
    return inputStream;
}

int main()
{
    Date date(2022, 4, 12);
    std::cout << date << std::endl;

    Date dateTwo = date + 20;
    std::cout << date;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
