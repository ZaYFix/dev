#include <iostream>
#include <iomanip>
#include <fstream>
#include "Temps.h"

using namespace std;

int main() 
{
   /* Question 1 */
   
   cout << "Question 1 : " << endl;    
   Temps t1;
   cout << "Temps : " << t1.getValeur() << " secondes\n";
   cout << "Temps (HH:MM:SS) : " << setfill('0') << setw(2) << t1.getHeure() << ":" << setfill('0') << setw(2) << t1.getMinute() << ":" << setfill('0') << setw(2) << t1.getSeconde() << endl;
   
   Temps t2(3670);
   cout << "Temps : " << t2.getValeur() << " secondes\n";
   cout << "Temps (HH:MM:SS) : " << setfill('0') << setw(2) << t2.getHeure() << ":" << setfill('0') << setw(2) << t2.getMinute() << ":" << setfill('0') << setw(2) << t2.getSeconde() << endl;
   
   Temps t3(1, 60, 30);
   cout << "Temps : " << t3.getValeur() << " secondes\n";
   cout << "Temps (HH:MM:SS) : " << setfill('0') << setw(2) << t3.getHeure() << ":" << setfill('0') << setw(2) << t3.getMinute() << ":" << setfill('0') << setw(2) << t3.getSeconde() << endl;
   
   cout << endl;
   
   
   /* Question 2 */
   
   cout << "Question 2 : " << endl;
   cout << "Temps t1 : " << t1 << endl;
   cout << "Temps t2 : " << t2 << endl;
   cout << "Temps t3 : " << t3 << endl;
   cout << endl;
   

   /* Question 3 */
   
   cout << "Question 3 : " << endl; 
   Temps t4;
   
   cin >> t4;
   if (! cin) 
   {
      cout << "Erreur de lecture !\n";
   }
   else
   {
      cout << "Temps t4 : " << t4.getValeur() << " secondes\n";
      cout << "Temps t4 : " << t4 << endl;         
   }
   cout << endl;
   

   /* Question 4 */
   
   cout << "Question 4 : " << endl;  
   fstream *fichier = NULL;
   string nom;
   Temps temps;
   
   fichier = new fstream("chronos.txt", fstream::in);

   cout << "Natation > Championnats du monde : 1500m nage libre Homme" << endl;   

   *fichier >> nom;
   while (! fichier->eof()) 
   {
      *fichier >> temps;
      cout << nom << " -> " << temps << endl;
      while (fichier->get() != '\n');
      *fichier >> nom;  
   }
   
   fichier->close();
   delete fichier; 
   cout << endl;
   

   /* Question 5 */
   cout << "Question 5 : " << endl;   
    ofstream resultats;
    resultats.open ("resultats.txt");
    resultats << t1 << "\n";
    resultats << t2 << "\n";
    resultats << t3 << "\n";
    resultats.close();


   /* Question 6 */
   
   cout << "Question 6 : " << endl;  

   cout << "Temps t1 : " << t1 << endl;
   t1 += 10; 
   cout << "Temps t1 + 10 : " << t1 << endl << endl;

   cout << "Temps t1 : " << t1 << endl;
   t1 -= 10; 
   cout << "Temps t1 - 10 : " << t1 << endl << endl;

   cout << "Temps t2 : " << t2 << endl;
   cout << "Temps t3 : " << t3 << endl; 
   t2 += t3;    
   cout << "Temps t2 += t3 : " << t2 << endl << endl;

   cout << "Temps t2 : " << t2 << endl;
   cout << "Temps t3 : " << t3 << endl;
   t2 -= t3; 
   cout << "Temps t2 -= t3 : " << t2 << endl << endl; 

   cout << "Temps t2 : " << t2 << endl;
   cout << "Temps t3 : " << t3 << endl;
   t1 = t2 + t3; 
   cout << "Temps t2 + t3 : " << t1 << endl << endl;

   cout << "Temps t2 : " << t2 << endl;
   cout << "Temps t3 : " << t3 << endl;
   t1 = t3 - t2; 
   cout << "Temps t3 - t2 : " << t1 << endl << endl; 
   cout << endl;
   
   /* Bonnus Question 6 */
   cout << " Question 6 Bonnus " << endl;
   
   cout << t1 << endl;
   ++t1;
   cout << "Temps t1 : " << "++t1 : " << t1 << endl;
   
   cout << t1 << endl;
   --t1;
   cout << "Temps t1 : " << "--t1 : " << t1 << endl;
   cout << endl;
   
   /* Question 7 */
   
   cout << "Question 7 : " << endl;  
   Temps t5(1, 1, 10); // 01:01:10
      
   //cout << "t2 : " << t2 << endl;
   //cout << "t3 : " << t3 << endl;
   //cout << "t5 : " << t5 << endl;
   
   if(t2 == t5) 
   {
       cout << "t2 égal à t5\n"; 
   }
   else
   {
       cout << "t2 différent de t5\n"; 
   }
   if(t3 != t5)
   {
       cout << "t3 différent de t5\n"; 
   }
   else
   {
       cout << "t3 égal à t5\n"; 
   }
   
   
   /* Question 8 :  */
    cout << "Question 8 : " << endl; 
    
    cout << " t1 : " << t1 << endl;
    Temps t6 = t1;
    cout << " t6 : " << t6 << endl;
      
      
   return 0;
}
