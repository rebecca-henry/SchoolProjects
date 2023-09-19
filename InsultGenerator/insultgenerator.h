//
//  insultgenerator.h
//
//
//  Created by Rebecca Henry on 2021-09-30.
//

#ifndef insultgenerator_h
#define insultgenerator_h

#endif /* insultgenerator_h */

#include <string>
#include <vector>

using namespace std;

// FileException class

class FileException {
public:
    FileException(const string& message);
    string& what();
private:
    string message;
};

// NumInsultsOutOfBounds class
class NumInsultsOutOfBounds {
public:
    NumInsultsOutOfBounds(const string& message);
    string& what();
private:
    string message;
};

// InsultGenerator
class InsultGenerator {
public:
    InsultGenerator();
    vector<string> initialize(); //this will initialize
        //the insulting words into the generator using file IO
    string talkToMe(); // calls generate to output 1 insult
    vector<string> generate(int n); //generates n insults
    void generateAndSave(const string& fileName, int m);
                    //calls generate to make m insults
                // uses file IO to save insults to fileName
    vector<string> words; // this attribute containing
                    //the insulting words
};
