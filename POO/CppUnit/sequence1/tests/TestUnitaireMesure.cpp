#include <cppunit/config/SourcePrefix.h>

#include "TestUnitaireMesure.h"
#include "mesure.h" // la classe à tester

// Enregistrement des différents cas de tests
CPPUNIT_TEST_SUITE_REGISTRATION( TestUnitaireMesure );

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TestUnitaireMesure::TestUnitaireMesure()
{

}

TestUnitaireMesure::~TestUnitaireMesure()
{

}

void TestUnitaireMesure::setUp() 
{
    // Initialisation pour les tests
    mesure = new Mesure;   
}

void TestUnitaireMesure::tearDown() 
{
    // fin du test
    delete mesure;
}

void TestUnitaireMesure::testReinitialiser()
{
	// Test 1
	
    // Appel méthode testée (lancement)
    mesure->reinitialiser();
    
    // Vérification des résultats attendus
    CPPUNIT_ASSERT_EQUAL( 0., mesure->getMesure() ); // valide
    CPPUNIT_ASSERT_EQUAL( 0., mesure->getMesureMin() ); // valide
    CPPUNIT_ASSERT_EQUAL( 0., mesure->getMesureMax() ); // valide
    CPPUNIT_ASSERT_EQUAL( 0, mesure->nbEchantillons() ); // valide
    
    // Test 2
    const int NB_ELT = 4;
	vector<double> echantillons(NB_ELT);
	
	echantillons[0] = 35.02;
	echantillons[1] = 35.10;
	echantillons[2] = 35.23;
	echantillons[3] = 35.53;
    
    mesure->ajouterEchantillons(echantillons);
    
    // Appel méthode testée (lancement)
    mesure->reinitialiser();

    // Vérification des résultats attendus
    CPPUNIT_ASSERT_EQUAL( 0., mesure->getMesure() ); // valide
    CPPUNIT_ASSERT_EQUAL( 0., mesure->getMesureMin() ); // valide
    CPPUNIT_ASSERT_EQUAL( 0., mesure->getMesureMax() ); // valide
    CPPUNIT_ASSERT_EQUAL( 0, mesure->nbEchantillons() ); // valide
}

void TestUnitaireMesure::testAjouterEchantillons()
{
	// Initialisation du test
	const int NB_ELT = 4;
	vector<double> echantillons(NB_ELT);
	
	echantillons[0] = 35.02;
	echantillons[1] = 35.10;
	echantillons[2] = 35.23;
	echantillons[3] = 35.53;
	
    mesure->reinitialiser();
    
    // Appel méthode testée (lancement)
    mesure->ajouterEchantillons(echantillons);

    // Vérification des résultats attendus    
    CPPUNIT_ASSERT_EQUAL( echantillons[0], mesure->getEchantillon(0) ); // valide
    CPPUNIT_ASSERT_EQUAL( echantillons[1], mesure->getEchantillon(1) ); // valide
    CPPUNIT_ASSERT_EQUAL( echantillons[2], mesure->getEchantillon(2) ); // valide
    CPPUNIT_ASSERT_EQUAL( echantillons[3], mesure->getEchantillon(3) ); // valide
    CPPUNIT_ASSERT_EQUAL( 0., mesure->getEchantillon(-1) ); // invalide
    CPPUNIT_ASSERT_EQUAL( 0., mesure->getEchantillon(4) ); // invalide
}

void TestUnitaireMesure::testEstTrie()
{
	// Initialisation du test
	const int NB_ELT = 4;
	vector<double> echantillons(NB_ELT);
	
	echantillons[0] = 35.02;
	echantillons[1] = 35.10;
	echantillons[2] = 35.23;
	echantillons[3] = 35.53;
	
    mesure->reinitialiser();
    mesure->ajouterEchantillons(echantillons);
    
    // Appel méthode testée (lancement)
    mesure->trier();

    // Vérification des résultats attendus
    // Le tableau doit être trié
    CPPUNIT_ASSERT_EQUAL( true, mesure->estTrie() );

    echantillons[0] = 35.10;
    echantillons[1] = 35.02;
	echantillons[2] = 35.53;
	echantillons[3] = 35.23;	
	
    mesure->reinitialiser();
    mesure->ajouterEchantillons(echantillons);

    // Vérification des résultats attendus
    // Le tableau n'est pas trié
    CPPUNIT_ASSERT_EQUAL( false, mesure->estTrie() );
}

