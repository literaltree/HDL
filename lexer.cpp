#include "splashkit.h"
#include <fstream>
#include <filesystem>
#include <vector>
#include <regex>
#include <utility>
using namespace std;

// todo:
// [-] Read all files in the folder where the original file is read using recursive <filesystem> directory iterator
// [-] Ensure correct file format/extension using <filesystem>

vector<string> line_extraction(ifstream &mainFile) {
    vector<string> lines;
    int numLines = 0;
    string line;
    while (mainFile.peek() != EOF) {
        getline(mainFile, line);
        lines.push_back(line);
    }
    mainFile.close();
    return lines;
}

vector<string> comment_cull(vector<string> oldLines) {
    vector<string> noComments;
    smatch m;
    for (int i=0; i<oldLines.size(); i++) {
        regex_match(oldLines.at(i), m, regex("//.*"));
    }
    for (int i=0; i<m.length(); i++) {
        noComments.push_back(m[i]);
    }
    return noComments;
}

vector<pair<string, int>> call_token_extract(vector<string> processedLines) {
    vector<pair<string, int>> uniqueCalls;
    vector<int> lines;
    regex pattern("^[a-zA-Z][^(]*");
    smatch m;
    for (int i=0; i<processedLines.size(); i++) {
        regex_match(processedLines.at(i), m, pattern);
        lines.push_back(i);
    }
    for (int i=0; i<m.length(); i++) {
        uniqueCalls.push_back(make_pair(m[i], lines.at(i)));
    }

    return uniqueCalls;
}

vector<string> sub_io_token_extract(string line) {
    vector<string> subIO;
    regex pattern("\(([^\(\)]*?)\)");
    smatch m;

    regex_match(line, m, pattern);
    for (int i=0; i<m.length(); i++) {
        subIO.push_back(m[i]);
    }
    return subIO;
}

vector<string> io_token_extract(vector<string> processedLines, bool io) {
    vector<string> IOs;
    string inout;
    if (io) {
        inout = "IN";
    } else inout = "OUT";

    regex pattern(inout + ":\s*([^,\s]+)(\s*,\s*([^,\s]+))*");
    smatch m;

    for (int i=0; i<processedLines.size(); i++) {
        regex_match(processedLines.at(i), m, pattern);
    }
    for (int i=0; i<m.length(); i++) {
        IOs.push_back(m[i]);
    }
    return IOs;
}