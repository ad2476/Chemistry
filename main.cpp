#include "Chemistry.h"

int main()
{
	char choice;
	char again='y';
	
	while(again!='n')
	{
		cout << "Welcome to Chemistry!" << endl;
		cout << "---------------------" << endl;
		cout << "A) Calculate molar mass\n";
		cout << "B) Calculate percent composition\n";
		cout << "C) Calculate percent yield" << endl;
	
		cout << "> ";
		cin >> choice;

		Molecule c_molecule;
	
		if((choice=='a')||(choice=='A'))
			c_molecule.findMass();
		else if((choice=='b')||(choice=='B'))
			c_molecule.percentComp();
		else if((choice=='c')||(choice=='C'))
			c_molecule.percentYield
		else {
			cout << "Did you enter your choice correctly?" << endl;
			cin.get();
		}

		cout << "Again? (y/n)" << endl;
		cin >> again;
	}
	
	return 0;
}