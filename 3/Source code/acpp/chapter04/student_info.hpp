#ifndef ACPP_STUDENT_INFO_HPP
#define ACPP_STUDENT_INFO_HPP

// `student_info.hpp' header file
#include <iostream>
#include <string>
#include <vector>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif /* ACPP_STUDENT_INFO_HPP */