void TestUnitaireMesure::testTriTaillePaire()
{
    // Initialisation du jeu de test :
    const int NB_ELT = 6;
    vector<double> echantillons(NB_ELT);
   
    echantillons[0] = 35.23;
	echantillons[1] = 35.53;
	echantillons[2] = 35.02;
	echantillons[3] = 35.10;
	echantillons[4] = 34.45;
    echantillons[5] = 35.40;

    mesure->reinitialiser();
    mesure->ajouterEchantillons(echantillons);

    // Appel méthode testée (lancement)
    mesure->trier();

    // Vérification des résultats attendus
    // Le tableau doit être trié
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "classe valide : le vector doit être trié (taille paire)", true, mesure->estTrie());
    
    // Vérifions que les échantillons sont maintenant triés
    CPPUNIT_ASSERT_EQUAL( echantillons[4], mesure->getEchantillon(0) );
    CPPUNIT_ASSERT_EQUAL( echantillons[2], mesure->getEchantillon(1) );
    CPPUNIT_ASSERT_EQUAL( echantillons[3], mesure->getEchantillon(2) );
    CPPUNIT_ASSERT_EQUAL( echantillons[0], mesure->getEchantillon(3) );
    CPPUNIT_ASSERT_EQUAL( echantillons[5], mesure->getEchantillon(4) );
}

void TestUnitaireMesure::testTriTailleImpaire()
{
    // Initialisation du jeu de test :
    const int NB_ELT = 5;
    vector<double> echantillons(NB_ELT);
   
    echantillons[0] = 35.23;
	echantillons[1] = 35.53;
	echantillons[2] = 35.02;
	echantillons[3] = 35.10;
	echantillons[4] = 34.45;

    mesure->reinitialiser();
    mesure->ajouterEchantillons(echantillons);

    // Appel méthode testée (lancement)
    mesure->trier();

    // Vérification des résultats attendus
    // Le tableau doit être trié
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "classe valide : le vector doit être trié (taille impaire)", true, mesure->estTrie());
    
    // Vérifions que les échantillons sont maintenant triés
    CPPUNIT_ASSERT_EQUAL( echantillons[4], mesure->getEchantillon(0) );
    CPPUNIT_ASSERT_EQUAL( echantillons[2], mesure->getEchantillon(1) );
    CPPUNIT_ASSERT_EQUAL( echantillons[3], mesure->getEchantillon(2) );
    CPPUNIT_ASSERT_EQUAL( echantillons[0], mesure->getEchantillon(3) );
}

void TestUnitaireMesure::testMesureMax()
{
    // Initialisation du test
	const int NB_ELT = 5;
	vector<double> echantillons(NB_ELT);
    double resultatAttendu = 39.00;

    // Test : premier échantillon du vector = valeur max
    echantillons[0] = resultatAttendu;
	echantillons[1] = 35.02;
	echantillons[2] = 35.10;
	echantillons[3] = 35.23;
	echantillons[4] = 35.53;
	
    mesure->reinitialiser();
    mesure->ajouterEchantillons(echantillons);

    // Vérification
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "classe valide 1 : premier échantillon du vector = valeur max", resultatAttendu, mesure->getMesureMax());

    // Test : dernier échantillon du vector = valeur max
    echantillons[0] = 35.23;
	echantillons[1] = 35.02;
	echantillons[2] = 35.10;
	echantillons[3] = 35.53;
	echantillons[4] = resultatAttendu;
	
    mesure->reinitialiser();
    mesure->ajouterEchantillons(echantillons);

    // Vérification
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "classe valide 2 : dernier échantillon du vector = valeur max", resultatAttendu, mesure->getMesureMax());   

    // Test : échantillon du milieu du vector = valeur max
    echantillons[0] = 35.23;
	echantillons[1] = 35.02;
	echantillons[2] = resultatAttendu;
	echantillons[3] = 35.53;
	echantillons[4] = 35.10;
	
    mesure->reinitialiser();            
    mesure->ajouterEchantillons(echantillons);

    // Vérification
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "classe valide 3 : échantillon du milieu du vector = valeur max", resultatAttendu, mesure->getMesureMax());     
}

