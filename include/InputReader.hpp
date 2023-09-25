#ifndef INPUT_READER_HPP
#define INPUT_READER_HPP

#include <iostream>
#include <cstdlib>

class InputReader{
public:
    InputReader() = default;
    ~InputReader() = default;

    inline bool selectPrintableTeams(const int& argc,char** argv, std::vector<int>& printableTeams) {

        int teamId{};

        if (argc < 2) {
            std::cout << "Please, enter integers between 1 and 400. Enter the 0 to end the entry process." << std::endl;

            while (true) {
                std::string inputs;
                std::cout << "Please, enter input: ";
                std::cin >> inputs;

                teamId = std::atoi(inputs.c_str());

                if (teamId == 0) { break; }
                
                else if (teamId < 1 || teamId > 400) {
                    std::cerr << "[Invalid Input] : " << teamId << " is not a number between 1 and 400." << std::endl;
                    return 1;
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
                teamId = std::atoi(argv[i]);

                if (teamId == 0 && argv[i][0] != '0') {
                    std::cerr << "[Invalid Input] : " << argv[i] << " is not a number." << std::endl;
                    return 1;
                }

                if (teamId < 1 || teamId > 400) {
                    std::cerr << "[Invalid Input] : " << argv[i] << " is not a number between 1 and 400." << std::endl;
                    return 1;
                }
                printableTeams.push_back(--teamId);
            }
        }
        return 0;
    }
};

#endif
