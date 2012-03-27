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

#define CLEARSCREEN "clear"

using namespace std;

unordered_map<string, int> ATOMIC_NUMBER;
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



class Compound {

	vector<int> v_Elements; // container of each element, which will use atomic number instead of name
	int i_elements; // number of elements in the molecule
	vector<int> v_Quantities; // quantity of each element in the compound, in order
	float f_mass; // Mass of compound
	vector<float> v_Composition; // container of each element's percent comp
	string raw_molecule;
	
	public:
	Molecule(string s_molecule);
	void parseString();
	float findMass();
	void percentComp();
	float percentYield();
};

#endif
