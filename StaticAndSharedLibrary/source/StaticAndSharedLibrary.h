// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,03.04.2019</created>
/// <changed>ʆϒʅ,14.10.2019</changed>
// ********************************************************************************

#ifndef STATICANDSHAREDLIBRARY_H
#define STATICANDSHAREDLIBRARY_H


//#if WIN32
//#define WIN32_LEAN_AND_MEAN // rarely-used stuff exclusion
//#endif // WIN32


#include "StaticAndSharedLibrary_EXPORTS.h"
#include <iostream>
#include <string>


// creating DLLs are platform dependent,
// therefore explicit expressions, safety concerns and encapsulation concepts are always to be taken care of.

// win32: the declarations that need to be exported need export prefix (LIBRARY_EXPORT preprocessor)

// information on warning C4251 :
// https://stackoverflow.com/questions/767579/exporting-classes-containing-std-objects-vector-map-etc-from-a-dll


class LIBRARY_EXPORT Student
{
private:
  std::string firstName;
public:
  Student ( std::string );
  ~Student ();
  void Print ( void );
};


#endif // !STATICANDSHAREDLIBRARY_H
