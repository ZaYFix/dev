#include "IHM.h"
#include <ctime> // pour avoir le temps
#include <stdlib.h> // pour clear la fenêtre
#include <iostream> // pour cout et cin

using namespace std;

IHM::IHM(JeuPoulePoule *jeuPoulePoule): jeuPoulePoule(jeuPoulePoule), reponseJoueurNbOeufs(0), reponseQuestion('\0'), \
reponseRelancerManche('\0'), reponseQuestionFinDePartie('\0')
{
    joueur = new Joueur;
}

IHM::~IHM()
{
    delete joueur;
}

void IHM::afficherNomJeu() const
{
    cout << endl;
    cout << " `7MM```Mq.   .g8``8q. `7MMF'   `7MF'`7MMF'      `7MM```YMM      `7MM```Mq.   .g8``8q. `7MMF'   `7MF'`7MMF'      `7MM```YMM\n";
    cout << "   MM   `MM..dP'    `YM. MM       M    MM          MM    `7        MM   `MM..dP'    `YM. MM       M    MM          MM    `7\n";
    cout << "   MM   ,M9 dM'      `MM MM       M    MM          MM   d          MM   ,M9 dM'      `MM MM       M    MM          MM   d\n";
    cout << "   MMmmdM9  MM        MM MM       M    MM          MMmmMM          MMmmdM9  MM        MM MM       M    MM          MMmmMM\n";
    cout << "   MM       MM.      ,MP MM       M    MM      ,   MM   Y  ,       MM       MM.      ,MP MM       M    MM      ,   MM   Y  ,\n";
    cout << "   MM       `Mb.    ,dP' YM.     ,M    MM     ,M   MM     ,M       MM       `Mb.    ,dP' YM.     ,M    MM     ,M   MM     ,M\n";
    cout << " .JMML.       ``bmmd`'    `bmmmmd`'  .JMMmmmmMMM .JMMmmmmMMM     .JMML.       ``bmmd`'    `bmmmmd`'  .JMMmmmmMMM .JMMmmmmMMM\n";
    cout << "                                                                                                                        v"<<VERSION<<"\n";
}

void IHM::afficherRegles() const
{
    cout << "Tout d'abord, voici les règles : \n";
    cout << endl;
    cout << "Le Maître de Poule Poule (MPP) sera l'ordinateur durant toute la durée du jeu.\n";
    cout << "Le MPP va empiler les cartes, une par une, les unes sur les autres au centre de la table.\n"; 
    cout << "Une fois posées, ces cartes composeront le Film. Pendant ce temps, le joueur devra compter les Œufs !\n";
    cout << endl;
    cout << "Voici les cartes disponibles pour ce niveau 1 : 15 Œufs, 10 Poules et 10 Renards et un coq.\n";
    cout << endl;
    cout << "Quand un oeuf arrive dans le film : c'est un oeuf disponible." << endl;
    cout << "Quand une poule arrive et qu'un oeuf est disponible, l'oeuf devient indisponible." << endl;
    cout << "Quand un renard arrive après une poule, il la chasse et l'oeuf redevient alors disponible." << endl;
    cout << "Quand un chien arrive, il reste dans la basse cour et chassera le prochain renard." << endl;
    cout << "Quand un ver arrive, il attire la prochaine poule." << endl;
    cout << "Quand un canard arrive, rien ne change." << endl;
    cout << "Lorsqu'un coq arrive, la manche est finie, indiquez le nombre d'oeuf disponible. \n";
    cout << endl;
    cout << "Vous remportez 1 point par bonne réponse et gagnez la partie au bout de 3 points." << endl << endl;
}

