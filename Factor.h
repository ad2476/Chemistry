/*
 *  Factor.h
 *  
 *
 *  Created by Arun on 20.11.11.
 *  Copyright 2011 Arun Drelich. All rights reserved.
 *
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

bool negLC;

void displayFactored(int l, int m, int n, int o)
{
    string not_factorable;
    if(m>10000){
        cout << "\nWarning: Your expression was most likely not factorable!" << endl;
        cout << "View result anyway? (yes/no) ";
        cin >> not_factorable;
        
        if(not_factorable=="no")
            return;
    }
    
	cout << "\nFactored expression: ";
	if(negLC)
		cout << "-";
	cout << "(";
	
	if(l==1)
		cout << "";
	else
		cout << l;
	
	cout << "x";
	if (m<0)
		cout << "";
	else
		cout << "+";
	
	cout << m << ")(";
	
	if(n==1)
		cout << "";
	else
		cout << n;
	
	cout << "x";
	if(o<0)
		cout << "";
	else
		cout << "+";
	
	cout << o << ")";

	cin.get();
	return;
}
string stringErr(string missing)
{
       return "\nError! "+missing+" is missing from your input.";
}
int findCoefficients(int& a, int& b, int& c, string& polynomial)
{
	int t1, t2,t3;
	
	/* Find whether or not a is negative */
	if(polynomial[0]=='-') {
		polynomial.erase(0,1);
		a=-1; // a*=temp_a later on.
	}
	else
		a=1;
	
	// Replace x with a comma, to later be able to distinguish coefficients with a for loop
	t1=polynomial.find("x");
	if(t1==string::npos) {
        cout << stringErr("First x");
        return 2; }
        
	polynomial[t1]=',';
	
	if(polynomial.find("^")==string::npos) {
        cout << stringErr("^");
        return 2; }
        
	// Find whether b is negative or positive, and also record the location of the addition/subtraction sign
	if (polynomial[(polynomial.find("^")+2)]=='+') {
		t2=polynomial.find("+");
		b=1;
	}
	else if(polynomial[(polynomial.find("^")+2)]=='-') {
		t2=polynomial.find("-");
		b=-1;
	}
	
	if(t2==string::npos) {
        cout << stringErr("Addition/subtraction sign");
        return 2; }
	
	if((t2+1)=='x') // If there is no coefficient before x, i.e. x=+/-1...
		polynomial.insert((t2+1),"1");
	
	// erase from the carat to the addition/subtraction sign
	polynomial.erase((polynomial.begin()+polynomial.find("^")), (polynomial.begin()+t2+1));
	
	t3=polynomial.find("x"); // Find where the next 'x' is
	if(t3==string::npos) {
        cout << stringErr("Second x");
        return 2; }
	
	if(polynomial[(t3+1)]=='+') /* Determine the sign of c. Since we're using 'x' to find the 		
								   consecutive value (i.e. the sign), t3 can be substituted for polynomial.find("x") */
		c=1;
	else if(polynomial[(t3+1)]=='-')
		c=-1;
	
	polynomial[t3]=','; /* Replace that x AFTER finding the value after it (much easier, since 'x' is known, 
						 while the sign/numbers aren't. */
	
	polynomial.erase((polynomial.begin()+t3+1),(polynomial.begin()+t3+2)); // Remove the sign.
	
	/* By now, there should be no more non-integer values left in the string (apart from the commas).
	 So we can proceed to find each coefficient, isolate the number, and convert to int. */
	
	/* -------FIND A:------- */
	unsigned int i;
	int temp_a;
	string A;
	stringstream ss; stringstream bb;
	string s;
	
	if(polynomial.find(",")!=0) { // If the first value is not a comma, which would mean used to be x
		ss << polynomial[0];
		A=ss.str();
		ss.clear(); ss.str("");
		for (i=1; i!=polynomial.find(","); i++) {
			// Should hopefully concatenate strings
			ss << polynomial[i-1];
			bb << polynomial[i];
			A=ss.str()+bb.str();
		}
		ss.clear(); ss.str(A);
		ss >> temp_a;
		a*=temp_a;
	}
	else if(polynomial.find(",")==0)
		a*=1;	
	else
		cerr << "problem" << endl;
	
	
	ss.clear(); ss.str("");
	bb.clear(); bb.str("");
	
	// Erase from the beginning to the comma, since it is not needed anymore
	polynomial.erase(polynomial.begin(),(polynomial.begin()+polynomial.find(",")+1));
	
	/* -------FIND B:------- */
	int temp_b;
	string B;
	
	if (polynomial.find(",")!=0) {
		ss << polynomial[0];
		B=ss.str();
		ss.clear(); ss.str("");
		for(i=1;i!=polynomial.find(","); i++) {
			ss << polynomial[i-1];
			bb << polynomial[i];
			B=ss.str()+bb.str();
		}
		ss.clear(); ss.str(B);
		ss >> temp_b;
		b*=temp_b;
	}
	else if(polynomial.find(",")==0)
		b*=1;
	else
		cerr << "problem" << endl;
	
	ss.clear(); ss.str("");
	bb.clear(); bb.str("");
	
	polynomial.erase(polynomial.begin(), (polynomial.begin()+polynomial.find(",")+1));
	
	/* -------FIND C:------- */
	int temp_c;
	ss.str(polynomial);
	ss >> temp_c;
	c*=temp_c;
	
	ss.clear(); ss.str("");
	bb.clear(); bb.str("");
	
	return 1;
}
