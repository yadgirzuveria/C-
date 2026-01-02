#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int secret, guess;

    // Seed random number
    srand(time(0));

    // Random number between 1 and 100
    secret = rand() % 100 + 1;

    cout << "Guess a number between 1 and 100:\n";

    while(true) {
        cin >> guess;

        if(guess > secret) {
            cout << "Too high! Try again: ";
        }
        else if(guess < secret) {
            cout << "Too low! Try again: ";
        }
        else {
            cout << "?? Correct! You guessed the number!";
            break;
        }
    }

    return 0;
}

