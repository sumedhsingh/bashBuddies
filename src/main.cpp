#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
    // argc is the number of command line arguments passed including program name
    // argv is an array of C strings, where each element is a command line argument
    // argv[0] = program name and the rest are the arguments provided

    if(argc < 2){
        cerr << "Usage: utility_tool <command> [arguments]" << endl;
        return 1;
    }

    //get first argument
    string command = argv[1];

    if (command == "wthr"){
        if (argc < 3){
            cerr << "Usage: utility_tool wthr <city name>" << endl;
            return 1;
        }

        string city = argv[2];
        cout << "Fetching weather for: " << city << endl;       
    }

    else if (command == "time"){
        if (argc < 3){
            cerr << "Usage: utility_tool time <city name>" << endl;
            return 1;
        }

        string city = argv[2];
        cout << "Fetching time for: "<< city << endl;
    }

    else{
        cerr << "Unknown command: " << command <<endl;
        return 1;
    }

    return 0;                                                               // for indicating successful execution
}