#include <iostream>
using namespace std;

class TrafficSystem {
private:
    int carCount;
    int delayMinutes; // Optional for multiplication scenario

public:
    // Constructor
    TrafficSystem(int cars = 0, int delay = 0) {
        carCount = cars;
        delayMinutes = delay;
    }

    // Overload + operator (adding cars)
    TrafficSystem operator+(const TrafficSystem& other) {
        return TrafficSystem(carCount + other.carCount, delayMinutes + other.delayMinutes);
    }

    // Overload - operator (removing cars)
    TrafficSystem operator-(const TrafficSystem& other) {
        return TrafficSystem(carCount - other.carCount, delayMinutes - other.delayMinutes);
    }

    // Overload * operator (doubling delay)
    TrafficSystem operator*(const TrafficSystem& other) {
        return TrafficSystem(carCount * other.carCount, delayMinutes * other.delayMinutes);
    }

    // Overload == operator (check traffic equality)
    bool operator==(const TrafficSystem& other) {
        return (carCount == other.carCount && delayMinutes == other.delayMinutes);
    }

    // Display function
    void display() {
        cout << "Cars: " << carCount << ", Delay: " << delayMinutes << " minutes" << endl;
    }
};

int main() {
    TrafficSystem roadA(50, 5);
    TrafficSystem roadB(20, 5);
    TrafficSystem roadC(15, 0);
    TrafficSystem roadD(0, 2);

    cout << "Initial Traffic Road A: ";
    roadA.display();
    cout << "Initial Traffic Road B: ";
    roadB.display();

    cout << "\nAdding cars from Road B to Road A: ";
    TrafficSystem totalTraffic = roadA + roadB;
    totalTraffic.display();

    cout << "\nRemoving 15 cars: ";
    TrafficSystem easedTraffic = totalTraffic - roadC;
    easedTraffic.display();

    cout << "\nDoubling delay due to signal failure: ";
    TrafficSystem doubledDelay = easedTraffic * roadD;
    doubledDelay.display();

    cout << "\nChecking for gridlock: ";
    if (TrafficSystem(100, 0) == TrafficSystem(100, 0))
        cout << "Gridlock detected!" << endl;
    else
        cout << "Traffic moving fine." << endl;

    return 0;
}
