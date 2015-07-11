// Operadores y operandos.cpp: archivo de proyecto principal.
#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main(){

	stack<float>sufrimiento;
	string labica;
	float x, y;
	char*j;
	while (cin >> labica)//para su uso personal
	{
	  
			if (labica == "+"){
				x = sufrimiento.top();			sufrimiento.pop();
				y = sufrimiento.top();			sufrimiento.pop();
				sufrimiento.push(y + x);

				cout << "    " << sufrimiento.top() << "   " << endl;
				

			}
			else
				if (labica == "-"){
					x = sufrimiento.top();				sufrimiento.pop();
					y = sufrimiento.top();				sufrimiento.pop();
					sufrimiento.push(y - x);

					cout << "    " << sufrimiento.top() << "   " << endl;

				}
				else
					if (labica == "*"){
						x = sufrimiento.top();					sufrimiento.pop();
						y = sufrimiento.top();					sufrimiento.pop();
						sufrimiento.push(y * x);

						cout << "    " << sufrimiento.top() << "   " << endl;

					}
					else
						if (labica == "/"){
							x = sufrimiento.top();						sufrimiento.pop();
							y = sufrimiento.top();						sufrimiento.pop();
							sufrimiento.push(y / x);

							cout << "    " << sufrimiento.top() << "   " << endl;
						}
						else{

							j = new char[labica.length() + 1];
							strcpy(j, labica.c_str());

							sufrimiento.push(atof(j));
							for (int i = 0; i < labica.length()+1; i++)
					            cout <<"\t"<< j[i];
							
						}
		
	}

	

	return 0;
}
