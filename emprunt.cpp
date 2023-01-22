#include "emprunt.h"



Emprunt::Emprunt(std::string dateEmprt , int ibsnEmprt, std::string idlec): _dateEmprt(dateEmprt), _ibsnEmprt(ibsnEmprt), _idEmprt(idlec) {

};


std::string Emprunt::getdateEmprt() const{
	return _dateEmprt;

};

int Emprunt::getibsnEmprt() const {
	return _ibsnEmprt;
};
std::string Emprunt::getidlec() const{
	return _idEmprt ;
};

std::ostream& operator << (std::ostream& os, Emprunt& e){
    os << "Date d'emprunt : " << e.getdateEmprt() << "\n ISBN du livre: " << e.getibsnEmprt() << "\n id du Lecteur : " << e.getidlec();
	return os ;
}
