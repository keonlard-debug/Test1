#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int main() {
    char again = 'y';
    bool error;
    int temp=0;
    std::vector <int> playerNumbers, kenoNumbers, matches;;

    do {
        std::cout << "\nTo play Keno, select 10 unique (no repeats) numbers in the range of 1-80.\n\n";
        std::cout << "Let's Play Keno!\n\n";
        // Get player picks
        for (int i=0;i<10;i++){
            error = false;
            std::cout << "Enter your pick #" << i+1 <<": ";
            std::cin >> temp;
            if (std::cin.fail())
            {
                error = true;
                std::cin.clear();
                std::cin.ignore(100,'\n');
                std::cout << "Invalid data input! Try again. ";
            }
            else if (temp > 80)
            {
                error = true;
                std::cout << temp << " is out of range! Try again. ";
            }
            else if (std::find(playerNumbers.begin(), playerNumbers.end(), temp) != playerNumbers.end()) {
                error = true;
                std::cout << temp << " was already picked! Try again. ";
            }
            if (error)
                i--;
            else
                playerNumbers.push_back(temp);
        }
        // End

        // Generate Keno numbers
        std::random_device rd;
        std::mt19937 gen(rd());
        gen.seed(0);
        std::uniform_int_distribution<int> distrib(1, 80);
        int num;
        for (int i = 1; i <= 20; ) {
            num = distrib(gen);
            if (std::find(kenoNumbers.begin(), kenoNumbers.end(), num) == kenoNumbers.end()) {
                kenoNumbers.push_back(num);
                i++;
            }
        }
        // End

        // Find matches
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 20; j++) {
                if(playerNumbers.at(i) == kenoNumbers.at(j)) {
                    matches.push_back(playerNumbers.at(i));
                }
            }
        }
        // End

        // Display results
        std::cout <<"\n----------------------------------Results----------------------------------\n";
        std::cout << "Keno Numbers: ";
        std::sort(kenoNumbers.begin(), kenoNumbers.end());
        for (auto i:kenoNumbers) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        std::cout << "Players: ";
        std::sort(playerNumbers.begin(), playerNumbers.end());
        for (auto i:playerNumbers) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        std::cout << "You matched: ";
        std::sort(matches.begin(), matches.end());
        for (auto i:matches) {
            std::cout << i << " ";
        }

        if (matches.size() > 0) {
            std::cout<<"\nMatching " << matches.size() << " of 20 numbers wins ";
            switch (matches.size()){
                case 10:
                    std::cout<<"the GRAND PRIZE of $25,000";
                break;
                case 9:
                    std::cout << "$2,500";
                break;
                case 8:
                    std::cout<<"$250";
                break;
                case 7:
                    std::cout<<"$50";
                break;
                case 6:
                    std::cout<<"$10";
                break;
                case 5:
                    std::cout<<"$5";
                break;
                default:
                    std::cout<<"$0. Sorry, better luck next time.";
            }
        }
        else {
            std::cout << "\nSorry, you didn't have any matches.";
        }
        // End

        std::cout << "\n\nPlay again? (y/n): ";
        std::cin >> again;
        playerNumbers.clear();
        kenoNumbers.clear();
        matches.clear();
    } while (tolower(again) == 'y');
    std::cout << "\nTHANKS FOR PLAYING!!\n";

    return 0;
}
