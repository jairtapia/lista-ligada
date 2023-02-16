#include"song.hpp"
#include"list.hpp"
#include"menu_listaligada.hpp"
enum {Exit,Inserdata,deletedata,showlist,nextp,previousp,firstp,lastp,retrieve,findData,write,read};
using namespace std;
void menu::Userinterface(List<Song>& SongList){
    system("color 03");
    Song newsong;
    int opc,addelem;
    string name,mp3,namesong,Rank;
    List<Song>::Position pos;
do{
cout<<"**********************************************************"<<endl;
cout<<"**--------------------------menu------------------------**"<<endl;
cout<<"**--------------------1.insertar data-------------------**"<<endl;
cout<<"**--------------------2.delete data---------------------**"<<endl;
cout<<"**--------------------3.mostrar-------------------------**"<<endl;
cout<<"**--------------------4.posicion siguiente--------------**"<<endl;
cout<<"**--------------------5.posicion anterior---------------**"<<endl;
cout<<"**--------------------6.primer posicion-----------------**"<<endl;
cout<<"**--------------------7.ultima posicion-----------------**"<<endl;
cout<<"**--------------------8.recupera------------------------**"<<endl;
cout<<"**--------------------9.localiza------------------------**"<<endl;
cout<<"**--------------------10.archivo para escritura---------**"<<endl;
cout<<"**--------------------11.archivo para lectura-----------**"<<endl;
cout<<"**--------------------0.exit----------------------------**"<<endl;
cout<<"**------------------------------------------------------**"<<endl;
cout<<"**********************************************************"<<endl;
cout<<"escoge una opcion"<<endl;
cin>>opc;
switch(opc){
    case Exit:
            cout<<"**********************************************************"<<endl;
            cout<<"**------------------saliendo del programa---------------**"<<endl;
            cout<<"**********************************************************"<<endl;
        break;
    case Inserdata:
        do{
            cout<<"**********************************************************"<<endl;
            cout<<"**--------------------insertando datos------------------**"<<endl;
            cout<<"**********************************************************"<<endl;
            cout<<"escribe el nombre del cantante"<<endl;
            cin.ignore();
            getline(cin,name);
            newsong.setInterpreter(name);
            cout<<"escribe el nombre del autor"<<endl;
            getline(cin,name);
            newsong.setAuthor(name);
            cout<<"nombre de la cancion"<<endl;
            getline(cin,namesong);
            newsong.setNamesong(namesong);
            cout<<"ahora el nombre en mp3"<<endl;
            getline(cin,mp3);
            newsong.setMp3(mp3);
            cout<<"escribe el rankin"<<endl;
            getline(cin,Rank);
            newsong.setSongRank(Rank);
            SongList.insertData(SongList.getLast(),newsong);
            cout<<"**********************************************************"<<endl;
            cout<<"**----------quieres agregar una nueva cancion?----------**\n**----------1 = si 2 = no-------------------------------**"<<endl;
            cout<<"**********************************************************"<<endl;
            cin>>addelem;
            system("cls");
        }while(addelem!=2);
        break;
    case deletedata:
        cout<<"escribe el nombre de la cancion"<<endl;
            cin.ignore();
            getline(cin,namesong);
            newsong.setNamesong(namesong);
            pos = SongList.findData(newsong);
            if(pos==nullptr){
                cout<<"no se encontro la cancion"<<endl;
            }else{
                SongList.deleteData(pos);
            }
        break;
    case showlist:
        cout<<"**********************************************************************************************************"<<endl;
        cout<<"|author             |nombre de la cancion     |interprete             |nombre mp3|                ranking|"<<endl;
        cout<<"**********************************************************************************************************"<<endl;
        cout<<SongList.toString();
        cout<<"**********************************************************************************************************"<<endl;
        break;
    case nextp:
        cout<<"escribe el nombre de la cancion"<<endl;
        cin.ignore();
        getline(cin,namesong);
        newsong.setNamesong(namesong);
        pos = SongList.findData(newsong);
        pos = SongList.getNextpos(pos);
        if(pos==nullptr){
            cout<<"no se encontro la cancion"<<endl;
        }else{
            cout<<"**********************************************************************************************************"<<endl;
            cout<<"|author             |nombre de la cancion     |interprete             |nombre mp3|                ranking|"<<endl;
            cout<<"**********************************************************************************************************"<<endl;
            cout<<SongList.retrieve(pos).toString();
            cout<<"**********************************************************************************************************"<<endl;
        }
        break;
    case previousp:
        cout<<"escribe el nombre de la cancion"<<endl;
        cin.ignore();
        getline(cin,namesong);
        newsong.setNamesong(namesong);
        pos = SongList.findData(newsong);
        pos = SongList.getPrevpos(pos);
        if(pos==nullptr){
            cout<<"no se encontro la cancion"<<endl;
        }else{
        cout<<"**********************************************************************************************************"<<endl;
        cout<<"|author             |nombre de la cancion     |interprete             |nombre mp3|                ranking|"<<endl;
        cout<<"**********************************************************************************************************"<<endl;
        cout<<SongList.retrieve(pos).toString();
        cout<<"**********************************************************************************************************"<<endl;
        }
        break;
    case firstp:
        pos = SongList.getFirst();
        cout<<"**********************************************************************************************************"<<endl;
        cout<<"|author             |nombre de la cancion     |interprete             |nombre mp3|                ranking|"<<endl;
        cout<<"**********************************************************************************************************"<<endl;
        cout<<SongList.retrieve(pos).toString()<<endl;
        cout<<"**********************************************************************************************************"<<endl;
        break;
    case lastp:
        pos = SongList.getLast();
        cout<<"**********************************************************************************************************"<<endl;
        cout<<"|author             |nombre de la cancion     |interprete             |nombre mp3|                ranking|"<<endl;
        cout<<"**********************************************************************************************************"<<endl;
        cout<<SongList.retrieve(pos).toString()<<endl;
        cout<<"**********************************************************************************************************"<<endl;
        break;
    case retrieve:
            cout<<"escribe el nombre de la cancion"<<endl;
            cin.ignore();
            getline(cin,namesong);
            newsong.setNamesong(namesong);
            pos = SongList.findData(newsong);
            if(pos==nullptr){
                cout<<"no se encontro"<<endl;
            }
            cout<<"**********************************************************************************************************"<<endl;
            cout<<"|author             |nombre de la cancion     |interprete             |nombre mp3|                ranking|"<<endl;
            cout<<"**********************************************************************************************************"<<endl;
            cout<<SongList.retrieve(pos).toString()<<endl;
            cout<<"**********************************************************************************************************"<<endl;
        break;
    case findData:
            cout<<"escribe el nombre de la cancion"<<endl;
            cin.ignore();
            getline(cin,namesong);
            newsong.setNamesong(namesong);
            pos = SongList.findData(newsong);
            if(pos==nullptr){
                cout<<"no se encontro la cancion"<<endl;
            }else{
                cout<<"**********************************************************************************************************"<<endl;
                cout<<"|author             |nombre de la cancion     |interprete             |nombre mp3|                ranking|"<<endl;
                cout<<"**********************************************************************************************************"<<endl;
                cout<<SongList.retrieve(pos).toString()<<endl;
                cout<<"**********************************************************************************************************"<<endl;
            }
        break;
    case write:
        SongList.writeToDisk("prueba.txt");
        break;
    case read:
        SongList.readfromDisk("canciones");
        break;
    default:
        cout<<"opcion no valida"<<endl;
}
}while(opc != 0);

}

menu::menu(List<Song>& SongList){
Userinterface(SongList);
}
