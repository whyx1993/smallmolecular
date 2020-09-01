#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <exception>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

const char *MainMessage =
    "Nitrogen Rich Compound Analyzer - Help You Access Physicochemical "
    "Parameters\n"
    "Test Version 1.0.1, Test Date 2019.06\n"
    "Project Leader: W. L. Yuan, L. Zhang, G. H. Tao, L. He\n"
    "For internal test only, please refer to the following literature for "
    "relevant computational results\n"
    "1. M. H. Keshavarz, H. R. Pouretedal, Propellants, Explosives, Pyrotechnics 2005, 105-108\n"
    "2. M. H. Keshavarz, Propellants, Explosives, Pyrotechnics 2008, 360-364\n"
    "3. P. Politzer, J. Martinez, J. S. Murray, M. C. Concha, A.Toro-Labbe, Molecular Physics, 2009, 2095-2101\n"
    "4. P. Politzer, J. Martinez, J. S. Murray, M. C. Concha, Molecular Physics, 2010, 1391-1396\n"
    "\n"
    "1. Choose Molecular Skeleton for Target Compounds.\n"
    "2. Compounds Possibility Analysis and Screening.\n"
    "3. Calculate the Density of the Compounds.\n"
    "4. Calculate the Detonation Behavior of the Compounds.\n"
    "5. Calculate the Molecular Orbital of the Compounds.\n"
    "6. More Features are Under the Development.\n"
    "7. Exit.\n"
    "> ";

const char *Message1 =
    "Which molecular framework need to be chosen?\n"
    "(1) Pyrrole, (2) Imidazole, (3) Pyrazole, (4) 1,2,3-Triazole, (5) "
    "1,2,4-Triazole, (6) Tetrazole, (7) Pentazole, (8) Advanced options\n"
    "> ";

const char *Message11 =
    "Please input your functional groups in order, eg: 1,3,3,2\n"
    "(1) Hydrogen, (2) Amino, (3) Nitro, (4) Cyano, (5) Hydrazine, (6) Azide, "
    "(7) Advanced options\n";

const char *Picture11 = "Pyrrole structure\n"
                        "  2C---C3\n"
                        "  /     \\\n"
                        " 1C     C4\n"
                        "  \\     /\n"
                        "     N\n"
                        "\n"
                        "Press 0 to return...\n"
                        "> ";

const char *Message12 =
    "Please input your functional groups in order, eg: 1,3,5\n"
    "(1) Hydrogen, (2) Amino, (3) Nitro, (4) Cyano, (5) Hydrazine, (6) Azide, "
    "(7) Advanced options\n";

const char *Picture12 = "Pyrrole structure\n"
                        "  2C---N\n"
                        "  /     \\\n"
                        " 1C     C3\n"
                        "  \\     /\n"
                        "     N\n"
                        "\n"
                        "Press 0 to return...\n"
                        "> ";

const char *Message13 =
    "Please input your functional groups in order, eg: 1,3,5\n"
    "(1) Hydrogen, (2) Amino, (3) Nitro, (4) Cyano, (5) Hydrazine, (6) Azide, "
    "(7) Advanced options\n";

const char *Picture13 = "Pyrrole structure\n"
                        "  2C---C3\n"
                        "  /     \\\n"
                        " 1C      N\n"
                        "  \\     /\n"
                        "     N\n"
                        "\n"
                        "Press 0 to return...\n"
                        "> ";

const char *Message14 =
    "Please input your functional groups in order, eg: 1,6\n"
    "(1) Hydrogen, (2) Amino, (3) Nitro, (4) Cyano, (5) Hydrazine, (6) Azide, "
    "(7) Advanced options\n";

const char *Picture14 = "Pyrrole structure\n"
                        "  2C---N\n"
                        "  /     \\\n"
                        " 1C      N\n"
                        "  \\     /\n"
                        "     N\n"
                        "\n"
                        "Press 0 to return...\n"
                        "> ";

const char *Message15 =
    "Please input your functional groups in order, eg: 1,6\n"
    "(1) Hydrogen, (2) Amino, (3) Nitro, (4) Cyano, (5) Hydrazine, (6) Azide, "
    "(7) Advanced options\n";

const char *Picture15 = "Pyrrole structure\n"
                        "   N---C2\n"
                        "  /     \\\n"
                        " 1C      N\n"
                        "  \\     /\n"
                        "     N\n"
                        "\n"
                        "Press 0 to return...\n"
                        "> ";

const char *Message16 = "Please input your functional groups in order, eg: 1\n"
                        "(1) Hydrogen, (2) Amino, (3) Nitro, (4) Cyano, (5) "
                        "Hydrazine, (6) Azide, (7) Advanced options\n";

const char *Picture16 = "Pyrrole structure\n"
                        "   N---N\n"
                        "  /     \\\n"
                        " 1C      N\n"
                        "  \\     /\n"
                        "     N\n"
                        "\n"
                        "Press 0 to return...\n"
                        "> ";

const char *Message17 =
    "Don\'t need to input functional groups :) Go to the next step\n";

const char *Picture17 = "Pyrrole structure\n"
                        "   N---N\n"
                        "  /     \\\n"
                        " N       N\n"
                        "  \\     /\n"
                        "     N\n"
                        "\n"
                        "Press 0 to return...\n"
                        "> ";

const char *File1 = "C:\\Users\\linrongbin\\Desktop\\1.chk";

const char *FileHeader1 = "%chk=C:\\Users\\Desktop\\1.chk\n"
                          "# b3lyp/6-311g++ opt freq\n"
                          "\n"
                          "1\n"
                          "\n"
                          "0 1\n"
                          "\n";

const char *Message2 =
    "Which molecular framework need to be chosen?\n"
    "(1) Pyrrole, (2) Imidazole, (3) Pyrazole, (4) 1,2,3-Triazole, (5) "
    "1,2,4-Triazole, (6) Tetrazole, (7) Pentazole, (8) Advanced "
    "options(developing)\n"
    "> ";

const char *MessageHint1 =
    "Functional Groups + Molecular Formula + Molecular Weight + Element "
    "content + H% + C% + N% + O% + others:\n";

const char *MessageHint2 = "Would you like to search the target index of all "
                           "the possible structures?\n"
                           "1-Yes, 2-No, and return to the main menu\n"
                           "> ";

const char *MessageHint3 =
    "Which target need to search?\n"
    "(1) Molecular Weight, (2) Hydrogen content, (3) Carbon content, (4) "
    "Nitrogen content, (5) Oxygen content, (6) Advanced options(developing)\n"
    "> ";

const char *MessageHint31 = "Input Molecular Weight, eg: 98.04-104.32\n"
                            "> ";

const char *MessageHint32 = "Input Hydrogen content, eg: 98.04-104.32\n"
                            "> ";

const char *MessageHint33 = "Input Carbon content, eg: 98.04-104.32\n"
                            "> ";

const char *MessageHint34 = "Input Nitrogen content, eg: 98.04-104.32\n"
                            "> ";

const char *MessageHint35 = "Input Oxygen content, eg: 98.04-104.32\n"
                            "> ";

const char *MessageHint36 =
    "This function is under construction, please contact inventor.\n"
    "Press 0 to return...\n"
    "> ";

const char *Message21 = "Choose your functional groups (from 1 to 4)\n"
                        "(1) Hydrogen, (2) Amino, (3) Nitro, (4) Cyano, (5) "
                        "Hydrazine, (6) Azide, (7) MethlyHydrazine\n";

const char *Message22 = "Choose your functional groups (from 1 to 3)\n"
                        "(1) Hydrogen, (2) Amino, (3) Nitro, (4) Cyano, (5) "
                        "Hydrazine, (6) Azide, (7) MethlyHydrazine\n";

const char *Message23 = "Choose your functional groups (from 1 to 3)\n"
                        "(1) Hydrogen, (2) Amino, (3) Nitro, (4) Cyano, (5) "
                        "Hydrazine, (6) Azide, (7) MethlyHydrazine\n";

const char *Message24 = "Choose your functional groups (from 1 to 2)\n"
                        "(1) Hydrogen, (2) Amino, (3) Nitro, (4) Cyano, (5) "
                        "Hydrazine, (6) Azide, (7) MethlyHydrazine\n";

const char *Message25 = "Choose your functional groups (from 1 to 2)\n"
                        "(1) Hydrogen, (2) Amino, (3) Nitro, (4) Cyano, (5) "
                        "Hydrazine, (6) Azide, (7) MethlyHydrazine\n";

const char *Message26 = "Choose your functional groups (from 1 to 1)\n"
                        "(1) Hydrogen, (2) Amino, (3) Nitro, (4) Cyano, (5) "
                        "Hydrazine, (6) Azide, (7) MethlyHydrazine\n";

const char *Message27 =
    "Don\'t need to input functional groups :) Go to the next step\n";

const char *Message3 = "Which Compounds Need to Calculate?\n"
                       "(1) Neutral Compound, (2) Ionic Salts\n"
                       "> ";

const char *Message31 =
    "Input the molar mass M, molecular volume Vm, Product of sigma^2_tot and "
    "nu orderly\n"
    "If you don\'t obtain the parapmaters, please return main menu and go "
    "\"More Features are Under the Development\"\n"
    "> ";

const char *Message32 =
    "Input the molar mass M, molecular volume Vm, volume of a cation\'s "
    "positive electrostatic potential surface V_s^+, volume of a anion\'s "
    "surface negative electrostatic potential surface V_s^-, average value of "
    "that cation\'s potential A_s^+ and average value of that anion\'s "
    "potential A_s^- orderly\n"
    "> ";

const char *Message4 = "Input the number of Carbon, Hydrogen, Nitrogen and "
                       "Oxygen atoms of the compound\n"
                       "> ";

// util functions

std::string trim(const std::string &s) {
  int i = 0, j = (int)s.length() - 1;
  for (; i < (int)s.length(); i++) {
    if (!std::isspace(s[i])) {
      break;
    }
  }
  for (; j >= 0; j--) {
    if (!std::isspace(s[j])) {
      break;
    }
  }
  return i > j ? "" : s.substr(i, j - i + 1);
}

void readAnyKey() {
  std::string line;
  std::getline(std::cin, line);
  std::printf("\n");
}

std::string readLine() {
  std::string line;
  std::getline(std::cin, line);
  return trim(line);
}

std::vector<std::string> readMultiLine() {
  std::vector<std::string> lines;
  while (true) {
    std::printf("> ");
    std::string line;
    std::getline(std::cin, line);
    line = trim(line);
    if (line == "EOF" || line == "eof") {
      return lines;
    }
    lines.push_back(line);
  }
  return lines;
}

