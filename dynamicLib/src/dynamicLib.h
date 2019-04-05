// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,03.04.2019</created>
/// <changed>ʆϒʅ,05.04.2019</changed>
// ********************************************************************************

// dynamicLib.h : Include file for standard system include files,
// or project specific include files.


#pragma once


#if WIN32
#define WIN32_LEAN_AND_MEAN
#endif // WIN32


#include "dynamicLib_EXPORTS.h"
#include <iostream>
#include <string>


// creating DLLs are platform dependent,
// therefore explicit expressions, safety concerns and encapsulation concepts are always to be taken care of.

// win32: the declarations that need to be exported need export prefix (DYNAMIC_EXPORT preprocessor)

// information on warning C4251 :
// https://stackoverflow.com/questions/767579/exporting-classes-containing-std-objects-vector-map-etc-from-a-dll


class DYNAMIC_EXPORT Student
{
private:
  std::string firstName;
public:
  Student ( std::string );
  ~Student ();
  void Print ( void );
};

// TODO: Reference additional headers your program requires here.
