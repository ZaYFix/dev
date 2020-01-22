#ifndef _TESTUNITAIREMESURE_H
#define _TESTUNITAIREMESURE_H

#include <cppunit/extensions/HelperMacros.h>

class Mesure; // La classe à tester

class TestUnitaireMesure : public CPPUNIT_NS::TestFixture
{
  // On crée une suite de tests unitaires pour la classe 
  CPPUNIT_TEST_SUITE( TestUnitaireMesure );
  CPPUNIT_TEST( testReinitialiser ) ;
  CPPUNIT_TEST( testAjouterEchantillons ) ;
  CPPUNIT_TEST( testEstTrie ) ;  
  CPPUNIT_TEST( testTriTailleImpaire ) ;
  CPPUNIT_TEST( testMesureMax ) ;
  CPPUNIT_TEST_SUITE_END();

private:
   Mesure *mesure; // un pointeur sur une instance de la classe à tester
   
public:
   TestUnitaireMesure();
   virtual ~TestUnitaireMesure();

   // Call before tests : instancie l'objet à tester
   void setUp();
   
   // Call after tests : libère l'objet testé
   void tearDown();
        
   // Liste des tests
   void testReinitialiser();
   void testAjouterEchantillons();
   void testEstTrie();   
   void testTriTailleImpaire();   
   void testMesureMax();
};

#endif
