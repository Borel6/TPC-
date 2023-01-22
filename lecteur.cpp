
#include "lecteur.h"




Lecteur::Lecteur(std::string nom, std::string prenom):_nom(nom),_prenom(prenom){

	_ibsnLivre.clear();
	_id = _prenom + _nom.substr(2);

}

	std::string Lecteur::id() const{
		return _id ;
	}

 	std::string Lecteur::nom() const{
 		return _nom ;
 	}
 	std::string Lecteur::prenom()const{
 		return _prenom;
 	}

 	std::vector<int> Lecteur::get_listeibsn() const{
 		return _ibsnLivre ;

 	}


	bool Lecteur::operator == (const Lecteur& L) const{
  if(_ibsnLivre.size() == L.get_listeibsn().size()){
  return true;
  }
  return false;
 }

 bool Lecteur::operator != (const Lecteur& L) const{
  if(_ibsnLivre.size() != L.get_listeibsn().size()){
  return true;
  }
  return false;
 }

	bool Lecteur::operator < (const Lecteur& L) const{
		
		 if(_ibsnLivre.size() < L.get_listeibsn().size()){
  return true;
  }
  return false;
 }
 bool Lecteur::operator <= (const Lecteur& L) const{
  if(*this == L) return true;
  if(*this < L) return true;
  return false;
 }
 bool Lecteur::operator >= (const Lecteur& L) const{
  return !(*this<L);
 }
 bool Lecteur::operator > (const Lecteur& L) const{
  return !(*this<=L);
 }





 	void Lecteur::setNom(std::string nom){
 		_nom = nom ;
 	}
 	void Lecteur::setPrenom(std::string prenom){
 		_prenom= prenom ;

 	}
 	void Lecteur::setId(std::string id){
 		_id = id ;
 	}

	void Lecteur::addibsn(int c){
		_ibsnLivre.push_back(c);
	}


std::ostream& operator << (std::ostream& os,  Lecteur& L){
	std::string to_display = "votre Identifiant est : " + L.id() + "\n Noms et prenoms : " + L.prenom() + " " + L.nom() + "\n";
	to_display = to_display + "Liste des livres empruntés : ";
		for (int i = 0; i < L.get_listeibsn().size(); i++)
	{
		to_display = to_display + std::to_string(L.get_listeibsn().at(i)) + " , ";
	}
	os << to_display << std::endl;
	return os;
}
