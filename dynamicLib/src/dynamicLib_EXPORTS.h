// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,04.04.2019</created>
/// <changed>ʆϒʅ,05.04.2019</changed>
// ********************************************************************************

#ifndef DYNAMICLIB_EXPORTS_H
#define DYNAMICLIB_EXPORTS_H

#ifdef WIN32

#ifdef DYNAMIC_IMPORTS
#define DYNAMIC_EXPORT __declspec(dllimport)
#else
#define DYNAMIC_EXPORT __declspec(dllexport)
#endif // DYNAMIC_EXPORT

#else
#define DYNAMIC_EXPORT

#endif // WIN32

#endif // DYNAMICLIB_EXPORTS_H
