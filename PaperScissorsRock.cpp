#include <iostream>
#include <vector>
#include <random>
#include <string>
 
 
int  user_score = 0;
int  computer_score = 0;
int choice;
void compare_results(const std::string &user_choice, const std::string &computer_choice){
    if (user_choice == "rock" && computer_choice == "paper") {
        computer_score +=1;
    }
 
    if (user_choice == "rock" && computer_choice == "scissors") {
        user_score ++;
    }
    if (user_choice == "paper" && computer_choice == "rock") {
        user_score ++;
    }
    if (user_choice == "paper" && computer_choice == "scissors") {
        computer_score ++;
    }
    if (user_choice == "scissors" && computer_choice == "rock") {
        computer_score ++;
    }
    if (user_choice == "scissors" && computer_choice == "paper") {
        user_score++;
    }
    if (user_choice == computer_choice)
        std::cout << "draw" << "\n";
}
int validate_input(int x){
    if (x >= 0 && x <= 3)
        return x;
    std::cout << "Invalid input" << "\n" << "Press 1 to choose rock, 2 for paper and 3 for scissors" << "\n";
    std::cin >> choice;
}
int main() {
    int number_of_rounds;
 
    std::string user_choice;
    std::string computer_choice;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 2);
    dist(mt); // random number 0-2 range
    std::vector<std::string> choices = {"rock", "paper", "scissors"};
    std::cout << "How many rounds do you want to play?" << "\n";
    std::cin >> number_of_rounds;
 
 
    while (number_of_rounds) {
        std::cout << "Press 1 to choose rock, 2 for paper and 3 for scissors" << "\n";
        std::cin >> choice;
        switch (choice) {
        case 1:
        user_choice = "rock";
        break;
        case 2:
        user_choice = "paper";
        break;
        case 3:
        user_choice = "scissors";
        break;
        default:
        std::cout << "Invalid input" << "\n" << "Press 1 to choose rock, 2 for paper and 3 for scissors" << "\n";
        std::cin >> choice;
        break;
}
        std::cout << "Your choice: " + user_choice << "\n";
        validate_input(choice);
        computer_choice = choices[dist(mt)];
        std::cout << "Computer's choice: " + computer_choice << "\n";
        compare_results(user_choice, computer_choice);
        std::cout << "Your score: " << user_score << "\n" << "Computer score: " << computer_score << "\n";
        std::cout << "#####################################################" << "\n";
        number_of_rounds--;
 
 
    }
    if (user_score > computer_score)
        std::cout << "You have won the game";
    else if (user_score < computer_score)
        std::cout << "Computer has won the game";
    else
        std::cout << "Draw";
    return 0;
}