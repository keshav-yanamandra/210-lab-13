// Keshav Yanamandra
// COMSC-210-5293, Fall 2026
// Lab 13

#include <iostream>
#include <fstream>

using namespace std;

// stores one student id and exam score which is in the input file
struct Student {
    int id;
    double score;
};

void selectionSortById(Student[], int);
void selectionSortByScore(Student[], int);

int main() {
    Student students[150];

    ifstream fin;
    Student s;

    fin.open("210-lab-13-grades.txt");

    //for line number
    int i = 0;

    //read from file and put into struct and then into array 
    if (fin.good()) {
        while (fin >> s.id >> s.score) {

            cout << i << endl;
            cout << s.id << endl;
            cout << s.score << endl;


            students[i] = s;
            i++;
        }

        fin.close();
    }
    selectionSortById(students, i);

    //write output to file
    ofstream fout;
    fout.open("210-lab-13-grades-sorted.txt");

    for (int j = 0; j < i; j++) {
        fout << students[j].id << " " << students[j].score << endl;
    }

    fout.close();

    cout << "sorted result written to output file" << endl;

    return 0;
}

void selectionSortById(Student arr[], int count) {
    for (int i = 0; i < count - 1; i++) {
        int indexSmallest = i;

        for (int j = i + 1; j < count; j++) {
            
            if (arr[j].id < arr[indexSmallest].id) {
                indexSmallest = j;
            }
        }

        Student temp = arr[i];

        arr[i] = arr[indexSmallest];
        arr[indexSmallest] = temp;
    }
}