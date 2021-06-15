#include <string>
#include <course.hpp>
#include <vector>
#include <iostream>

#pragma once

class Student {
    private:
        std::string name_;	                      //Name of the student
        std::string uin_;	                      //UIN of the student
        std::string net_id_;	                  //NetID of the student
        std::string major_;	                      //Major of the student
        bool graduated_;	                      //Whether the stuent has graduated or not
        std::vector<Course> courses_;             //Courses the student has taken
        static const int min_credits_grad_ = 120; // Minimum credits student needs to graduate. Value is 120.
    public:
        Student(std::string name, std::string uin, std::string net_id);
        Student(std::string name, std::string uin, std::string net_id, std::string major, std::vector<Course> courses, bool graduated);
        std::string GetName();
        std::string GetUIN();
        std::string GetNetId();
        std::string GetMajor();
        bool HasGraduated();
        const std::vector<Course>& GetCourses();
        void SetName(std::string name);
        void SetMajor(std::string major);
        bool AddCourse(Course c);	
        void Graduate();
};

std::ostream& operator<<(std::ostream& os, const Student& s);

