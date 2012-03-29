/* ------ CHEMISTRY ------ */
/*     By Arun Drelich     */

/* This software is provided for use free of charge and without any warranty whatsoever        */
/* It may not be sold for money without the consent of the author                              */
/* Please give credit where it is due- Even though it's free please do not remove this notice  */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <locale>
#include <cctype>
#include <sstream>

#define CLEARSCREEN "clear"

using namespace std;

char again;

class Compound {
	map<string, int> ATOMIC_NUMBER;
	vector<int> v_Elements; // container of each element, which will use atomic number instead of name
	int i_elements; // number of elements in the molecule
	vector<int> v_Quantities; // quantity of each element in the compound, in order
	float f_mass; // Mass of compound
	vector<float> v_Composition; // container of each element's percent comp
	string raw_molecule;
	
public:
	Compound(string s_molecule);
	void setValues();
	bool parseString();
	float findMass();
	void percentComp();
	float percentYield();
};

int toInt(char str) {
	int i_str;
	i_str=atoi(&str);
	
	return i_str;
}

void Compound::setValues() {
	// --- Database of element info: --- //
	
	ATOMIC_NUMBER["H"]=1;
	ATOMIC_NUMBER["Li"]=3;
	ATOMIC_NUMBER["Be"]=4;
	ATOMIC_NUMBER["B"]=5;
	ATOMIC_NUMBER["C"]=6;
	ATOMIC_NUMBER["N"]=7;
	ATOMIC_NUMBER["O"]=8;
	ATOMIC_NUMBER["F"]=9;
	ATOMIC_NUMBER["Na"]=11;
	ATOMIC_NUMBER["Mg"]=12;
	ATOMIC_NUMBER["Al"]=13;
	ATOMIC_NUMBER["Si"]=14;
	ATOMIC_NUMBER["P"]=15;
	ATOMIC_NUMBER["S"]=16;
	ATOMIC_NUMBER["Cl"]=17;
	ATOMIC_NUMBER["K"]=19;
	ATOMIC_NUMBER["Ca"]=20;
	ATOMIC_NUMBER["Sc"]=21;
	ATOMIC_NUMBER["Ti"]=22;
	ATOMIC_NUMBER["Cr"]=24;
	ATOMIC_NUMBER["Mn"]=25;
	ATOMIC_NUMBER["Fe"]=26;
	ATOMIC_NUMBER["Co"]=27;
	ATOMIC_NUMBER["Ni"]=28;
	ATOMIC_NUMBER["Cu"]=29;
	ATOMIC_NUMBER["Zn"]=30;
	ATOMIC_NUMBER["Ga"]=31;
	ATOMIC_NUMBER["Ge"]=32;
	ATOMIC_NUMBER["As"]=33;
	ATOMIC_NUMBER["Se"]=34;
	ATOMIC_NUMBER["Br"]=35;
	ATOMIC_NUMBER["Rb"]=37;
	ATOMIC_NUMBER["Sr"]=38;
	ATOMIC_NUMBER["Zr"]=40;
	ATOMIC_NUMBER["Ag"]=47;
	ATOMIC_NUMBER["Cd"]=48;
	ATOMIC_NUMBER["In"]=49;
	ATOMIC_NUMBER["Sn"]=50;
	ATOMIC_NUMBER["Sb"]=51;
	ATOMIC_NUMBER["I"]=53;
	ATOMIC_NUMBER["Xe"]=54;
	ATOMIC_NUMBER["Cs"]=55;
	ATOMIC_NUMBER["Ba"]=56;
	ATOMIC_NUMBER["Os"]=76;
	ATOMIC_NUMBER["Pt"]=78;
	ATOMIC_NUMBER["Au"]=79;
	ATOMIC_NUMBER["Hg"]=80;
	ATOMIC_NUMBER["Pb"]=82;
	
	float ATOMIC_MASS[83]={0.0, 1.008, 0.0, 6.941, 9.012, 10.81, 12.01, 14.01, 16.00, 19.00, 0.0, 22.99, 24.31, 26.98, 
		28.09, 30.97, 32.07, 35.45, 0.0, 39.10, 40.08, 44.96, 47.87, 0.0, 52.00, 54.94, 55.85, 58.93, 58.69, 63.55, 65.39, 
		69.72, 72.61, 74.92, 78.96, 79.90, 0.0, 85.47, 87.62, 0.0, 91.22, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 107.9, 112.4, 114.8, 
		118.7, 121.8, 0.0, 126.9, 131.3, 132.9, 137.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
		0.0, 0.0, 0.0, 0.0, 0.0, 190.2, 0.0, 195.1, 197.0, 200.6, 0, 207.2};
	// 0.0 means an unused (for the purposes of the program) element. Have the program check mass!0.0 before proceeding
	// to ensure no errors were made.
}

