#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

namespace ma{
	string UserRequest();										/* chiede all'utente una path per il boilerplate */
}

namespace head{
	string UserRequest();										/* chiede all'utente una path per il boilerplate */
}

namespace path{
	string UserRequest();										/* chiede all'utente una path per il boilerplate */
}

namespace msg{
	void init();												/* funzione decorativa per il terminale */
	void end(string, string, vector<string>);					/* funzione decorativa per il terminale */
}

void createFile(string, string);										/* crea un file con nome passato */
vector<string> requestAux();										/* chiede all'utente tutti i file ausiliari e li salva in un vettore */
void createDirectory(string); 										/* crea una directory per il progetto */
void linkFile(string, string, vector<string>, string);			/* inserisce il testo atto a collegare i file */
