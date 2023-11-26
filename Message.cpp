#include"Message.h"
#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include <vector>
#include <iostream>
using namespace std;

void Message::OutputTrMessage()
{
    ifstream file;
    file.open("C:/SE/Examination_System/teacher.txt");
    if (!file) {
        std::cout << "Something went wrong Try again...";
    }
    std::string line;
    string name, email, subject, employeeID;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        if (iss >> name >> email >> subject >> employeeID) {
            std::cout << "Name: " << name << "\t";
            std::cout << "Subject: " << subject << "\t";
            std::cout << "ID: " << employeeID << std::endl;
        }
        else {
            std::cerr << "Invalid format in file." << std::endl;
        }
    }
    file.close();
}

void Message::Ques_toTeacher(int& studentID) {
    int index=0;  // 这个index是从文件中获取的，用于标识问题编号

    // 读取文件中现有的最后一个index值，用于累加在后面
   ifstream askT("C:/SE/Examination_System/Message/askTeacher.txt");
   if (!askT) {
       cout << "Error opening askTeacher file." << endl;
       return;
   }

   string line;
   while (getline(askT, line)) {
       //cout << "Line read: " << line << endl; // Output the line being read for debugging
       istringstream iss(line);
       int trcode, tempIndex,flag;
       string t;
       if (iss >> tempIndex>>flag >> t >> trcode) {
           index = tempIndex;
           //cout << index << " "; // Update index value for the last index in the file
       }
   }
   askT.close();


    ofstream askTeacherFile("C:/SE/Examination_System/Message/askTeacher.txt", ios::app);
    if (!askTeacherFile) {
        cout << "Error opening askTeacher file for writing." << endl;
        return;
    }
    OutputTrMessage();
    int teacherCode;
    std::cout << "Enter Teacher's ID to get his/her reply: ";
    std::cin >> teacherCode;
    string question; 
    cout << "Enter your question: ";
    cin >> question;
    index++; 
    int flag = 1;
    askTeacherFile << index << " " << flag << " " << question << " " << teacherCode << endl;
    askTeacherFile.close();
}

void Message::ansStudent(int& teacherCode) {
    std::ifstream askTeacherFile("C:/SE/Examination_System/Message/askTeacher.txt");
    if (!askTeacherFile) {
        std::cout << "Error opening askTeacher file." << std::endl;
        return;
    }

    std::ofstream tempFile("C:/SE/Examination_System/Message/tempFile.txt");
    if (!tempFile) {
        std::cout << "Error creating temporary file." << std::endl;
        return;
    }

    bool questionFound = false;
    std::string line;
    while (std::getline(askTeacherFile, line)) {
        std::istringstream iss(line);
        int index, tempTeacherCode, flag;
        std::string questionText;
        if (iss >> index >> flag >> questionText >> tempTeacherCode) {
            if (flag==1 && tempTeacherCode == teacherCode) {
                questionFound = true;
                std::cout << "Q: " << questionText << std::endl;
                std::string answer;
                std::cout << "Reply Here: ";
                std::cin.ignore(); // Clear buffer
                std::cin >> answer;

                std::ofstream answerFile("C:/SE/Examination_System/Message/ansStudent.txt", std::ios::app);
                if (!answerFile) {
                    std::cout << "Error opening teacher_answers file for writing." << std::endl;
                    return;
                }
                // Writing the answer to the file with the corresponding question index
                answerFile << index << " " << answer << std::endl;
                answerFile.close();

                flag = 0; // Update flag to indicate the question has been answered
            }
        }
        tempFile << index << " " << flag << " " << questionText << " " << tempTeacherCode << std::endl;
    }
    askTeacherFile.close();
    tempFile.close();

    if (!questionFound) {
        std::cout << "No question found for your teacher." << std::endl;
    }

    // Replace the original file with the temporary file
    if (std::remove("C:/SE/Examination_System/Message/askTeacher.txt") != 0) {
        std::cout << "Error removing original file." << std::endl;
    }
    if (std::rename("C:/SE/Examination_System/Message/tempFile.txt", "C:/SE/Examination_System/Message/askTeacher.txt") != 0) {
        std::cout << "Error renaming file." << std::endl;
    }
    return;
}

void Message:: viewTeacherReply() {
    std::ifstream askTeacherFile("C:/SE/Examination_System/Message/askTeacher.txt");
    if (!askTeacherFile) {
        std::cout << "Error opening askTeacher file." << std::endl;
        return;
    }
    OutputTrMessage();
    int teacherCode;
    std::cout << "Enter Teacher's ID to get his/her reply: ";
    std::cin >> teacherCode;

    bool found = false;
    std::string s;
    while (std::getline(askTeacherFile, s)) {
        std::istringstream iss(s);
        int index, tempTeacherCode,flag;
        std::string questionText;
        if (iss >> index>> flag >> questionText >> tempTeacherCode) {
            if (flag==0 && tempTeacherCode == teacherCode) {
                std::cout << "Asked: " << questionText << std::endl;

                std::ifstream answerFile("C:/SE/Examination_System/Message/ansStudent.txt");
                if (!answerFile) {
                    std::cout << "Error opening ansStudent file." << std::endl;
                    return;
                }
                std::string answer;
                std::string answerLine;
                int Index;
                while (std::getline(answerFile, answerLine)) {
                    std::istringstream issAnswer(answerLine);
                    issAnswer >> Index >> answer;
                    if (Index == index) {
                         std::cout << "Reply: " << answer << std::endl;
                         found = true;
                         break;
                    }
                }
                answerFile.close();
            }
        }
    }
    askTeacherFile.close();

    if (!found) {
        std::cout << "No answers found for the entered Teacher's code." << std::endl;
    }
}
