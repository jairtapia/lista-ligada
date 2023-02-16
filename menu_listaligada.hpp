#ifndef MENU_LISTALIGADA_HPP_INCLUDED
#define MENU_LISTALIGADA_HPP_INCLUDED
#include"list.hpp"
#include"song.hpp"
class menu{
private:
    void Userinterface(List<Song>&);
public:
    menu(List<Song>&);
};

#endif // MENU_LISTALIGADA_HPP_INCLUDED
