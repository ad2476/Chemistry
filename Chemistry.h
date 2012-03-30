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
	float ATOMIC_MASS[];
	
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
	
	
	ATOMIC_MASS[1]=1.008;
	ATOMIC_MASS[3]=6.941;
	ATOMIC_MASS[4]=9.012;
	ATOMIC_MASS[5]=10.81;
	ATOMIC_MASS[6]=12.01;
	ATOMIC_MASS[7]=14.01;
	ATOMIC_MASS[8]=16.00;
	ATOMIC_MASS[9]=19.00;
	ATOMIC_MASS[11]=22.99;
	ATOMIC_MASS[12]=24.31;
	ATOMIC_MASS[13]=26.98;
	ATOMIC_MASS[14]=28.09;
	ATOMIC_MASS[15]=30.97;
	ATOMIC_MASS[16]=32.07;
	ATOMIC_MASS[17]=35.45;
	ATOMIC_MASS[19]=39.10;
	ATOMIC_MASS[20]=40.08;
	ATOMIC_MASS[21]=44.96;
	ATOMIC_MASS[22]=47.87;
	ATOMIC_MASS[24]=52.00;
	ATOMIC_MASS[25]=54.94;
	ATOMIC_MASS[26]=55.85;
	ATOMIC_MASS[27]=58.93;
	ATOMIC_MASS[28]=58.69;
	ATOMIC_MASS[29]=63.55;
	ATOMIC_MASS[30]=65.39;
	ATOMIC_MASS[31]=69.72;
	ATOMIC_MASS[32]=72.61;
	ATOMIC_MASS[33]=74.92;
	ATOMIC_MASS[34]=78.96;
	ATOMIC_MASS[35]=79.90;
	ATOMIC_MASS[37]=85.47;
	ATOMIC_MASS[38]=87.62;
	ATOMIC_MASS[40]=91.22;
	ATOMIC_MASS[47]=107.9;
	ATOMIC_MASS[48]=112.4;
	ATOMIC_MASS[49]=114.8;
	ATOMIC_MASS[50]=118.7;
	ATOMIC_MASS[51]=121.8;
	ATOMIC_MASS[53]=126.9;
	ATOMIC_MASS[54]=131.3;
	ATOMIC_MASS[55]=132.9;
	ATOMIC_MASS[56]=137.3;
	ATOMIC_MASS[76]=190.2;
	ATOMIC_MASS[78]=195.1;
	ATOMIC_MASS[79]=197.0;
	ATOMIC_MASS[80]=200.6;
	ATOMIC_MASS[82]=207.2;
	// 0.0 means an unused (for the purposes of the program) element. Have the program check mass!0.0 before proceeding
	// to ensure no errors were made.

}

