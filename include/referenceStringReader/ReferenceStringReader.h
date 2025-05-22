//
// Created by abav on 21.05.2025.
//

#ifndef REFERENCESTRINGREADER_H
#define REFERENCESTRINGREADER_H
#include <vector>
#include <string>

class ReferenceStringReader {
private:
  std::vector<int> references;
public:
  explicit ReferenceStringReader(std::string referenceStringFileName);
};
#endif //REFERENCESTRINGREADER_H
