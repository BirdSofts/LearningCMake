// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,04.04.2019</created>
/// <changed>ʆϒʅ,10.04.2019</changed>
// ********************************************************************************

#ifndef STATICANDSHAREDLIBRARY_EXPORTS_H
#define STATICANDSHAREDLIBRARY_EXPORTS_H

#ifdef WIN32

#ifdef LIBRARY_IMPORTS
#define LIBRARY_EXPORT __declspec(dllimport)
#else
#define LIBRARY_EXPORT __declspec(dllexport)
#endif // LIBRARY_EXPORT

#else
#define LIBRARY_EXPORT

#endif // WIN32

#endif // STATICANDSHAREDLIBRARY_EXPORTS_H
