#include <fstream>
#include <unistd.h>

#include "../include/Input.hpp"
#include "../include/Logger.hpp"

bool isStringInt(string input){
    bool result = true;
    short minusCount = 0;
    for(char c : input){
        // Is there a char which isn't a digit?
        if(c<'0'||c >'9'){
            if(c=='-'){
                // Is there a minus?
                minusCount++;

                // If there are more than one minus, or
                // a minus not at the first place, return false.
                if(minusCount>1||input.find(c)!=0){
                    result = false;
                }
            } else {
                result = false;
            }
        }
    }
    return result;
}

bool isStringFloat(string input){
    bool result = true;
    short dotCount = 0;
    short minusCount = 0;
    for(char c : input){
        if(c<'0'||c >'9'){
            if(c=='.'){
                dotCount++;
            }
            if(dotCount>1){
                result = false;
            }
            if(c=='-'){
                minusCount++;
            }
            if(minusCount>1){
                result = false;
            }
        }
    }
    return result;
}

bool isCharInString(string inputString, char character){
    bool result = false;
    for(long unsigned int i = 0; i < inputString.size(); i++){
        if(inputString[i]==character){
            result = true;
            break;
        }
    }
    return result;
}

bool isSubstringInString(string inputString, string substring){
    bool result = true;
    if(inputString.size() < substring.size()){
        //cout << "Input string has to be larger than substring." << endl;
    }
    for(long unsigned int i = 0; i < substring.size(); i++){
        if(inputString[i] != substring[i]){
            result = false;
        }
    }
    return result;
}

string deleteSubstringInString(string inputString, string substring){
    string result;
    long unsigned int index = 0;
    if(isSubstringInString(inputString,substring)){
        for(long unsigned int i = 0; i < inputString.size(); i++) {
            if (inputString[i] != substring[i]) {
                index = i;
                break;
            }
        }
        for(long unsigned int i = index; i < inputString.size(); i++){
            result += inputString[i];
        }
    } else {
        result = "";
    }
    return result;
}

double stringToDouble(string input){
    double result = 0.0;
    if(input.empty()){
        displayError(ERROR_NO_ARGUMENT, "You did not put in a value for an argument.");
    }
    if(!isStringFloat(input)){
        displayError(ERROR_BAD_ARGUMENT, "The floating-point value you entered was not formatted properly.");
    }
    try {
        result = stod(input);
    } catch (invalid_argument& e) {
        displayError(ERROR_BAD_ARGUMENT, "The floating-point value you entered was not formatted properly.");
    } catch (out_of_range& e){
        displayError(ERROR_BAD_CAST, "The value you entered could not be cast to the correct datatype (double).\nCheck if the value is not too large.");
    }
    return result;
}

int stringToInt(string input){
    int result = 0;
    if(input.empty()){
        displayError(ERROR_NO_ARGUMENT, "You did not put in a value for an argument.");
    }
    if(!isStringInt(input)){
        displayError(ERROR_BAD_ARGUMENT, "The integer value you entered was not formatted properly.");
    }
    try {
        result = stoi(input);
    } catch (invalid_argument& e) {
        displayError(ERROR_BAD_ARGUMENT, "The integer value you entered was not formatted properly.");
    } catch (out_of_range& e){
        displayError(ERROR_BAD_CAST, "The value you entered could not be cast to the correct datatype (int).\nCheck if the value is not too large.");
    }
    return result;
}

long int stringToLongInt(string input){
    long int result = 0;
    if(input.empty()){
        displayError(ERROR_NO_ARGUMENT, "You did not put in a value for an argument.");
    }
    if(!isStringInt(input)){
        displayError(ERROR_BAD_ARGUMENT, "The integer value you entered was not formatted properly.");
    }
    try {
        result = stol(input);
    } catch (invalid_argument& e) {
        displayError(ERROR_BAD_ARGUMENT, "The integer value you entered was not formatted properly.");
    } catch (out_of_range& e){
        displayError(ERROR_BAD_CAST, "The value you entered could not be cast to the correct datatype (long int).\nCheck if the value is not too large.");
    }
    return result;
}

