//
// Created by jakea on 10/31/2018.
//

//Utpod.cpp

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Song.h"
#include "UtPod.h"


using namespace std;


UtPod::UtPod() { //default constuctor
    // set size to default value
    songs = NULL;
    memSize = MAX_MEMORY;
    numSongs = 0;

}

UtPod::UtPod(int size) {
    // set size to parameter value
    songs = NULL;
    if(size > MAX_MEMORY || size <= 0) //set mem
        memSize = MAX_MEMORY;
    else{
        memSize = size;
    }
}

int UtPod::addSong(Song const &s) {
    if(getRemainingMemory() >= s.getSize()){   // need to have enough space for song
        SongNode* temp;
        temp = new SongNode;                // mallocc for c++
        temp->songer.setSize(s.getSize());
        temp->songer.setArtist(s.getArtist());
        temp->songer.setTitle(s.getTitle());
        temp->next = songs;
        songs = temp;
        numSongs++;
        return SUCCESS;
    }
    else{
        return NO_MEMORY;
    }
}

int UtPod::removeSong(Song const &s) {          // This searches through for a specific song, if equivalent will remove
        SongNode* current;
        SongNode* previous;

        current = songs;
        previous = NULL;

        while(current != NULL)
        {

            if(current->songer == s){
                if(previous == NULL)
                {
                    songs= current->next;
                }
                else {
                    previous->next = current->next;
                }
                    delete (current);
                    numSongs--;
                    return SUCCESS;

            }
            previous= current;
            current= current->next;
        }
        return -1;



}

void UtPod::shuffle() {

    if(numSongs < 3)
    {
        return;
    }

    int var1;
    int var2;
    SongNode *p1;
    SongNode *p2;

    unsigned int currentTime = 42;
    srand(currentTime);
    for(int i = 0; i <(2*numSongs); i++)
    {
        p1 = songs;
        p2 = songs;
        //cout << p1->songer.getTitle();
        //cout << p2->songer.getTitle();
        var1 = rand() % numSongs;
        var2 = rand() % numSongs;
        for(int j = 0; j < var1; j++)
        {
            p1 = p1->next;

        }

        for(int k = 0; k < var2; k++)
        {
            p2 = p2->next;
        }

        songSwapper(p1, p2);
    }
    //This shuffles twice the size
}

void UtPod::showSongList() {
    if(songs == NULL) {
        cout << "Song list is empty!" << endl;
    }
    else{
        SongNode* temp = songs;
        while(temp != NULL){
            cout << temp->songer.getArtist()<< ", " << temp->songer.getTitle() << " " <<  temp->songer.getSize() <<  " " << "MB" << endl;
            temp = temp->next;
        }
    }
    cout << endl;
    return;
}

void UtPod::songSwapper(SongNode *p1, SongNode *p2){

    SongNode *temp;
    temp = new SongNode;

    temp->songer.setSize(p1->songer.getSize());
    temp->songer.setArtist(p1->songer.getArtist());
    temp->songer.setTitle(p1->songer.getTitle());




    p1->songer.setArtist(p2->songer.getArtist());
    p1->songer.setSize(p2->songer.getSize());
    p1->songer.setTitle(p2->songer.getTitle());

    p2->songer.setArtist(temp->songer.getArtist());
    p2->songer.setTitle(temp->songer.getTitle());
    p2->songer.setSize(temp->songer.getSize());

    delete(temp);


}

void UtPod::sortSongList() {

    if(numSongs < 2)
    {
    return;
    }

    SongNode *sorter;
    sorter = songs;
    SongNode *best;


    for(int i = 0; i < numSongs; i++)
    {
        best = findBest(sorter);
        songSwapper(best, sorter);
        sorter = sorter->next;

    }



}


struct UtPod::SongNode * UtPod::findBest(SongNode *start)
{
    SongNode * best;
    best = start;
    SongNode * temp;
    temp = start;
    int counter = 0;
    int bester = 0;
    while( temp != NULL)
    {
        if(temp->songer < best->songer)
        {
            best = temp;
            bester = counter;

        }
        counter++;
        temp = temp->next;
    }

    /*SongNode *deep;
    deep = new SongNode;
    deep->next = best->next;
    deep->songer = best->songer;

    return deep*/
    return best;

}


void UtPod::clearMemory() {

    SongNode* temp;
    temp = songs;


    while(numSongs != 0)
    {
        temp = temp->next;
            delete (songs);
            songs = temp;
            numSongs--;


    }


}




int UtPod::getRemainingMemory() {
    int currentMemory;
    currentMemory= getTotalMemory();
    return MAX_MEMORY-currentMemory;

}

int UtPod::getTotalMemory(){
    memSize = 0;
    SongNode* temp;
    temp = songs;
    while (temp != NULL){
        memSize = memSize + temp->songer.getSize();
        temp = temp->next;
    }
    return memSize;
}

int UtPod::getNumSongsInUtPod(){
    int numSongs = 0;
    SongNode* temp;
    temp = songs;
    while (temp != NULL){
        numSongs++;
        temp = temp->next;
    }
    return numSongs;
}

UtPod::~UtPod(){
    while(songs != NULL){
        SongNode* temp;
        temp = songs;
        songs = temp->next;
        delete(temp);
    }
    //cout << "All clear" << endl;
}
