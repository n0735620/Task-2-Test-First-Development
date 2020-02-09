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
      std::stringstream stream;//converts nmeachecksum to hex
      stream << std::hex << nmeachecksum;
      const std::string result(stream.str());

      return hexElement == result ? true:false;

  }


  std::vector<std::string> extractSentanceData(std::string line)
  {
      line.resize(line.size()-3);//Gets rid of $ and checksum
      line.erase (0,3);
      std::vector<std::string> returnVector;
      std::cout << line;
      std::stringstream ss(line);
      while(ss.good()){
          std::string element;
          getline(ss, element, ',');
          returnVector.push_back(element);
      }

      return returnVector;

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
