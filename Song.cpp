//
// Created by jakea on 10/31/2018.
//


#include <cstdlib>
#include <iostream>
#include <string>
#include "Song.h"

using namespace std;

Song::Song(){        //Default song settings: set blank strings and null size.
    setArtist("\0");
    setTitle("\0");
    setSize(1);
}

Song::Song(string artistName, string songName, int sizeSong){
    setArtist(artistName);
    setTitle(songName);
    setSize(sizeSong);

}
void Song::setArtist(string artistName){
    artist = artistName;

}
void Song::setTitle(string titleName){
    title = titleName;

}
void Song::setSize(int siz){
    songSize = siz;

}
string Song::getArtist() const{
    return artist;

}
string Song::getTitle() const{
    return title;

}
int Song::getSize() const{
    return songSize;
}

bool Song::operator >(Song const &rhs)  //operator overide ?
{
    if(this->artist > rhs.artist)
    {
        return true;
    }
    else if(this->artist == rhs.artist)
    {
        if(this->title > rhs.title)
        {
            return true;
        }
        if(this->title == rhs.title)
        {
            if(this->songSize > rhs.songSize)
            {
                return true;
            }
        }
    }

    else{
        return false;
    }

}
bool Song::operator <(Song const &rhs) //operator override?
{
    if(this->artist < rhs.artist)
    {
        return true;
    }
    else if(this->artist == rhs.artist)
    {
        if(this->title < rhs.title)
        {
            return true;
        }
        if(this->title == rhs.title)
        {
            if(this->songSize < rhs.songSize)
            {
                return true;
            }
        }
    }

    else{
        return false;
    }

}

bool Song::operator == (Song const &s) //operator overirider ?
{
    return ( (this->artist == s.artist) &&
             (this->title == s.title) &&
             (this->songSize == s.songSize)
    );
}


