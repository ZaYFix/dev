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
  CPPUNIT_TEST( testTriTaillePaire );
  CPPUNIT_TEST( testTriTailleImpaire ) ;
  CPPUNIT_TEST( testMesureMax ) ;
  CPPUNIT_TEST( testMesureMin ) ;
  CPPUNIT_TEST( testNbEchantillon ) ;
  CPPUNIT_TEST( testGetEchantillon ) ;
  CPPUNIT_TEST( testMesure ) ;
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
   void testTriTaillePaire();
   void testTriTailleImpaire();   
   void testMesureMax();
   void testMesureMin();
   void testGetEchantillon();
   void testNbEchantillon();
   void testMesure();
};

#endif
