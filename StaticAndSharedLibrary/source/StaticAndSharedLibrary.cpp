// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,03.04.2019</created>
/// <changed>ʆϒʅ,10.04.2019</changed>
// ********************************************************************************

// StaticAndSharedLibraryLib.cpp : Defines the entry point for the application.
//


#include "StaticAndSharedLibrary.h"


Student::Student ( std::string name ) :firstName ( name ) {}


Student::~Student () {}


void Student::Print ( void )
{
  std::cout << "The student first name is " << firstName << "." << std::endl;
  std::getchar ();
}
