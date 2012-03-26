#ifndef _CHEMISTRY_H_
	#define _CHEMISTRY_H_

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Compound {

	vector<int> v_Elements; // container of each element, which will use atomic number instead of name
	int elements; // number of elements in the molecule
	vector<int> quantities; // quantity of each element in the compound, in order
	string molecule; // Raw input containing the formula

	public:
	Molecule();
	void parseString();
	float findMass();
	float percentComp();
	float percentYield();
};

#endif