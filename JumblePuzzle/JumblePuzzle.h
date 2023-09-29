//
//  JumblePuzzle.h
//  
//
//  Created by Rebecca Henry on 2021-11-17.
//

#include <string>
#include <stdio.h>

using namespace std;

class BadJumbleException{
    string message;
    public:
        BadJumbleException(const string& message); //returns the error message
        string& what();
};

class JumblePuzzle{
    // attributes
    string _word;           // the hidden word
    string _difficulty;     // the difficulty level
    int _size;              // rows (= cols)
    char _dir;              // N, E, S or W - direction of word
    int _rowPos;            // Row word starts in
    int _colPos;            // Col word starts in
    char** _jumble;         // array of arrays containing the puzzle 

    public:
        // methods
        JumblePuzzle(const string& _word = "HELLO", const string& _difficulty = "easy");   // constructor
        JumblePuzzle& operator=(const JumblePuzzle& other); // copy assignment constructor
        JumblePuzzle(const JumblePuzzle& other);            // copy constructor
        ~JumblePuzzle();                                    // destructor
        
        // accessors
        char** getJumble() const;                           // a pointer that points to an pointer containing the puzzle        
        int getSize() const;                                // gets sizes of puzzle
        char getDirection() const;                          // gets direction of word
        int getRowPos() const;                              // gets row pos of first letter of hidden word
        int getColPos() const;                              // gets column pos of first letter of hidden word
        string getWord() const;
        string getDiff() const;

};