ExecParameters_t getExecParamFromArgv(vector<string> argv){

    // These are the standard parameters.
    ExecParameters_t execParameters;
    execParameters.lowerBound = 0.0;
    execParameters.upperBound = 2.0;
    execParameters.gridLineDist = 1.0;
    execParameters.needleLength = 1.0;
    execParameters.numberThreads = 1;
    execParameters.numberNeedles = 10000;
    execParameters.iterations = 1;
    execParameters.filename = "result.txt";

    // This vector keeps track if some argument has been used twice.
    vector<short> argCounts(8, 0);

    // Iterate through all arguments.
    for(string arg : argv){

        // Check for every possible command line argument,
        // and execute something different each time.
        if(isSubstringInString(arg, cmdLineArgs[0])){
            displayHelp();
        } else if(isSubstringInString(arg, cmdLineArgs[1])){
            displayHelp();
        } else if(isSubstringInString(arg, cmdLineArgs[2])){
            execParameters.lowerBound=stringToDouble(deleteSubstringInString(arg, cmdLineArgs[2]));
            argCounts[0]++;
        } else if(isSubstringInString(arg, cmdLineArgs[3])){
            execParameters.lowerBound=stringToDouble(deleteSubstringInString(arg, cmdLineArgs[3]));
            argCounts[0]++;
        } else if(isSubstringInString(arg, cmdLineArgs[4])){
            execParameters.upperBound=stringToDouble(deleteSubstringInString(arg, cmdLineArgs[4]));
            argCounts[1]++;
        } else if(isSubstringInString(arg, cmdLineArgs[5])){
            execParameters.upperBound=stringToDouble(deleteSubstringInString(arg, cmdLineArgs[5]));
            argCounts[1]++;
        } else if(isSubstringInString(arg, cmdLineArgs[6])){
            execParameters.gridLineDist=stringToDouble(deleteSubstringInString(arg, cmdLineArgs[6]));
            argCounts[2]++;
        } else if(isSubstringInString(arg, cmdLineArgs[7])){
            execParameters.gridLineDist=stringToDouble(deleteSubstringInString(arg, cmdLineArgs[7]));
            argCounts[2]++;
        } else if(isSubstringInString(arg, cmdLineArgs[8])){
            execParameters.needleLength=stringToDouble(deleteSubstringInString(arg, cmdLineArgs[8]));
            argCounts[3]++;
        } else if(isSubstringInString(arg, cmdLineArgs[9])){
            execParameters.needleLength=stringToDouble(deleteSubstringInString(arg, cmdLineArgs[9]));
            argCounts[3]++;
        } else if(isSubstringInString(arg, cmdLineArgs[10])){
            execParameters.numberThreads=stringToInt(deleteSubstringInString(arg, cmdLineArgs[10]));
            argCounts[4]++;
        } else if(isSubstringInString(arg, cmdLineArgs[11])){
            execParameters.numberThreads=stringToInt(deleteSubstringInString(arg, cmdLineArgs[11]));
            argCounts[4]++;
        } else if(isSubstringInString(arg, cmdLineArgs[12])){
            execParameters.numberNeedles=stringToLongInt(deleteSubstringInString(arg, cmdLineArgs[12]));
            argCounts[5]++;
        } else if(isSubstringInString(arg, cmdLineArgs[13])){
            execParameters.numberNeedles=stringToLongInt(deleteSubstringInString(arg, cmdLineArgs[13]));
            argCounts[5]++;
        } else if(isSubstringInString(arg, cmdLineArgs[14])){
            execParameters.iterations=stringToLongInt(deleteSubstringInString(arg, cmdLineArgs[14]));
            argCounts[6]++;
        } else if(isSubstringInString(arg, cmdLineArgs[15])){
            execParameters.iterations=stringToLongInt(deleteSubstringInString(arg, cmdLineArgs[15]));
            argCounts[6]++;
        } else if (isSubstringInString(arg, cmdLineArgs[16])){
            execParameters.filename=deleteSubstringInString(arg, cmdLineArgs[16]);
            argCounts[7]++;
        } else if (isSubstringInString(arg, cmdLineArgs[17])){
            execParameters.filename=deleteSubstringInString(arg, cmdLineArgs[17]);
            cout << deleteSubstringInString(arg, cmdLineArgs[16]) << endl;
            argCounts[7]++;
        } else {
            string errMesg = arg;
            errMesg.append(" does not exist as an option.\nType --help or -h to get a list of all available arguments.");
            displayError(ERROR_NO_SUCH_ARG,errMesg);
        }
        for(short i : argCounts){
            if(i > 1){
                displayError(ERROR_MULTIPLE_ARG, "You have entered arguments of the same kind multiple times.");
            }
        }
    }
    return sanitizeParameters(execParameters);
}

ExecParameters_t sanitizeParameters(ExecParameters_t execParameters){
    ExecParameters_t cleanParameters;
    if(execParameters.lowerBound >= execParameters.upperBound){
        displayError(ERROR_LOGIC_BOUNDS, "The lower boundary of the canvas\nshould be smaller than the upper boundary.");
    }
    cleanParameters.lowerBound = execParameters.lowerBound;
    cleanParameters.upperBound = execParameters.upperBound;

    if(execParameters.gridLineDist == 0){
        displayError(ERROR_LOGIC_ZERO, "Grid Line Distance cannot be zero.");
    }
    cleanParameters.gridLineDist = abs(execParameters.gridLineDist);

    if(execParameters.needleLength == 0 ){
        displayError(ERROR_LOGIC_ZERO, "Needle length has to be zero.");
    }

    cleanParameters.needleLength = abs(execParameters.needleLength);

    if(execParameters.numberThreads == 0){
        displayError(ERROR_LOGIC_ZERO,
                     "Number of threads cannot be zero.");
    }

    cleanParameters.numberThreads =
            abs(execParameters.numberThreads);

    if(execParameters.numberNeedles == 0){
        displayError(ERROR_LOGIC_ZERO,
                     "Number of needles cannot be zero.");
    }

    cleanParameters.numberNeedles = abs(execParameters.numberNeedles);

    if(execParameters.iterations == 0){
        displayError(ERROR_LOGIC_ZERO, "Number of iterations cannot be zero.");
    }

    cleanParameters.iterations = abs( execParameters.iterations);


    ifstream file(execParameters.filename);
    if(file.is_open()){
        string warningMessage = "WARNING: " + execParameters.filename
                + " exists already.\nTerminate with Ctrl+C within 5 seconds"
                  " to prevent the file to be overwritten.";
        displayMessage(warningMessage);

        // THIS DOES NOT WORK FOR NON-UNIX SYSTEMS
        // USE WINDOWS.H INSTEAD OF UNISTD.h OR REMOVE ENTIRELY!!
        sleep(5);
    }

    cleanParameters.filename = execParameters.filename;

    return cleanParameters;
}