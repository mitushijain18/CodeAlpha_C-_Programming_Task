#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

/**
 * @file main.cpp
 * @brief CodeAlpha C++ Programming Internship - TASK 1: CGPA Calculator
 * @details Calculates GPA/CGPA based on course grades and credit hour weights.
 */

// Structure to hold individual course details for easy display
struct Course {
    std::string name;
    double gradePoints;
    int creditHours;
};

int main() {
    int totalCourses;
    double totalEarnedPoints = 0.0;
    int totalCreditHours = 0;

    std::cout << "=========================================\n";
    printf("         CODEALPHA CGPA CALCULATOR       \n"); // Using formatting tools for clear visuals
    std::cout << "=========================================\n";

    // 1. Input the total number of courses
    std::cout << "Enter the total number of courses taken: ";
    std::cin >> totalCourses;

    if (totalCourses <= 0) {
        std::cout << "Invalid number of courses. Exiting...\n";
        return 1;
    }

    std::vector<Course> courseList;

    // 2. Loop through each course to gather info
    for (int i = 0; i < totalCourses; ++i) {
        Course c;
        std::cout << "\n--- Course " << (i + 1) << " ---\n";
        std::cout << "Enter Course Name/Code (e.g., CS101): ";
        std::cin >> c.name;

        // Input grade scale points (e.g., A=4.0, B=3.0, etc.)
        std::cout << "Enter Grade Points earned (0.0 to 4.0 scale): ";
        std::cin >> c.gradePoints;

        // Input credit hour valuation
        std::cout << "Enter Credit Hours for this course: ";
        std::cin >> c.creditHours;

        // Accumulate running sums for totals
        totalEarnedPoints += (c.gradePoints * c.creditHours);
        totalCreditHours += c.creditHours;

        // Save structure record to list for printing later
        courseList.push_back(c);
    }

    // 3. Compute the final GPA metrics
    double finalCGPA = 0.0;
    if (totalCreditHours > 0) {
        finalCGPA = totalEarnedPoints / totalCreditHours;
    }

    // 4. Display the compiled final report card
    std::cout << "\n=========================================\n";
    std::cout << "             OFFICIAL REPORT CARD        \n";
    std::cout << "=========================================\n";
    std::cout << std::left << std::setw(15) << "Course" 
              << std::setw(15) << "Grade Points" 
              << "Credit Hours\n";
    std::cout << "-----------------------------------------\n";

    for (const auto& course : courseList) {
        std::cout << std::left << std::setw(15) << course.name 
                  << std::setw(15) << std::fixed << std::setprecision(2) << course.gradePoints 
                  << course.creditHours << "\n";
    }

    std::cout << "-----------------------------------------\n";
    std::cout << "Total Credits Attempted: " << totalCreditHours << "\n";
    std::cout << "Final Computed CGPA:     " << std::fixed << std::setprecision(2) << finalCGPA << "\n";
    std::cout << "=========================================\n";

    return 0;
}