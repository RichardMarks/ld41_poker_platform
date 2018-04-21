#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

#include "SpriteData.hpp"

std::vector<std::string> tokenize(std::string const& source, std::string const& delimiters) {
  std::vector<std::string> tokens;

  size_t p0 = 0;
  size_t p1 = std::string::npos;

  while (p0 != std::string::npos)
  {
    p1 = source.find_first_of(delimiters, p0);
    if (p1 != p0)
    {
      std::string token = source.substr(p0, p1 - p0);
      tokens.push_back(token);
    }
    p0 = source.find_first_not_of(delimiters, p1);
  }

  return tokens;
}

SpriteData::SpriteData(std::string const& filename) {
  std::ifstream inFile(filename);

  if (!inFile.is_open()) {
    throw std::runtime_error(std::string("Unable to load sprite data from file: ") + filename);
  }

  // std::cout << "reading " << filename << std::endl;

  while (!inFile.eof()) {
    std::string line;
    std::getline(inFile, line);
    if (line.size()) {
      // std::cout << "reading line [" << line.size() << "]: " << line << std::endl;
      std::vector<std::string> tokens = tokenize(line, ",");

      std::string frameName;
      int x, y, w, h;

      // std::cout << tokens.size() << " tokens" << std::endl;

      frameName = tokens.at(0);
      x = static_cast<int>(::atof(tokens.at(1).c_str()));
      y = static_cast<int>(::atof(tokens.at(2).c_str()));
      w = static_cast<int>(::atof(tokens.at(3).c_str()));
      h = static_cast<int>(::atof(tokens.at(4).c_str()));

      // std::cout
      //   << frameName
      //   << " { " << x
      //   << ", " << y
      //   << ", " << w
      //   << ", " << h
      //   << " }" << std::endl;

      auto& frame = allFrames[frameName];
      frame.left = x;
      frame.top = y;
      frame.width = w;
      frame.height = h;
    }
  }

  std::cout << "done" << std::endl;

  inFile.close();
}

std::vector<sf::IntRect> SpriteData::frames(std::vector<std::string> framesRequested) {
  std::vector<sf::IntRect> result;

  for (auto it = framesRequested.begin(); it != framesRequested.end(); ++it) {
    auto pairFound = allFrames.find(*it);
    if (pairFound != allFrames.end()) {
      result.push_back(pairFound->second);
    } else {
      throw std::runtime_error(std::string("Unable to find frame named: ") + *it);
    }
  }

  return result;
}
