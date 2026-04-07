#include <iostream>
using namespace std;

// Forward declaration of class BallsFaced for friend function
class BallsFaced;

class Runs {
private:
    int runs;

public:
    Runs(int r) {
        runs = r;
    }

    // Declare friend function
    friend double calculateStrikeRate(Runs r, BallsFaced b);
};

class BallsFaced {
private:
    int balls;

public:
    BallsFaced(int b) {
        balls = b;
    }

    // Declare friend function
    friend double calculateStrikeRate(Runs r, BallsFaced b);
};

// Friend function to calculate strike rate
double calculateStrikeRate(Runs r, BallsFaced b) {
    if (b.balls == 0) return 0; // Avoid division by zero
    return (static_cast<double>(r.runs) / b.balls) * 100;
}

int main() {
    Runs playerRuns(85);        // 85 runs
    BallsFaced playerBalls(60); // 60 balls

    double strikeRate = calculateStrikeRate(playerRuns, playerBalls);

    cout << "Strike Rate: " << strikeRate << endl;

    return 0;
}