void IHM::afficherCarte(TypeCarte typeCarte, bool afficheNumeroCarte) const
{    
    cout << " * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << " *                                           *\n";
    cout << " *                                           *\n";
    switch (typeCarte)
    {
    case POULE:
        afficherCartePoule();      
        break;    
    case OEUF: 
        afficherCarteOeuf();       
        break;
    case RENARD:
        afficherCarteRenard();        
        break;    
    case COQ:
        afficherCarteCoq();
        break;
    case CHIEN:
        afficherCarteChien();
        break;
    case CANARD:
        afficherCarteCanard();
        break;
    case VER:
        afficherCarteVer();
    default:
        break;
    }
    cout << " *                                           *\n";
    if(!afficheNumeroCarte)
    {
        if (this->jeuPoulePoule->getNumCarte() > NB_MAX_POUR_UN_CARACTERE_ESPACE)
        {
            //on retire un caractère d'espace 
            cout << " *                   - " << this->jeuPoulePoule->getNumCarte() << " -                  *\n";
        }
        else
        {
            cout << " *                   - " << this->jeuPoulePoule->getNumCarte() << " -                   *\n";
        }
    }
    else
    {
        cout << " *                                           *\n";
    }
    cout << " *                                           *\n";
    cout << " * * * * * * * * * * * * * * * * * * * * * * *\n";
}

void IHM::afficherCarteOeuf() const
{
    cout << " *                  ████████                 *\n";
    cout << " *                ██        ██               *\n";
    cout << " *              ██            ██             *\n";
    cout << " *            ██                ██           *\n";
    cout << " *            ██                ██           *\n";
    cout << " *          ██                    ██         *\n";
    cout << " *          ██                    ██         *\n";
    cout << " *        ██                        ██       *\n";
    cout << " *        ██                        ██       *\n";
    cout << " *        ██                        ██       *\n";
    cout << " *        ██                        ██       *\n";
    cout << " *          ██                    ██         *\n";
    cout << " *          ██                    ██         *\n";
    cout << " *            ██                ██           *\n";
    cout << " *              ████        ████             *\n";
    cout << " *                  ████████                 *\n";
    cout << " *                                           *\n";
}

void IHM::afficherCartePoule() const
{
    cout << " *          ,~.                              *\n";
    cout << " *       ,-'__ `-,                           *\n";
    cout << " *      {,-'  `. }              ,')          *\n";
    cout << " *     ,( a )   `-.__         ,',')~,        *\n";
    cout << " *    <=.) (         `-.__,==' ' ' '}        *\n";
    cout << " *        ')                        /)       *\n";
    cout << " *          \\   ,                    )       *\n";
    cout << " *           |  \\       `~.         /        *\n";
    cout << " *           \\   `._        \\      /         *\n";
    cout << " *            \\     `._____,'    ,'          *\n";
    cout << " *             `-.             ,'            *\n";
    cout << " *                `-._     _,-'              *\n";
    cout << " *                    77jj'                  *\n";
    cout << " *                   //_||                   *\n";
    cout << " *                __//--'/`                  *\n";
    cout << " *              ,--'/`  '                    *\n";
    cout << " *                                           *\n";
}

void IHM::afficherCarteRenard() const
{
    cout << " *              ,-.      .-,                 *\n";
    cout << " *              |-.\\ __ /.-|                 *\n";
    cout << " *              \\  `    `  /                 *\n";
    cout << " *              / _     _  \\                 *\n";
    cout << " *              | _`q  p _ |                 *\n";
    cout << " *              '._=/  \\=_.'                 *\n";
    cout << " *                |`\\()/` `\\                 *\n";
    cout << " *                |         \\                *\n";
    cout << " *                |         \\                *\n";
    cout << " *                \\ ,--,   .- \\              *\n";
    cout << " *                |-'    '/    \\             *\n";
    cout << " *                | | | | |     ;            *\n";
    cout << " *                | | |.;.,..__ |            *\n";
    cout << " *              .-"";`           `|            *\n";
    cout << " *             /    |           /            *\n";
    cout << " *             `-../____,..---'`             *\n";
    cout << " *                                           *\n";
}

void IHM::afficherCarteCoq() const
{
    cout << " *                                           *\n"; 
    cout << " *                                           *\n"; 
    cout << " *                                           *\n"; 
    cout << " *         ___//             ________        *\n";
    cout << " *        /@_ \\            / / / _/ \\        *\n";
    cout << " *        ~ O\\ \\_         | /_/_/ _//\\       *\n";
    cout << " *          o \\  \\________/// / //__/'''     *\n";
    cout << " *             |  \\           ___/           *\n";
    cout << " *             \\_ \\___________/              *\n";
    cout << " *                 \\___    __/               *\n";
    cout << " *                     \\  /                  *\n";
    cout << " *                     || |                  *\n";
    cout << " *                     || |                  *\n";
    cout << " *                   _/_/|\\_                 *\n";
    cout << " *                                           *\n"; 
    cout << " *                                           *\n"; 
    cout << " *                                           *\n"; 
}

