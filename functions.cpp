#include "functions.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<vector<string>> readTable(ifstream &file) {

int pos1=0;
int pos2 =0;
string vas1;
vector<string> row;     //single vector
vector<vector<string>> infoVect; //double vector
while(!file.eof()){
   getline(file, vas1);
while(true) {//split the line
    pos2 = vas1.find(",", pos1);  //Looks for comma
    row.push_back(vas1.substr(pos1, pos2 - pos1)); //puts the information in the vector
    pos1 = pos2 + 1;
if (pos2 == string::npos)
     break;
}
    infoVect.push_back(row); //puts one vector in the other
     row.clear();
}
    file.close(); //closes the file
    return infoVect;  //returns the vector
}




void writeTable(ofstream &file, vector<vector<string>> &table) {
    file<<"ID,NAME,AGE,MAKE,MODEL,YEAR"<<endl; //Gives the headings of the file
    for (int i =0; i<table.size(); i++) {  //Goes down the array
        for (int j = 0; j <table[i].size()-1; j++) {  //goes across the array at each i
            file << table[i][j] << ","; //gives file the information in the table
        }
        file << table[i][table[i].size()-1] <<endl; //gets rid of comma at the end
    }
}

vector<vector<string>> innerJoin(vector<vector<string>> leftTable, vector<vector<string>> rightTable) {

    vector<string> row;
    vector< vector<string>> joinedTable; //creates the joint array

    for(int i =1; i <leftTable.size();i++) {    //number of rows
        for(int j = 1; j < rightTable.size(); j++) {
            if (leftTable[i][0].compare( rightTable[j][0])==0) { //if the id numbers match
                for(int k = 0; k < leftTable[i].size(); k++) {
                    if(k==leftTable[i].size()-1){
                        int temp = stoi(leftTable[i][k]);
                        leftTable[i][k]= to_string(temp);
                    }
                    row.push_back(leftTable[i][k]);
                }
                for(int k = 1; k <rightTable[i].size() ; k++) {
                    row.push_back(rightTable[j][k]);
                }

            }
            if(row.size()>0)
                joinedTable.push_back(row);  //the joinedTable array gets the line array
            row.clear();
        }


    }
    return joinedTable;//returns joined table
}