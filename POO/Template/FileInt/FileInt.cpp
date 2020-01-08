#include "FileInt.h"

FileInt::FileInt(int c/*=CAPACITE_MAX*/)
{
   this->taille = 0;
   t = new int[c];
   for (int i = 0; i < c ; i++) t[i] = 0;
   this->capacite = c;
   this->in = 0;
   this->out = 0;
}

FileInt::~FileInt() 
{
   delete [] t;
}

FileInt::FileInt(const FileInt &fi) 
{
   cout << "FileInt::FileInt(const FileInt &fi)" << endl;
   this->taille = fi.taille;
   this->capacite = fi.capacite;
   this->t = new int[fi.capacite];
   for (int i = 0; i < fi.capacite ; i++) this->t[i] = fi.t[i];
   this->in = fi.in;
   this->out = fi.out;
}

FileInt & FileInt::operator = (const FileInt &fi) 
{
   if (this != &fi) 
   {
      delete [] t;
      taille = fi.taille;
      capacite = fi.capacite;
      t = new int[fi.capacite];
      for (int i = 0; i < fi.capacite ; i++) t[i] = fi.t[i];
      this->in = fi.in;
      this->out = fi.out;
   }
   return *this;
}

void FileInt::affiche()
{
   cout << "FileInt : " << *this << endl;
}

ostream & operator << (ostream & os, const FileInt &fi) 
{
   int nb = 0;

   if (fi.taille > 0) 
   {
       os << "<" << fi.taille << "/" << fi.capacite << ">";
       os << " [" << fi.in << "," << fi.out << "] ";
       os << "{";
       for (int i = fi.out; i < (fi.out+fi.taille); i++) 
       {
           //if(fi.t[i] != 0)
           {
               nb++;
               if(nb == 1)
                    os << fi.t[i%fi.capacite];
               else os << ", " << fi.t[i%fi.capacite];
           }
       }
       os << "}";       
   }
   else os << "{" << "}";
   return os;
}

int FileInt::operator-() throw(FileException)
{
   int x;
   
   if (this->taille == 0) throw FileException("FileInt vide");
   x = this->t[this->out];
   //this->t[this->out] = 0; /* élement vide */
   this->taille--;
   this->out = (this->out + 1) % this->capacite;

   return x;
}

void FileInt::operator + (const int x) throw(FileException)
{
   //if(x == 0) return; /* élement vide */
   if (this->taille >= this->capacite) throw FileException("FileInt pleine");
   this->t[this->in] = x;
   this->taille++;
   this->in = (this->in + 1) % this->capacite;
}
