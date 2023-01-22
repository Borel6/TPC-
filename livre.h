#include <iostream>
#include <vector>
#include "date.h"
#include "auteur.h"

class Livre
{ 


public:

 	Livre ( Date datedepublication, std::string titrelivre, Auteur auteurlivre, std::string langue, std::string genre , bool dispo);

	void settitre(std::string title);
	std::string gettitre() const;


	
	Auteur getnameAuteur() const ;


	void setlanguage(std::string language);
	std::string getlanguage() const ;


	void setGenre(std::string Genre);
	std::string getGenre() const ;

	
	Date getdatedepub() const;


	void setISBN(int isbn);
	int getISBN() const ;


	void setdispo (bool dispo);
	bool getdispo () const ;

	
	
	std::vector<std::string> listeidlecteur() const;

	bool operator == (const Livre& L) const;
	bool operator != (const Livre& L) const;


	private :
	Date _datedepublication;
	std::string _titre;
	Auteur _auteur;
	std::string _langue;
	std::string _genre;
	int _ibsn=0;
	bool _dispo ;
	std::vector<std::string> _listeidlecteur;
	



};

std::ostream& operator << (std::ostream& os, Livre& L);