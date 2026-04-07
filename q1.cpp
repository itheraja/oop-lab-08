#include <iostream>
using namespace std;

// Forward declaration of class Time for friend function
class Time;

class Speed {
private:
    double speed; // km/h

public:
    Speed(double s) {
        speed = s;
    }

    // Declare friend function
    friend double calculateDistance(Speed s, Time t);
};

class Time {
private:
    double hours;

public:
    Time(double h) {
        hours = h;
    }

    // Declare friend function
    friend double calculateDistance(Speed s, Time t);
};

// Friend function to calculate distance
double calculateDistance(Speed s, Time t) {
    return s.speed * t.hours;
}

int main() {
    Speed mySpeed(60);   // 60 km/h
    Time travelTime(2);  // 2 hours

    double distance = calculateDistance(mySpeed, travelTime);

    cout << "Distance traveled: " << distance << " km" << endl;

    return 0;
}
