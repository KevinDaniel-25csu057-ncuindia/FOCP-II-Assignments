#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to replace {name} with actual student name
string replaceName(string excuse, string name) {

    size_t pos = excuse.find("{name}");

    while (pos != string::npos) {

        excuse.replace(pos, 6, name);

        pos = excuse.find("{name}");
    }

    return excuse;
}

// Function to display a random excuse
void generateExcuse(string name, vector<string> &excuses) {

    // Generate random index
    int randomIndex = rand() % excuses.size();

    // Select random excuse
    string finalExcuse = excuses[randomIndex];

    // Replace placeholder with user name
    finalExcuse = replaceName(finalExcuse, name);

    // Display excuse
    cout << "\nGenerated Excuse:\n";
    cout << finalExcuse << endl;
}

int main() {

    string name;

    // Ask user for input
    cout << "Enter student name: ";
    getline(cin, name);

    // Validate input
    if (name.empty()) {

        cout << "Please enter a valid name." << endl;

        return 0;
    }

    // Store excuse templates
    vector<string> excuses = {

        "{name} couldn't submit the assignment because the laptop started updating right before the deadline.",

        "{name} was about to finish the homework when the WiFi suddenly disappeared for three hours.",

        "{name} spent the entire night debugging the wrong file by mistake.",

        "{name}'s project folder mysteriously vanished moments before submission.",

        "{name} tried completing the lab record, but the compiler produced errors nobody had ever seen before.",

        "{name} planned to start the assignment early but accidentally started watching coding memes instead.",

        "{name}'s system froze exactly when the final version of the project was ready.",

        "{name} completed the assignment mentally, but unfortunately forgot to type it.",

        "{name} opened the assignment at 8 PM and somehow ended up reorganizing desktop folders until midnight.",

        "{name}'s internet speed during submission time was slower than a loading bar in a lab computer."
    };

    // Initialize random generator
    srand(time(0) + clock());

    // Generate and display excuse
    generateExcuse(name, excuses);

    return 0;
}