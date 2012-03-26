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
	// islower() and isupper()
	string temp;
	for (int i=0; i<=raw_molecule.size(); i++) {
		if ((isupper(raw_molecule[i]))&&(i==0))
			temp=raw_molecule[i];
		else if(isupper(raw_molecule[i])&&(i!=0)) {
			// New element- so, convert to atomic # then store in v_Elements			
		}
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
	
		if ((choice=='c')||(choice=='C')) {
			// Bring up different screen
		}
		else {
			system(CLEARSCREEN);
			cout << "Enter the chemical formula of the compound" << endl;
			cout << "> ";
			cin >> formula;
			
			Compound c_molecule (formula);
			
			if ((choice=='a')||(choice=='A'))
				cout << "The molar mass of " << formula << " is: " << c_molecule.findMass();
			else if ((choice=='b')||(choice=='B'))
				c_molecule.percentComp();
			else {
				cout << "Did you enter a valid choice?";
				continue;
			}

		}


		cout << "Again? (y/n)" << endl;
		cin >> again;
	}
	
	return 0;
}
