#include "splashkit.h"
#include <fstream>
#include <filesystem>
#include <set>
#include "lexer.h"
#include <utility>

using namespace std;

int main(int argc, char* argv[]) 
{
    // todo:
    // [-] use <filesystem> + user inputs + <fstream> to get a file
    // [-] make sure the file exists and is the right extension
    if (argc != 2) {
        return 1;
    }
    ifstream mainFile(argv[1]);
    if (!mainFile.is_open()) {
        return 2;
    }

    filesystem::path chip_dir = filesystem::current_path() / "Chips";
    set<string> filepaths;
    for (auto& file : filesystem::directory_iterator(chip_dir)) {
        if (file.path().extension() == ".HDL") {
            filepaths.insert(file.path().string());
        }
    }

    vector<string> extractedLines = line_extraction(mainFile);
    vector<string> commentlessLines = comment_cull(extractedLines);
    vector<pair<string, int>> callTokens = call_token_extract(commentlessLines);
    
    vector<vector<string>> subIOTokens;
    vector<string> temp;
    for (int i=0; i<callTokens.size(); i++) {
        temp = sub_io_token_extract(commentlessLines.at(callTokens.at(i).second));
        subIOTokens.push_back(temp);
    }

    vector<string> inputs = io_token_extract(commentlessLines, 1);
    vector<string> outputs = io_token_extract(commentlessLines, 0);

    return 0;
}