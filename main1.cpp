
#include "date.h"

#include "bibliotheque.h"

#include<vector>

int main(int argc, char const *argv[])
{
	

Auteur GF("Flaubert","Gustave",Date(5,8,1880));
Auteur AC("Albert","Camus",Date(10,7,1913));
Auteur EZ("Emile","Zola",Date(4,1,1840));
Auteur JPS("Jean-paul","Sartre",Date(6,21,1905));
Auteur MK("Masashi","Kishimoto",Date(11,8,1974));
Auteur EO("Echiro","Oda",Date(1,1,1975));

Livre l1 ( Date(1,1,1938),"La nausée" , JPS , "Français" , "Philosophiue" , true);
Livre l2 ( Date(4,2,1948),"Les Mains sales" , JPS , "Français" , "Théâtre" , true);
Livre l3 ( Date(1,15,1856),"Madame bovary" , GF , "Français" , "roman" , true);
Livre l4 ( Date(1,1,1862),"Salamnbô" , GF , "Français" , "roman" , true);
Livre l5 ( Date(1,1,1942),"L'Étranger" , AC , "Français" , "roman" , true);
Livre l6 ( Date(6,10,1957),"La Peste" , AC , "Français" , "roman" , true);
Livre l7 ( Date(1,1,1883),"Au Bonheur des Dames" , EZ, "Français" , "roman" , true);
Livre l8 ( Date(1,1,1873),"Le Ventre de Paris" , EZ , "Français" , "roman" , true);
Livre l9 ( Date(9,21,1905),"Naruto" ,MK  , "Français" , "genre" , true);
Livre l10 ( Date(12,24,1997),"One piece" , EO , "Français" , "genre" , true);

Lecteur lec1 ("borel" , "styve");
Lecteur lec2 ("ivan" , "junior");
Lecteur lec3 ("yannick" , "edward");

Bibliotheque B ;
B.adduser(lec1);
B.adduser(lec2);
B.adduser(lec3);

B.addlivre(l1);
B.addlivre(l2);
B.addlivre(l3);
B.addlivre(l4);
B.addlivre(l5);
B.addlivre(l6);
B.addlivre(l7);
B.addlivre(l8);
B.addlivre(l9);
B.addlivre(l10);

B.addauteur(GF);
B.addauteur(EZ);
B.addauteur(MK);
B.addauteur(EO);
B.addauteur(JPS);
B.addauteur(AC);

B.emprunt(lec1, l2);
B.emprunt(lec1, l9);
B.emprunt(lec2, l4);
B.emprunt(lec2, l5);
B.emprunt(lec2, l8);
B.emprunt(lec3, l9);


if(lec2 > lec1){
	std::cout<< "ok pour la surcharge" <<std::endl ;
};

std::cout<< B.get_emprunt().at(0) << std::endl ;

B.bestreader();


std::cout<< lec1.get_listeibsn().size()<<std::endl ;
std::cout<< lec3.get_listeibsn().size()<<std::endl ;
std::cout<< lec2.get_listeibsn().size()<<std::endl ;










	return 1;
}