bool isInt(const char &c) { return std::isdigit(c); }

bool isFloat(const char &c) {
  return std::isdigit(c) || c == '+' || c == '-' || c == '.';
}

bool isUnsignedFloat(const char &c) { return std::isdigit(c) || c == '.'; }

void dumpFile(const std::string &fileName,
              const std::vector<std::string> &lines) {
  FILE *fp = std::fopen(fileName.c_str(), "w");
  for (int i = 0; i < (int)lines.size(); i++) {
    std::fprintf(fp, "%s", lines[i].c_str());
  }
  std::fclose(fp);
}

int skipSpace(const std::string &s, int start) {
  int i = start;
  while (i < (int)s.length() && std::isspace(s[i])) {
    i++;
  }
  return i;
}

int nextSpace(const std::string &s, int start) {
  int i = start;
  while (i < (int)s.length() && !std::isspace(s[i])) {
    i++;
  }
  return i;
}

int parseInt(const std::string &s) { return std::stoi(s); }

std::pair<double, double> parseTwoInts(const std::string &s) {
  std::string a, b;
  int i = 0, j = 0;
  while (j < (int)s.length()) {
    if (!isUnsignedFloat(s[j])) {
      break;
    }
    j++;
  }
  a = s.substr(i, j - i);
  i = j;
  while (j < (int)s.length()) {
    if (isUnsignedFloat(s[j])) {
      break;
    }
    j++;
  }
  i = j;
  while (j < (int)s.length()) {
    if (!isUnsignedFloat(s[j])) {
      break;
    }
    j++;
  }
  b = s.substr(i, j - i);
  return std::make_pair(std::stod(a), std::stod(b));
}

bool outerEq(const std::vector<int> &v1, const std::vector<int> &v2) {
  if (v1.size() != v2.size()) {
    return false;
  }
  bool allSame = true;
  for (int i = 0; i < (int)v1.size(); i++) {
    if (v1[i] != v2[i]) {
      allSame = false;
    }
  }
  if (allSame) {
    return true;
  }
  bool outerSame = true;
  for (int i = 0; i < (int)v1.size(); i++) {
    if (v1[i] != v2[v2.size() - 1 - i]) {
      outerSame = false;
    }
  }
  return outerSame;
}

bool innerEq(const std::vector<int> &v1, const std::vector<int> &v2) {
  if (v1.size() != v2.size()) {
    return false;
  }
  bool allSame = true;
  for (int i = 0; i < (int)v1.size(); i++) {
    if (v1[i] != v2[i]) {
      allSame = false;
    }
  }
  if (allSame) {
    return true;
  }
  return v1[v1.size() - 1] == v2[v2.size() - 2] &&
         v1[v1.size() - 2] == v2[v2.size() - 1];
}

bool existInts(const std::vector<std::vector<int>> &v,
               const std::vector<int> &a,
               bool (*eq)(const std::vector<int> &, const std::vector<int> &)) {
  for (int i = 0; i < (int)v.size(); i++) {
    if (eq(v[i], a)) {
      return true;
    }
  }
  return false;
}

bool existInt(const std::vector<int> &v, int e) {
  for (int i = 0; i < (int)v.size(); i++) {
    if (v[i] == e) {
      return true;
    }
  }
  return false;
}

std::vector<int> dedupInts(const std::vector<int> &v) {
  std::vector<int> u;
  for (int i = 0; i < (int)v.size(); i++) {
    if (!existInt(u, v[i])) {
      u.push_back(v[i]);
    }
  }
  return u;
}

void recursiveExtendCombinationImpl(int *p, int n,
                                    const std::vector<int> &candidates,
                                    int prev,
                                    std::vector<std::vector<int>> &v) {
  // loop end
  if (prev == n) {
    std::vector<int> vec;
    for (int i = 0; i < n; i++) {
      vec.push_back(p[i]);
    }
    v.push_back(vec);
    return;
  }

  // loop iterator
  for (int i = 0; i < (int)candidates.size(); i++) {
    p[prev] = candidates[i];
    recursiveExtendCombinationImpl(p, n, candidates, prev + 1, v);
  }
}

// all possible v which v.length()=n, v[i] belongs to candidates
std::vector<std::vector<int>>
recursiveExtendCombination(const std::vector<int> &candidates, int n) {
  std::vector<std::vector<int>> v;
  int p[4];
  recursiveExtendCombinationImpl(p, n, candidates, 0, v);
  return v;
}

void combinationOnceChoice(std::vector<int> &choose, int prev, int prev_one,
                           const std::vector<int> &s, int m,
                           std::vector<std::vector<int>> &result) {
  if (prev == m) {
    std::vector<int> tmp;
    for (int i = 0; i < (int)choose.size(); i++) {
      if (choose[i] == 1) {
        tmp.push_back(s[i]);
      }
    }
    result.push_back(tmp);
    return;
  }

  for (int i = prev_one + 1; i < (int)s.size(); i++) {
    if (choose[i] == 0) {
      choose[i] = 1;
      combinationOnceChoice(choose, prev + 1, i, s, m, result);
      choose[i] = 0;
    }
  }
}

// all posibilities choice that choose m item from s, m <= s.size()
std::vector<std::vector<int>> combinationOnce(const std::vector<int> &s,
                                              int m) {
  std::vector<std::vector<int>> r;
  std::vector<int> choose(s.size(), 0);
  combinationOnceChoice(choose, 0, -1, s, m, r);
  return r;
}

std::vector<std::vector<int>> extendCombination(
    const std::vector<std::vector<int>> &v, int expect,
    bool (*eq)(const std::vector<int> &, const std::vector<int> &)) {
  std::vector<std::vector<int>> u;
  for (int i = 0; i < (int)v.size(); i++) {
    std::vector<std::vector<int>> possibles =
        recursiveExtendCombination(v[i], expect);
    // mege possibles to u
    for (int k = 0; k < (int)possibles.size(); k++) {
      if (!existInts(u, possibles[k], eq)) {
        u.push_back(possibles[k]);
      }
    }
  }
  return u;
}

// expect length: expect
std::vector<std::vector<int>>
combination(const std::vector<int> &v, int expect,
            bool (*eq)(const std::vector<int> &, const std::vector<int> &)) {
  std::vector<std::vector<int>> pg;
  std::vector<int> u = dedupInts(v);
  // choose m items from u
  for (int m = 1; m <= (int)u.size(); m++) {
    std::vector<std::vector<int>> comb = combinationOnce(u, m);
    std::vector<std::vector<int>> extendComb =
        extendCombination(comb, expect, eq);
    // merge extendComb to pg
    for (int i = 0; i < (int)extendComb.size(); i++) {
      if (!existInts(pg, extendComb[i], eq)) {
        pg.push_back(extendComb[i]);
      }
    }
  }
  return pg;
}

std::vector<std::vector<int>> permutationImpl(
    const std::vector<int> &v,
    bool (*eq)(const std::vector<int> &, const std::vector<int> &)) {
  std::vector<std::vector<int>> p;
  std::vector<int> start = v;
  do {
    // mege start to p
    if (!existInts(p, start, eq)) {
      p.push_back(start);
    }
  } while (std::next_permutation(start.begin(), start.end()));
  return p;
}

std::vector<std::vector<int>> permutation(const std::vector<int> &v,
                                          bool (*eq)(const std::vector<int> &,
                                                     const std::vector<int> &),
                                          int expect) {
  std::vector<std::vector<int>> r;
  std::vector<std::vector<int>> comb = combination(v, expect, eq);
  for (int i = 0; i < (int)comb.size(); i++) {
    std::vector<std::vector<int>> tmp = permutationImpl(comb[i], eq);
    // merge tmp to r
    for (int j = 0; j < (int)tmp.size(); j++) {
      if (!existInts(r, tmp[j], eq)) {
        r.push_back(tmp[j]);
      }
    }
  }
  return r;
}

std::vector<int> splitIntsByComma(const std::string &s) {
  std::vector<int> v;
  int i = skipSpace(s, 0);
  while (i < (int)s.length()) {
    int j = i;
    while (j < (int)s.length() && isInt(s[j])) {
      j++;
    }
    v.push_back(parseInt(s.substr(i, j - i)));
    while (j < (int)s.length() && !isInt(s[j])) {
      j++;
    }
    i = j;
  }
  return v;
}

std::vector<double> splitDoublesByComma(const std::string &s) {
  std::vector<double> v;
  int i = skipSpace(s, 0);
  while (i < (int)s.length()) {
    int j = i;
    while (j < (int)s.length() && isFloat(s[j])) {
      j++;
    }
    v.push_back(std::stod(s.substr(i, j - i)));
    while (j < (int)s.length() && !isFloat(s[j])) {
      j++;
    }
    i = j;
  }
  return v;
}

// structure

struct FunctionalGroupItem {
  // one item of funtional group
  std::string raw;
  std::string name;
  double x;
  double y;
  double z;

  FunctionalGroupItem() {}

  FunctionalGroupItem(const std::string &a_raw) : raw(a_raw) {
    std::vector<double> v;
    int i = 0;

    // get name
    int j = i;
    while (j < (int)a_raw.length() && std::isalpha(a_raw[j])) {
      j++;
    }
    name = a_raw.substr(i, j - i);
    i = skipSpace(a_raw, j);

    // get coordinate
    while (i < (int)a_raw.length()) {
      j = nextSpace(a_raw, i);
      v.push_back(std::stod(a_raw.substr(i, j - i)));
      i = skipSpace(a_raw, j);
    }

    if (v.size() != 3) {
      std::printf("ERROR! Invalid atomic coordinates:%s\n", a_raw.c_str());
      std::exit(-1);
    }
    x = v[0];
    y = v[1];
    z = v[2];
  }

  static std::pair<int, FunctionalGroupItem> parse(const std::string &s) {
    FunctionalGroupItem fgItem;
    std::vector<std::string> v;
    int i = 0;

    // get name
    int j = i;
    while (j < (int)s.length() && std::isalpha(s[j])) {
      j++;
    }
    fgItem.name = s.substr(i, j - i);
    i = skipSpace(s, j);

    // get coordinate
    while (i < (int)s.length()) {
      j = nextSpace(s, i);
      v.push_back(s.substr(i, j - i));
      i = skipSpace(s, j);
    }

    if (v.size() != 3) {
      std::printf("ERROR! Invalid atomic coordinates:%s\n", s.c_str());
      return std::make_pair(-1, fgItem);
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < (int)v[i].length(); j++) {
        if (!isFloat(v[i][j])) {
          std::printf("ERROR! Invalid atomic coordinates:%s\n", s.c_str());
          return std::make_pair(-1, fgItem);
        }
      }
    }
    fgItem.x = std::stod(v[0]);
    fgItem.y = std::stod(v[1]);
    fgItem.z = std::stod(v[2]);
    fgItem.raw = fgItem.name + std::string(16 - fgItem.name.length(), ' ') +
                 v[0] + std::string(14 - v[0].length(), ' ') + v[1] +
                 std::string(14 - v[1].length(), ' ') + v[2];
    return std::make_pair(0, fgItem);
  }
};

