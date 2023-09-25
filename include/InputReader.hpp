#ifndef INPUT_READER_HPP
#define INPUT_READER_HPP

#include <iostream>
#include <cstdlib>

class InputReader{
public:
    InputReader() = default;
    ~InputReader() = default;

    inline bool selectPrintableTeams(const int& argc, char** argv, std::vector<int>& printableTeams) {

        int teamId{};

        if (argc < 2) {
            std::cout << "Please, enter integers between 1 and 400. Enter the 0 to end the entry process." << std::endl;

            while (true) {
                std::string input{};

                try {
                    std::cout << "Please, enter an integer: ";
                    std::cin >> input;

                    teamId = std::stoi(input);
                }
                catch(const std::exception& e) {
                    std::cerr << e.what() << '\n';
                    printCharacterError(input);
                    return 1;
                }

                if (teamId == 0) { break; }
                
                else if (teamId < 1 || teamId > 400) {
                    printRangeError(teamId);
                }

                else { printableTeams.push_back(--teamId); }

                if (printableTeams.size() > 399) {
                    std::cerr << "You can enter up to 400 numbers. Finalizing the entry process..." << std::endl;
                    break;
                }
            }
        }

        else {
            for (int i = 1; i < argc; ++i) {
                try {
                   teamId = std::atoi(argv[i]);
                }
                catch(const std::exception& e) {
                    std::cerr << e.what() << '\n';
                    return 1;
                }

                if (teamId == 0 && argv[i][0] != '0') {
                    printCharacterError(argv[i]);
                    return 1;
                }

                if (teamId < 1 || teamId > 400) {
                    printRangeError(teamId);
                    return 1;
                }
                printableTeams.push_back(--teamId);
            }
        }
        return 0;
    }
private:
    inline void printRangeError(const int& number){
        std::cerr << "[Invalid Input] : " << number << " is not a number between 1 and 400." << std::endl;
    }
    inline void printCharacterError(const std::string& characters) {
        std::cerr << "[Invalid Input] : " << characters << " is not a number." << std::endl;
    }
};

#endif
