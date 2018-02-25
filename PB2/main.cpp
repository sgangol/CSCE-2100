/********************************************************************
 **        NAME:  Srizan Gangol         USERID:sg0440	           	**
 **  ASSIGNMENT:  CSCE2100		  				                  	**
 ** DESCRIPTION:  main.CPP				Project: Bonus 2- DNA	   	**
 **         														**
 ********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int alphabets = 26;


// Greetings Function
void greetings();

int min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return a;
	else if (b <= a && b <= c)
		return b;
	else
		return c;
}

vector<vector<int> > align(const string &a, const string &b, int alpha_gap, int alpha[alphabets][alphabets], string &a_aligned, string &b_aligned)
{
	int n = a.size();
	int m = b.size();

	vector<vector<int> > A(n + 1, vector<int>(m + 1));
	A[0][0] = 0;
	for (int i = 1; i <= m; i++)
		A[0][i] = alpha_gap * i;
	for (int i = 1; i <= n; i++)
		A[i][0] = alpha_gap * i;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			A[i][j] = min(A[i - 1][j - 1] + alpha[a[i - 1] - 'A'][b[j - 1] - 'A'], A[i - 1][j] + alpha_gap, A[i][j - 1] + alpha_gap);
		}
	}
	a_aligned = "";
	b_aligned = "";
	int j = m;
	int i = n;
	while (i >= 1 && j >= 1)
	{
		if (A[i][j] == A[i - 1][j - 1] + alpha[a[i - 1] - 'A'][b[j - 1] - 'A'])
		{
			a_aligned += a[i - 1];
			b_aligned += b[j - 1];
			--j;
			--i;
		}
		else if (A[i][j] == A[i][j - 1] + alpha_gap)
		{
			a_aligned += '-';
			b_aligned += b[j - 1];
			--j;
		}
		else if (A[i][j] == A[i - 1][j] + alpha_gap)
		{
			a_aligned += a[i - 1];
			b_aligned += '-';
			--i;
		}
	}
	b_aligned += string(i, '-');
	a_aligned += a.substr(0, i);
	a_aligned += string(j, '-');
	b_aligned += a.substr(0, j);
	reverse(a_aligned.begin(), a_aligned.end());
	reverse(b_aligned.begin(), b_aligned.end());
	return A;
}

int main()
{
	string a1, b1;						// First String
	string a2, b2;						// Second String
	vector<vector<int> > A;				// vector
	int alpha[alphabets][alphabets];	// array
	int gap_penalty = 1; 				// gap
	
	
	for (int i = 0; i < alphabets; ++i)
	{
		for (int j = 0; j < alphabets; ++j)
		{
			if (i == j) alpha[i][j] = -2; // mismatch
			else alpha[i][j] = 4; // match
		}
	}
	char choice;
	// Printing heading and the Greetings
	greetings();
	
	// Printing Main Menu & loops until exit
	while (1)
	{
		cout << "\n###########    MAIN MENU     ###########\n"; 
		cout << " Please select the option [ ] below \n\n";
		
		cout << " [I] Input DNAs for analysis\n";
		cout << " [V] View DNA inputs\n";
		cout << " [G] Generate sequence alignment\n";
		cout << " [M] Matrix generated for the alignment\n";
		cout << " [S] Show the most recently generated alignment\n";
		cout << " [Q] Quit the program\n";
		cout << " CSCE2100>";
		cin >> choice;
		if (choice == 'I')
		{
			bool ok = false;
			while (ok == false)
			{
				ok = true;
				cout << " Insert first sequence> ";
				cin >> a1;
				cout << " Insert second sequence> ";
				cin >> b1;
				for (int i = 0; i < a1.size(); i++)
				{
					if (a1[i] != 'A' && a1[i] != 'T' && a1[i] != 'C' && a1[i] != 'G')
					{
						cout << " Sorry! Program detected invalid input, make sure it is DNA sequence with all caps, and try again! Thank You!\n";
						bool ok = false;
					}
				}
				if (ok)
				{
					for (int i = 0; i < b1.size(); i++)
					{
						if (b1[i] != 'A' && b1[i] != 'T' && b1[i] != 'C' && b1[i] != 'G')
						{
							cout << " Sorry! Program detected invalid input, make sure it is DNA sequence with all caps, and try again! Thank You!\n";
							bool ok = false;
						}
					}
				}
			}
			a2 = "";
			b2 = "";
		} else
		if (choice == 'V')
		{
			if (a1 == "" || b1 == "") cout << " Sorry! Seems like you did not input anything \n"; 
			else
			{
				cout << " First DNA sequence: \t" << a1 << endl;
				cout << " Second DNA sequence: \t" << b1 << endl;
			}
		} else
		if (choice == 'G')
		{
			if (a1 == "" || b1 == "") cout << " Sorry! Seems like you did not input anything \n"; 
			else
			{A = align(a1, b1, gap_penalty, alpha, a2, b2);
			cout << " Sequence Alignment has been generated \n";
			}

		} else
		if (choice == 'M')
		{
			for (int i = 0; i < A.size(); i++)
			{
				for (int j = 0; j < A[i].size(); j++)
				{
					// If, else to make alignment look good!! :-)
					if ((A[i][j])<0)
					{
					cout << A[i][j] << "\t";	
					}
					else
					{
						cout << " " << A[i][j] << "\t";
					}
				}
				cout << endl;
			}
		} else
		if (choice == 'S')
		{
			if (a2 == "" || b2 == "") cout << " Sorry! You did not generate alignment \n"; else
			{
				cout << " First DNA sequence: \t" << a2 << endl;
				cout << " Second DNA sequence:\t" << b2 << endl;
			}
		} else
		if (choice == 'Q')
		{
			cout << " Thank You for analyzing the DNA using this Program. Have a good day!\n\n\n\n";
			return 0;
		}
		else cout << " Sorry! Your choice cannot be recognized. Please try again.";
		cout<<"\n";
		cout<<"\n";
	}
	return 0;
}

// Greetings Function
void greetings()
{
	cout << "\n \n";
	cout << "+---------------------------------------------------------+" << endl;
	cout << "|              Computer Science and Engineering           |" << endl;
	cout << "|              CSCE 2100 - Computer Foundations I         |" << endl;
	cout << "|   Srizan Gangol     ID: sg0440      srizan@gmail.com    |" << endl;
	cout << "|   Program: Smith-Waterman analysis for DNA [Bonus 2]    |" << endl;
	cout << "+---------------------------------------------------------+" << endl << endl;
	
	cout << "+---------------------------------------------------------+" << endl;
	cout << "|          Welcome to Smith-Waterman algorithm for        |" << endl;
	cout << "|          the local DNA alightment Program in C++        |" << endl;
	cout << "+---------------------------------------------------------+" << endl << endl;
	

	cout << " NOTE: \t\t\tThis program only accepts UPPER-CASE CHARACTERS\n"	;	
	cout << " RECOMMENDATION: \tPlease leave the Caps Lock [ON]\n"	;
}




