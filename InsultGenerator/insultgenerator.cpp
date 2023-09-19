//
//  insultgenerator.cpp
//
//
//  Created by Rebecca Henry on 2021-09-30.
//

#include "insultgenerator.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

FileException::FileException(const string& message) : message(message) {}
string& FileException::what() { return message; }

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& message) : message(message) {}
string& NumInsultsOutOfBounds::what() { return message; }

InsultGenerator::InsultGenerator(): words(initialize()){};

// initializes by importing from the txt file and putting words into vector "words"
vector<string> InsultGenerator::initialize()
{
    ifstream fileIn("InsultsSource.txt");
    vector<string> words;
    string line;
    if (fileIn.fail()) {
        throw FileException("File cannot be read.\n");
    }
    while (getline(fileIn, line)){
        words.push_back(line.substr(0,line.find("\t")));
        line.erase(0, line.find("\t")+1);
        words.push_back(line.substr(0,line.find("\t")));
        line.erase(0, line.find("\t")+1);
        words.push_back(line);
    }
    fileIn.close();
    return words;
    
}

// outputs 1 insult
string InsultGenerator::talkToMe() {
    vector<string> insults = generate(1);
    return insults[0];
}

// generates numInsults, saves them to <insults>, returns <insults>
vector<string> InsultGenerator::generate(int n){
    vector<string> insults; //to be returned
    vector<string> words1;
    vector<string> words2;
    vector<string> words3;
    int rand1;
    int rand2;
    int rand3;
    srand(time(0));
    string rands;
    vector<string> used;
    used.push_back("-1 -1 -1");

    if (n > 10000 or n < 1){
        throw NumInsultsOutOfBounds("Number of insults requested must be greater than 0 and less than or equal to 10 000.\n");
    }
    for (int k=0; k< 150; k++) {
        if (k%3 == 0) {
            words1.push_back(words[k]);
        }
        if (k%3 == 1){
            words2.push_back(words[k]);
        }
        if (k%3 == 2){
            words3.push_back(words[k]);
        }
    }
    
    while(n>0){
        rand1 = rand()%49;
        rand2 = rand()%49;
        rand3 = rand()%49;
        rands = to_string(rand1)+" "+to_string(rand2)+" "+to_string(rand3);
        while (find(used.begin(),used.end(),rands) != used.end()){
            rand1 = (rand() % 49);
            rand2 = rand()%49;
            rand3 = rand()%49;
            rands = to_string(rand1)+" "+to_string(rand2)+" "+to_string(rand3);
        }
        insults.push_back(" Thou " + words1[rand1] + " " + words2[rand2] + " " + words3[rand3] + "!");
        used.push_back(rands);
        n = n-1;
    }
    sort(insults.begin(), insults.end());
    return insults;
}

// generates m insults and saves them to filename
void InsultGenerator::generateAndSave(const string& filename, int m) {
    vector<string> insults = generate(m);
    unsigned int lineCount = 0;
    ofstream fileOut(filename);
    if (fileOut.fail()) {
        throw FileException("File cannot be written.");
    }
    if (m > 10000 or m < 1){
        throw NumInsultsOutOfBounds("Number of insults requested must be greater than 0 and less than or equal to 10 000.");
    }
    while (lineCount < m) {
        fileOut << insults.at(lineCount) << endl;
        lineCount++;
    }
    fileOut.close();
} // end writeFile

