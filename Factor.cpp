/*
 *  Factor.cpp
 *  
 *
 *  Created by Arun on 30.10.2011.
 *  Copyright 2011 Arun. All rights reserved.
 *
 * FOR COMPILING ON WINDOWS: Make sure to change any system() functions to corresponding windows equivalent. 
 * e.g. "clear" becomes "cls"
 *
 */

#include "Factor.h"

#define CLEARSCREEN "cls"

void Factor(int a, int b, int c)
{
	/* Section I-Declare variables, make stuff amemable for use in later sections */
	int p=0;
	vector<int> factorsC;
	bool AC; // Store the truth a!=1 in a bool, to know later on to use AC method if AC=true
	negLC=(a<0); // Do the same if leading coefficient is negative
	
	// Given factored (lx+m)(nx+o)
	int l,m,n,o;
	
	// "Factor" out a negative if a<0
	if(negLC) {
		a/=-1;
		b/=-1;
		c/=-1;
	}
	
	AC=(a!=1);
	if(AC)
		c*=a;
	
	c=abs(c); // Make c positive. Factors' signs will be determined later anyway, and it makes things more difficult
	
	/* Section II- Find how many factors, fill factorsC with those factors etc */
	for(int i=1;i<=c;i++) {
		if((c%i)==0)
			p++;
	}
	// Make an array to hold each factor
	factorsC.resize(p);
	
	p=0; // "reset" p
	for(int i=1; i<=c; i++) {
		if((c%i)==0) {
			factorsC[p]=c/i;
			p++;
		}
	}
	
	/* Section IIB-If there's an odd number of factors, then one factor must be a
	 squareroot of c and should occur twice for Section III to work */
	if((p%2)!=0) {
		int square;
		for (unsigned int i=0; i<factorsC.size(); i++) {
			if(factorsC[i]*factorsC[i]==c) {
				square=factorsC[i];
				break;
			}
		}
		
		factorsC.push_back(square);
		sort(factorsC.begin(), factorsC.end());
	}
	
	/* Section III- Find which factors work as values for m and o */
	p=factorsC.size()-1;
	
	// let m=the first factor, o=the second
	for (unsigned int i=0; i<factorsC.size(); i++) {
		if ((factorsC[i]+factorsC[p-i])==b) {
			m=factorsC[i];
			o=factorsC[p-i];
			break; // found a factor pair
		}
		else if(((-1*factorsC[i])-factorsC[p-i])==b) {
			m=-1; o=-1; // both m and o are negative, as in the case of x^2-3x+2
			m*=factorsC[i];
			o*=factorsC[p-i];
		}
		else if((factorsC[i]-factorsC[p-i])==b) {
			m=factorsC[i];
			o=-1; // o is negative
			o*=factorsC[p-i];
			break;
		}
		else if((factorsC[p-i]-factorsC[i])==b) {
			m=-1; // m is negative
			m*=factorsC[i];
			o=factorsC[p-i];
			break; 
		}
	}
	
	/* Section IIIB-If a is not 1, then use AC method */
	if(AC) {
		l=a; n=a;
		m*=a; o*=a;
		// For version 1.0, don't bother reducing to the LCF yet. See if it just works at all.
	}
	else {
		l=1; n=1; }
	
	displayFactored(l,m,n,o);
	
	return;
}
void help()
{
     system(CLEARSCREEN);
     cout << "About the program:" << endl;
     cout << "-------------------" << endl;
     cout << "This program factors a quadratic in standard form using human-like" << endl;
     cout << "factoring techniques." << endl;

     cout <<"\nHow to use it:" << endl;
     cout << "-----------------" << endl;
     cout << "Please be sure to enter the quadratic in the form:" << endl;
     cout << "\tax^2+bx+c\nwhere a and c are not equal to 0." << endl;
     cout << "Note that the program understands the lack of a coefficient to signify a 1." << endl;
     cout << "Please don't use spaces or variables other than x." << endl;
     cout << "\nRemember: If you get a very large answer that is clearly wrong, ask yourself:" << endl;
     cout << "\"Is this expression factorable?\"" << endl;
     
     cout << "\nAbout the developer:" << endl;
     cout << "-----------------------" << endl;
     cout << "You can contact Arun at: ad2476@gmail.com" << endl;
     cout << "Please don't steal this program. Sharing is fine," << endl;
     cout << "Just make sure you mention where you got it from." << endl;
     
     cout << "\nPress [Enter] to go back to the main screen." << endl;
     
     cin.get(); cin.get();
}
int main()
{
	int a,b,c;
	string polynomial;
	
	while(true)
	{
        polynomial.clear();
        system(CLEARSCREEN);
	    cout << "Welcome to Factor v. 0.6!" << endl;
	    cout << "---------------------------" << endl;
	    cout << "Please enter a polynomial in the form ax^2+bx+c." << endl;
	    cout << "Example: x^2+3x-10. Please follow the format given. Enter help for more info.\n" << endl;
	    cout << ">> ";
	    cin >> polynomial;
	    
	    if(polynomial=="quit")
            return 0;
        else if(polynomial=="help") {
            help();
            continue;
        }
	
	    if(findCoefficients(a,b,c,polynomial)==1) {
            if((a==0)||(c==0))
                cout << "\nHerp! Something went wrong! Make sure a or c don't equal 0." << endl;
            else
                Factor(a,b,c);
        }
	
	    cout << "\n\n\nAgain (yes/no)?" << endl;
	    cout << ">> ";
	    cin >> polynomial;
	    
	    if((polynomial=="n")||(polynomial=="no"))
            return 0;
    }
    
    cout << "\nThank you for using Factor v. 0.6!";
	return 0;
}
