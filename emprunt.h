#include <iostream>




class Emprunt
{
public:

	Emprunt(std::string dateEmprt , int _ibsnEmprt, std::string _idlec) ;

	
	std::string getdateEmprt() const;
	int getibsnEmprt() const ;
	std::string getidlec() const;

private :

	std::string _dateEmprt ;
	int _ibsnEmprt ;
	std::string _idEmprt;



};
std::ostream& operator << (std::ostream& os, Emprunt& e);