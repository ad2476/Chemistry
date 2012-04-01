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
	
	if((raw_molecule.find("(")!=string::npos)&&(raw_molecule.find(")")==string::npos)) {
		cout << "You appear to be missing an end parenthesis.\n" << endl;
		raw_molecule.clear();
		again='n';
	}
	else if((raw_molecule.find("(")==string::npos)&&(raw_molecule.find(")")!=string::npos)) {
		cout << "You appear to have forgotten a starting parenthesis.\n" << endl;
		raw_molecule.clear();
		again='n';
	}
	else if((raw_molecule.find("(")!=string::npos)&&(raw_molecule.find(")")!=string::npos)) {
		for (int i=0; i<raw_molecule.length(); i++) {
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
		if (!s_temp.empty())
			v_SubMols.push_back(s_temp);
	}
	else
		v_SubMols.push_back(raw_molecule);
	
	for (int i=0; i<v_SubMols.size(); i++) {
		if(!v_SubMols[i].empty()) {
			if(!parseString(v_SubMols[i])) {
				cout << "\nThere was an error parsing your formula. Are you sure that ";
				cout << v_SubMols[i] << " is a valid compound?" << endl;
				again='n';
			}
		}
	}
	
	f_mass=findMass();
}
bool Compound::parseString(string s_compound) {
	map<string,int>::const_iterator search;
	vector<int> v_Temp; // To hold the temporary quantities
	string s_temp;
	int i_temp;
	
	// Check if the passed arg refers to a polyatomic ion
	int scalar=1;
	if (s_compound[0]=='(') {
		// Search for quantity at the end of the string
		size_t find_paren=s_compound.find(")");
		
		find_paren+=1;
		for (int i=int(find_paren); i<s_compound.length(); i++) {
			if (toInt(s_compound[i])==0)
				return false;
			else if (isdigit(s_compound[i+1])) {
				if (isdigit(s_compound[i+2])) {
					i_temp=(toInt(s_compound[i])*100)+(toInt(s_compound[i+1])*10)+toInt(s_compound[i+2]);
					scalar=i_temp;
				}
				else {
					i_temp=(toInt(s_compound[i])*10)+toInt(s_compound[i+1]);
					scalar=i_temp;
				}
				
			}
			else
				scalar=toInt(s_compound[i]);
		}
		s_compound.erase(s_compound.begin());
		s_compound.erase(find_paren-1, s_compound.length());
	}
	
	for (int i=0; i<=s_compound.length(); i++) {
		if ((isupper(s_compound[i]))&&(i==0))
			s_temp=s_compound[i];
		else if(isupper(s_compound[i])&&(i!=0)) {
			// New element- so, convert s_temp to atomic # then store in v_Elements
			search=ATOMIC_NUMBER.find (s_temp);
			if (search==ATOMIC_NUMBER.end()) 
				return false;// There is a problem
			else
				v_Elements.push_back(search->second); // Add atomic number into vector
			
			s_temp=s_compound[i]; // Replace temp with the new element
			
		}
		else if(islower(s_compound[i]))
			s_temp+=s_compound[i]; // E.g. N+=a which means temp=="Na"
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
	for (int i=0; i<=s_compound.length(); i++) {
		if (isdigit(s_compound[i])) {
			if (toInt(s_compound[i])==0)
				return false;
			else if (isdigit(s_compound[i+1])) {
				if (isdigit(s_compound[i+2])) {
					i_temp=(toInt(s_compound[i])*100)+(toInt(s_compound[i+1])*10)+toInt(s_compound[i+2]);
					v_Temp.push_back(i_temp);
				}
				else {
					i_temp=(toInt(s_compound[i])*10)+toInt(s_compound[i+1]);
					v_Temp.push_back(i_temp);
				}
				
			}
			else if(!isdigit(s_compound[i-1])) { // Look back to make sure the digit is not part of a larger number
				v_Temp.push_back(toInt(s_compound[i])); // This will not work for polyatomic ions
			}
		}
		else if(i<(s_compound.length()-1)) {
			if (isupper(s_compound[i+1])) {
				v_Temp.push_back(1);
			}
		}
		// If there is no number, there is only 1 atom. Between O and N for example: O is upper, N is upper, O has 1.
		else if(i==(s_compound.length()-1)) {
			if (isalpha(s_compound[i]))
				v_Temp.push_back(1);
		}
	}
	
	// Multiply each element of the vector by the scalar
	for (int i=0; i<v_Temp.size(); i++) {
		v_Temp[i]*=scalar;
		v_Quantities.push_back(v_Temp[i]);
	}
	
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
void help() {
	system(CLEARSCREEN);
	cout << "Available commands:\n" << endl;
	cout << "mass <compound>\t\t\tFind the molar mass of <compound>" << endl;
	cout << "weight <compound>\t\tSame as mass" << endl;
	cout << "pcomp <compound>\t\tFind the percent composition of each element in <compound>" << endl;
	cout << "tomole <grams> <compound>\tFind the number of moles in <grams> of <compound>" << endl;
	cout << "\nMore features coming soon!" << endl;
	cout << "\n[Press enter]" << endl;
}
int main() {
	string choice;
	again='y';
	string formula;
	float grams;
	int pos;
	string temp;
	
	while(again!='n')
	{
		system(CLEARSCREEN);

		cout << "For information on commands: \"help\". To quit: \"quit\"\n" << endl;
		cout << ">> ";
		getline(cin, choice);
		
	
		if (choice=="quit")
			break;
		else if(choice=="help"){
			help();
			cin.get(); continue;
		}
		else if (choice.find("pyield")==string::npos) {
			system(CLEARSCREEN);
			formula=choice.substr(choice.find_last_of(" ")+1);
			
			Compound c_molecule (formula);
			
			if ((choice.find("mass")!=string::npos)||(choice.find("weight")!=string::npos))
				cout << "The molar mass of " << formula << " is: " << c_molecule.findMass() << endl;
			else if (choice.find("pcomp")!=string::npos)
				c_molecule.percentComp();
			else if (choice.find("tomole")!=string::npos) {
				for (int i=0; i<choice.length(); i++) {
					if(isdigit(choice[i]))
						temp+=choice[i];
				}
				grams=atoi(temp.c_str());
				
				system(CLEARSCREEN);
				cout << "In " << grams << "g of " << formula << ", there are ";
				cout << grams/c_molecule.findMass() << " moles" << endl;
			}
			else {
				help();
				cin.get(); continue;
			}

		}
		else {
			help();
			cin.get(); continue;
		}

		cout << "\n\nPress enter to continue. " << endl;
		cin.get();
	}
	
	system(CLEARSCREEN);
	return 0;
}
