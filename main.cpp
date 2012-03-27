/* ------ CHEMISTRY ------ */
/*     By Arun Drelich     */

/* This software is provided for use free of charge and without any warranty whatsoever        */
/* It may not be sold for money without the consent of the author                              */
/* Please give credit where it is due- Even though it's free please do not remove this notice  */

#include "Chemistry.h"

Compound::Compound(string s_molecule) {
	raw_molecule=s_molecule;
	parseString();
	
	f_mass=findMass();
}
void Compound::parseString() {
	unordered_map<string,int>::const_iterator search;
	string temp;
	
	for (int i=0; i<=raw_molecule.size(); i++) {
		if ((isupper(raw_molecule[i]))&&(i==0))
			temp=raw_molecule[i];
		else if(isupper(raw_molecule[i])&&(i!=0)) {
			// New element- so, convert temp to atomic # then store in v_Elements
			search=ATOMIC_NUMBER.find (temp);
			if (search==ATOMIC_NUMBER.end()) 
				// There is a problem
			else
				v_Elements.push_back(search->second); // Add atomic number into vector
			
			temp=raw_molecule[i]; // Replace temp with the new element

		}
		else if(islower(raw_molecule[i]))
			temp+=raw_molecule[i]; // E.g. N+=a which means temp=="Na"
		else
			continue; // It is a number/parentheses or something
	}
}
void Compound::percentComp() {
}
float Compound::findMass() {
}
float percentYield() {
}
int main() {
	char choice;
	char again='y';
	string formula;
	locale loc;
	
	while(again!='n')
	{
		system(CLEARSCREEN);
		cout << "Welcome to Chemistry!" << endl;
		cout << "---------------------" << endl;
		cout << "A) Calculate molar mass\n";
		cout << "B) Calculate percent composition\n";
		cout << "C) Calculate percent yield" << endl;
	
		cout << "> ";
		cin >> choice;
		
		tolower(choice, loc);
	
		if (choice=='c') {
			// Bring up different screen
		}
		else {
			system(CLEARSCREEN);
			cout << "Enter the chemical formula of the compound" << endl;
			cout << "> ";
			cin >> formula;
			
			Compound c_molecule (formula);
			
			if (choice=='a')
				cout << "The molar mass of " << formula << " is: " << c_molecule.findMass();
			else if (choice=='b')
				c_molecule.percentComp();
			else {
				cout << "Did you enter a valid choice?\nPress enter.";
				cin.get();
				continue;
			}

		}


		cout << "Again? (y/n)" << endl;
		cin >> again;
		tolower(again,loc);
	}
	
	return 0;
}
