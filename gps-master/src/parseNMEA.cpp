#include "earth.h"
#include "parseNMEA.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <regex>
#include <algorithm>

namespace NMEA
{
  bool isWellFormedSentence(std::line)
  {
    std::ifstream in('gll.log');
    bool check ='true';
    while(std::getline(in,line)){

        std::cout<<"error";

    }


  }

  bool hasValidChecksum(std::string)
  {
      std::string substring = line.substr (1,line.size()-3);
      std::cout << "\n" << substring;
      std::string hexstring = line.substr (line.size()-2);
      std::stringstream ss;
      ss << hexstring;
      int hexvalue;
      ss >> std::hex >> hexvalue;
      std::cout << "\n" << hexstring << "\n" << hexvalue << "\n";
      return true;

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
