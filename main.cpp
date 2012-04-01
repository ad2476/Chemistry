/* ------ CHEMISTRY ------ */
/*     By Arun Drelich     */

/* This software is provided for use free of charge and without any warranty whatsoever        */
/* It may not be sold for money without the consent of the author                              */
/* Please give credit where it is due- Even though it's free please do not remove this notice  */

#include "Chemistry.h"

Compound::Compound(string s_molecule) {
	vector<string> v_SubMols;
	string s_temp;
	setValues();
	
	raw_molecule=s_molecule;
	
	for (int i=0; i<=raw_molecule.length(); i++) {
		if (raw_molecule[i]=='(') {
			v_SubMols.push_back(s_temp);
			s_temp.clear();
			for (int j=i; raw_molecule[j-1]!=')'; j++) {
				s_temp+=raw_molecule[j];
				if (raw_molecule[j]==')') {
					if (isdigit(raw_molecule[j+1])) {
						s_temp+=raw_molecule[j+1];
						if (isdigit(raw_molecule[j+2]))
							s_temp+=raw_molecule[j+2];
					}
				}
				i=j;
			}
			v_SubMols.push_back(s_temp);
			s_temp.clear();
		}
		else if (isdigit(raw_molecule[i])) {
			if(raw_molecule[i-1]==')')
				continue;
			else if(raw_molecule[i-2]==')') {
				if (isdigit(raw_molecule[i-1]))
					continue;
			}
			else
				s_temp+=raw_molecule[i];
			
		}
		else
			s_temp+=raw_molecule[i];

	}
	v_SubMols.push_back(s_temp);
	
	for (int i=0; i<v_SubMols.size(); i++) {
		cout << v_SubMols[i] << endl;
	}
	/*
	if(!parseString()) {
		cout << "\nThere was an error parsing your formula. Are you sure that ";
		cout << raw_molecule << " is a valid compound?" << endl;
		again='n';
	} */
	
	f_mass=findMass();
}
bool Compound::parseString() {
	map<string,int>::const_iterator search;
	string s_temp;
	int i_temp;
	
	for (int i=0; i<=raw_molecule.length(); i++) {
		if ((isupper(raw_molecule[i]))&&(i==0))
			s_temp=raw_molecule[i];
		else if(isupper(raw_molecule[i])&&(i!=0)) {
			// New element- so, convert s_temp to atomic # then store in v_Elements
			search=ATOMIC_NUMBER.find (s_temp);
			if (search==ATOMIC_NUMBER.end()) 
				return false;// There is a problem
			else
				v_Elements.push_back(search->second); // Add atomic number into vector
			
			s_temp=raw_molecule[i]; // Replace temp with the new element

		}
		else if(islower(raw_molecule[i]))
			s_temp+=raw_molecule[i]; // E.g. N+=a which means temp=="Na"
		else
			continue; // It is a number/parentheses or something
	}
	// Whatever's in temp must be converted to atomic number and stored in vector
	search=ATOMIC_NUMBER.find (s_temp);
	if (search==ATOMIC_NUMBER.end()) 
		return false;// There is a problem
	else
		v_Elements.push_back(search->second); // Add atomic number into vector
	
	// --- Find quantities next --- // 
	for (int i=0; i<=raw_molecule.length(); i++) {
		if (isdigit(raw_molecule[i])) {
			if (toInt(raw_molecule[i])==0)
				return false;
			else if (isdigit(raw_molecule[i+1])) {
				if (isdigit(raw_molecule[i+2])) {
					i_temp=(toInt(raw_molecule[i])*100)+(toInt(raw_molecule[i+1])*10)+toInt(raw_molecule[i+2]);
					v_Quantities.push_back(i_temp);
				}
				else {
					i_temp=(toInt(raw_molecule[i])*10)+toInt(raw_molecule[i+1]);
					v_Quantities.push_back(i_temp);
				}
					
			}
			else if(!isdigit(raw_molecule[i-1])) { // Look back to make sure the digit is not part of a larger number
				v_Quantities.push_back(toInt(raw_molecule[i])); // This will not work for polyatomic ions
			}
		}
		else if(i<(raw_molecule.length()-1)) {
			if (isupper(raw_molecule[i+1])) {
				v_Quantities.push_back(1);
			}
		}
		// If there is no number, there is only 1 atom. Between O and N for example: O is upper, N is upper, O has 1.
		else if(i==(raw_molecule.length()-1)) {
			if (isalpha(raw_molecule[i]))
				v_Quantities.push_back(1);
		}
	}
	
	// --- For debugging only. Remove when complete. --- //
	cout << "v_Elements contents:" << endl;
	for (int i=0; i<v_Elements.size(); i++) {
		cout << i << ": " << v_Elements[i] << endl;
	}
	cout << "v_Quantities contents:" << endl;
	for (int i=0; i<v_Quantities.size(); i++) {
		cout << i << ": " << v_Quantities[i] << endl;
	}
	
	cout << "-----------------" << endl;
			
	return true;
}
				 
void Compound::percentComp() {
	int hash_lookup;
	map<string, int>::const_iterator search;
	vector<string> v_Output; 
	
	for (int i=0; i<v_Elements.size(); i++) {
		hash_lookup=v_Elements[i]; // Lookup the atomic # in the compound
		
		// Reverse-key lookup the element abbreviation
		for (search=ATOMIC_NUMBER.begin(); search!=ATOMIC_NUMBER.end(); search++) {
			if (search->second==v_Elements[i]) // If the # is part of the compound
				v_Output.push_back(search->first);
		}
		cout << v_Output[i] << ": " << ((ATOMIC_MASS[hash_lookup]*v_Quantities[i])/f_mass)*100 << "%" << endl;
	}
}
float Compound::findMass() {
	float mass=0;
	int hash_lookup;
	
	for (int i=0; i<v_Elements.size(); i++) {
		hash_lookup=v_Elements[i];
		mass+=ATOMIC_MASS[hash_lookup]*v_Quantities[i];
	}
	
	return mass;
}
float percentYield() {
}
int main() {
	char choice;
	again='y';
	string formula;
	
	while(again!='n')
	{
		system(CLEARSCREEN);
		cout << "Welcome to Chemistry!" << endl;
		cout << "---------------------" << endl;
		cout << "A) Calculate molar mass\n";
		cout << "B) Calculate percent composition\n";
		cout << "C) Calculate percent yield\n";
		cout << "D) Exit" << endl;
	
		cout << "> ";
		cin >> choice;
		
		choice=toupper(choice);
	
		if (choice=='C') {
			// Bring up different screen
		}
		else if (choice=='D')
			break;
		else {
			system(CLEARSCREEN);
			cout << "Enter the chemical formula of the compound. Proper capitalisation is imperative." << endl;
			cout << "> ";
			cin >> formula;
			
			Compound c_molecule (formula);
			
			if (choice=='A')
				cout << "The molar mass of " << formula << " is: " << c_molecule.findMass() << endl;
			else if (choice=='B')
				c_molecule.percentComp();
			else {
				cout << "Did you enter a valid choice?\nPress enter.";
				cout << choice;
				cin.get();
				cin.get();
				continue;
			}

		}


		cout << "\nAgain? (y/n)" << endl;
		cin >> again;
		again=tolower(again);
	}
	
	system(CLEARSCREEN);
	return 0;
}
