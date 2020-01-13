#ifndef FILET_H
#define FILET_H

#include <iostream>
#include <exception>

#define DEBUG

using namespace std;

class FileException : public exception
{
private:
    string cause;

public:
    FileException(string c) throw() : cause(c) {}
    ~FileException() throw() {}
    const char *what() const throw() { return cause.c_str(); }
};

template<class T> 
class FileT;
template<class T> ostream &operator<<(ostream &os, const FileT<T> &fi);

template<class T> 
class FileT
{
protected:
    static const int CAPACITE_MAX = 100;
    T *t;
    int capacite,
        taille,
        in,
        out;

public:
    FileT(int c=CAPACITE_MAX);
    virtual ~FileT();
    FileT(const FileT &fi);

    T &operator=(const FileT<T> &fi);
    virtual void operator+(const T ajoutEntierALaFile) throw();
    virtual T &operator-() throw();
    virtual void affiche();
    friend ostream &operator<<<>(ostream &os, const FileT<T> &fi);
};

#include "FileT.tcc"
#endif

