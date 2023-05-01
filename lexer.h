#ifndef LEXER
#define LEXER

#include "splashkit.h"
#include <fstream>
#include <filesystem>
#include <vector>
#include <regex>
#include <utility>
using namespace std;


/**
 * Extracts the chosen text file into an array to be analysed.
 * 
 * @param mainFile      The ifstream file to extract into an array
 * @returns             Vector version of file
 */
vector<string> line_extraction(ifstream &mainFile);

/**
 * Culls out comments for the analysis.
 * 
 * @param old_lines         The vector to be cleaned of comments
 * @returns                 Vector clean of comments
 */
vector<string> comment_cull(vector<string> old_lines);

/**
 * Extracts all call tokens.
 * 
 * @param processed_lines       The vector whose call tokens will be extracted
 * @returns                     A new vector containing the call tokens used and their respective line numbers
 */
vector<pair<string, int>> call_token_extract(vector<string> processed_lines);

/**
 * Extracts i/o tokens.
 * 
 * @param processed_lines       The vector whose input tokens will be extracted\
 * @param io                    1: Inputs; 0: Outputs
 * @returns                     A new array containing the i/o tokens used
 */
vector<string> io_token_extract(vector<string> processedLines, bool io);

/**
 * Extracts all sub-io tokens.
 * 
 * @param line       The line to analyse
 * @returns          A new vector containing the sub io tokens
 */
vector<string> sub_io_token_extract(string line);

#endif