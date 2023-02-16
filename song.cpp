#include<string>
#include<iomanip>
#include"song.hpp"
using namespace std;

Song::Song():author("unknown"),namesong("unknown"),mp3("unknown"),songrank("0"),interpreter("unknown"){}
void Song::copyAll(const Song& s)
{
    this->interpreter = s.interpreter;
    this->author = s.author;
    this->namesong = s.namesong;
    this->mp3 = s.mp3;
    this->songrank = s.songrank;

}

Song::Song(const Song& s)
{
    copyAll(s);
}

string Song::operator+(Song& s)
{
    return author+"\t"+interpreter+"\t"+namesong+"\t"+mp3+"\t"+songrank+"\n"+s.toString();
}

Song& Song::operator=(const Song& s)
{
 copyAll(s);
 return *this;
}


bool Song::operator==(const Song& s) const
{
    return (namesong==s.namesong);
}

bool Song::operator!=(const Song& s) const
{
    return (namesong!=s.namesong);
}

bool Song::operator<(const Song& s) const
{
return (namesong<s.namesong);
}

bool Song::operator<=(const Song& s) const
{
return (namesong<=s.namesong);
}

bool Song::operator>(const Song& s) const
{
return (namesong>s.namesong);
}

bool Song::operator>=(const Song& s) const
{
return (namesong>=s.namesong);
}

void Song::setNamesong(const std::string& ns)
{
namesong=ns;
}
void Song::setAuthor(const std::string& na)
{
author=na;
}
void Song::setInterpreter(const std::string& ni)
{
interpreter=ni;
}
void Song::setMp3(const std::string& cancion)
{
    mp3 = cancion;
}

void Song::setSongRank(const std::string& Rank)
{
    songrank = Rank;
}



string Song::toString() const
{
string song;
song+="| ";
song+=author;
song.resize(19);
song+=" | ";
song+=namesong;
song.resize(45);
song+=" | ";
song+=interpreter;
song.resize(69);
song+=" | ";
song+=mp3;
song.resize(100);
song+=" | ";
song+=songrank;
song+=" |\n";
return song;
}
std::string Song::getAuthor() const
{
return author;
}
string Song::getNamesong() const
{
return namesong;
}
std::string Song::getInterpreter() const
{
return interpreter;
}
string Song::getMp3() const
{
    return mp3;
}

std::string Song::getSongRank() const
{
    return songrank;
}

int Song::compareByauthor(const Song& a, const Song& b)
{
    return a.author.compare(b.author);
}

int Song::compareBynamesong(const Song& a, const Song& b)
{
    return a.namesong.compare(b.namesong);
}

int Song::compareByinterpreter(const Song& a, const Song& b)
{
    return a.interpreter.compare(b.interpreter);
}
int Song::compareBymp3(const Song& a, const Song& b)
{
return a.mp3.compare(b.mp3);
}

int Song::compareBysongrank(const Song& a, const Song& b)
{
return a.songrank.compare(b.songrank);
}

std::ostream& operator << (std::ostream& os, const Song& s){
    os<<s.author<<endl;
    os<<s.interpreter<<endl;
    os<<s.namesong<<endl;
    os<<s.songrank<<endl;
    os<<s.mp3<<endl;

    return os;
}

std::istream& operator >> (std::istream& is, Song& c){
    getline(is, c.interpreter);
    getline(is, c.author);
    getline(is, c.namesong);
    getline(is,c.mp3);
    getline(is,c.songrank);
    return is;
}

