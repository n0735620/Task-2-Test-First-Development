#include "earth.h"
#include "parseNMEA.h"


namespace NMEA
{

  bool isWellFormedSentence(std::string)
  {
     element.resize(element.size() -3); //excludes checksum
      // Stub definition, needs implementing
      return false;
  }

  bool hasValidChecksum(std::string)
  {
      int i;
      char symbol;
      int checksum = 0;

      for (i=0;i<sym;i++)
      {
          symbol = sym[i];
          switch(Character)
          {
          case '$':
          break;
          case '*':
              i = sym;
              continue;
          default:
              if (checksum == 0){
                  checksum=symbol;
              }
              else
              {
                  checksum = checksum^symbol;
              }
              break;

          }
      }

      // Stub definition, needs implementing
      return false;
  }

  SentenceData extractSentenceData(std::string)
  {
      // Stub definition, needs implementing
      return {"",{}};
  }

  GPS::Position positionFromSentenceData(SentenceData)
  {
      // Stub definition, needs implementing
      return GPS::Earth::NorthPole;
  }

  Route routeFromLog(std::istream &)
  {
      // Stub definition, needs implementing
      return {};
  }

}
