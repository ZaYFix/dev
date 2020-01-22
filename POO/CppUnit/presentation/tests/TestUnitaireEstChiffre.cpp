#include <cppunit/config/SourcePrefix.h>

#include "TestUnitaireEstChiffre.h"
#include "exemple.h" // la fonction à tester

// Enregistrement des différents cas de tests
CPPUNIT_TEST_SUITE_REGISTRATION( TestUnitaireEstChiffre );

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TestUnitaireEstChiffre::TestUnitaireEstChiffre()
{

}

TestUnitaireEstChiffre::~TestUnitaireEstChiffre()
{

}

void TestUnitaireEstChiffre::setUp() 
{
    // Initialisation pour les tests
}

void TestUnitaireEstChiffre::tearDown() 
{
    // fin du test
}

void TestUnitaireEstChiffre::testValide1()
{
    // Valide n°1 : un chiffre au milieu de la plage
    char c = '5';
    bool resultatAttendu = true;
    bool resultatObtenu;
    
    resultatObtenu = estChiffre(c);
   
    CPPUNIT_ASSERT_EQUAL( resultatAttendu, resultatObtenu );
}

void TestUnitaireEstChiffre::testValide2()
{
    // Valide n°2 : le premier chiffre de la plage
    char c = '0';
    bool resultatAttendu = true;
    bool resultatObtenu;
    
    resultatObtenu = estChiffre(c);   
    
    // avec un message :
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "le premier chiffre de la plage", resultatAttendu, resultatObtenu );
}

void TestUnitaireEstChiffre::testValide3()
{
    // Valide n°3 : le dernier chiffre de la plage
    char c = '9';
    bool resultatAttendu = true;
    bool resultatObtenu;
    
    resultatObtenu = estChiffre(c);
   
    // avec un message : (autre façon)
    CPPUNIT_ASSERT_MESSAGE("le dernier chiffre de la plage", (resultatAttendu == resultatObtenu) );
}

void TestUnitaireEstChiffre::testInvalide1()
{
    // Invalide n°1 : pas un chiffre
    char c = 'A';
    bool resultatAttendu = false;
    bool resultatObtenu;
    
    resultatObtenu = estChiffre(c);
   
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "un caractère qui n'est pas un chiffre", resultatAttendu, resultatObtenu );
}

void TestUnitaireEstChiffre::testInvalide2()
{
    // Invalide n°2 : le caractère précédent le premier chiffre de la plage
    char c = '/';
    bool resultatAttendu = false;
    bool resultatObtenu;
    
    resultatObtenu = estChiffre(c);
   
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "le caractère précédent le premier chiffre de la plage", resultatAttendu, resultatObtenu );
}

void TestUnitaireEstChiffre::testInvalide3()
{
    // Invalide n°3 : le caractère suivant le dernier chiffre de la plage
    //CPPUNIT_FAIL( "TODO : le caractère suivant le dernier chiffre de la plage" );
    char c = ':';
    bool resultatAttendu = false;
    bool resultatObtenu;
    
    resultatObtenu = estChiffre(c);
   
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "le caractère suivant le dernier chiffre de la plage", resultatAttendu, resultatObtenu );
}
