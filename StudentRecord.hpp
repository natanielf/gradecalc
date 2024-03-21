#include <string>

#ifndef STUDENTRECORD_HPP
#define STUDENTRECORD_HPP

class StudentRecord {
   public:
    StudentRecord()
        : quiz1_grade_(0.0),
          quiz2_grade_(0.0),
          quiz3_grade_(0.0),
          midterm_grade_(0.0),
          final_grade_(0.0),
          total_grade_(-1.0){};
    StudentRecord(double quiz1_grade, double quiz2_grade, double quiz3_grade,
                  double midterm_grade, double final_grade)
        : quiz1_grade_(quiz1_grade),
          quiz2_grade_(quiz2_grade),
          quiz3_grade_(quiz3_grade),
          midterm_grade_(midterm_grade),
          final_grade_(final_grade),
          total_grade_(-1.0){};

    // Getters
    double getQuiz1Grade();
    double getQuiz2Grade();
    double getQuiz3Grade();
    double getMidtermGrade();
    double getFinalGrade();

    // Setters
    void setQuiz1Grade(double quiz1_grade);
    void setQuiz2Grade(double quiz2_grade);
    void setQuiz3Grade(double quiz3_grade);
    void setMidtermGrade(double midterm_grade);
    void setFinalGrade(double final_grade);

    double computeNumericScore();
    char computeLetterGrade();
    std::string toString();
    bool equals(StudentRecord other);

   private:
    double quiz1_grade_;
    double quiz2_grade_;
    double quiz3_grade_;
    double midterm_grade_;
    double final_grade_;
    double total_grade_;

    // Point allocation of various assessments
    const unsigned int QUIZ_POINTS = 10;
    const unsigned int MIDTERM_POINTS = 100;
    const unsigned int FINAL_POINTS = 100;

    // Grade weights (percent)
    const unsigned int QUIZ_WEIGHT = 25;
    const unsigned int MIDTERM_WEIGHT = 35;
    const unsigned int FINAL_WEIGHT = 40;
};

#endif  // STUDENTRECORD_HPP