void TestUnitaireMesure::testMesureMin()
{
    // Initialisation du test
	const int NB_ELT = 5;
	vector<double> echantillons(NB_ELT);
    double resultatAttendu = 34.00;

    // Test : premier échantillon du vector = valeur max
    echantillons[0] = resultatAttendu;
	echantillons[1] = 35.02;
	echantillons[2] = 35.10;
	echantillons[3] = 35.23;
	echantillons[4] = 35.53;
	
    mesure->reinitialiser();
    mesure->ajouterEchantillons(echantillons);

    // Vérification
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "classe valide 1 : échantillon le plus petit = résultat de getMesureMin() ", resultatAttendu, mesure->getMesureMin());
}

void TestUnitaireMesure::testGetEchantillon()
{
    // Initialisation du test
	const int NB_ELT = 5;
	vector<double> echantillons(NB_ELT);
    double resultatAttendu = 39.00;

    // Test : premier échantillon du vector = valeur max
    echantillons[0] = resultatAttendu;
	echantillons[1] = 35.02;
	echantillons[2] = 35.10;
	echantillons[3] = 35.23;
	echantillons[4] = 35.53;
	
    mesure->reinitialiser();
    mesure->ajouterEchantillons(echantillons);

    // Vérification
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "classe valide 1 : premier échantillon du vector = échantillation du get", resultatAttendu, mesure->getEchantillon(0));
}

void TestUnitaireMesure::testNbEchantillon()
{
    // Initialisation du test
	const int NB_ELT = 5;
	vector<double> echantillons(NB_ELT);

    // Test : premier échantillon du vector = valeur max
    echantillons[0] = 35.08;
	echantillons[1] = 35.02;
	echantillons[2] = 35.10;
	echantillons[3] = 35.23;
	echantillons[4] = 35.53;
	
    mesure->reinitialiser();
    mesure->ajouterEchantillons(echantillons);

    // Vérification
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "classe valide 1 : premier échantillon du vector = valeur max", NB_ELT, mesure->nbEchantillons());
}

void TestUnitaireMesure::testMesure()
{
    //Impaire

    const int NB_ELT_IMPAIRE = 5;
    vector<double> echantillonsImpaire(NB_ELT_IMPAIRE);
    double ResultatAttendueImpaire = 0.0;

    echantillonsImpaire[0] = 35.23;
	echantillonsImpaire[1] = 35.53;
	echantillonsImpaire[2] = 35.02;
	echantillonsImpaire[3] = 35.10;
	echantillonsImpaire[4] = 34.45;

    mesure->reinitialiser();
    mesure->ajouterEchantillons(echantillonsImpaire);

    ResultatAttendueImpaire = echantillonsImpaire[3];

    mesure->trier();

    CPPUNIT_ASSERT_EQUAL_MESSAGE( "classe valide : le vector doit être impaire", ResultatAttendueImpaire, mesure->getMesure());

    // Paire

    const int NB_ELT_PAIRE = 6;
    vector<double> echantillonsPaire(NB_ELT_PAIRE);
    double ResultatAttenduePaire = 0.0;
   
    echantillonsPaire[0] = 35.23;
	echantillonsPaire[1] = 35.53;
	echantillonsPaire[2] = 35.02;
	echantillonsPaire[3] = 35.10;
	echantillonsPaire[4] = 34.45;
    echantillonsPaire[5] = 35.40;

    mesure->reinitialiser();
    mesure->ajouterEchantillons(echantillonsPaire);

    ResultatAttenduePaire = (echantillonsPaire[0]+echantillonsPaire[3])/2;

    mesure->trier();

    CPPUNIT_ASSERT_EQUAL_MESSAGE( "classe valide : le vector doit être paire", ResultatAttenduePaire, mesure->getMesure());
}