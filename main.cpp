#include <iostream>
#include "functions.h"
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main() {
    ofstream stream("../Results.csv");

    ifstream carfile;
    carfile.open("../CarsTable.csv");
    vector<vector<string>> cars;  //creates a vector for the carfile
    ifstream userfile;
    userfile.open("../UsersTable.csv");
    cars = readTable(carfile); //gets the carfile
    vector<vector<string>> ppl;  //creates a vector for the people file
    ppl = readTable(userfile); //gets the pplfile
    vector<vector<string>> combine; //vector to combine the two
    combine = innerJoin(ppl, cars);  //gets the function that combines the two
    writeTable(stream, combine); //this displays the table


return 0;

}



