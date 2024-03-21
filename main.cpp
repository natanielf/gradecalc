#include <iomanip>
#include <iostream>

#include "StudentRecord.hpp"

using namespace std;

int main() {
    // Create StudentRecord object
    StudentRecord sr;

    // Read user input for each score
    double quiz1_score = 0.0;
    cout << "Enter score for quiz 1 (10 points):" << endl;
    cin >> quiz1_score;
    sr.setQuiz1Grade(quiz1_score);

    double quiz2_score = 0.0;
    cout << "Enter score for quiz 2 (10 points):" << endl;
    cin >> quiz2_score;
    sr.setQuiz2Grade(quiz2_score);

    double quiz3_score = 0.0;
    cout << "Enter score for quiz 3 (10 points):" << endl;
    cin >> quiz3_score;
    sr.setQuiz3Grade(quiz3_score);

    double midterm_score = 0.0;
    cout << "Enter score for the midterm (100 points):" << endl;
    cin >> midterm_score;
    sr.setMidtermGrade(midterm_score);

    double final_score = 0.0;
    cout << "Enter score for the final (100 points):" << endl;
    cin >> final_score;
    sr.setFinalGrade(final_score);

    // Output the student grade
    double numeric_score = sr.computeNumericScore();
    char letter_grade = sr.computeLetterGrade();
    cout << fixed << setprecision(2);
    cout << sr.toString() << endl;
    cout << "Final score: " << numeric_score << "% (" << letter_grade << ")"
         << endl;

    return 0;
}
