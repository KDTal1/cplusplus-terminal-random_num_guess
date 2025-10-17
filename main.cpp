/*
Number Guessing Game!

Win the game with a total score of 50 to win.

Initial finish: 10/17/2025 - 4:32 PM GMT+8
*/

#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <string>
#include <random>

using namespace std;

int randomNumber() { // Sets up the randomizer for the guessing game.
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10);

    return dist(gen);
}

void clear() { // Clears the screen.
#ifdef _WIN32 // It first checks if the operating system is Windows-based, thus initializes a bool variable to true.
    const bool isWindows = true;
#else
    const bool isWindows = false;
#endif

    if (isWindows) // If the operating system is Windows, it will run cls.
        system("cls");
    else // otherwise.
        system("clear");
}

void nice_messages() {
    string message[] = {
        "Good job!",
        "You're doing great!",
        "Amazing!",
        "Good guess!",
        "Egg.",
        "Good call.",
        "There is a chance that you get it right again",
        "Right!",
        "Next number!",
        "Woah, that's a good guess!"
    };

    cout << message[randomNumber() - 1] << endl;
}

int main() {
    int userGuess, programNum, score;
    srand(time(0)); 
    score = 0;

    while (score != 50) {
        clear();
        programNum = randomNumber(); // Initializes through the randomizer
        cout << "!!!  NUMBER GUESSING GAME  !!!\nGet to the total score of 50 to win!" << endl;
        cout << string(45, '=') << endl;
        cout << "Current score: " << score << endl;
        cout << "Guess what number from 1 - 10 am I thinking right now: ";
        cin >> userGuess;

        if (!cin) { // Runs when the input is not a number, or integer
            cout << string(45, '=') << endl;
            cout << "Is this actually a number?" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        if (userGuess == programNum) { // Main program
            cout << string(45, '=') << endl;
            cout << "You are correct!" << endl;
            nice_messages(); // Messages given to the user when they got the number right.
            score++;
        } else {
            cout << string(45, '=') << endl;
            cout << "Sorry, try again!" << endl; // Tells the user to try again if they failed.
        }
        cout << string(45, '=') << endl;
        cout << "Updated score! It is now " << score << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
    clear();
    cout << string(45, '=') << endl;
    cout << "Thank you for playing, see you next time" << endl;
    cout << string(45, '=') << endl;
    this_thread::sleep_for(chrono::seconds(1));

    return 0;
}