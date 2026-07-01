//wap to create quiz application 
#include <iostream>
#include <vector>
#include <string>

struct Question {
    std::string questionText;
    std::vector<std::string> options;
    int correctOption; // 1-based index
};

void runQuiz(const std::vector<Question>& quiz) {
    int score = 0;
    int userChoice;

    std::cout << "=== Welcome to the Quiz ===\n\n";

    for (size_t i = 0; i < quiz.size(); ++i) {
        std::cout << "Q" << (i + 1) << ": " << quiz[i].questionText << "\n";
        
        for (size_t j = 0; j < quiz[i].options.size(); ++j) {
            std::cout << "  " << (j + 1) << ". " << quiz[i].options[j] << "\n";
        }

        std::cout << "Your answer (1-" << quiz[i].options.size() << "): ";
        while (!(std::cin >> userChoice) || userChoice < 1 || userChoice > static_cast<int>(quiz[i].options.size())) {
            std::cout << "Invalid input. Please enter a valid option number: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        if (userChoice == quiz[i].correctOption) {
            std::cout << "Correct!\n\n";
            score++;
        } else {
            std::cout << "Wrong. The correct answer was option " << quiz[i].correctOption << ".\n\n";
        }
    }

    std::cout << "=== Quiz Finished ===\n";
    std::cout << "Your total score: " << score << " / " << quiz.size() << "\n";
}

int main() {
    std::vector<Question> quizBank = {
        {
            "Which programming language is known as a superset of C?",
            {"Java", "Python", "C++", "C#"},
            3
        },
        {
            "What is the correct way to output 'Hello World' in C++?",
            {"print(\"Hello World\");", "std::cout << \"Hello World\";", "System.out.println(\"Hello World\");", "echo \"Hello World\";"},
            2
        },
        {
            "Which data type is used to store true or false values in C++?",
            {"int", "float", "bool", "string"},
            3
        }
    };

    runQuiz(quizBank);

    return 0;
}
