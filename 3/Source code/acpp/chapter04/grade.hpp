#ifndef ACPP_GRADE_HPP
#define ACPP_GRADE_HPP

// `grade.hpp'
#include "student_info.hpp"
#include <vector>

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);

#endif /* ACPP_GRADE_HPP */
