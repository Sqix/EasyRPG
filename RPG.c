#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <ctype.h>

#include "consoleColor.h"
#include "level.h"
#include "weaponType.h"
#include "unitType.h"
#include "unitData.h"


const int maxUnitsCount = 35;


HANDLE consoleHandle = 0;
bool isGameActive = true;

unsigned char levelData[rowsCount][columnsCount];

UnitData unitsData[maxUnitsCount];
int unitsCount = 0;
int heroIndex = 0;


void SetupSystem()
{
  srand( time(0) );

  consoleHandle = GetStdHandle( STD_OUTPUT_HANDLE );

  CONSOLE_CURSOR_INFO cursorInfo;
  cursorInfo.dwSize = 1;
  cursorInfo.bVisible = 0;
  SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void Initialize()
{
  unitsCount = 0;

  for(int r = 0; r < rowsCount; r++)
  {
    for (int c = 0; c < columnsCount; c++)
    {
      unsigned char cellSymbol = levelData[r][c];

      levelData[r][c] = cellSymbol;

      switch ( cellSymbol )
      {
        case CellSymbol_Hero: heroIndex = unitsCount;

        case CellSymbol_Orc:
        case CellSymbol_Skeleton:
        {
          UnitType unitType = GetUnitTypeFromCell( cellSymbol );
          unitsData[unitsCount].type = unitsType;
          unitsData[unitsCount].row = r;
          unitsData[unitsCount].column = c;
          unitsData[unitsCount].weapon = GetUnitDefaultWeapon( unitType );
          unitsData[unitsCount].health = GetUnitDefaultHealth( unitType );
          unitsCount++;

          break;
        }
      }
    }
  }
}

void Render()
{
  //Move cursor to (0;0)
  COORD cursorCoord;
  cursorCoord.X = 0;
  cursorCoord.Y = 0;
  SetConsoleCursorPosition(consoleHandle, cursorCoord);

  SetConsoleTextAttribute( consoleHandle, ConsoleColor_Green);
  printf("\n\tDungeons And Orcs");

  printf("\n\n\t");
  for(int r = 0; r < rowsCount; r++)
  {
    for(int c = 0; c < columnsCount; c++)
    {
      unsigned char cellSymbol = levelData[r][c];

      unsigned char renderCellSymbol = GetRenderCellSymbol( cellSymbol );
      ConsoleColor cellColor = GetRenderCellSymbolColor( cellSymbol );

      SetConsoleTextAttribute( consoleHandle, cellColor);
      printf("%c", renderCellSymbol );
    }
    printf("\n\t");
  }
}

void Update()
{
  unsigned char inputChar = _getch();
  inputChar = tolower ( inputChar );

  switch ( inputChar )
  {
    case 'r':
      Initialize();
      break;
  }
}


void Shutdown()
{
  system("cls");
  printf("\n\tGame over...");
  _getch();
}

int int main()
{
  SetupSystem();
  Initialize();

  do
  {
    Render();
    Update();
  }
  while( isGameActive );

  Shutdown();

  return 0;
}
