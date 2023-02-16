#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED
#include<exception>
#include<string>
#include<fstream>

template<class T>
class List{
    class Node;
    public:
    typedef Node* Position;
    private:
        class Node{
            private:
                T data;
                Node *next;
                Node *prev;
            public:
                Node();
                Node(const T&);

                T getData();
                Node* getNext();
                Node* getPrev();

                void setData(const T&);
                void setNext(Node*);
                void setPrev(Node*);
        };

        Node* anchor;
        void copyALL(const List<T>&);

        bool isValid(Node*)const;


    public:
        class Exception : public std::exception{
            private:
            std::string msg;
            public:
            explicit Exception(const char* message) : msg(message){ }
            explicit Exception(const std::string& message) : msg(message){ }
            virtual ~Exception() throw(){}
            virtual const char* what()const throw(){
            return msg.c_str();
            }
        };


    List();
    List(const List<T>&);

    ~List();

    bool isEmpty()const;
    void insertData(Position, const T&);
    void deleteData(Position);

    Position getFirst()const;
    Position getLast()const;
    Position getPrevpos(Position)const;
    Position getNextpos(Position)const;
    void deleteALL();

    Position findData(const T&)const;
    T retrieve(Position)const;


    std::string toString();

    List<T>& operator = (const List<T>&);


    void writeToDisk(const std::string&);
    void readfromDisk(const std::string&);


};

using namespace std;
template<class T>
List<T>::Node::Node(): next(nullptr), prev(nullptr){}

template<class T>
List<T>::Node::Node(const T& e): data(e), next(nullptr), prev(nullptr){}

template<class T>
T List<T>::Node::getData(){
return data;
}

template<class T>
typename List<T>::Node* List<T>::Node::getNext(){
    return next;
}
template<class T>
typename List<T>::Node* List<T>::Node::getPrev(){
    return prev;
}

template<class T>
void List<T>::Node::setData(const T& e){
data = e;
}

template<class T>
void List<T>::Node::setNext(Node* p){
next = p;
}

template<class T>
void List<T>::Node::setPrev(Node* p){
prev = p;
}

///inician metodos de la lista
template<class T>
void List<T>::copyALL(const List<T>& l)
{
    Node* aux(l.anchor);
    Node* last(nullptr);
    Node* newNode;
    while(aux != nullptr){
        if(newNode = new Node(aux->getData())==nullptr){
        throw Exception("memoria no disponible: coppyALL");
        }
        if(last == nullptr){
            anchor = newNode;
        }else{
            last->setNext(newNode);
            newNode->setPrev(last);
        }
        last = newNode;
        aux = aux->getNext();
    }
}

template<class T>//se queda igual
bool List<T>::isValid(List<T>::Position p) const{
    Position aux(anchor);
    while(aux != nullptr){
        if(aux == p){
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}

template<class T>
List<T>::List(): anchor(nullptr) {}

template<class T>
List<T>::List(const List<T>& l):anchor(nullptr){
copyALL(l);
}

template<class T>
List<T>::~List()
{
deleteALL();
}

template<class T>
bool List<T>::isEmpty() const
{
return anchor == nullptr;
}

template <class T>
void List<T>::insertData(Position p, const T& e)
{
    if( p != nullptr and !isValid(p) ){
        throw Exception("Posicion invalida, insertData");
    }

    Position aux(new Node(e));
    if(aux == nullptr) {
        throw Exception("Memoria no disonible, insertData");
    }
    if(p==nullptr){
        aux->setNext(anchor);
        if(anchor != nullptr){
            anchor->setPrev(aux);
        }
        anchor = aux;
    }
    else{///cualquier otro lugar
        aux->setPrev(p);
        aux->setNext(p->getNext());
        if(p->getNext()!=nullptr){
            p->getNext()->setPrev(aux);
        }
        p ->setNext(aux);
    }
}

template<class T>
void List<T>::deleteData(Position p)
{
if(!isValid(p)){
    throw Exception("posiccion invalida: dele data");
}
if(p->getPrev()!= nullptr){
    p->getPrev()->setNext(p->getNext());
}
if(p->getNext()!=nullptr){
    p->getNext()->setPrev(p->getPrev());
}
if(p == anchor){
    anchor = anchor->getNext();
}
delete p;
}

template<class T>
typename List<T>::Position List<T>::getFirst() const
{
return anchor;
}

template<class T>
typename List<T>::Position List<T>::getLast() const
{
    Position aux(anchor);
    if(isEmpty()){
        return nullptr;
    }
    while(aux->getNext()!=nullptr){
        aux = aux->getNext();
    }
    return aux;
}

template<class T>
typename List<T>::Position List<T>::getPrevpos(Position p) const
{
    if(!isValid(p)){
        return nullptr;
    }
    return p->getPrev();
}

template<class T>
typename List<T>::Position List<T>::getNextpos(Position p) const
{
    if(!isValid(p)){
        return nullptr;
    }
    return p->getNext();
}

template<class T>
void List<T>::deleteALL(){
    Position aux;
    while(anchor != nullptr){
        aux = anchor;
        anchor = anchor->getNext();
        delete aux;
    }
}

template<class T>
typename List<T>::Position List<T>::findData(const T& e) const
{
    Position aux (anchor);
    while(aux != nullptr and aux->getData() != e){
          aux = aux->getNext();
    }
    return aux;
}

template<class T>
T List<T>::retrieve(Position p) const{
    if(!isValid(p)){
     throw Exception("posicion invalida:retrieve");
    }
    return p->getData();
}

template<class T>
std::string List<T>::toString(){
    std::string result;
    Position aux(anchor);
    while(aux != nullptr){
        result+=aux->getData().toString();
        aux = aux->getNext();
    }
    return result;
}

template<class T>
List<T>& List<T>::operator = (const List<T>& l){
    deleteALL();
    copyALL(l);
    return *this;
}

template<class T>
void List<T>::writeToDisk(const std::string& filename){
    ofstream myFile;
    myFile.open(filename,myFile.trunc);
    if(!myFile.is_open()){
        throw Exception("no se pudo abrir el archivo para escritura: writeTodisk");
    }
    Position aux (anchor);
    while(aux!=nullptr){
        myFile<<aux->getData()<<endl;
        aux = aux->getNext();
    }
    myFile.close();
}

template<class T>
void List<T>::readfromDisk(const std::string& filename){
    ifstream myFile;
    Position last(nullptr);
    Position newNode;
    myFile.open(filename);
    if(!myFile.is_open()){
        throw Exception("no se pudo abrir el archivo para lectura: read from disk");
    }
    deleteALL();
    T data;
    while(myFile>>data){
        if((newNode = new Node(data)) == nullptr){
            myFile.close();
            throw  Exception("memoria no disponible: read from disk");
        }
        if(last == nullptr){
            anchor = newNode;
        }else{
            last->setNext(newNode);
        }
        last = newNode;
    }
    myFile.close();
}

#endif // LIST_HPP_INCLUDED
