#ifndef FILEINT_H
#define FILEINT_H

#include <iostream>
#include <exception>

using namespace std;

class FileException : public exception 
{
   private:
      string cause;

   public:
      FileException(string c) throw() : cause(c) {}
      ~FileException() throw() {}
      const char* what() const throw() {return cause.c_str();}
};

class FileInt 
{
   protected:
      static const int CAPACITE_MAX = 100;
      int   *t;
      int   capacite,
            taille,
            in,
            out;

   public:
      FileInt(int c = CAPACITE_MAX);
      virtual ~FileInt();
      FileInt(const FileInt & fi);
      FileInt & operator = (const FileInt & fi);

      // ajout d'un entier à la file
      virtual void operator + (const int x) throw(FileException);
      // retrait d'un entier de la file
      virtual int operator - () throw(FileException);
      virtual void affiche();
      
      friend ostream & operator << (ostream &, const FileInt &fi);
};

#endif

