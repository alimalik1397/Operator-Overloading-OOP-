/*Ali Shehzad Malik
Task 1
Overload the following operators in an Integer Class having data members left and right.
1. / operator
2. ^ operator
Task 2
Overload the following operators using the Box class. *= operator
1. != operator
2. >> operator
3. << operator
4. = (assignment operator)
5. Copy constructor
Make sure you implement dynamic memory allocation in your program.
*/


#include <iostream>
#include <string.h>
using namespace std;

class Box
{
private:
	int *left;
	int *right;

public:
	Box(Box &B1)
	{
		left = new int;
		*left = *B1.left;
		right = new int;
		*right = *B1.right;
	}
	Box(){
		left = new int;//Dynamic Allocation of memory
		*left = 0;
		right = new int;
		*right = 0;
	}
	void settervalues()//Setter function
	{

		cout << "Enter left value " << endl;
		cin >> *left;
		cout << "Enter right value" << endl;
		cin >> *right;
	}
	~Box(){
		delete left;//Freeing the heap memory
		delete right;//Freeing the heap memory
	}
	void operator*=(const Box &B1)
	{
		Box B5;
		*B5.left = (*left)* (*B1.left);//Dividing the left hand side with left hand side
		*B5.right = (*right) * *(B1.right);//Dividing the right hand side with right hand side
		cout << "The result of left side is" << *B5.left << endl;
		cout << "The result of right side is " << *B5.right << endl;

	}
	void operator!=(const Box &B1)
	{
		if (*left = *B1.left)
		{
			cout << "The left hand sides are equal" << endl;

		}
		if (*right = *B1.right)
		{
			cout << "The right hand sides are equal" << endl;
		}
	}
	friend ostream& operator<<(ostream &output, const Box &B1);
	friend istream& operator>>(istream &input, Box &B1);
	
};//Class definition ends
ostream& operator<<(ostream &output, const Box &B1)
{
	output << "Left hand side : " << *B1.left << endl << " Right hand side  : " << *B1.right;
	return output;
}
istream& operator>>(istream &input, Box &B1)
{
	cout << "Enter the left hand side for object 3 " << endl;
	cout << "and right hand side of the object 3 respectively" << endl;
	input >> *B1.left;
		input >> *B1.right;
	return input;
}

int main()
{
	Box b1, b2;

	b1.settervalues();
	b2.settervalues();
	b1 *= b2;
	b1 != b2;
	Box b3;
	cin >> b3;
	cout << b3;
	Box b4(b3);
	cout << b4;
}
