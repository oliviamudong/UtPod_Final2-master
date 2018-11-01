//
// Created by jakea on 10/31/2018.
//

#ifndef UTPOD_FINAL_SONG_H
#define UTPOD_FINAL_SONG_H

#endif //UTPOD_FINAL_SONG_H


//
//
//

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


//DOCUMENT HERE

#ifndef SONG_H
#define SONG_H

//Song class declaration
class Song
{
private:
    string artist;
    string title;
    int songSize;


public:
    Song();
    Song(string, string, int);
    void setArtist(string);
    void setTitle(string);
    void setSize(int);
    string getArtist() const;
    string getTitle() const;
    int getSize() const;

    bool operator >(Song const &rhs);       //These are the operator overloads
    bool operator <(Song const &rhs);
    bool operator ==(Song const &rhs);

};



#endif
