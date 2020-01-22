#ifndef _TESTUNITAIRE_H
#define _TESTUNITAIRE_H

#include <cppunit/extensions/HelperMacros.h>

class TestUnitaireEstChiffre : public CPPUNIT_NS::TestFixture
{
  // On crée une suite de tests unitaires pour la classe 
  CPPUNIT_TEST_SUITE( TestUnitaireEstChiffre );
  CPPUNIT_TEST( testValide1 ) ;
  CPPUNIT_TEST( testValide2 ) ;
  CPPUNIT_TEST( testValide3 ) ;
  CPPUNIT_TEST( testInvalide1 ) ;
  CPPUNIT_TEST( testInvalide2 ) ;
  CPPUNIT_TEST( testInvalide3 ) ;
  CPPUNIT_TEST_SUITE_END();

private:
   
public:
   TestUnitaireEstChiffre();
   virtual ~TestUnitaireEstChiffre();

   // Call before tests
   void setUp();
   
   // Call after tests
   void tearDown();
        
   // Liste des tests
   void testValide1();
   void testValide2();
   void testValide3();
   void testInvalide1();
   void testInvalide2();
   void testInvalide3();
};

#endif
