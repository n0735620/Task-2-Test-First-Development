#include "earth.h"
#include "parseNMEA.h"


namespace NMEA
{

  bool isWellFormedSentence(std::line)
  {
    std::ifstream in('gll.log');
    while(std::getline(in,str)){

        std::cout<<"error";

    }
    bool check = 'true';

  }

  bool hasValidChecksum(std::string)
  {
      std::string ent = element.substr(1);//removes $ and *checksum
      ent= ent.substr(0, ent.size()- 3);
      std::string hexElement = element.substr(value.length()-2);
      std::transform(hexElement.begin(), hexElement.end(). hexElement.begin(), ::tolower);

      float nmeachecksum =0;
      for(size_t i = 0; i < ent.length(); i++)
        nmeachecksum ^=ent[i];

  }

  SentenceData extractSentenceData(std::string)
  {
      element.resize(element.size() -3); //excludes checksum
      //to get nmea sentence format
      const std::string ElementA = element.subst(3,3);
      std::vector<std::string>NMAEElement =stringvector(element);
      nmeaValues.erase(NMAEElement.begin());
      std::vector<string>
      stringvector(std::string line){

      }

      return{ElementA, NMAEElement};
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
