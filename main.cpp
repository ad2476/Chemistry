#include "Chemistry.h"


int main()
{
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
				c_molecule.findMass();
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