struct FunctionalGroup {
  // n-th item => functional group item
  std::vector<FunctionalGroupItem> items;
};

struct PositionFG {
  // position 0-3 => functional group
  std::vector<std::vector<FunctionalGroup>> fgroups;
};

PositionFG getPositionFG() {
  PositionFG pfg;

  // position 1
  {
    std::vector<std::string> hydrogen1Str = {
        "H               1.00162410    1.33801783   -0.00022530"};
    std::vector<std::string> amino1Str = {
        "N               0.99171058    1.73789497   -0.00027401",
        "H               1.45310708    2.08286867    0.81710376",
        "H               1.45630908    2.08274913   -0.81588656"};
    std::vector<std::string> nitro1Str = {
        "N               0.99171058    1.73789497   -0.00027401",
        "O               1.45237423    2.02379023    0.81239423",
        "O               1.45239402    2.08723527   -0.81120841"};

    std::vector<std::string> cyano1Str = {
        "C               0.98997571    1.80787346   -0.00028253",
        "N               0.96155861    2.95412126   -0.00042216"};
    std::vector<std::string> hydrazine1Str = {
        "N               0.99171058    1.73789497   -0.00027401",
        "H               1.45479419    2.08271147   -0.81676353",
        "N               1.63978905    2.22091063    1.14283148",
        "H               2.38560752    2.82917148    0.87121861",
        "H               0.98707213    2.72555162    1.70789616"};
    std::vector<std::string> azide1Str = {
        "N               0.99171058    1.73789497   -0.00027401",
        "N               0.96117694    2.96951653   -0.00042404",
        "N               0.92647961    4.36908649   -0.00059452"};
    FunctionalGroupItem hydrogen1Item0(hydrogen1Str[0]);
    FunctionalGroup hydrogen1FG;
    hydrogen1FG.items.push_back(hydrogen1Item0);

    FunctionalGroupItem amino1Item0(amino1Str[0]);
    FunctionalGroupItem amino1Item1(amino1Str[1]);
    FunctionalGroupItem amino1Item2(amino1Str[2]);
    FunctionalGroup amino1FG;
    amino1FG.items.push_back(amino1Item0);
    amino1FG.items.push_back(amino1Item1);
    amino1FG.items.push_back(amino1Item2);

    FunctionalGroupItem nitro1Item0(nitro1Str[0]);
    FunctionalGroupItem nitro1Item1(nitro1Str[1]);
    FunctionalGroupItem nitro1Item2(nitro1Str[2]);
    FunctionalGroup nitro1FG;
    nitro1FG.items.push_back(nitro1Item0);
    nitro1FG.items.push_back(nitro1Item1);
    nitro1FG.items.push_back(nitro1Item2);

    FunctionalGroupItem cyano1Item0(cyano1Str[0]);
    FunctionalGroupItem cyano1Item1(cyano1Str[1]);
    FunctionalGroup cyano1FG;
    cyano1FG.items.push_back(cyano1Item0);
    cyano1FG.items.push_back(cyano1Item1);

    FunctionalGroupItem hydrazine1Item0(hydrazine1Str[0]);
    FunctionalGroupItem hydrazine1Item1(hydrazine1Str[1]);
    FunctionalGroupItem hydrazine1Item2(hydrazine1Str[2]);
    FunctionalGroupItem hydrazine1Item3(hydrazine1Str[3]);
    FunctionalGroupItem hydrazine1Item4(hydrazine1Str[4]);
    FunctionalGroup hydrazine1FG;
    hydrazine1FG.items.push_back(hydrazine1Item0);
    hydrazine1FG.items.push_back(hydrazine1Item1);
    hydrazine1FG.items.push_back(hydrazine1Item2);
    hydrazine1FG.items.push_back(hydrazine1Item3);
    hydrazine1FG.items.push_back(hydrazine1Item4);

    FunctionalGroupItem azide1Item0(azide1Str[0]);
    FunctionalGroupItem azide1Item1(azide1Str[1]);
    FunctionalGroupItem azide1Item2(azide1Str[2]);
    FunctionalGroup azide1FG;
    azide1FG.items.push_back(azide1Item0);
    azide1FG.items.push_back(azide1Item1);
    azide1FG.items.push_back(azide1Item2);

    std::vector<FunctionalGroup> p1vec;
    p1vec.push_back(hydrogen1FG);
    p1vec.push_back(amino1FG);
    p1vec.push_back(nitro1FG);
    p1vec.push_back(cyano1FG);
    p1vec.push_back(hydrazine1FG);
    p1vec.push_back(azide1FG);
    pfg.fgroups.push_back(p1vec);
  }

  // position 2
  {
    std::vector<std::string> hydrogen2Str = {
        "H               3.11825920   -0.24474128    0.00215515"};
    std::vector<std::string> amino2Str = {
        "N               3.46706646   -0.14067952    0.00295745",
        "H               3.55196181    0.73709569    0.47444813",
        "H               4.01880670   -0.82774355    0.47574253"};
    std::vector<std::string> nitro2Str = {
        "N               3.46706646   -0.14067952    0.00295745",
        "O               4.18234018   -1.02374238    0.01893741",
        "O               3.23897428    1.23849234    0.64418477"};
    std::vector<std::string> cyano2Str = {
        "C               3.52810773   -0.12246871    0.00309785",
        "N               4.93675244    0.29778071    0.00633791"};
    std::vector<std::string> hydrazine2Str = {
        "N               3.38917574    0.23340437   -0.47762390",
        "H               3.86277614   -0.64671927   -0.44468405",
        "N               4.24814749    1.24273123   -0.02659528",
        "H               3.77454716    2.12285490   -0.05953533",
        "H               4.52560087    1.04851030    0.91430740"};
    std::vector<std::string> azide2Str = {
        "N               3.46706646   -0.14067952    0.00295745",
        "N               4.80863285    0.25955802    0.00604321",
        "N               5.98921128    0.61176706    0.00875869"};
    FunctionalGroupItem hydrogen2Item0(hydrogen2Str[0]);
    FunctionalGroup hydrogen2FG;
    hydrogen2FG.items.push_back(hydrogen2Item0);

    FunctionalGroupItem amino2Item0(amino2Str[0]);
    FunctionalGroupItem amino2Item1(amino2Str[1]);
    FunctionalGroupItem amino2Item2(amino2Str[2]);
    FunctionalGroup amino2FG;
    amino2FG.items.push_back(amino2Item0);
    amino2FG.items.push_back(amino2Item1);
    amino2FG.items.push_back(amino2Item2);

    FunctionalGroupItem nitro2Item0(nitro2Str[0]);
    FunctionalGroupItem nitro2Item1(nitro2Str[1]);
    FunctionalGroupItem nitro2Item2(nitro2Str[2]);
    FunctionalGroup nitro2FG;
    nitro2FG.items.push_back(nitro2Item0);
    nitro2FG.items.push_back(nitro2Item1);
    nitro2FG.items.push_back(nitro2Item2);

    FunctionalGroupItem cyano2Item0(cyano2Str[0]);
    FunctionalGroupItem cyano2Item1(cyano2Str[1]);
    FunctionalGroup cyano2FG;
    cyano2FG.items.push_back(cyano2Item0);
    cyano2FG.items.push_back(cyano2Item1);

    FunctionalGroupItem hydrazine2Item0(hydrazine2Str[0]);
    FunctionalGroupItem hydrazine2Item1(hydrazine2Str[1]);
    FunctionalGroupItem hydrazine2Item2(hydrazine2Str[2]);
    FunctionalGroupItem hydrazine2Item3(hydrazine2Str[3]);
    FunctionalGroupItem hydrazine2Item4(hydrazine2Str[4]);
    FunctionalGroup hydrazine2FG;
    hydrazine2FG.items.push_back(hydrazine2Item0);
    hydrazine2FG.items.push_back(hydrazine2Item1);
    hydrazine2FG.items.push_back(hydrazine2Item2);
    hydrazine2FG.items.push_back(hydrazine2Item3);
    hydrazine2FG.items.push_back(hydrazine2Item4);

    FunctionalGroupItem azide2Item0(azide2Str[0]);
    FunctionalGroupItem azide2Item1(azide2Str[1]);
    FunctionalGroupItem azide2Item2(azide2Str[2]);
    FunctionalGroup azide2FG;
    azide2FG.items.push_back(azide2Item0);
    azide2FG.items.push_back(azide2Item1);
    azide2FG.items.push_back(azide2Item2);

    std::vector<FunctionalGroup> p2vec;
    p2vec.push_back(hydrogen2FG);
    p2vec.push_back(amino2FG);
    p2vec.push_back(nitro2FG);
    p2vec.push_back(cyano2FG);
    p2vec.push_back(hydrazine2FG);
    p2vec.push_back(azide2FG);
    pfg.fgroups.push_back(p2vec);
  }

  // position 3
  {
    std::vector<std::string> hydrogen3Str = {
        "H               2.62988332   -2.96618225    0.00292120"};
    std::vector<std::string> amino3Str = {
        "N               2.60325634   -2.93331455    0.00283193",
        "H               3.44561389   -2.67860122    0.47775810",
        "H               2.17676684   -3.70654234    0.47211382"};
    std::vector<std::string> nitro3Str = {
        "N               2.64154306   -3.06478281   -0.12221418",
        "O               2.36464511   -4.47898566   -0.44087686",
        "O               3.88064589   -3.03102803   -0.32266876"};
    std::vector<std::string> cyano3Str = {
        "C               2.73063948   -3.18328372   -0.13458398",
        "N               3.29814166   -4.14082161    0.14065050"};
    std::vector<std::string> hydrazine3Str = {
        "N               3.00141999   -3.05231154    0.33356415",
        "H               3.22148796   -4.00503228    0.12405692",
        "N               4.17454876   -2.28839491    0.31941236",
        "H               3.95448076   -1.33567413    0.52891938",
        "H               4.81090003   -2.64203797    1.00497318"};
    std::vector<std::string> azide3Str = {
        "N               2.95660283   -2.72499523   -0.11631019",
        "N               4.09918389   -3.53197638   -0.05895216",
        "N               5.10465522   -4.24211980   -0.00847708"};
    FunctionalGroupItem hydrogen3Item0(hydrogen3Str[0]);
    FunctionalGroup hydrogen3FG;
    hydrogen3FG.items.push_back(hydrogen3Item0);

    FunctionalGroupItem amino3Item0(amino3Str[0]);
    FunctionalGroupItem amino3Item1(amino3Str[1]);
    FunctionalGroupItem amino3Item2(amino3Str[2]);
    FunctionalGroup amino3FG;
    amino3FG.items.push_back(amino3Item0);
    amino3FG.items.push_back(amino3Item1);
    amino3FG.items.push_back(amino3Item2);

    FunctionalGroupItem nitro3Item0(nitro3Str[0]);
    FunctionalGroupItem nitro3Item1(nitro3Str[1]);
    FunctionalGroupItem nitro3Item2(nitro3Str[2]);
    FunctionalGroup nitro3FG;
    nitro3FG.items.push_back(nitro3Item0);
    nitro3FG.items.push_back(nitro3Item1);
    nitro3FG.items.push_back(nitro3Item2);

    FunctionalGroupItem cyano3Item0(cyano3Str[0]);
    FunctionalGroupItem cyano3Item1(cyano3Str[1]);
    FunctionalGroup cyano3FG;
    cyano3FG.items.push_back(cyano3Item0);
    cyano3FG.items.push_back(cyano3Item1);

    FunctionalGroupItem hydrazine3Item0(hydrazine3Str[0]);
    FunctionalGroupItem hydrazine3Item1(hydrazine3Str[1]);
    FunctionalGroupItem hydrazine3Item2(hydrazine3Str[2]);
    FunctionalGroupItem hydrazine3Item3(hydrazine3Str[3]);
    FunctionalGroupItem hydrazine3Item4(hydrazine3Str[4]);
    FunctionalGroup hydrazine3FG;
    hydrazine3FG.items.push_back(hydrazine3Item0);
    hydrazine3FG.items.push_back(hydrazine3Item1);
    hydrazine3FG.items.push_back(hydrazine3Item2);
    hydrazine3FG.items.push_back(hydrazine3Item3);
    hydrazine3FG.items.push_back(hydrazine3Item4);

    FunctionalGroupItem azide3Item0(azide3Str[0]);
    FunctionalGroupItem azide3Item1(azide3Str[1]);
    FunctionalGroupItem azide3Item2(azide3Str[2]);
    FunctionalGroup azide3FG;
    azide3FG.items.push_back(azide3Item0);
    azide3FG.items.push_back(azide3Item1);
    azide3FG.items.push_back(azide3Item2);

    std::vector<FunctionalGroup> p3vec;
    p3vec.push_back(hydrogen3FG);
    p3vec.push_back(amino3FG);
    p3vec.push_back(nitro3FG);
    p3vec.push_back(cyano3FG);
    p3vec.push_back(hydrazine3FG);
    p3vec.push_back(azide3FG);
    pfg.fgroups.push_back(p3vec);
  }

  // position 4
  {
    std::vector<std::string> hydrogen4Str = {
        "H               -0.41334918   -3.24484703    0.10515732"};
    std::vector<std::string> amino4Str = {
        "N               0.23280024   -3.35635359   -0.07806900",
        "H              -0.23303661   -3.69471632    0.73955359",
        "H              -0.29736968   -3.60216985   -0.88954557"};
    std::vector<std::string> nitro4Str = {
        "N               0.21339162   -3.58046579   -0.09003400",
        "O              -0.92543122   -4.47065714   -0.38807759",
        "O               1.16905372   -4.32571338   -0.41868766"};
    std::vector<std::string> cyano4Str = {
        "C               0.37730636   -3.43373680    0.01384779",
        "N               0.39059992   -4.58021344    0.02415140"};
    std::vector<std::string> hydrazine4Str = {
        "N               0.03114231   -3.59244967   -0.46613512",
        "H              -0.70760597   -3.60262913    0.20776944",
        "N               0.62498405   -4.85881305   -0.52676327",
        "H               1.36373219   -4.84863365   -1.20066798",
        "H               0.99598711   -5.09632600    0.37098075"};
    std::vector<std::string> azide4Str = {
        "N               0.37944506   -3.61818463    0.01550546",
        "N               0.44355107   -5.01367850   -0.07662102",
        "N               0.49996435   -6.24171310   -0.15769232"};
    FunctionalGroupItem hydrogen4Item0(hydrogen4Str[0]);
    FunctionalGroup hydrogen4FG;
    hydrogen4FG.items.push_back(hydrogen4Item0);

    FunctionalGroupItem amino4Item0(amino4Str[0]);
    FunctionalGroupItem amino4Item1(amino4Str[1]);
    FunctionalGroupItem amino4Item2(amino4Str[2]);
    FunctionalGroup amino4FG;
    amino4FG.items.push_back(amino4Item0);
    amino4FG.items.push_back(amino4Item1);
    amino4FG.items.push_back(amino4Item2);

    FunctionalGroupItem nitro4Item0(nitro4Str[0]);
    FunctionalGroupItem nitro4Item1(nitro4Str[1]);
    FunctionalGroupItem nitro4Item2(nitro4Str[2]);
    FunctionalGroup nitro4FG;
    nitro4FG.items.push_back(nitro4Item0);
    nitro4FG.items.push_back(nitro4Item1);
    nitro4FG.items.push_back(nitro4Item2);

    FunctionalGroupItem cyano4Item0(cyano4Str[0]);
    FunctionalGroupItem cyano4Item1(cyano4Str[1]);
    FunctionalGroup cyano4FG;
    cyano4FG.items.push_back(cyano4Item0);
    cyano4FG.items.push_back(cyano4Item1);

    FunctionalGroupItem hydrazine4Item0(hydrazine4Str[0]);
    FunctionalGroupItem hydrazine4Item1(hydrazine4Str[1]);
    FunctionalGroupItem hydrazine4Item2(hydrazine4Str[2]);
    FunctionalGroupItem hydrazine4Item3(hydrazine4Str[3]);
    FunctionalGroupItem hydrazine4Item4(hydrazine4Str[4]);
    FunctionalGroup hydrazine4FG;
    hydrazine4FG.items.push_back(hydrazine4Item0);
    hydrazine4FG.items.push_back(hydrazine4Item1);
    hydrazine4FG.items.push_back(hydrazine4Item2);
    hydrazine4FG.items.push_back(hydrazine4Item3);
    hydrazine4FG.items.push_back(hydrazine4Item4);

    FunctionalGroupItem azide4Item0(azide4Str[0]);
    FunctionalGroupItem azide4Item1(azide4Str[1]);
    FunctionalGroupItem azide4Item2(azide4Str[2]);
    FunctionalGroup azide4FG;
    azide4FG.items.push_back(azide4Item0);
    azide4FG.items.push_back(azide4Item1);
    azide4FG.items.push_back(azide4Item2);

    std::vector<FunctionalGroup> p4vec;
    p4vec.push_back(hydrogen4FG);
    p4vec.push_back(amino4FG);
    p4vec.push_back(nitro4FG);
    p4vec.push_back(cyano4FG);
    p4vec.push_back(hydrazine4FG);
    p4vec.push_back(azide4FG);
    pfg.fgroups.push_back(p4vec);
  }
  return pfg;
}

