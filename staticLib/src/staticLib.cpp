// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,04.04.2019</created>
/// <changed>ʆϒʅ,05.04.2019</changed>
// ********************************************************************************

// sharedLib.cpp : Defines the entry point for the application.
//

#include "staticLib.h"


Student::Student ( std::string name ) :firstName ( name ) {}


void Student::Print ( void )
{
  std::cout << "The student first name is " << firstName << "." << std::endl;
  std::getchar ();
}
