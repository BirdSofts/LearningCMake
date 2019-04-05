// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,04.04.2019</created>
/// <changed>ʆϒʅ,05.04.2019</changed>
// ********************************************************************************

// sharedLib.h : Include file for standard system include files,
// or project specific include files.

#pragma once


#if WIN32
#define WIN32_LEAN_AND_MEAN
#endif // WIN32


#include <iostream>
#include <string>


class Student
{
  std::string firstName;
public:
  Student ( std::string );
  void Print ( void );
};

// TODO: Reference additional headers your program requires here.