void IHM::afficherCarteChien() const
{
    cout << " *                                           *\n";              
    cout << " *            ,'._,_. 7\\                     *\n";
    cout << " *           j `-'     /                     *\n";
    cout << " *           |o_, o    \\                     *\n";
    cout << " *          .`_y_`-,'   !                    *\n";
    cout << " *          |/   `, `._ `-,                  *\n";
    cout << " *          |_     \\   _.'*\\                 *\n";
    cout << " *            >--,-'`-'*_*'``---.            *\n";
    cout << " *          |\\_* _*'-'         '             *\n";
    cout << " *           /    `               \\          *\n";
    cout << " *           \\.         _ .       /          *\n";
    cout << " *            '`._     /   )     /           *\n";
    cout << " *             \\  |`-,-|  /c-'7 /            *\n";
    cout << " *              ) \\ (_,| |   / (_            *\n";
    cout << " *             ((_/   ((_;)  \\_)))           *\n";
    cout << " *                                           *\n";
    cout << " *                                           *\n";


}

void IHM::afficherCarteCanard() const
{
    cout << " *         ,--``~:-.                         *\n";
    cout << " *       ,'         `.                       *\n";
    cout << " *      ; (((__   __)))                      *\n";
    cout << " *      ;  ( (#) ( (#)                       *\n";
    cout << " *      |   \\_/___\\_/|                       *\n";
    cout << " *     ,'  ,-'    '__'.                      *\n";
    cout << " *    (   ( ._   ____`.)--._        _        *\n";
    cout << " *     `._ `-.`-' \\(`-'  _  `-. _,-' `-/`.   *\n";
    cout << " *      ,')   `.`._))  ,' `.   `.  ,','  ;   *\n";
    cout << " *    .'  .     `--'  /     ).   `.      ;   *\n";
    cout << " *   ;     `-        /     '  )         ;    *\n";
    cout << " *   \\                       ')       ,'     *\n";
    cout << " *    \\                     ,'       ;       *\n";
    cout << " *     \\               `~~~'       ,'        *\n";
    cout << " *      `.                      _,'          *\n";
    cout << " *        `.                ,--'             *\n";
    cout << " *          `-._________,--'                 *\n";
}

void IHM::afficherCarteVer() const
{
    cout << " *                                           *\n";
    cout << " *                                           *\n";
    cout << " *                                           *\n";
    cout << " *                              _-~~-_       *\n";
    cout << " *                             /     \\       *\n";
    cout << " *                            /       |      *\n";
    cout << " *                           /   \\  * |      *\n";
    cout << " *             ________     /    /\\__/       *\n";
    cout << " *     _      /        \\   /    /            *\n";
    cout << " *    / \\    /  ____    \\_/    /             *\n";
    cout << " *   //\\ \\  /  /    \\         /              *\n";
    cout << " *   V  \\ \\/  /      \\       /               *\n";
    cout << " *       \\___/        \\_____/                *\n";
    cout << " *                                           *\n";
    cout << " *                                           *\n";
    cout << " *                                           *\n";
    cout << " *                                           *\n";
}

void IHM::effacerIHM() const
{
    #ifndef DEBUG
    system("clear");
    #endif
}

