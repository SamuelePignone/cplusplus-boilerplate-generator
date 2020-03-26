#include "header.h"
#include <sys/stat.h> 
#include <sys/types.h> 

void msg::init(){
	cout << "\x1B[2J\x1B[H";
	cout << "\e[8;40;170t";
	cout << "\033[3;47;35m";
	cout << R"(

  _____                ____          _  _                     _         _           _____                                 _                
 / ____|  _      _    |  _ \        (_)| |                   | |       | |         / ____|                               | |               
| |     _| |_  _| |_  | |_) |  ___   _ | |  ___  _ __  _ __  | |  __ _ | |_  ___  | |  __   ___  _ __    ___  _ __  __ _ | |_   ___   _ __ 
| |    |_   _||_   _| |  _ <  / _ \ | || | / _ \| '__|| '_ \ | | / _` || __|/ _ \ | | |_ | / _ \| '_ \  / _ \| '__|/ _` || __| / _ \ | '__|
| |____  |_|    |_|   | |_) || (_) || || ||  __/| |   | |_) || || (_| || |_|  __/ | |__| ||  __/| | | ||  __/| |  | (_| || |_ | (_) || |   
 \_____|              |____/  \___/ |_||_| \___||_|   | .__/ |_| \__,_| \__|\___|  \_____| \___||_| |_| \___||_|   \__,_| \__| \___/ |_|   
	                                              | |                                                                                  
	                                              |_|                                                                                  
)" << endl;
	cout << "\033[0m";
}

string ma::UserRequest(){
	string name;
	cout << "Insert a name for the main file: ";
	getline(cin, name);
	return name = name.substr(0, name.find(".", 0))+".cpp";
}

string head::UserRequest(){
	string header; 
	cout << "Insert a name for the header file: ";
	getline(cin, header);
	return header = header.substr(0, header.find(".", 0))+".h";
}

string path::UserRequest(){
	string directory; 
	cout << "Insert the path where boilerplate's files will be created: ";
	getline(cin, directory);
	return isspace(directory[directory.size()-1]) ? directory.substr(0, directory.size()-1) : directory;
}

vector<string> requestAux(){
	vector<string> aux;
	char choice;
	string tmp;
	do {
		cout << "Insert a name for the auxiliary file: ";
		cin >> tmp;
		tmp = tmp.substr(0, tmp.find(".", 0))+".cpp";
		if(find(aux.begin(), aux.end(), tmp) != aux.end()) {
		    choice = 'y';
		    cout << "\n\033[1;31mInsert a different name from the previous ones!\033[0m\n" << endl;
		} else {
		    aux.push_back(tmp);
			cout << "Create another auxiliary file? (y/N) ";
			cin >> choice;
		}
	} while(choice == 'y' || choice == 'Y');
	return aux;
}

void createFile(string nome, string directory){
	ofstream myfile(directory + "/" + nome);
}

void linkFile(string main_name, string header_name, vector<string> aux_name, string directory){
	ofstream main(directory + "/" + main_name);
	main << "#include \""+header_name+"\"\n\nint main(){\n\n\n\treturn 0;\n}";
	ofstream header(directory + "/" + header_name);
	header << "#include <iostream>\n\nusing namespace std;\n\n/* Functions prototypes and namespace implementation*/";
	for (int i=0; i<aux_name.size(); i++){
		ofstream aux(directory + "/" + aux_name[i]);
		aux << "#include \""+header_name+"\"\n\n/*Functions' implementation */";
	}
}

void msg::end(string project_name, string name, vector<string> aux){
	cout << "\n\nThanks for using c++ boilerplate generator.\n\n\033[1;35mIn order to compile just use this command:\n\ng++ "+name+" ";
	for (int i=0; i<aux.size(); i++) cout << aux[i]+" ";
	cout << "or simply g++ *.cpp!";
	cout << "\033[0m\n\n\nCopyright @samuelepignone & @milogalli\n\nFollow us on github:\n\n\t@SamuelePignone\n\t@Peek-Ink\n" << endl;
}









