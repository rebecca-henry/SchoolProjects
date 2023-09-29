//
//  JumblePuzzle.cpp
//  
//
//  Created by Rebecca Henry on 2021-11-17.
//

#include <string>
#include <stdio.h>
#include "JumblePuzzle.h"
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

// BadJumbleException
BadJumbleException::BadJumbleException(const string& message): message(message){}
string& BadJumbleException::what(){
    return message;
    }
JumblePuzzle::JumblePuzzle(const string& word, const string& difficulty):_word(word), _difficulty(difficulty){
    if (_difficulty != "easy" && _difficulty != "medium" && _difficulty != "hard"){
        throw BadJumbleException("BadJumbleException: Difficulty must be \"easy\", \"medium\", or \"hard\".");
    }
    if (_word.length() < 3){
        throw BadJumbleException("BadJumbleException: Word length must be greater than 3 characters.");
    }
    if (_word.length() > 10){
        throw BadJumbleException("BadJumbleException: Word length must be less than 10 characters.");
    }

    srand(time(0));
    int size;
    if (_difficulty == "easy") {           // make easy
        size = _word.length()*2;
    }
    else if (_difficulty == "medium") {    // make medium
        size = _word.length()*3;
    }
    else if (_difficulty == "hard") {       // make difficult
        size = _word.length()*4;
    }
    
    char dir;
    int len = _word.length();
    int ran = rand()%4; 
    if (ran == 0){                  // set north
        dir = 'n';
    }
    else if(ran == 1){              // set east
        dir= 'e';
    }
    else if(ran == 2){              // set south
        dir= 's';
    }
    else if(ran == 3){              // set west
        dir= 'w';
    }
    else{                           // set south
        dir = 's';
    }

    // make a puzzle
    int rowPos, colPos;

    string letters = "abcdefghijklmnopqrstuvwxyz";              // all possible letters
    char** jumble = new char*[size];                            // make the frame jumble
    for (int r = 0; r<size; r++){                               // build the puzzle
        jumble[r] = new char[size]; 
        for (int c = 0; c<size; c++){
            jumble[r][c] = letters[rand()%26];
        }
    }

    if (dir == 'e')             // put word east into puzzle
    {   
        //b/n 0 and size - word.length
        colPos = rand() % (size - _word.length() - 2);
        rowPos = rand() % (size-1);
        for (int j=0; j < _word.length(); j++){
            jumble[rowPos][colPos + j] = _word[j];
        }
    }
    
    else if (dir == 'w')        // put word west into puzzle
    {
        // b/n word.length and size
        colPos = (rand() % (_word.length()-1)) + (rand() % (size - _word.length() - 2));
        rowPos = rand() % (size-1);
        for (int j = 0; j < _word.length(); j++){
            jumble[rowPos][colPos + j]= _word[_word.length()-j-1];
        }
        colPos = _word.length() + colPos - 1;
    }
    
    else if (dir == 'n')        // put word north into puzzle
    {   
        // b/n word.length and size
        rowPos = (rand() % (_word.length()-1)) + (rand() % (size - _word.length() - 2));
        colPos = rand() % (size-1);
        for (int j = 0; j < _word.length(); j++){
            jumble[rowPos + j][colPos]= _word[_word.length()-j-1];
        }
        rowPos = _word.length() + rowPos - 1;
    }

    // south is working
    else if (dir == 's')        // put word south into puzzle
    {
        // b/n 0 and size - word.length
        rowPos = rand() % (size - _word.length() - 2);
        colPos = rand() % (size-1);
        for (int j=0; j < _word.length(); j++){
            jumble[rowPos + j][colPos] = _word[j];
        }
    }
    
    //set the private attributes of the class
    _size = size;
    _rowPos = rowPos;
    _colPos = colPos;
    _dir = dir;
    _jumble = jumble;
}

// accessors
char** JumblePuzzle::getJumble() const{
    char** jumble = new char*[_size];
    for (int r = 0; r<_size; r++){                //make the array 2d by filling array with arrays
        jumble[r] = new char[_size];       // according to size 
        for (int c=0; c<_size; c++){
            jumble[r][c] = _jumble[r][c];
        }
    }  
    return jumble;}

int JumblePuzzle::getSize() const{return _size;}

int JumblePuzzle::getRowPos() const{return _rowPos;}

int JumblePuzzle::getColPos() const{return _colPos;}

char JumblePuzzle::getDirection() const{return _dir;}

string JumblePuzzle::getWord() const{return _word;}

string JumblePuzzle::getDiff() const{return _difficulty;}

// copy constructor
JumblePuzzle::JumblePuzzle(const JumblePuzzle& other){
    _word = other._word;
    _difficulty = other._difficulty;
    _size = other._size;
    _rowPos = other._rowPos;
    _colPos = other._colPos;
    _dir = other._dir;
    
    _jumble = new char*[other._size];      // allocate memory on heap for jumble puzzle
    for (int r = 0; r<_size; r++){                //make the array 2d by filling array with arrays
        _jumble[r] = new char[other._size];       // according to size 
        for (int c=0; c<_size; c++){
            _jumble[r][c] = other._jumble[r][c];
        }
    }    
}

// assignment operator
JumblePuzzle& JumblePuzzle::operator=(const JumblePuzzle& other){
    if (this != &other){                          // check for self assignment
        this->_word = other._word;
        this->_difficulty = other._difficulty;
        this->_size = other._size;
        this->_rowPos = other._rowPos;
        this->_colPos = other._colPos;
        this->_dir = other._dir;
        _jumble = new char*[other._size];      // allocate memory on heap for jumble puzzle
        for (int r = 0; r<_size; r++){                //make the array 2d by filling array with arrays
            _jumble[r] = new char[other._size];       // according to size 
            for (int c=0; c<_size; c++){
                _jumble[r][c] = other._jumble[r][c];
            }
        }    
    }
    return *this;
}

// destructor
JumblePuzzle::~JumblePuzzle(){
    for (int r=0;r<_size;r++){
        delete[] _jumble[r];
    }
    delete[] _jumble;
}
