
#include <vector>
#include "livre.h"

Livre::Livre ( Date datedepublication, std::string titrelivre, Auteur auteurlivre, std::string langue, std::string genre, bool dispo ): _datedepublication(datedepublication) , _titre(titrelivre) , _auteur(auteurlivre) , _langue (langue),_genre(genre),_dispo(dispo){
	_listeidlecteur.clear(); 
	_ibsn = rand() ;
}

	void Livre::settitre(std::string title) {
		_titre= title;
	};

	std::string Livre::gettitre() const{
		return _titre;
	};
	


	Auteur Livre::getnameAuteur() const {
		return _auteur;
	};

	void Livre::setlanguage(std::string language) {
		_langue = language;
	};

	std::string Livre::getlanguage()const {
		return _langue;
	}
	

	void Livre::setGenre(std::string Genre) {
		_genre = Genre;
	};
	

	std::string Livre::getGenre() const {
		return _genre;
	};



	Date Livre::getdatedepub() const{
		return _datedepublication ;
	};


	void Livre::setISBN(int isbn) {
		_ibsn = isbn;
	};



	int Livre::getISBN() const{
		return _ibsn;
	};





	void Livre::setdispo (bool dispo){
		_dispo = dispo ;
	};


	bool Livre::getdispo () const {
		return _dispo ;
	};


	std::vector<std::string> Livre::listeidlecteur() const {
		return _listeidlecteur ;

	}

	std::ostream& operator << (std::ostream& os, Livre& L){
	std::string to_display = "Titre : " + L.gettitre() + "\n langue : " + L.getlanguage() + "\n Genre : " + L.getGenre() + "\n ISBN : " + std::to_string(L.getISBN());
	to_display = to_display + " \n Liste des identifiants des emprunteurs : ";
		for (int i = 0; i < L.listeidlecteur().size(); ++i)
	{
		to_display = to_display + L.listeidlecteur().at(i) + " , ";
	}
	to_display = to_display + "\n Date de publication : ";
	os << to_display << L.getdatedepub() << std::endl << L.getnameAuteur() << std::endl;
	return os;
}

	bool Livre::operator == (const Livre& L) const{
	if( L.getISBN() == _ibsn){
		return true;
	}
	return false;

	}
bool Livre::operator != (const Livre& L) const{
		return !(*this==L);
	}
	