struct MolecularStructure {
  std::string nameHeader;
  std::vector<std::string> nameBody;
  std::string formula;
  double weight;
  int content;
  double H;
  double C;
  double N;
  double O;
  double others;

  std::string getLine() {
    std::stringstream line;
    line << nameHeader;
    if (nameBody.size() != 0) {
      line << "-";
    }
    for (int i = 0; i < (int)nameBody.size(); i++) {
      line << nameBody[i];
      if (i < (int)nameBody.size() - 1) {
        line << "-";
      }
    }
    char weightBuf[128];
    char HBuf[128];
    char CBuf[128];
    char NBuf[128];
    std::sprintf(weightBuf, "%.2f", weight);
    std::sprintf(HBuf, "%.2f", H);
    std::sprintf(CBuf, "%.2f", C);
    std::sprintf(NBuf, "%.2f", N);
    line << " " << formula << " " << weightBuf << " " << content << " " << HBuf
         << " " << CBuf << " " << NBuf << " "
         << "0.00 0.00";
    return line.str();
  }
};

struct MolecularItemHeader {
  std::string name;
  int H;
  int N;
  int C;
  int O;
};

struct FunctionalGroupMap {
  std::vector<MolecularItemHeader> mmap;
};

FunctionalGroupMap getFunctionalGroupMap() {
  FunctionalGroupMap mm;
  {
    MolecularItemHeader m1;
    m1.name = "H";
    m1.H = 1;
    m1.N = 0;
    m1.C = 0;
    m1.O = 0;
    mm.mmap.push_back(m1);
  }
  {
    MolecularItemHeader m2;
    m2.name = "NH2";
    m2.H = 2;
    m2.N = 1;
    m2.C = 0;
    m2.O = 0;
    mm.mmap.push_back(m2);
  }
  {
    MolecularItemHeader m3;
    m3.name = "NO2";
    m3.H = 0;
    m3.N = 1;
    m3.C = 0;
    m3.O = 2;
    mm.mmap.push_back(m3);
  }
  {
    MolecularItemHeader m4;
    m4.name = "CN";
    m4.H = 0;
    m4.N = 1;
    m4.C = 1;
    m4.O = 0;
    mm.mmap.push_back(m4);
  }
  {
    MolecularItemHeader m5;
    m5.name = "N2H3";
    m5.H = 3;
    m5.N = 2;
    m5.C = 0;
    m5.O = 0;
    mm.mmap.push_back(m5);
  }
  {
    MolecularItemHeader m6;
    m6.name = "N3";
    m6.H = 0;
    m6.N = 3;
    m6.C = 0;
    m6.O = 0;
    mm.mmap.push_back(m6);
  }
  {
    MolecularItemHeader m7;
    m7.name = "CN2H5";
    m7.H = 5;
    m7.N = 2;
    m7.C = 1;
    m7.O = 0;
    mm.mmap.push_back(m7);
  }
  return mm;
}

