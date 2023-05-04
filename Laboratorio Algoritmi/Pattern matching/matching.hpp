#pragma once
#include <string>
#include <vector>

/* based on Knuth-Morris-Pratt FAST MATCHING IN STRINGS */

int match(std::string, std::string);
int countMatch(std::string, std::string);
bool cyclicRotation(std::string, std::string);
int tandemRepeat(std::string, std::string);
int borderLength(std::string);
int period(std::string);
std::vector<int> matchList(std::string, std::vector<std::string>);