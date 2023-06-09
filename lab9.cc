#include <iostream>
#include <fstream>

using namespace std;

// function declarations
int getLowest(int dailyLow[]);
int getHighest(int dailyLow[]);
double getAverage(int dailyLow[]);

int main() {
    // declare array to hold daily low temperatures
    int dailyLow[30];

    // open data file and read daily lows into array
    ifstream infile("athens_low_temps.txt");
    if (infile.fail()) {
        cout << "Failed to open file.\n";
        return 1;
    }
    for (int i = 0; i < 30; i++) {
        infile >> dailyLow[i];
    }

    // call functions to get lowest, highest, and average daily low temperatures
    int lowest = getLowest(dailyLow);
    int highest = getHighest(dailyLow);
    double average = getAverage(dailyLow);

    // output results to terminal
    cout << "Lowest daily low temperature: " << lowest << endl;
    cout << "Highest daily low temperature: " << highest << endl;
    cout << "Average daily low temperature: " << average << endl;

    // output results to text file
    ofstream outfile("results.txt");
    if (outfile.fail()) {
        cout << "Failed to open file.\n";
        return 1;
    }
    outfile << "Lowest daily low temperature: " << lowest << endl;
    outfile << "Highest daily low temperature: " << highest << endl;
    outfile << "Average daily low temperature: " << average << endl;
    outfile.close();

    return 0;
}

// function to get lowest daily low temperature
int getLowest(int dailyLow[]) {
    int lowest = dailyLow[0];
    for (int i = 1; i < 30; i++) {
        if (dailyLow[i] < lowest) {
            lowest = dailyLow[i];
        }
    }
    return lowest;
}

// function to get highest daily low temperature
int getHighest(int dailyLow[]) {
    int highest = dailyLow[0];
    for (int i = 1; i < 30; i++) {
        if (dailyLow[i] > highest) {
            highest = dailyLow[i];
        }
    }
    return highest;
}

// function to get average daily low temperature
double getAverage(int dailyLow[]) {
    int sum = 0;
    for (int i = 0; i < 30; i++) {
        sum += dailyLow[i];
    }
    double average = static_cast<double>(sum) / 30;
    return average;
}