void subOption11() {
  std::vector<std::string> lines;
  std::string basicStr =
      "C               0.35945177   -1.89390249    0.00000900\n"
      "C               1.76120177   -1.89390249    0.00000900\n"
      "C               2.18519977   -0.52310649    0.00000900\n"
      "C               1.02814277    0.26834651   -0.00009500\n"
      "N               -0.08027523  -0.57339449    0.00000000\n"
      "H               -1.02060323  -0.28269349   -0.00021700\n";
  lines.push_back(FileHeader1);
  lines.push_back(basicStr);

  std::printf("%s> ", Message11);
  std::string fgStr = readLine();
  std::vector<int> posfg = splitIntsByComma(fgStr);

  if (posfg.size() != 4) {
    std::printf("ERROR! Please input again\n\n");
    return;
  }

  PositionFG pfg = getPositionFG();

  for (int i = 0; i < (int)posfg.size(); i++) {
    if (posfg[i] < 1 || posfg[i] > 7) {
      std::printf("ERROR! Please input again\n\n");
      return;
    }
    if (posfg[i] == 7) {
      std::printf("Please input the %d atomic coordinates(end with EOF):\n",
                  i + 1);
      std::vector<std::string> spStrList = readMultiLine();
      for (int p = 0; p < (int)spStrList.size(); p++) {
        std::pair<int, FunctionalGroupItem> spfgItem =
            FunctionalGroupItem::parse(spStrList[p]);
        if (spfgItem.first != 0) {
          std::printf("ERROR! Please input again\n\n");
          return;
        }
        lines.push_back(spfgItem.second.raw + "\n");
      }
    } else {
      for (int p = 0; p < (int)pfg.fgroups[i][posfg[i] - 1].items.size(); p++) {
        FunctionalGroupItem tmpItem = pfg.fgroups[i][posfg[i] - 1].items[p];
        lines.push_back(tmpItem.raw + "\n");
      }
    }
  }
  lines.push_back("\n");
  lines.push_back("\n");

  std::printf("%s", Message11);
  std::printf("%s", Picture11);
  dumpFile(File1, lines);
  readAnyKey();
}

void subOption12() {
  std::vector<std::string> lines;
  std::string basicStr =
      "C               0.35945177   -1.89390249    0.00000900\n"
      "N               1.76120177   -1.89390249    0.00000900\n"
      "C               2.18519977   -0.52310649    0.00000900\n"
      "C               1.02814277    0.26834651   -0.00009500\n"
      "N               -0.08027523  -0.57339449    0.00000000\n"
      "H               -1.02060323  -0.28269349   -0.00021700\n";

  lines.push_back(FileHeader1);
  lines.push_back(basicStr);

  std::printf("%s> ", Message12);
  std::string fgStr = readLine();
  std::vector<int> posfg = splitIntsByComma(fgStr);

  if (posfg.size() != 3) {
    std::printf("ERROR! Please input again\n\n");
    return;
  }

  PositionFG pfg = getPositionFG();

  for (int i = 0; i < (int)posfg.size(); i++) {
    if (posfg[i] < 1 || posfg[i] > 7) {
      std::printf("ERROR! Please input again\n\n");
      return;
    }
    if (posfg[i] == 7) {
      std::printf("Please input the %d atomic coordinates(end with EOF):\n",
                  i + 1);
      std::vector<std::string> spStrList = readMultiLine();
      for (int p = 0; p < (int)spStrList.size(); p++) {
        std::pair<int, FunctionalGroupItem> spfgItem =
            FunctionalGroupItem::parse(spStrList[p]);
        if (spfgItem.first != 0) {
          std::printf("ERROR! Please input again\n\n");
          return;
        }
        lines.push_back(spfgItem.second.raw + "\n");
      }
    } else {
      for (int p = 0; p < (int)pfg.fgroups[i][posfg[i] - 1].items.size(); p++) {
        FunctionalGroupItem tmpItem = pfg.fgroups[i][posfg[i] - 1].items[p];
        lines.push_back(tmpItem.raw + "\n");
      }
    }
  }
  lines.push_back("\n");
  lines.push_back("\n");

  std::printf("%s", Message12);
  std::printf("%s", Picture12);
  dumpFile(File1, lines);
  readAnyKey();
}

void subOption13() {
  std::vector<std::string> lines;
  std::string basicStr =
      "C               1.02814277    0.26834651   -0.00009500\n"
      "N               -0.08027523  -0.57339449    0.00000000\n"
      "H               -1.02060323  -0.28269349   -0.00021700\n"
      "C               2.18519977   -0.52310649    0.00000900\n"
      "N               0.35945177   -1.89390249    0.00000900\n"
      "C               1.76120177   -1.89390249    0.00000900\n";

  lines.push_back(FileHeader1);
  lines.push_back(basicStr);

  std::printf("%s> ", Message13);
  std::string fgStr = readLine();
  std::vector<int> posfg = splitIntsByComma(fgStr);

  if (posfg.size() != 3) {
    std::printf("ERROR! Please input again\n\n");
    return;
  }

  PositionFG pfg = getPositionFG();

  for (int i = 0; i < (int)posfg.size(); i++) {
    if (posfg[i] < 1 || posfg[i] > 7) {
      std::printf("ERROR! Please input again\n\n");
      return;
    }
    if (posfg[i] == 7) {
      std::printf("Please input the %d atomic coordinates(end with EOF):\n",
                  i + 1);
      std::vector<std::string> spStrList = readMultiLine();
      for (int p = 0; p < (int)spStrList.size(); p++) {
        std::pair<int, FunctionalGroupItem> spfgItem =
            FunctionalGroupItem::parse(spStrList[p]);
        if (spfgItem.first != 0) {
          std::printf("ERROR! Please input again\n\n");
          return;
        }
        lines.push_back(spfgItem.second.raw + "\n");
      }
    } else {
      for (int p = 0; p < (int)pfg.fgroups[i][posfg[i] - 1].items.size(); p++) {
        FunctionalGroupItem tmpItem = pfg.fgroups[i][posfg[i] - 1].items[p];
        lines.push_back(tmpItem.raw + "\n");
      }
    }
  }
  lines.push_back("\n");
  lines.push_back("\n");

  std::printf("%s", Message13);
  std::printf("%s", Picture13);
  dumpFile(File1, lines);
  readAnyKey();
}

void subOption14() {
  std::vector<std::string> lines;
  std::string basicStr =
      "C               1.02814277    0.26834651   -0.00009500\n"
      "N               -0.08027523  -0.57339449    0.00000000\n"
      "H               -1.02060323  -0.28269349   -0.00021700\n"
      "C               2.18519977   -0.52310649    0.00000900\n"
      "N               0.35945177   -1.89390249    0.00000900\n"
      "C               1.76120177   -1.89390249    0.00000900\n";

  lines.push_back(FileHeader1);
  lines.push_back(basicStr);

  std::printf("%s> ", Message14);
  std::string fgStr = readLine();
  std::vector<int> posfg = splitIntsByComma(fgStr);

  if (posfg.size() != 2) {
    std::printf("ERROR! Please input again\n\n");
    return;
  }

  PositionFG pfg = getPositionFG();

  for (int i = 0; i < (int)posfg.size(); i++) {
    if (posfg[i] < 1 || posfg[i] > 7) {
      std::printf("ERROR! Please input again\n\n");
      return;
    }
    if (posfg[i] == 7) {
      std::printf("Please input the %d atomic coordinates(end with EOF):\n",
                  i + 1);
      std::vector<std::string> spStrList = readMultiLine();
      for (int p = 0; p < (int)spStrList.size(); p++) {
        std::pair<int, FunctionalGroupItem> spfgItem =
            FunctionalGroupItem::parse(spStrList[p]);
        if (spfgItem.first != 0) {
          std::printf("ERROR! Please input again\n\n");
          return;
        }
        lines.push_back(spfgItem.second.raw + "\n");
      }
    } else {
      for (int p = 0; p < (int)pfg.fgroups[i][posfg[i] - 1].items.size(); p++) {
        FunctionalGroupItem tmpItem = pfg.fgroups[i][posfg[i] - 1].items[p];
        lines.push_back(tmpItem.raw + "\n");
      }
    }
  }
  lines.push_back("\n");
  lines.push_back("\n");

  std::printf("%s", Message14);
  std::printf("%s", Picture14);
  dumpFile(File1, lines);
  readAnyKey();
}

void subOption15() {
  std::vector<std::string> lines;
  std::string basicStr =
      "C               1.02814277    0.26834651   -0.00009500\n"
      "N               -0.08027523  -0.57339449    0.00000000\n"
      "H               -1.02060323  -0.28269349   -0.00021700\n"
      "N               0.35945177   -1.89390249    0.00000900\n"
      "C               1.76120177   -1.89390249    0.00000900\n"
      "N               2.18519977   -0.52310649    0.00000900\n";

  lines.push_back(FileHeader1);
  lines.push_back(basicStr);

  std::printf("%s> ", Message15);
  std::string fgStr = readLine();
  std::vector<int> posfg = splitIntsByComma(fgStr);

  if (posfg.size() != 2) {
    std::printf("ERROR! Please input again\n\n");
    return;
  }

  PositionFG pfg = getPositionFG();

  for (int i = 0; i < (int)posfg.size(); i++) {
    if (posfg[i] < 1 || posfg[i] > 7) {
      std::printf("ERROR! Please input again\n\n");
      return;
    }
    if (posfg[i] == 7) {
      std::printf("Please input the %d atomic coordinates(end with EOF):\n",
                  i + 1);
      std::vector<std::string> spStrList = readMultiLine();
      for (int p = 0; p < (int)spStrList.size(); p++) {
        std::pair<int, FunctionalGroupItem> spfgItem =
            FunctionalGroupItem::parse(spStrList[p]);
        if (spfgItem.first != 0) {
          std::printf("ERROR! Please input again\n\n");
          return;
        }
        lines.push_back(spfgItem.second.raw + "\n");
      }
    } else {
      for (int p = 0; p < (int)pfg.fgroups[i][posfg[i] - 1].items.size(); p++) {
        FunctionalGroupItem tmpItem = pfg.fgroups[i][posfg[i] - 1].items[p];
        lines.push_back(tmpItem.raw + "\n");
      }
    }
  }
  lines.push_back("\n");
  lines.push_back("\n");

  std::printf("%s", Message15);
  std::printf("%s", Picture15);
  dumpFile(File1, lines);
  readAnyKey();
}

