#include<iostream>
#include<fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <string>
/**
 * TO DO:
 * Add <vector>, <cstdlib>, and <ctime>​
 */

using namespace std;

/**
 * TO DO:
 * Create function prototypes for all the functions.
 * Write their function declarations below mai()).
 *
 * See promptFile(...) and printVec(...), which serve as examples.
 *
 */


 //------------------------PROTOTYPE-------------------------------------------
void promptFile(vector<string>&);
void printVec(vector<string>);
int ranGen(int questionCount);
bool readFile(string filename, vector<string>& vec);
bool writeFile(string filename, const vector<string>& v0,
    const vector<string>& v1);

int main()
{
    vector<string> roster;
    vector<string> qBank;
    if (!readFile("2310_F26_Rosters.csv", roster)) {
        return 1;
    }

    if (!readFile("Questions.csv", qBank)) {
        return 1;
    }

    if (!writeFile("Student_question_bank.csv", roster, qBank)) {
        return 1;
    }

    // printVec(roster);
    // printVec(qBank);

    // cout << "Size of roster: " << roster.size() << endl; 
    // cout << "Size of qBank: " << qBank.size() << endl;

    cout << "Student_question_bank.csv was created successfully." << endl;
    return 0;

}

//------------------------DECLARATIONS-------------------------------------------
/**
 * @brief randomly returns a number from 0 to 5.
 * - It is hardcoded to be from 0 to 5.
 * - Uses srand(nullptr) in main()
 * TO DO:
 * Modify it so that randGen() reads in
 * the size of the questions instead of 6 (e.g. questions.size())
 *
 * TO DO:
 * Use <random> for modern C++ random generation instead
 *
 * @return int: index of question
 */
int ranGen(int questionCount) {
    static random_device rd;
    static mt19937 generator(rd());

    uniform_int_distribution<int> distribution(0, questionCount - 1);

    return distribution(generator);
}

/**
 * @brief reads contents of filename and populates into vec
 *
 * @param filename :string
 * @param vec: vector<string> &
 *
 * TO DO:
 * ​​​Return a bool instead in order to indicate whether the operation
 * succeeded or not
 */
bool readFile(string filename, vector<string>& vec) {

    ifstream inputFile(filename);

    //error handling
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file\n";
        return false;
    }

    string line;

    while (getline(inputFile, line)) {
        vec.push_back(line);
    }

    inputFile.close();
    return true;
}

/**
 * @brief writes to filename with the first column from v0, second column from v1
 *
 * @param filename: string
 * @param v0: vector<string> (for students names)
 * @param v1: vector<string> (for questions)
 *
 * TO DO:
 * ​​​Return a bool instead in order to indicate whether the operation
 * succeeded or not
 *
 * TO DO:
 * ​​Use pass by const reference (const vector<string> & v0, const vector<string> & v1)
 * as opposed to pass by value (vector<string> v0, vector<string> v1).
 *
 * What is the differennce between:
 * -  pass by reference (e.g. vector<string> & v0),
 * -  pass by value (e.g. vector<string> v0),
 * -  pass by const reference (e.g. const vector<string> & v0),
 */
bool writeFile(string filename, const vector<string>& v0,
    const vector<string>& v1) {

    if (v1.empty()) {
        cerr << "Error: The question bank is empty." << endl;
        return false;
    }

    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cerr << "Error: File could not create " << filename << endl;
        return false;
    }

    for (size_t i = 0; i < v0.size(); i++) {
        outputFile << v0[i] << ","
            << v1[ranGen(static_cast<int>(v1.size()))]
            << endl;
    }

    outputFile.close();
    return true;
}

/**
* @brief prompts the user to give a file to read
*
*/
void promptFile(vector<string>& v) {
    cout << "file to read?\n";
    string myFile = "";
    cin >> myFile;
    readFile(myFile, v);
}


/**
 * @brief prints out the elements in v
 *
 * @param v: vector<string>
 */
void printVec(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}
