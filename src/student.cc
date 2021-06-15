#include "student.hpp"

// class Student {
//     private:
//         std::string name_;	                      //Name of the student
//         std::string uin_;	                      //UIN of the student
//         std::string net_id_;	                  //NetID of the student
//         std::string major_;	                      //Major of the student
//         bool graduated_;	                      //Whether the stuent has graduated or not
//         std::vector<Course> courses_;             //Courses the student has taken
//         static const int min_credits_grad_ = 120; // Minimum credits student needs to graduate. Value is 120.
//     public:
//         Student(std::string name, std::string uin, std::string net_id);
//         Student(std::string name, std::string uin, std::string net_id, std::string major, std::vector<Course> courses, bool graduated);
//         std::string GetName();
//         std::string GetUIN();
//         std::string GetNetId();
//         std::string GetMajor();
//         bool HasGraduated();
//         const std::vector<Course>& GetCourses();
//         void SetName(std::string name);
//         void SetMajor(std::string major);
//         bool AddCourse(Course c);	
//         void Graduate();
// };

Student::Student(std::string name, std::string uin, std::string net_id) {
    name_ = name;
    uin_ = uin;
    net_id_ = net_id;
    major_ = "Undeclared";
    graduated_ = false;
}


Student::Student(std::string name, std::string uin, std::string net_id, std::string major, std::vector<Course> courses, bool graduated) {
    name_ = name;
    uin_ = uin;
    net_id_ = net_id;
    major_ = major;
    graduated_ = graduated;
    for (int i = 0; i < courses.size(); i++) courses_.push_back(courses[i]);
}

std::string Student::GetName() { return name_; }

std::string Student::GetUIN() { return uin_; }

std::string Student::GetNetId() { return net_id_; }

std::string Student::GetMajor() { return major_; }

bool Student::HasGraduated() { return graduated_; }

const std::vector<Course>& Student::GetCourses() { return courses_; }

void Student::SetName(std::string name) {
    name_ = name;
}
void Student::SetMajor(std::string major) {
    major_ = major;
}
bool Student::AddCourse(Course c) {
    int taken = 0;
    for (int i = 0; i < courses_.size(); i++) if (courses_[i].name.compare(c.name) && c.credits == courses_[i].credits) taken = 1;
    if (taken == 0) {
        courses_.push_back(c);
        return true;
    }
    return false;
}
void Student::Graduate() {
    int sum = 0;
    for (int i = 0; i < courses_.size(); i++) sum += courses_[i].credits;
    if (sum >= Student::min_credits_grad_) graduated_ = true;
    else graduated_ = false;
}

std::ostream& operator<<(std::ostream& os, const Student& s) {
    (void) s;
}