void subOption16() {
  std::vector<std::string> lines;
  std::string basicStr =
      "C               1.02814277    0.26834651   -0.00009500\n"
      "N               -0.08027523  -0.57339449    0.00000000\n"
      "H               -1.02060323  -0.28269349   -0.00021700\n"
      "N               0.35945177   -1.89390249    0.00000900\n"
      "N               2.18519977   -0.52310649    0.00000900\n"
      "N               1.76120177   -1.89390249    0.00000900\n";

  lines.push_back(FileHeader1);
  lines.push_back(basicStr);

  std::printf("%s> ", Message16);
  std::string fgStr = readLine();
  std::vector<int> posfg = splitIntsByComma(fgStr);

  if (posfg.size() != 1) {
    std::printf("ERROR! Please input again\n\n");
    return;
  }

  PositionFG pfg = getPositionFG();

  for (int i = 0; i < (int)posfg.size(); i++) {
    if (posfg[i] < 1 || posfg[i] > 7) {
      std::printf("ERROR! Please input again\n\n");
      return;
    }
    if (posfg[i] == 7) {
      std::printf("Please input the %d atomic coordinates(end with EOF):\n",
                  i + 1);
      std::vector<std::string> spStrList = readMultiLine();
      for (int p = 0; p < (int)spStrList.size(); p++) {
        std::pair<int, FunctionalGroupItem> spfgItem =
            FunctionalGroupItem::parse(spStrList[p]);
        if (spfgItem.first != 0) {
          std::printf("ERROR! Please input again\n\n");
          return;
        }
        lines.push_back(spfgItem.second.raw + "\n");
      }
    } else {
      for (int p = 0; p < (int)pfg.fgroups[i][posfg[i] - 1].items.size(); p++) {
        FunctionalGroupItem tmpItem = pfg.fgroups[i][posfg[i] - 1].items[p];
        lines.push_back(tmpItem.raw + "\n");
      }
    }
  }
  lines.push_back("\n");
  lines.push_back("\n");

  std::printf("%s", Message16);
  std::printf("%s", Picture16);
  dumpFile(File1, lines);
  readAnyKey();
}

void subOption17() {
  std::vector<std::string> lines;
  std::string basicStr =
      "N                  1.02814277    0.26834651   -0.00009500\n"
      "N                 -0.08027523   -0.57339449    0.00000000\n"
      "H                 -1.02060323   -0.28269349   -0.00021700\n"
      "N                  0.35945177   -1.89390249    0.00000900\n"
      "N                  2.18519977   -0.52310649    0.00000900\n"
      "N                  1.76120177   -1.89390249    0.00000900\n";

  lines.push_back(FileHeader1);
  lines.push_back(basicStr);
  lines.push_back("\n");
  lines.push_back("\n");

  std::printf("%s> ", Message17);
  readAnyKey();
  std::printf("%s", Message17);
  std::printf("%s", Picture17);
  readAnyKey();
}

void subOption18() {
  std::vector<std::string> lines;
  lines.push_back(FileHeader1);

  for (int i = 0;; i++) {
    std::printf("Please input the %d atomic coordinates(end with EOF):\n",
                i + 1);
    std::vector<std::string> spStrList = readMultiLine();
    if (spStrList.size() == 0) {
      break;
    }
    for (int p = 0; p < (int)spStrList.size(); p++) {
      std::pair<int, FunctionalGroupItem> spfgItem =
          FunctionalGroupItem::parse(spStrList[p]);
      if (spfgItem.first != 0) {
        std::printf("ERROR! Please input again\n\n");
        return;
      }
      lines.push_back(spfgItem.second.raw + "\n");
    }
  }
  lines.push_back("\n");
  lines.push_back("\n");

  std::printf("Press 0 to return...\n> ");
  dumpFile(File1, lines);
  readAnyKey();
}

void option1() {
  std::printf("%s", Message1);
  std::string optionStr = readLine();
  int option = parseInt(optionStr);
  switch (option) {
  case 1:
    subOption11();
    break;
  case 2:
    subOption12();
    break;
  case 3:
    subOption13();
    break;
  case 4:
    subOption14();
    break;
  case 5:
    subOption15();
    break;
  case 6:
    subOption16();
    break;
  case 7:
    subOption17();
    break;
  case 8:
    subOption18();
    break;
  default:
    std::printf("ERROR! Invalid option: %s\n", optionStr.c_str());
  }
}

