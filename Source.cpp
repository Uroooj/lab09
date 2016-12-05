#include <iostream>  //including libraries
#include <conio.h>
#include <string>
#include <stack>
using namespace std;

struct Node{  //node
	char value;
	int position;
	Node *next;
};

class Stack{  //class
	int size;
public:
	Node *top;
	Stack(){
		size = 0;
		top = NULL;
	}
	char Top(){ return top->value; }
	int pos(){
		if (!top) return -1;
		else return top->position;
	}
	void push(char val, int a);
	char pop();
	bool isEmpty();
	void peek();
	bool ArePair(char opening, char closing) //ArePair function
	{
		if (opening == '(' && closing == ')') return true; //checks brackets
		else if (opening == '{' && closing == '}') return true;
		else if (opening == '[' && closing == ']') return true;
		return false;
	}
	bool validity(string exp){ //validity function
		Stack S;

		for (int i = 0; i < exp.size(); i++)  //pushes opening brackets and pops closing brackets
		{
			if (exp.at(i) == '(' || exp.at(i) == '{' || exp.at(i) == '[')
				S.push(exp.at(i), i);
			else if (exp.at(i) == ')' || exp.at(i) == '}' || exp.at(i) == ']')
			{
				if (S.isEmpty()){
					return false;
				}
				else
				if (!ArePair(S.Top(), exp.at(i)))
					return false;
				else
					S.pop();
			}
		}
		return S.isEmpty() ? true : false;
	}
};

void Stack::push(char val, int a){  //push function
	Node *temp = new Node;
	if (top == NULL)  //if stack is empty - insert new node at top 
	{
		temp->value = val;
		temp->position = a;
		temp->next = NULL;
		top = temp;
		size++;
	}
	else  //otherwise
	{
		temp->value = val;
		temp->position = a;
		temp->next = top;
		top = temp;
		size++;
	}
}

char Stack::pop(){  //pop function
	char z;
	if (isEmpty()){ //if stack is empty
		cout << "Stack is empty!" << endl;
		return -9999;
	}
	else{  //non empty stack - remove from top
		Node *temp = top;
		top = top->next;
		z = temp->value;
		delete temp;
		size--;
	}
	return z;
}

bool Stack::isEmpty(){  //isEmpty function
	if (size == 0) //if size of stack is zero, return true otherwise false
		return true;
	return false;
}

void Stack::peek() //peek function
{
	Node *temp;
	temp = top;
	while (temp != NULL) //displays all values of stack
	{
		cout << temp->value << "  ";
		temp = temp->next;
	}
}

//cubic function
void solveEq(string e){

	double a, b, c, d, value;
	double f, g, h, i, j, k, l, m, n, p, po;
	double r, s, t, u;
	double x1, x2, x2re, x2im, x3re, x3im, x3;

	int strLength = e.length(); // To compute the length of the string.
	char * charArray = new char[strLength]; //Dynamic memory allocation

	/**
	* The following for loop converts the string into an array.
	*/
	for (int ind = 0; ind < strLength; ind++) {
		charArray[ind] = e[ind];
	}

	cout << endl << "The elements of the character array are as follows: {";
	for (int ind = 0; ind < strLength; ind++) {
		if (ind != strLength - 1) {
			cout << "\'" << charArray[ind] << "\', ";
		}
		else {
			cout << "\'" << charArray[ind] << "\'}";
		}
	}

	char c1, c2, c3, c4;
	c1 = charArray[0];
	c2 = charArray[6];
	c3 = charArray[12];
	c4 = charArray[18];

	a = c1 - '0';
	b = c2 - '0';
	c = c3 - '0';
	d = c4 - '0';

	cout << a << endl << b << endl << c << endl << d << endl;

	f = ((3 * c / a) - ((b*b) / (a*a))) / 3;
	g = ((2 * (b*b*b) / (a*a*a)) - (9 * b*c / (a*a)) + (27 * d / a)) / 27;
	h = ((g*g) / 4) + ((f*f*f) / 27);

	if (f == 0 && g == 0 && h == 0){     // all roots are real and equal
		x1 = pow((d / a), 0.33333333333333333333333333333333);
		x2 = pow((d / a), 0.33333333333333333333333333333333);
		x3 = pow((d / a), 0.33333333333333333333333333333333);
		cout << "x = " << x1 << endl;
		cout << "x = " << x2 << endl;
		cout << "x = " << x3 << endl;
	}
	else if (h <= 0){         // all 3 roots are real
		i = pow((((g*g) / 4) - h), 0.5);
		j = pow(i, 0.33333333333333333333333333333333);
		k = acos((g / (2 * i))*-1);
		l = j * -1;
		m = cos(k / 3);
		n = sqrt(3) * sin(k / 3);
		p = (b / (3 * a))*-1;
		x1 = (2 * j)*m - (b / (3 * a));
		cout << "x = " << x1 << endl;
		x2 = l * (m + n) + p;
		cout << "x = " << x2 << endl;
		x3 = l * (m - n) + p;
		cout << "x = " << x3 << endl;
	}
	else if (h > 0){        // only 1 root is real
		r = ((g / 2)*-1) + pow(h, 0.5);
		s = pow(r, 0.33333333333333333333333333333333);
		t = ((g / 2)*-1) - pow(h, 0.5);
		u = pow((t), 0.33333333333333333333333333333333);
		x1 = (s + u) - (b / (3 * a));
		cout << "x = " << x1 << endl;
		x2re = (((s + u)*-1) / 2) - (b / (3 * a));
		x2im = -(s - u)*pow(3, 0.5) / 2;
		cout << "x = (" << x2re << "," << x2im << ")" << endl;
		x3re = (((s + u)*-1) / 2) - (b / (3 * a));
		x3im = (s - u)*pow(3, 0.5) / 2;
		cout << "x = (" << x3re << "," << x3im << ")" << endl;
	}
}

int main(){
	Stack s;
	//Testing parantheses to be balanced*/
	string expression;
	cout << "Enter an expression:  "; // input expression 
	cin >> expression;

	if (s.validity(expression))
		cout << "The Expression is valid.\n";
	else
		//cout << "ERROR.The expression is not balanced at position" << s.pos() + 1 << endl;
		cout << "ERROR. The expression is not balanced." << endl;
	solveEq(expression);

	system("pause");
	return 0;
}
