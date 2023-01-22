#include <iostream>
#include<vector>


 class Lecteur {

 public:

 	Lecteur(std::string nom, std::string prenom) ;

 	std::string id() const;
 	std::string nom() const;
 	std::string prenom()const;
    std::vector <int> get_listeibsn() const;
    bool operator == (const Lecteur& L) const;
	bool operator != (const Lecteur& L) const;
    bool operator < (const Lecteur& L) const;
    bool operator <= (const Lecteur& L) const;
    bool operator > (const Lecteur& L) const;
    bool operator >= (const Lecteur& L) const;
	

    
 	void setNom(std::string nom);
 	void setPrenom(std::string prenom);
 	void setId(std::string id);
	void addibsn(int c);
	



    



 	private :
 	std::string _id ;
 	std::string _nom ;
 	std::string _prenom;
 	std::vector <int> _ibsnLivre ;





 };

std::ostream& operator << (std::ostream& os, Lecteur& L);