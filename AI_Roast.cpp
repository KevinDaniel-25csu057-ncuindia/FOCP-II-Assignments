#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to replace {name} with actual user input
string replaceName(string roast, string name) {

    size_t pos = roast.find("{name}");

    while (pos != string::npos) {

        roast.replace(pos, 6, name);

        pos = roast.find("{name}");
    }

    return roast;
}

int main() {

    string name;

    // Get user input
    cout << "Enter your name: ";
    getline(cin, name);

    // Validate input
    if (name.empty()) {

        cout << "Please enter a valid name." << endl;

        return 0;
    }

    // Roast templates
    vector<string> roasts = {

        "{name}'s assignment submission speed is slower than college WiFi during exams.",

        "{name} writes code with so many bugs that even antivirus software gets confused.",

        "If sleeping in class were a profession, {name} would already be CEO.",

        "{name}'s debugging strategy is refreshing the page and hoping for a miracle.",

        "{name} studies one night before exams and still asks why life is unfair.",

        "{name}'s code works perfectly... only in their imagination.",

        "Even ChatGPT needs extra processing time to understand {name}'s logic.",

        "{name} opens VS Code just to change the theme and close it again.",

        "{name}'s attendance is so low that even the faculty forgot their face.",

        "{name} treats deadlines like movie release dates — always waiting for the sequel."
    };

    // Initialize random generator
    srand(time(0) + clock());

    // Generate random roast index
    int randomIndex = rand() % roasts.size();

    // Get selected roast
    string finalRoast = roasts[randomIndex];

    // Replace placeholder with user name
    finalRoast = replaceName(finalRoast, name);

    // Display output
    cout << "\nFunny Roast:\n";
    cout << finalRoast << endl;

    return 0;
}