void IHM::afficherExemple()
{
    this->effacerIHM();

    this->afficherCarte(OEUF, true);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->effacerIHM();

    this->afficherCarte(RENARD, true);
    cout << endl << "Il n'y a pas de poule, le renard passe son chemin." << endl << endl;
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->effacerIHM();

    this->afficherCarte(OEUF, true);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->effacerIHM();

    this->afficherCarte(POULE, true);
    cout << endl << "Il y a 2 oeufs disponibles, donc la poule couvre 1 oeuf, il ne reste qu'un oeuf disponible." << endl << endl;
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->effacerIHM();

    this->afficherCarte(VER, true);
    cout << endl << "Un ver arrive, il va distraire la prochaine poule" << endl << endl;
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->effacerIHM();

    this->afficherCarte(POULE, true);
    cout << endl << "Il y a 1 oeuf disponible, mais il y a un ver, la poule est distraite par le ver , il reste 1 oeuf." << endl << endl;
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->effacerIHM();

    this->afficherCarte(POULE, true);
    cout << endl << "Il y a 1 oeuf disponible, donc la poule couvre l'oeuf, il n'y a aucun oeuf disponible." << endl << endl;
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->effacerIHM();

    this->afficherCarte(OEUF, true);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->effacerIHM();

    this->afficherCarte(CHIEN, true);
    cout << endl << "Un chien arrive dans la basse-cour, il va chasser le prochain renard." << endl << endl;
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->effacerIHM();

    this->afficherCarte(RENARD, true);
    cout << endl << "Un renard arrive, il y a un chien, le renard est chassé par le chien." << endl << endl;
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->effacerIHM();

    this->afficherCarte(CHIEN, true);
    cout << endl << "Un chien arrive dans la basse-cour, il va chasser le prochain renard." << endl << endl;
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->effacerIHM();

    this->afficherCarte(CANARD, true);
    cout << endl << "Rien ne se passe le canard est juste là pour vous perturber." << endl << endl;
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->attendre(TEMPS_AFFICHAGE_EXEMPLE);
    this->effacerIHM();

    cout << "Il y a donc 1 oeuf disponible." << endl;

    fairePartieDemonstration();
}

void IHM::fairePartieDemonstration()
{
    do
    {
        cout << "Voulez-vous jouer une partie de démonstration ? (o/n)" << endl;
        setReponseQuestion();
    }
    while (getReponseQuestion() != 'o' && getReponseQuestion() != 'n');

    if (getReponseQuestion() == 'o' )
        {
            this->afficherCarte(OEUF, true);
            this->jeuPoulePoule->setNbOeufs(1);
            afficherQuestionPartieDemo();
            
            this->afficherCarte(POULE, true);
            this->jeuPoulePoule->setNbOeufs(0);
            afficherQuestionPartieDemo();
            
            this->afficherCarte(CHIEN);
            this->jeuPoulePoule->setNbOeufs(0);
            afficherQuestionPartieDemo();

            this->afficherCarte(POULE, true);
            this->jeuPoulePoule->setNbOeufs(0);
            afficherQuestionPartieDemo();

            this->afficherCarte(RENARD, true);
            this->jeuPoulePoule->setNbOeufs(0);
            afficherQuestionPartieDemo();

            this->afficherCarte(RENARD, true);
            this->jeuPoulePoule->setNbOeufs(1);
            afficherQuestionPartieDemo();
            
            this->afficherCarte(CANARD, true);
            this->jeuPoulePoule->setNbOeufs(1);
            afficherQuestionPartieDemo();

            this->afficherCarte(OEUF, true);
            this->jeuPoulePoule->setNbOeufs(2);
            afficherQuestionPartieDemo();

            this->afficherCarte(VER, true);
            this->jeuPoulePoule->setNbOeufs(2);
            afficherQuestionPartieDemo();

            this->afficherCarte(POULE, true);
            this->jeuPoulePoule->setNbOeufs(1);
            afficherQuestionPartieDemo();

            afficherNbTotalOeufs();
        }
}

void IHM::afficherQuestionPartieDemo()
{
    setReponseJoueurNbOeufs();
    if (getReponseJoueurNbOeufs() != this->jeuPoulePoule->getNbOeufsDisponible())
    {
        cout << "Non il y en a " << this->jeuPoulePoule->getNbOeufsDisponible() << endl;
    }
}

void IHM::attendre(unsigned int tempsAffichageDefini) const
{
    unsigned long int tempsReel = time(NULL);
    unsigned long int tempsAffichage = tempsReel + tempsAffichageDefini;

    while(tempsAffichage > tempsReel)
    {
        tempsReel = time(NULL);
    }
}

void IHM::afficherBienvenue() const
{
    cout << "Bonjour et bienvenue ! ";
}

