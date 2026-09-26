// Keshav Yanamandra
// COMSC-210-5293, Fall 2026
// Lab 13

#include <iostream>
#include <fstream>
#include <cmath>

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


    int minIndex = 0;
    int maxIndex = 0;
    double total = 0;
    double mean;

    for (int j = 0; j < i; j++) {
        if (students[j].score < students[minIndex].score) {
            minIndex = j;
        }

        if (students[j].score > students[maxIndex].score) {
            maxIndex = j;
        }

        total = total + students[j].score;
    }

    mean = total/i;

    cout << endl;
    cout << "Statistics" << endl;
    cout << "----------" << endl;


    cout << "Minimum: " << students[minIndex].score << " for ID: " << students[minIndex].id << endl;

    cout << "Maximum: " << students[maxIndex].score << " for ID: " << students[maxIndex].id << endl;

    cout << "Mean: " << mean << endl;

    // make a copy so we can sort by score without changing students
    Student byScore[150];

    for (int j = 0; j < i; j++) {
        byScore[j] = students[j];
    }

    selectionSortByScore(byScore, i);

    // median
    double median;
    int medianId;

    median = (byScore[(i/2) - 1].score + byScore[(i/2)].score) / 2;
    medianId = byScore[(i/2)].id;

    cout << "Median: " << median << " for ID: " << medianId << endl;

    // standard deviation
    double sumSquares = 0;
    double stdDev;

    for (int j = 0; j < i; j++) {
        sumSquares = sumSquares + (students[j].score - mean) * (students[j].score - mean);
    }

    stdDev = sqrt(sumSquares / i);

    cout << "Standard Deviation: " << stdDev << endl;

    cout << endl;


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

    void selectionSortByScore(Student arr[], int count) {
        
        for (int i = 0; i < count - 1; i++) {
            int indexSmallest = i;

            for (int j = i + 1; j < count; j++) {
                if (arr[j].score < arr[indexSmallest].score) {
                    indexSmallest = j;
                }
            }

            Student temp = arr[i];

            arr[i] = arr[indexSmallest];
            arr[indexSmallest] = temp;
        }
    }
