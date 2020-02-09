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
      struct sentanceData {
          std::string elementA;
          std::vector<std::string> nmeaElements;

      } ;

      std::vector<std::string> extractSentanceData(std::string line);
      bool getLineOk(std::string line);
      bool getvalidchecksum(std::string line);


      bool getLineOk(std::string line){
          bool correctFormat = true;

          std::string a = line.substr (0,1);
          std::string b = line.substr (line.size()-3, 1);
          line.erase(std::remove(line.begin(), line.end(), ','), line.end());

          if (a == "$"){
              line.erase(0,1);

          }
          else {
              correctFormat = false;
          }
          if (b == "*"){
              line.erase(line.size()-3,1);

          }
          else {
              correctFormat = false;
          }



          //std::regex testreg("(GP)\w{3}\\d{4}\\d{2}\\D\\d{3}\\d{2}\\D\\d{5}\W\d{2}");
          std::regex testreg("(GP)(.{3})([0-9]{4})(\\.)([0-9]{2})([A-Z])([0-9]{3})(\\.)([0-9]{2})([A-Z])([0-9]{7})");
          if ( regex_match(line, testreg) ) {


              correctFormat = true;

          }
          else {
              correctFormat = false;
          }
          return correctFormat;
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
