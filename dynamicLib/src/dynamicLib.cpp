// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,03.04.2019</created>
/// <changed>ʆϒʅ,05.04.2019</changed>
// ********************************************************************************

// dynamicLib.cpp : Defines the entry point for the application.
//


#include "dynamicLib.h"


Student::Student ( std::string name ) :firstName ( name ) {}


Student::~Student () {}


void Student::Print ( void )
{
  std::cout << "The student first name is " << firstName << "." << std::endl;
  std::getchar ();
}
