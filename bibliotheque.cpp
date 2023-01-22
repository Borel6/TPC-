#include "bibliotheque.h"
#include <ctime>
#include <string>
#include <iostream>
#include <algorithm>



Bibliotheque::Bibliotheque(){};


		void Bibliotheque::addlivre(Livre L){
			_livres.push_back(L);
		};
		void Bibliotheque::adduser(Lecteur L){
			_utilisateurs.push_back(L);
		};
		void Bibliotheque::addemprunt(Emprunt E){
			_historique.push_back(E);
		};

		void Bibliotheque::addauteur(Auteur A){
			_auteurs.push_back(A);
		}

	
   std::vector <Auteur> Bibliotheque::get_auteur() const{
	return _auteurs ;
   }
   std::vector <Emprunt> Bibliotheque::get_emprunt() const{
	return _historique ;
   }
   std::vector <Lecteur> Bibliotheque::get_lecteur() const {
	return _utilisateurs ;
   }

    std::vector <Livre> Bibliotheque::get_livre() const{
	return _livres ;
   }
   


 




		void Bibliotheque::emprunt(Lecteur& u, Livre& l){
			if ( l.getdispo()==true){
				time_t tmm = time(0);
				char* dt = ctime(&tmm);
				Emprunt e (dt,l.getISBN(),u.id() ) ;
				_historique.push_back(e);
				u.addibsn(l.getISBN());
				l.setdispo(false);
				l.listeidlecteur().push_back(u.id());

			}else{

				std::cout<< "désolé Monsieur " <<u.prenom() << " ce livre n'est pas disponible";
			}
		}


		void Bibliotheque::restitution(Lecteur& u, Livre& l){
			
			if ((u.id().compare(l.listeidlecteur().back())) == 0){
				l.setdispo(true);

			}

			std::cout << " vous ne pouvez pas rendre le livre emprunté par l'utilisateur :" << l.listeidlecteur().back() <<std::endl;

		}

std::ostream& operator << (std::ostream& os, const Bibliotheque& B){
 std::string to_display = "Informations de la Bibliotheque : \n Liste des auteurs : ";
  for (int i = 0; i < B.get_auteur().size(); ++i)
 {
  to_display = to_display + B.get_auteur().at(i).getprenom() + " " + B.get_auteur().at(i).getnom() + ", ";
 }
 to_display = to_display + "\n Liste des livres [ Livre(ISBN) ] : ";
  for (int i = 0; i < B.get_livre().size(); ++i)
 {
  to_display = to_display + B.get_livre().at(i).gettitre() + "(" + std::to_string(B.get_livre().at(i).getISBN()) + ")" + ", ";
 }

 to_display = to_display + "\n Liste des lecteurs [ Lecteur(ID) ] : ";
  for (int i = 0; i < B.get_lecteur().size(); ++i)
 {
  to_display = to_display + B.get_lecteur().at(i).prenom() + " " + B.get_lecteur().at(i).nom() + "(" + B.get_lecteur().at(i).id() + ")" + ", ";
 }

 to_display = to_display + "\n Liste des emprunts [ ISBN_Livre - ID_Lecteur - Date ] : ";
  for (int i = 0; i < B.get_emprunt().size(); ++i)
 {
  to_display = to_display + std::to_string(B.get_emprunt().at(i).getibsnEmprt()) + " - " + B.get_emprunt().at(i).getidlec() + "- " + B.get_emprunt().at(i).getdateEmprt() + ",";
 }
 os << to_display << std::endl;
 return os;
}


void Bibliotheque::livreDeLauteur (Auteur A){
 std::cout<<"Les livres [Livre(ISBN)] ecrits par "<< A.getprenom() <<" "<<A.getnom() <<" sont : "<<std::endl;
 for (int i = 0; i < _livres.size(); i++)
 {
  if (_livres.at(i).getnameAuteur() ==A)
  {
   std::cout<<_livres.at(i).gettitre() <<"("<<_livres.at(i).getISBN() << ")" <<std::endl;
  }
 }
 std::cout<<""<<std::endl;
}


 
		void Bibliotheque::livreEmprunteLecteur (Lecteur L){
			  std::cout<<"Les livres [Livre(ISBN)] empruntés  par "<< L.prenom() <<" "<<L.nom() <<" sont : "<<std::endl;
 for (int j=0; j < L.get_listeibsn().size(); j++)				  
 for (int i = 0; i < _livres.size(); i++)
 {
  if (_livres.at(i).getISBN() == L.get_listeibsn().at(j))
  {
   std::cout<<_livres.at(i).gettitre() <<"("<<_livres.at(i).getISBN() << ")" <<std::endl;
  }
 }
 std::cout<<""<<std::endl;
 
 
		}

	
void Bibliotheque::bestreader() {
	std::sort(_utilisateurs.begin(), 
	_utilisateurs.end(), 
	[](Lecteur& l1, Lecteur& l2) { return l1 < l2;});
}



void Bibliotheque::pourcentageLivre(){

 float moyenne=0;
 float nb=0;
 
 std::cout<<"Les livres [Livre(ISBN] empruntes sont : "<<std::endl;
 for (int i = 0; i < _livres.size() ; i++)
 {
  if (_livres.at(0).getdispo()==false)
  {
   nb=nb+1;
   
   
    std::cout<<_livres.at(i).gettitre() <<"("<<_livres.at(i).getISBN()<< ")" <<std::endl;
 
  }
 }
 moyenne = ( nb/_livres.size() )*100;
 std::cout<<"Le pourcentage de livre emprunte est : " << moyenne <<"%" <<std::endl;
}
