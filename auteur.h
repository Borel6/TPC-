#include <iostream>
#include "date.h"


class Auteur{

public:

	Auteur(std::string pren, std::string name, Date date);

	
	std::string getnom() const;

	
	std::string getprenom() const;

	
	Date getdatenaissance() const;

	void setidentifiantnumerique(int identifi);
	int getidentifiantnumerique() const ;



	void tostring();



	bool operator == (const Auteur& a) const;
	bool operator != (const Auteur& a) const;


		private :

	std::string _nom;
	std::string _prenom;
	int _identifiantnumerique;
	Date _datedenaissance;


};


std::ostream& operator << (std::ostream& os, const Auteur& a);