void IHM::demanderNom()
{
    string nomJoueur = "\0";
    cout << "Quel est votre nom ? ";
    cin >> nomJoueur;
    cout << endl;
    joueur->setNomJoueur(nomJoueur);
}

void IHM::afficherQuestionExemple()
{
    cout << "Voulez-vous un exemple ? (o/n)" << endl;
    this->setReponseQuestion();
    switch(reponseQuestion)
    {
        case 'o':
            afficherExemple();
            break;
        case 'n':
            break;
        default:
            afficherValeurIncorrecte();
            afficherQuestionExemple();
    }
}

void IHM::afficherGagnerPartie()
{
    cout << endl;
    cout << "Bravo " << joueur->getNomJoueur() << " ! Vous avez comptabilité 3 points, vous avez donc gagné la partie !" << endl;
    afficherQuestionFinDePartie();
}

void IHM::afficherQuestionFinDeManche()
{
    cout << "Combien y'a t'il d'oeuf(s) disponible(s) ? ";
    cin >> reponseJoueurNbOeufs;
}

void IHM::afficherQuestionFinDePartie()
{
    cout << "Voulez-vous rejouer ou quitter ? (o/n)" << endl;
    cin >> reponseQuestionFinDePartie;
    switch(reponseQuestionFinDePartie)
    {
        case 'o':
            jeuPoulePoule->reinitialiserNbPoint();
            jeuPoulePoule->rejouer();
            break;
        case 'n':
            cout << "A bientôt " << joueur->getNomJoueur() << " !" << endl;
            exit(0);
    }
}

void IHM::afficherBravoManche()
{
    cout << endl;
    cout << "Bravo " << joueur->getNomJoueur() << " vous avez gagné une manche !" << endl;
    cout << "Il ne vous reste plus que " << NOMBRE_DE_MANCHE - jeuPoulePoule->getNbPoints() << " manche(s) pour gagner la partie !" << endl;
    afficherRelancerManche();
}

void IHM::afficherRelancerManche()
{
    cout << "Êtes-vous prêt à relancer une manche ? (o)";
    cin >> reponseRelancerManche;
    if(reponseRelancerManche == 'o')
    {
        jeuPoulePoule->rejouer();
    }
    else
    {
        afficherRelancerManche();
    }
}

void IHM::afficherMauvaiseReponse()
{
    cout << "Dommage ! Il y a " << jeuPoulePoule->getNbOeufsDisponible() << " Oeufs et non pas " << reponseJoueurNbOeufs << " !" << endl;
    cout << "Vous ne gagnez donc pas de point ! Vous avez "<< jeuPoulePoule->getNbPoints() << " point(s) !" << endl;
    afficherRelancerManche();
}

void IHM::afficherRevoirPartie() const
{
    cout << "Voulez vous revoir la partie " << joueur->getNomJoueur() << " ? (o/n)" << endl;
}

void IHM::afficherNbTotalOeufs() const
{
    cout << endl;
    cout << "Donc il y a au total " << jeuPoulePoule->getNbOeufsDisponible() << " oeuf(s)." << endl;
}

void IHM::afficherNbTotalOeufsActuel() const
{
    cout << endl;
    cout << "Il y a " << jeuPoulePoule->getNbOeufsDisponible() << " oeuf(s)." << endl;
    cout << endl;
}

void IHM::afficherValeurIncorrecte() const
{
    cout << endl;
    cout << "Valeur incorrecte ! Veuillez réessayer." << endl;
    cout << endl;
}

// accesseur(s)
char IHM::getReponseQuestion() const
{
    return this->reponseQuestion;
}

unsigned int IHM::getReponseJoueurNbOeufs() const
{
    return this->reponseJoueurNbOeufs;
}

// mutateur(s)
void IHM::setReponseQuestion()
{
    cin >> reponseQuestion;
    this->reponseQuestion = reponseQuestion;
}

void IHM::setReponseJoueurNbOeufs()
{
    cout << endl << "Combien y a t-il d'oeuf ? : ";
    cin >> reponseJoueurNbOeufs;
    this->reponseJoueurNbOeufs = reponseJoueurNbOeufs;
}