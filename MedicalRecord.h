#pragma once
#include <string>
#include <stdexcept>

#include "Baby.h"

using namespace std;

class MedicalRecord {
public:
	// default constructor
	MedicalRecord() {
		// TO BE COMPLETED
	}

	// destructor
	~MedicalRecord() {
		// TO BE COMPLETED
	}

	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string filename) {
		ifstream myfile(filename);

		if (myfile.is_open()) {
			cout << "Successfully opened file " << filename << endl;
			string name;
			int weight;
			while (myfile >> name >> weight) {
				// cout << name << " " << weight << endl;
				Baby b(name, weight);
				addEntry(b);
			}
			myfile.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}

	// return the most frequently appearing name in the text file
	string mostPopularName() {
		return "COMPLETE ME"; // TO BE COMPLETED
	}

    // return the number of baby records loaded from the text file
    int numberOfBirths() {
        number_of_records = i;
        return number_of_records;
    }
    
	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() {
        int count = 0;
        for(int i = 0; i < number_of_records; i++)
        {
            if (weights[i] < 2500)
            {
                count++;
            }
        }
        
        return count;
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) {
        int count = 0;
        for(int i = 0; i < number_of_records; i++)
        {
            if (names[i] == s)
            {
                count++;
            }
        }
        
        return count;
	}

private:
    int i = 0; // used to add names
    int number_of_records;
    
    string names[1000];
    int weights[1000];
    
	// update the data structure with information contained in Baby object
	void addEntry(Baby b) {
        names[i] = b.getName();
        weights[i] = b.getWeight();
        i++;
	}
    
    
   
    
    
    
	// Add private member variables for your data structure along with any 
	// other variables required to implement the public member functions

};
