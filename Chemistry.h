/* ------ CHEMISTRY ------ */
/*     By Arun Drelich     */

/* This software is provided for use free of charge and without any warranty whatsoever        */
/* It may not be sold for money without the consent of the author                              */
/* Please give credit where it is due- Even though it's free please do not remove this notice  */

#ifndef _CHEMISTRY_H_
	#define _CHEMISTRY_H_

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <locale>
#include <cctype>
#include <sstream>

#define CLEARSCREEN "clear"

using namespace std;

char again;

class Compound {
	
	vector<int> v_Elements; // container of each element, which will use atomic number instead of name
	int i_elements; // number of elements in the molecule
	vector<int> v_Quantities; // quantity of each element in the compound, in order
	float f_mass; // Mass of compound
	vector<float> v_Composition; // container of each element's percent comp
	string raw_molecule;
	
public:
	Molecule(string s_molecule);
	bool parseString();
	float findMass();
	void percentComp();
	float percentYield();
};

int toInt(const char* str) {
	int i_str;
	stringstream convert(str);
	
	if (!(convert >> i_str))
		i_str=0;
	
	return i_str;
}

// --- Database of element info: --- //

unordered_map<string, int> ATOMIC_NUMBER = {
	{"H",1}
	{"Li",3}
	{"Be",4}
	{"B",5}
	{"C",6}
	{"N",7}
	{"O",8}
	{"F",9}
	{"Na",11}
	{"Mg",12}
	{"Al",13}
	{"Si",14}
	{"P",15}
	{"S",16}
	{"Cl",17}
	{"K",19}
	{"Ca",20}
	{"Sc",21}
	{"Ti",22}
	{"Cr",24}
	{"Mn",25}
	{"Fe",26}
	{"Co",27}
	{"Ni",28}
	{"Cu",29}
	{"Zn",30}
	{"Ga",31}
	{"Ge",32}
	{"As",33}
	{"Se",34}
	{"Br",35}
	{"Rb",37}
	{"Sr",38}
	{"Zr",40}
	{"Ag",47}
	{"Cd",48}
	{"In",49}
	{"Sn",50}
	{"Sb",51}
	{"I",53}
	{"Xe",54}
	{"Cs",55}
	{"Ba",56}
	{"Os",76}
	{"Pt",78}
	{"Au",79}
	{"Hg",80}
	{"Pb",82} };

const float ATOMIC_MASS[82]={0.0, 1.008, 0.0, 6.941, 9.012, 10.81, 12.01, 14.01, 16.00, 19.00, 0.0, 22.99, 24.31, 26.98, 
	28.09, 30.97, 32.07, 35.45, 0.0, 39.10, 40.08, 44.96, 47.87, 0.0, 52.00, 54.94, 55.85, 58.93, 58.69, 63.55, 65.39, 
	69.72, 72.61, 74.92, 78.96, 79.90, 0.0, 85.47, 87.62, 0.0, 91.22, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 107.9, 112.4, 114.8, 
	118.7, 121.8, 0.0, 126.9, 131.3, 132.9, 137.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
	0.0, 0.0, 0.0, 0.0, 0.0, 190.2, 0.0, 195.1, 197.0, 200.6, 0, 207.2};
	// 0.0 means an unused (for the purposes of the program) element. Have the program check mass!0.0 before proceeding
	// to ensure no errors were made.

#endif
