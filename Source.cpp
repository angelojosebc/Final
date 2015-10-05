#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main(){

	stack<float>sufrimiento;
	string labica;
	float x, y;
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

						char* j = new char[labica.length() + 1];
						strcpy(j, labica.c_str());

						sufrimiento.push(atof(j));
		}
					
					
				
	}
	


	return 0;
}