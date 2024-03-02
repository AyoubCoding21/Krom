#pragma once

#include "KromProgram.h"

#include <string>
using std::string;
using std::to_string;

#include <vector>
using std::vector;

#include <functional>
using std::string;

#include "utils/stringUtils.h"

bool substringMatches(const string& in, int pos, const string& subStr);

int searchInString(const string& in, const string& pattern, int startPos=0);

string replaceSubstring(const string& in, const string& searchFor, const string& replaceWith);

void sliceStringBy(const string& in, const string& pattern, vector<string>& out);
string indentString(const string& in, string indent="    ", int level=1);

string tabsToSpaces(const string& in, int spaceNum=4);

void tabsToSpaces(vector<string>& in);

string padString(const string& in, int size, int alignment=1, string pad=" ", string leftCap="", string rightCap="");

string getTextOfLine(const string& in, int lineNum);

string lineListToBoxedString(const vector<string>& in, string boxName="", int lineNum=-1, bool alwaysWidthMax=false, int maxWidth=-1);

string putStringInBox(const string& in, string boxName="", bool showLineNums=false, bool alwaysWidthMax=false, int maxWidth=-1);

string putStringInTable(const string& in, string tableName);

string assembleTreeString(const string& root, vector<string>& leaves);

string doubleToString(double in);

int stringToInt(string in);

double stringToDouble(string in);

string loadEntireFile(string inName, bool debug=false);

bool writeFile(const string& filename, const string& contents, bool debug=false);
char getRandChar();

string getUniqueString(string hint, std::function<bool (string)> checker, bool alwaysAppendRandom=false);

string runCmd(string cmd, bool printOutput=false);

int getTermWidth();
