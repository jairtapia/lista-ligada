#ifndef SONG_HPP_INCLUDED
#define SONG_HPP_INCLUDED


#include<iostream>
#include<string>


class Song{
private:
std::string author;
std::string namesong;
std::string mp3;
std::string songrank;
std::string interpreter;

void copyAll(const Song&);

public:
Song();
Song(const Song&);
void setNamesong(const std::string&);
void setAuthor(const std::string&);
void setInterpreter(const std::string&);
void setMp3(const std::string&);
void setSongRank(const std::string&);


std::string toString()const;


std::string getAuthor()const;
std::string getNamesong()const;
std::string getMp3()const;
std::string getSongRank()const;
std::string getInterpreter()const;

Song& operator = (const Song&);
bool operator ==(const Song&) const;
bool operator !=(const Song&) const;
bool operator <(const Song&) const;
bool operator <=(const Song&) const;
bool operator >(const Song&) const;
bool operator >=(const Song&) const;

std::string operator + (Song&);

static int compareByauthor(const Song&,const Song&);
static int compareBynamesong(const Song&,const Song&);
static int compareByinterpreter(const Song&,const Song&);
static int compareBymp3(const Song&, const Song&);
static int compareBysongrank(const Song&, const Song&);


friend std::istream& operator >> (std::istream&,Song&);
friend std::ostream& operator << (std::ostream&,const Song&);

};
#endif // SONG_HPP_INCLUDED
