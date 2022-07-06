#pragma once
#include "level.h"



enum weaponType
{
  weaponType_None;
  weaponType_Fist;
  weaponType_Stick;
  weaponType_Club;
  weaponType_Spear;
  weaponType_Saber;
}

const char* WeaponName_None  = "None";
const char* WeaponName_Fist  = "Fist";
const char* WeaponName_Stick = "Stick";
const char* WeaponName_Club  = "Club";
const char* WeaponName_Spear = "Spear";
const char* WeaponName_Saber = "Saber";

const char* GetWeaponName( WeaponType weaponType )
{
  switch ( weaponType )
  {
    case WeaponType_Fist:  return WeaponName_Fist;
    case WeaponType_Stick: return WeaponName_Stick;
    case WeaponType_Club:  return WeaponName_Club;
    case WeaponType_Spear: return WeaponName_Spear;
    case WeaponType_Saber: return WeaponName_Saber;
  }

  return WeaponName_None;
}

int GetWeaponDamage( WeaponType weaponType )
{
  switch ( weaponType )
  {
    case WeaponType_Fist:  return 2;
    case WeaponType_Stick: return 16;
    case WeaponType_Club:  return 24;
    case WeaponType_Spear: return 32;
    case WeaponType_Saber: return 40;
  }

  return 0;
}

GetWeaponTypeFromCell( unsigned char cellSymbol )
{
  switch ( cellSymbol )
  {
    case cellSymbol_Stick: return WeaponType_Stick;
    case cellSymbol_Club:  return WeaponType_Club;
    case cellSymbol_Spear: return WeaponType_Spear;
    case cellSymbol_Saber: return WeaponType_Saber;
  }
  return WeaponType_None;
}
