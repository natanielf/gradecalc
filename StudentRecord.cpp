#include "StudentRecord.hpp"

#include <assert.h>

#include <sstream>
#include <string>

using namespace std;

// Getters
double StudentRecord::getQuiz1Grade() { return this->quiz1_grade_; }

double StudentRecord::getQuiz2Grade() { return this->quiz2_grade_; }

double StudentRecord::getQuiz3Grade() { return this->quiz3_grade_; }

double StudentRecord::getMidtermGrade() { return this->midterm_grade_; }

double StudentRecord::getFinalGrade() { return this->final_grade_; }

// Setters
void StudentRecord::setQuiz1Grade(double quiz1_grade) {
    assert(quiz1_grade >= 0.0);
    assert(quiz1_grade <= QUIZ_POINTS);
    this->quiz1_grade_ = quiz1_grade;
}

void StudentRecord::setQuiz2Grade(double quiz2_grade) {
    assert(quiz2_grade >= 0.0);
    assert(quiz2_grade <= QUIZ_POINTS);
    this->quiz2_grade_ = quiz2_grade;
}

void StudentRecord::setQuiz3Grade(double quiz3_grade) {
    assert(quiz3_grade >= 0.0);
    assert(quiz3_grade <= QUIZ_POINTS);
    this->quiz3_grade_ = quiz3_grade;
}

void StudentRecord::setMidtermGrade(double midterm_grade) {
    assert(midterm_grade >= 0.0);
    assert(midterm_grade <= MIDTERM_POINTS);
    this->midterm_grade_ = midterm_grade;
}

void StudentRecord::setFinalGrade(double final_grade) {
    assert(final_grade >= 0.0);
    assert(final_grade <= FINAL_POINTS);
    this->final_grade_ = final_grade;
}

// Other methods
double StudentRecord::computeNumericScore() {
    double quiz_score =
        (quiz1_grade_ + quiz2_grade_ + quiz3_grade_) / (QUIZ_POINTS * 3.0);
    double midterm_score = midterm_grade_ / MIDTERM_POINTS;
    double final_score = final_grade_ / FINAL_POINTS;
    double total_score = (quiz_score * (QUIZ_WEIGHT / 100.0)) +
                         (midterm_score * (MIDTERM_WEIGHT / 100.0)) +
                         (final_score * (FINAL_WEIGHT / 100.0));
    this->total_grade_ = (total_score * 100.0);
    assert(this->total_grade_ >= 0.0);
    assert(this->total_grade_ <= 100.0);
    return this->total_grade_;
}

char StudentRecord::computeLetterGrade() {
    // Check whether the total grade has already been calculated
    if (this->total_grade_ < 0.0) this->computeNumericScore();
    if (this->total_grade_ >= 90.0) return 'A';
    if (this->total_grade_ >= 80.0) return 'B';
    if (this->total_grade_ >= 70.0) return 'C';
    if (this->total_grade_ >= 60.0) return 'D';
    return 'F';
}

string StudentRecord::toString() {
    stringstream s;
    s << "STUDENT RECORD:" << endl;
    s << "QUIZ 1: " << quiz1_grade_ << " / " << QUIZ_POINTS << endl;
    s << "QUIZ 2: " << quiz2_grade_ << " / " << QUIZ_POINTS << endl;
    s << "QUIZ 3: " << quiz3_grade_ << " / " << QUIZ_POINTS << endl;
    s << "MIDTERM: " << midterm_grade_ << " / " << MIDTERM_POINTS << endl;
    s << "FINAL: " << final_grade_ << " / " << final_grade_ << endl;
    s << "LETTER GRADE: " << computeLetterGrade();
    return s.str();
}

bool StudentRecord::equals(StudentRecord other) {
    return (this->quiz1_grade_ == other.quiz1_grade_ &&
            this->quiz2_grade_ == other.quiz2_grade_ &&
            this->quiz3_grade_ == other.quiz3_grade_ &&
            this->midterm_grade_ == other.midterm_grade_ &&
            this->final_grade_ == other.final_grade_ &&
            this->total_grade_ == other.total_grade_);
}
