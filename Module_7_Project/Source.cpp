/*
 * Module 7 Project
 *
 *  Date: 2/18/2022
 *  Author: Jonathan Wolanyk
 */

#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>
#include <Python.h>


using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	strcpy_s(procname, 999, pName.c_str());


	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	strcpy_s(procname, 999, proc.c_str());

	char* paramval = new char[param.length() + 1];
	strcpy_s(paramval, 999, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	strcpy_s(procname, 999, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

// Displays options
void DisplayMenu() {
	cout << endl << endl;
	cout << setfill('*') << setw(40) << '*' << endl;
	cout << "   1 - Generate list of all sales" << endl;
	cout << "   2 - Item search" << endl;
	cout << "   3 - Generate histogram of purchases" << endl;
	cout << "   4 - Exit Program" << endl;
	cout << setfill('*') << setw(40) << '*' << endl << endl;
	cout << "Enter your selection as a number (1, 2, 3, or 4): " << endl;
}

// Implements switch statements that allows users to
// generate certain reports
void TakeAction() {

	// Declaring local variables
	int userAction;

	// Prompting user for input
	cin >> userAction;

	// Input Validation
	while (!(userAction) || userAction > 4) {
		cin.clear();
		cin.ignore(123, '\n');
		cout << "Invalid entry, please enter a valid value (1, for example): " << endl;
		cin >> userAction;
	}

	// Switch statement implementation
	switch (userAction) {

	// Full list option
	case(1):
		system("CLS");
		CallProcedure("FullList");
		break;

	// Search for a specific item option
	case(2):
		system("CLS");
		CallProcedure("SpecificItem");
		break;

	// Print histogram of items option
	case(3):
		system("CLS");
		CallProcedure("PrintHistogram");
		break;

	// Exits program Option
	case(4):
		cout << "Exiting Program";
		exit(1);
	}
}


void main()
{
	char sentinelChar = 'C';

	// while loop to keep program running, no exit value needed
	// because TakeAction() gives an exit option
	while (sentinelChar != 'Q') {
		DisplayMenu();
		TakeAction();
	}
	
}