void subOption21() {
  std::printf("%s> ", Message21);
  std::string fgStr = readLine();
  std::vector<int> posfg = splitIntsByComma(fgStr);
  if (posfg.size() < 1 || posfg.size() > 4) {
    std::printf("ERROR! Please input again\n\n");
    return;
  }
  for (int i = 0; i < (int)posfg.size(); i++) {
    if (posfg[i] < 1 || posfg[i] > 7) {
      std::printf("ERROR! Please input again\n\n");
      return;
    }
  }

  // weight map: H - 1.008, N - 14.007, O - 15.999, C - 12.011
  FunctionalGroupMap moleMap = getFunctionalGroupMap();

  std::vector<std::vector<int>> perm = permutation(posfg, outerEq, 4);
  std::vector<MolecularStructure> msList;

  for (int i = 0; i < (int)perm.size(); i++) {
    std::vector<int> p = perm[i];
    MolecularStructure ms;
    int C = 4, H = 0, N = 1, O = 0;
    ms.nameHeader = "Pyrrole";
    for (int j = 0; j < (int)p.size(); j++) {
      MolecularItemHeader h = moleMap.mmap[p[j] - 1];
      C += h.C;
      H += h.H;
      N += h.N;
      O += h.O;
      ms.nameBody.push_back(h.name);
    }
    ms.formula = "C" + (C > 1 ? std::to_string(C) : "") + "N" +
                 (N > 1 ? std::to_string(N) : "") + "H" +
                 (H > 1 ? std::to_string(H) : "");
    ms.weight = (double)C * 12.011 + (double)N * 14.007 + (double)H * 1.008;
    ms.content = 100;
    ms.H = (double)H * 1.008 / ms.weight * 100.0;
    ms.C = (double)C * 12.011 / ms.weight * 100.0;
    ms.N = (double)N * 14.007 / ms.weight * 100.0;
    ms.O = 0.0;
    ms.others = 0.0;
    msList.push_back(ms);
  }

  std::printf("%s", Message21);
  std::printf("%s", MessageHint1);
  for (int i = 0; i < (int)msList.size(); i++) {
    MolecularStructure ms = msList[i];
    std::printf("%s\n", ms.getLine().c_str());
  }
  std::printf("\n");
  std::printf("%s", MessageHint2);
  std::string optionStr = readLine();
  int option = parseInt(optionStr);
  if (option != 1) {
    return;
  }
  while (true) {
    std::printf("%s", MessageHint3);
    optionStr = readLine();
    option = parseInt(optionStr);
    switch (option) {
    case 1: {
      std::printf("%s", MessageHint31);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.weight >= range.first && ms.weight <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 2: {
      std::printf("%s", MessageHint32);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.H >= range.first && ms.H <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 3: {
      std::printf("%s", MessageHint33);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.C >= range.first && ms.C <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 4: {
      std::printf("%s", MessageHint34);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.N >= range.first && ms.N <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 5: {
      std::printf("%s", MessageHint35);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.O >= range.first && ms.O <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 6: {
      std::printf("%s", MessageHint36);
      readAnyKey();
      break;
    }
    default:
      std::printf("ERROR! Invalid option:%s\n", optionStr.c_str());
      std::printf("Press 0 to return...\n> ");
      readAnyKey();
      return;
    }
  }
}

void subOption22() {
  std::printf("%s> ", Message22);
  std::string fgStr = readLine();
  std::vector<int> posfg = splitIntsByComma(fgStr);
  if (posfg.size() < 1 || posfg.size() > 3) {
    std::printf("ERROR! Please input again\n\n");
    return;
  }
  for (int i = 0; i < (int)posfg.size(); i++) {
    if (posfg[i] < 1 || posfg[i] > 7) {
      std::printf("ERROR! Please input again\n\n");
      return;
    }
  }

  // weight map: H - 1.008, N - 14.007, O - 15.999, C - 12.011
  FunctionalGroupMap moleMap = getFunctionalGroupMap();

  std::vector<std::vector<int>> perm = permutation(posfg, innerEq, 3);
  std::vector<MolecularStructure> msList;

  for (int i = 0; i < (int)perm.size(); i++) {
    std::vector<int> p = perm[i];
    MolecularStructure ms;
    int C = 3, H = 0, N = 2, O = 0;
    ms.nameHeader = "Imidazole";
    for (int j = 0; j < (int)p.size(); j++) {
      MolecularItemHeader h = moleMap.mmap[p[j] - 1];
      C += h.C;
      H += h.H;
      N += h.N;
      O += h.O;
      ms.nameBody.push_back(h.name);
    }
    ms.formula = "C" + (C > 1 ? std::to_string(C) : "") + "N" +
                 (N > 1 ? std::to_string(N) : "") + "H" +
                 (H > 1 ? std::to_string(H) : "");
    ms.weight = (double)C * 12.011 + (double)N * 14.007 + (double)H * 1.008;
    ms.content = 100;
    ms.H = (double)H * 1.008 / ms.weight * 100.0;
    ms.C = (double)C * 12.011 / ms.weight * 100.0;
    ms.N = (double)N * 14.007 / ms.weight * 100.0;
    ms.O = 0.0;
    ms.others = 0.0;
    msList.push_back(ms);
  }

  std::printf("%s", Message22);
  std::printf("%s", MessageHint1);
  for (int i = 0; i < (int)msList.size(); i++) {
    MolecularStructure ms = msList[i];
    std::printf("%s\n", ms.getLine().c_str());
  }
  std::printf("\n");
  std::printf("%s", MessageHint2);
  std::string optionStr = readLine();
  int option = parseInt(optionStr);
  if (option != 1) {
    return;
  }
  while (true) {
    std::printf("%s", MessageHint3);
    optionStr = readLine();
    option = parseInt(optionStr);
    switch (option) {
    case 1: {
      std::printf("%s", MessageHint31);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.weight >= range.first && ms.weight <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 2: {
      std::printf("%s", MessageHint32);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.H >= range.first && ms.H <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 3: {
      std::printf("%s", MessageHint33);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.C >= range.first && ms.C <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 4: {
      std::printf("%s", MessageHint34);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.N >= range.first && ms.N <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 5: {
      std::printf("%s", MessageHint35);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.O >= range.first && ms.O <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 6: {
      std::printf("%s", MessageHint36);
      readAnyKey();
      break;
    }
    default:
      std::printf("ERROR! Invalid option:%s\n", optionStr.c_str());
      std::printf("Press 0 to return...\n> ");
      readAnyKey();
      return;
    }
  }
}

void subOption23() {
  std::printf("%s> ", Message23);
  std::string fgStr = readLine();
  std::vector<int> posfg = splitIntsByComma(fgStr);
  if (posfg.size() < 1 || posfg.size() > 3) {
    std::printf("ERROR! Please input again\n\n");
    return;
  }
  for (int i = 0; i < (int)posfg.size(); i++) {
    if (posfg[i] < 1 || posfg[i] > 7) {
      std::printf("ERROR! Please input again\n\n");
      return;
    }
  }

  // weight map: H - 1.008, N - 14.007, O - 15.999, C - 12.011
  FunctionalGroupMap moleMap = getFunctionalGroupMap();

  std::vector<std::vector<int>> perm = permutation(posfg, innerEq, 3);
  std::vector<MolecularStructure> msList;

  for (int i = 0; i < (int)perm.size(); i++) {
    std::vector<int> p = perm[i];
    MolecularStructure ms;
    int C = 3, H = 0, N = 2, O = 0;
    ms.nameHeader = "Pyrazole";
    for (int j = 0; j < (int)p.size(); j++) {
      MolecularItemHeader h = moleMap.mmap[p[j] - 1];
      C += h.C;
      H += h.H;
      N += h.N;
      O += h.O;
      ms.nameBody.push_back(h.name);
    }
    ms.formula = "C" + (C > 1 ? std::to_string(C) : "") + "N" +
                 (N > 1 ? std::to_string(N) : "") + "H" +
                 (H > 1 ? std::to_string(H) : "");
    ms.weight = (double)C * 12.011 + (double)N * 14.007 + (double)H * 1.008;
    ms.content = 100;
    ms.H = (double)H * 1.008 / ms.weight * 100.0;
    ms.C = (double)C * 12.011 / ms.weight * 100.0;
    ms.N = (double)N * 14.007 / ms.weight * 100.0;
    ms.O = 0.0;
    ms.others = 0.0;
    msList.push_back(ms);
  }

  std::printf("%s", Message23);
  std::printf("%s", MessageHint1);
  for (int i = 0; i < (int)msList.size(); i++) {
    MolecularStructure ms = msList[i];
    std::printf("%s\n", ms.getLine().c_str());
  }
  std::printf("\n");
  std::printf("%s", MessageHint2);
  std::string optionStr = readLine();
  int option = parseInt(optionStr);
  if (option != 1) {
    return;
  }
  while (true) {
    std::printf("%s", MessageHint3);
    optionStr = readLine();
    option = parseInt(optionStr);
    switch (option) {
    case 1: {
      std::printf("%s", MessageHint31);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.weight >= range.first && ms.weight <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 2: {
      std::printf("%s", MessageHint32);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.H >= range.first && ms.H <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 3: {
      std::printf("%s", MessageHint33);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.C >= range.first && ms.C <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 4: {
      std::printf("%s", MessageHint34);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.N >= range.first && ms.N <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 5: {
      std::printf("%s", MessageHint35);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.O >= range.first && ms.O <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 6: {
      std::printf("%s", MessageHint36);
      readAnyKey();
      break;
    }
    default:
      std::printf("ERROR! Invalid option:%s\n", optionStr.c_str());
      std::printf("Press 0 to return...\n> ");
      readAnyKey();
      return;
    }
  }
}

void subOption24() {
  std::printf("%s> ", Message24);
  std::string fgStr = readLine();
  std::vector<int> posfg = splitIntsByComma(fgStr);
  if (posfg.size() < 1 || posfg.size() > 2) {
    std::printf("ERROR! Please input again\n\n");
    return;
  }
  for (int i = 0; i < (int)posfg.size(); i++) {
    if (posfg[i] < 1 || posfg[i] > 7) {
      std::printf("ERROR! Please input again\n\n");
      return;
    }
  }

  // weight map: H - 1.008, N - 14.007, O - 15.999, C - 12.011
  FunctionalGroupMap moleMap = getFunctionalGroupMap();

  std::vector<std::vector<int>> perm = permutation(posfg, outerEq, 2);
  std::vector<MolecularStructure> msList;

  for (int i = 0; i < (int)perm.size(); i++) {
    std::vector<int> p = perm[i];
    MolecularStructure ms;
    int C = 2, H = 0, N = 3, O = 0;
    ms.nameHeader = "1,2,3-Triazole";
    for (int j = 0; j < (int)p.size(); j++) {
      MolecularItemHeader h = moleMap.mmap[p[j] - 1];
      C += h.C;
      H += h.H;
      N += h.N;
      O += h.O;
      ms.nameBody.push_back(h.name);
    }
    ms.formula = "C" + (C > 1 ? std::to_string(C) : "") + "N" +
                 (N > 1 ? std::to_string(N) : "") + "H" +
                 (H > 1 ? std::to_string(H) : "");
    ms.weight = (double)C * 12.011 + (double)N * 14.007 + (double)H * 1.008;
    ms.content = 100;
    ms.H = (double)H * 1.008 / ms.weight * 100.0;
    ms.C = (double)C * 12.011 / ms.weight * 100.0;
    ms.N = (double)N * 14.007 / ms.weight * 100.0;
    ms.O = 0.0;
    ms.others = 0.0;
    msList.push_back(ms);
  }

  std::printf("%s", Message24);
  std::printf("%s", MessageHint1);
  for (int i = 0; i < (int)msList.size(); i++) {
    MolecularStructure ms = msList[i];
    std::printf("%s\n", ms.getLine().c_str());
  }
  std::printf("\n");
  std::printf("%s", MessageHint2);
  std::string optionStr = readLine();
  int option = parseInt(optionStr);
  if (option != 1) {
    return;
  }
  while (true) {
    std::printf("%s", MessageHint3);
    optionStr = readLine();
    option = parseInt(optionStr);
    switch (option) {
    case 1: {
      std::printf("%s", MessageHint31);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.weight >= range.first && ms.weight <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 2: {
      std::printf("%s", MessageHint32);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.H >= range.first && ms.H <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 3: {
      std::printf("%s", MessageHint33);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.C >= range.first && ms.C <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 4: {
      std::printf("%s", MessageHint34);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.N >= range.first && ms.N <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 5: {
      std::printf("%s", MessageHint35);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.O >= range.first && ms.O <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 6: {
      std::printf("%s", MessageHint36);
      readAnyKey();
      break;
    }
    default:
      std::printf("ERROR! Invalid option:%s\n", optionStr.c_str());
      std::printf("Press 0 to return...\n> ");
      readAnyKey();
      return;
    }
  }
}

void subOption25() {
  std::printf("%s> ", Message25);
  std::string fgStr = readLine();
  std::vector<int> posfg = splitIntsByComma(fgStr);
  if (posfg.size() < 1 || posfg.size() > 2) {
    std::printf("ERROR! Please input again\n\n");
    return;
  }
  for (int i = 0; i < (int)posfg.size(); i++) {
    if (posfg[i] < 1 || posfg[i] > 7) {
      std::printf("ERROR! Please input again\n\n");
      return;
    }
  }

  // weight map: H - 1.008, N - 14.007, O - 15.999, C - 12.011
  FunctionalGroupMap moleMap = getFunctionalGroupMap();

  std::vector<std::vector<int>> perm = permutation(posfg, outerEq, 2);
  std::vector<MolecularStructure> msList;

  for (int i = 0; i < (int)perm.size(); i++) {
    std::vector<int> p = perm[i];
    MolecularStructure ms;
    int C = 2, H = 0, N = 3, O = 0;
    ms.nameHeader = "1,2,4-Triazole";
    for (int j = 0; j < (int)p.size(); j++) {
      MolecularItemHeader h = moleMap.mmap[p[j] - 1];
      C += h.C;
      H += h.H;
      N += h.N;
      O += h.O;
      ms.nameBody.push_back(h.name);
    }
    ms.formula = "C" + (C > 1 ? std::to_string(C) : "") + "N" +
                 (N > 1 ? std::to_string(N) : "") + "H" +
                 (H > 1 ? std::to_string(H) : "");
    ms.weight = (double)C * 12.011 + (double)N * 14.007 + (double)H * 1.008;
    ms.content = 100;
    ms.H = (double)H * 1.008 / ms.weight * 100.0;
    ms.C = (double)C * 12.011 / ms.weight * 100.0;
    ms.N = (double)N * 14.007 / ms.weight * 100.0;
    ms.O = 0.0;
    ms.others = 0.0;
    msList.push_back(ms);
  }

  std::printf("%s", Message25);
  std::printf("%s", MessageHint1);
  for (int i = 0; i < (int)msList.size(); i++) {
    MolecularStructure ms = msList[i];
    std::printf("%s\n", ms.getLine().c_str());
  }
  std::printf("\n");
  std::printf("%s", MessageHint2);
  std::string optionStr = readLine();
  int option = parseInt(optionStr);
  if (option != 1) {
    return;
  }
  while (true) {
    std::printf("%s", MessageHint3);
    optionStr = readLine();
    option = parseInt(optionStr);
    switch (option) {
    case 1: {
      std::printf("%s", MessageHint31);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.weight >= range.first && ms.weight <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 2: {
      std::printf("%s", MessageHint32);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.H >= range.first && ms.H <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 3: {
      std::printf("%s", MessageHint33);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.C >= range.first && ms.C <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 4: {
      std::printf("%s", MessageHint34);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.N >= range.first && ms.N <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 5: {
      std::printf("%s", MessageHint35);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.O >= range.first && ms.O <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 6: {
      std::printf("%s", MessageHint36);
      readAnyKey();
      break;
    }
    default:
      std::printf("ERROR! Invalid option:%s\n", optionStr.c_str());
      std::printf("Press 0 to return...\n> ");
      readAnyKey();
      return;
    }
  }
}

void subOption26() {
  std::printf("%s> ", Message26);
  std::string fgStr = readLine();
  std::vector<int> posfg = splitIntsByComma(fgStr);
  if (posfg.size() < 1 || posfg.size() > 1) {
    std::printf("ERROR! Please input again\n\n");
    return;
  }
  for (int i = 0; i < (int)posfg.size(); i++) {
    if (posfg[i] < 1 || posfg[i] > 7) {
      std::printf("ERROR! Please input again\n\n");
      return;
    }
  }

  // weight map: H - 1.008, N - 14.007, O - 15.999, C - 12.011
  FunctionalGroupMap moleMap = getFunctionalGroupMap();

  std::vector<std::vector<int>> perm = permutation(posfg, outerEq, 1);
  std::vector<MolecularStructure> msList;

  for (int i = 0; i < (int)perm.size(); i++) {
    std::vector<int> p = perm[i];
    MolecularStructure ms;
    int C = 1, H = 0, N = 4, O = 0;
    ms.nameHeader = "Tetrazole";
    for (int j = 0; j < (int)p.size(); j++) {
      MolecularItemHeader h = moleMap.mmap[p[j] - 1];
      C += h.C;
      H += h.H;
      N += h.N;
      O += h.O;
      ms.nameBody.push_back(h.name);
    }
    ms.formula = "C" + (C > 1 ? std::to_string(C) : "") + "N" +
                 (N > 1 ? std::to_string(N) : "") + "H" +
                 (H > 1 ? std::to_string(H) : "");
    ms.weight = (double)C * 12.011 + (double)N * 14.007 + (double)H * 1.008;
    ms.content = 100;
    ms.H = (double)H * 1.008 / ms.weight * 100.0;
    ms.C = (double)C * 12.011 / ms.weight * 100.0;
    ms.N = (double)N * 14.007 / ms.weight * 100.0;
    ms.O = 0.0;
    ms.others = 0.0;
    msList.push_back(ms);
  }

  std::printf("%s", Message26);
  std::printf("%s", MessageHint1);
  for (int i = 0; i < (int)msList.size(); i++) {
    MolecularStructure ms = msList[i];
    std::printf("%s\n", ms.getLine().c_str());
  }
  std::printf("\n");
  std::printf("%s", MessageHint2);
  std::string optionStr = readLine();
  int option = parseInt(optionStr);
  if (option != 1) {
    return;
  }
  while (true) {
    std::printf("%s", MessageHint3);
    optionStr = readLine();
    option = parseInt(optionStr);
    switch (option) {
    case 1: {
      std::printf("%s", MessageHint31);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.weight >= range.first && ms.weight <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 2: {
      std::printf("%s", MessageHint32);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.H >= range.first && ms.H <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 3: {
      std::printf("%s", MessageHint33);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.C >= range.first && ms.C <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 4: {
      std::printf("%s", MessageHint34);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.N >= range.first && ms.N <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 5: {
      std::printf("%s", MessageHint35);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.O >= range.first && ms.O <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 6: {
      std::printf("%s", MessageHint36);
      readAnyKey();
      break;
    }
    default:
      std::printf("ERROR! Invalid option:%s\n", optionStr.c_str());
      std::printf("Press 0 to return...\n> ");
      readAnyKey();
      return;
    }
  }
}

void subOption27() {
  std::printf("%s> ", Message27);
  readAnyKey();

  // weight map: H - 1.008, N - 14.007, O - 15.999, C - 12.011
  FunctionalGroupMap moleMap = getFunctionalGroupMap();

  std::vector<MolecularStructure> msList;
  MolecularStructure ms;
  int C = 1, H = 0, N = 4, O = 0;
  ms.nameHeader = "Pentazole";
  ms.formula = "C" + (C > 1 ? std::to_string(C) : "") + "N" +
               (N > 1 ? std::to_string(N) : "") + "H" +
               (H > 1 ? std::to_string(H) : "");
  ms.weight = (double)C * 12.011 + (double)N * 14.007 + (double)H * 1.008;
  ms.content = 100;
  ms.H = (double)H * 1.008 / ms.weight * 100.0;
  ms.C = (double)C * 12.011 / ms.weight * 100.0;
  ms.N = (double)N * 14.007 / ms.weight * 100.0;
  ms.O = 0.0;
  ms.others = 0.0;
  msList.push_back(ms);

  std::printf("%s", MessageHint1);
  for (int i = 0; i < (int)msList.size(); i++) {
    MolecularStructure ms = msList[i];
    std::printf("%s\n", ms.getLine().c_str());
  }
  std::printf("\n");
  std::printf("%s", MessageHint2);
  std::string optionStr = readLine();
  int option = parseInt(optionStr);
  if (option != 1) {
    return;
  }
  while (true) {
    std::printf("%s", MessageHint3);
    optionStr = readLine();
    option = parseInt(optionStr);
    switch (option) {
    case 1: {
      std::printf("%s", MessageHint31);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.weight >= range.first && ms.weight <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 2: {
      std::printf("%s", MessageHint32);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.H >= range.first && ms.H <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 3: {
      std::printf("%s", MessageHint33);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.C >= range.first && ms.C <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 4: {
      std::printf("%s", MessageHint34);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.N >= range.first && ms.N <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 5: {
      std::printf("%s", MessageHint35);
      std::string rangeStr = readLine();
      std::pair<double, double> range = parseTwoInts(rangeStr);
      for (int i = 0; i < (int)msList.size(); i++) {
        MolecularStructure ms = msList[i];
        if (ms.O >= range.first && ms.O <= range.second) {
          std::printf("%s\n", ms.getLine().c_str());
        }
      }
      return;
    }
    case 6: {
      std::printf("%s", MessageHint36);
      readAnyKey();
      break;
    }
    default:
      std::printf("ERROR! Invalid option:%s\n", optionStr.c_str());
      std::printf("Press 0 to return...\n> ");
      readAnyKey();
      return;
    }
  }
}

void option2() {
  std::printf("%s", Message2);
  std::string optionStr = readLine();
  int option = parseInt(optionStr);
  switch (option) {
  case 1:
    subOption21();
    break;
  case 2:
    subOption22();
    break;
  case 3:
    subOption23();
    break;
  case 4:
    subOption24();
    break;
  case 5:
    subOption25();
    break;
  case 6:
    subOption26();
    break;
  case 7:
    subOption27();
    break;
  case 8:
    std::printf("Under construction, please contact inventor\n");
    std::printf("Press 0 to return...\n> ");
    break;
  default:
    std::printf("ERROR! Invalid option: %s\n", optionStr.c_str());
  }
  std::printf("\n");
}

void subOption31() {
  std::printf("%s", Message31);
  std::string numberStr = readLine();
  std::vector<double> number = splitDoublesByComma(numberStr);
  if ((int)number.size() != 3) {
    std::printf("ERROR! Invalid numbers: %s\n", numberStr.c_str());
    std::printf("Press 0 to return...\n> ");
    readAnyKey();
    return;
  }
  double density =
      (0.9183 * number[0] / number[1]) + (0.0028 * number[2]) + 0.0443;
  std::printf("%.2f\n", density);
  std::printf("Press 0 to return...\n> ");
  readAnyKey();
}

void subOption32() {
  std::printf("%s", Message32);
  std::string numberStr = readLine();
  std::vector<double> number = splitDoublesByComma(numberStr);
  if ((int)number.size() != 6) {
    std::printf("ERROR! Invalid numbers: %s\n", numberStr.c_str());
    std::printf("Press 0 to return...\n> ");
    readAnyKey();
    return;
  }
  double density = 1.0095 * ((1.0260 * number[0] / number[1]) +
                             (0.0514 * number[2] / number[4]) +
                             (0.0419 * number[3] / number[5]) + 0.0227);
  std::printf("The density of compound is %.2f g/cm-3\n", density);
  std::printf("Press 0 to return...\n> ");
  readAnyKey();
}

void option3() {
  std::printf("%s", Message3);
  std::string optionStr = readLine();
  int option = parseInt(optionStr);
  switch (option) {
  case 1:
    subOption31();
    break;
  case 2:
    subOption32();
    break;
  default:
    std::printf("ERROR! Invalid option: %s\n", optionStr.c_str());
  }
  std::printf("\n");
}

void option4() {
  std::printf("%s", Message4);
  std::string numberStr = readLine();
  std::vector<double> number = splitDoublesByComma(numberStr);
  if ((int)number.size() != 4) {
    std::printf("ERROR! Invalid numbers: %s\n", numberStr.c_str());
    std::printf("Press 0 to return...\n> ");
    readAnyKey();
    return;
  }
  double molecularWeight = number[0] * 12.011 + number[1] * 1.008 +
                           number[2] * 14.007 + number[3] * 15.999;
  double COOxygenBalance =
      ((number[3] - number[0] - number[1] / 2.0) * 16.0) / molecularWeight;
  double CO2OxygenBalance =
      ((number[3] - number[0] * 2.0 - number[1] / 2.0) * 16.0) /
      molecularWeight;
  std::printf("Molecular weight %.2f g/mol, CO Oxygen balance %.2f%%, CO2 "
              "Oxygen balance %.2f%%\n",
              molecularWeight, COOxygenBalance, CO2OxygenBalance);
  std::printf("Input the heat of formation (kJ/mol) and density (g/cm3) of the "
              "compounds\n> ");
  numberStr = readLine();
  number = splitDoublesByComma(numberStr);
  if ((int)number.size() != 2) {
    std::printf("ERROR! Invalid numbers: %s\n", numberStr.c_str());
    std::printf("Press 0 to return...\n> ");
    readAnyKey();
    return;
  }
  if (number[0] > 0.0) {
    std::printf("ERROR! Invalid numbers: %s\n", numberStr.c_str());
    std::printf("Press 0 to return...\n> ");
    readAnyKey();
    return;
  }
  double detonationVelocity =
      1.011 *
      std::sqrt((1.0 / molecularWeight) * std::sqrt(molecularWeight) *
                std::sqrt((-1000.0 * number[0]) / (4.812 * molecularWeight))) *
      (1.0 + 1.312 * number[1]);
  double detonationPressure =
      15.58 * number[1] * number[1] * (1.0 / molecularWeight) *
      std::sqrt(molecularWeight) *
      std::sqrt((-1000.0 * number[0]) / (4.812 * molecularWeight));
  std::printf("Detonation velocity %.2f km/s, Detonation pressure %.2f kbar\n",
              detonationVelocity, detonationPressure);
  std::printf("Press 0 to return...\n> ");
  readAnyKey();
}

void option5() {
  std::printf("Under construction, please contact inventor\n");
  std::printf("Press 0 to return...\n> ");
  readAnyKey();
}

void option6() {
  std::printf("Under construction, please contact inventor\n");
  std::printf("Press 0 to return...\n> ");
  readAnyKey();
}

void option7() {
  std::printf("Exit...\n");
  std::exit(0);
}

void mainRoutine() {
  std::printf("%s", MainMessage);
  std::string optionStr = readLine();
  int option;
  option = parseInt(optionStr);
  switch (option) {
  case 1:
    option1();
    break;
  case 2:
    option2();
    break;
  case 3:
    option3();
    break;
  case 4:
    option4();
    break;
  case 5:
    option5();
    break;
  case 6:
    option6();
    break;
  case 7:
    option7();
    break;
  default:
    std::printf("ERROR! Invalid option: %s\n", optionStr.c_str());
  }
}

int main(void) {
  while (1) {
    try {
      mainRoutine();
    } catch (...) {
      std::printf("ERROR! Please input again\n\n");
    }
  }
  return 0;
}
