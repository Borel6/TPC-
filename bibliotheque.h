#pragma once

#include <iostream>
#include "livre.h"
#include "lecteur.h"
#include "emprunt.h"
#include <vector>




class Bibliotheque{



public:
		Bibliotheque();
		void addlivre(Livre L);
		void adduser(Lecteur L);
		void addauteur(Auteur A);
		void addemprunt(Emprunt E);
		void emprunt(Lecteur& u, Livre& l) ;
		void restitution(Lecteur& u, Livre& l);
		void livreDeLauteur (Auteur A);
		void livreEmprunteLecteur (Lecteur L);
	
		void bestreader();
		void pourcentageLivre();




   std::vector <Auteur> get_auteur() const;
   std::vector <Emprunt> get_emprunt() const;
   std::vector <Lecteur> get_lecteur() const ;
   std::vector <Livre> get_livre() const;

	




private:

	std::vector<Livre> _livres ;
	std::vector<Lecteur> _utilisateurs ;
	std::vector<Emprunt> _historique;
	std::vector<Auteur> _auteurs;




};
std::ostream& operator << (std::ostream& os, const Bibliotheque& B);