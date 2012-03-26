#ifndef _CHEMISTRY_H_
	#define _CHEMISTRY_H_

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define CLEARSCREEN "clear"

using namespace std;

class Compound {

	vector<int> v_Elements; // container of each element, which will use atomic number instead of name
	int i_elements; // number of elements in the molecule
	vector<int> v_Quantities; // quantity of each element in the compound, in order
	float f_mass; // Mass of compound
	vector<float> v_Composition; // container of each element's percent comp
	
	public:
	Molecule(string s_molecule);
	void parseString();
	void findMass();
	void percentComp();
	float percentYield();
};

#endif
