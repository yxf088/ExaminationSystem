#include "paper.h"
#include"constant.h"
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;
void paper::make_paper() {
	 
	ifstream inputFile("C:/SE/Examination_System/result.txt");
	vector<string> lines;
	string line;
	// Read the content of the file into a vector
	while (getline(inputFile, line)) {
		lines.push_back(line);
	}
	inputFile.close();

	ofstream outputFile("C:/SE/Examination_System/temp_result.txt");
	if (!outputFile) {
		std::cout << "File Not Found or permission denied." << std::endl;
		return;
	}

	// Modify the flag in each line and write it to a temporary file
	for (const auto& l : lines) {
		string modifiedLine = l;
		if (!modifiedLine.empty()) {
			modifiedLine[0] = '0'; // Assuming the flag is the first character in each line
		}
		outputFile << modifiedLine << endl;
	}
	outputFile.close();

	// Replace the original file with the temporary file
	if (remove("C:/SE/Examination_System/result.txt") != 0) {
		std::cout << "Error deleting original result.txt file." << std::endl;
		return;
	}
	if (rename("C:/SE/Examination_System/temp_result.txt", "C:/SE/Examination_System/result.txt") != 0) {
		std::cout << "Error renaming temporary file to result.txt." << std::endl;
	}

	cout << "Make Paper \n";
	cout << "Select Subject : " << endl;
	for (int i = 0; i <= 4; i++) {
		cout << "Press " << i + 1 << " For " << subject[i] << endl;
	}
	cout << "==> ";
	int ch;
	cin >> ch;
	if (ch > 0 && ch < 7)
	{
		ofstream questionBank;
		ifstream paperFile(file_of_papers[ch - 1]);
		ifstream answerFile(Ans_of_paper[ch - 1]);
		questionBank.open(QuestionBank[ch - 1], ios::app);
		if (!questionBank) {
			cout << "Failed to open question bank file.";
		}
		if (paperFile && answerFile) {
			string line, answer;
			while (getline(paperFile, line) && getline(answerFile, answer)) {
				questionBank << "Question: " << line << "\n";
				questionBank << "Answer: " << answer << "\n\n";
			}
			questionBank.close();
		}

		if (ch > 0 && ch < 7) {
			cout << "Enter total number of Questions : ";
			cin >> total_qes;
			cout << "Enter Question : \n";
			ofstream paper; ofstream answerOfPaper;
			paper.open(file_of_papers[ch - 1]);
			answerOfPaper.open(Ans_of_paper[ch - 1]);
			if (!paper || !answerOfPaper) {
				cout << "Something went wrong Try again...";
			}
			for (int i = 0; i < total_qes; i++) {
				string Answer;
				cout << "Q" << i + 1 << " : ";
				cin.ignore();
				cin.getline(question, 256);
				cout << "Enter marks for this Question : ";
				cin >> each_marks;
				paper << question << " " << each_marks << endl;
				cout << "Answer of this Question: ";
				cin >> Answer;
				answerOfPaper << Answer << endl;
				total_marks = total_marks + each_marks;
			}
			cout << "Total marks : " << total_marks;
			paper.close();
			answerOfPaper.close();
		}
		else {
			cout << "class Not found";
		}
	}
}

void paper::practice()
{
	cout << "Self-Practice Old Questions \n";
	cout << "Select Subject to Practice : " << endl;
	for (int i = 0; i <= 4; i++) {
		cout << "Press " << i + 1 << " For " << subject[i] << endl;
	}
	cout << "==> ";
	int ch;
	cin >> ch;
	if (ch > 0 && ch < 7) {
		ifstream questionBank(QuestionBank[ch - 1]);
		if (!questionBank) {
			cout << "Failed to open question bank file.";
		}
		else {
			string line;
			bool questionFound = false;
			cout << "Questions for " << subject[ch - 1] << ":" << endl;

			while (std::getline(questionBank, line)) {
				if (line.find("Question:") != string::npos) {
					questionFound = true;
					cout << line << endl;
					string a;
					cout << "Your Answer:";
					cin >> a;
					// 输出答案部分
					std::getline(questionBank, line);
					cout << line << endl << endl;
				}
			}
			if (!questionFound) {
				cout << "No questions available for this subject." << endl;
			}
			questionBank.close();
		}
	}
	else {
		cout << "Invalid selection";
	}
	cout << "Press Any key to Quit.... ";
	getchar();
}

