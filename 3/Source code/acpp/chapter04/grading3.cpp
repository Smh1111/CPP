#include "student_info.hpp"
#include "grade.hpp"

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;                     using std::setprecision;
using std::cout;                    using std::sort;
using std::domain_error;            using std::streamsize;
using std::endl;                    using std::string;
using std::max;                     using std::vector;
using std::setw;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;    // the length of the longest name

    // read and store all the students' data.
    // Invariant: `students' contains all the student records read so far
    //            `maxlen' contains the length of the longest name
    //                     in `students'
    while (read(cin, record)) {
        // find the length of the longest name
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // alphabetize the student records
    sort(students.begin(), students.end(), compare);

    // write the names and grades
    for (const auto& s: students) {
        // write the name, padded on the right to `maxlen + 1' characters
        cout << std::left << setw(maxlen + 1) << s.name;

        // compute and write the grade
        try {
            double final_grade = grade(s);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec);
        }
        catch (const domain_error& e) {
            cout << e.what();
        }
        cout << endl;
    }
    return 0;
}
