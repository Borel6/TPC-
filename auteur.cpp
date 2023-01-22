

#include <vector>
#include "auteur.h"


	
	Auteur::Auteur(std::string pren, std::string name, Date date) :
		_prenom(pren), _nom(name), _datedenaissance(date) {
			_identifiantnumerique += 1;

	};

	

	std::string Auteur::getnom() const {
		return _nom;
	}; 



	std::string  Auteur::getprenom() const{
		return _prenom;
	}; 



	Date Auteur::getdatenaissance() const{
		return _datedenaissance;
	}; 

	
	int  Auteur::getidentifiantnumerique() const {
		return _identifiantnumerique;

	};

	

	std::ostream& operator << (std::ostream& os, const Auteur& a){
	std::string to_display = "L'Auteur s'appelle " + a.getprenom() + " " + a.getnom() + "\n Il est née le ";
	os << to_display << a.getdatenaissance() << std::endl;
	return os;

}
	bool Auteur::operator == (const Auteur& a) const{
		if (a.getdatenaissance() == _datedenaissance && a.getidentifiantnumerique() == _identifiantnumerique && a.getnom() == _nom && a.getprenom() == _prenom)
		{
			return true;

		}
		return false;

	}
	bool Auteur::operator != (const Auteur& a) const{
		return !(*this == a);
	}










