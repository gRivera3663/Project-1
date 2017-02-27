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
    int numberOfBirths(string filename) {
        ifstream myFile(filename);
        number_of_records = 0;
        string name;
        int weight;
        while ( myFile >> name >> weight )
        {
            number_of_records++;
        }
        
        myFile.close();
        
        return number_of_records;
    }
    
	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight(string filename) {
        ifstream myFile(filename);
        int count;
        string name;
        int weight;
        
        while (myFile >> name >> weight)
        {
            if (weight < 2500)
            {
                count++;
            }
        }
        
        myFile.close();
        
        return count;
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s, string filename) {
        ifstream myFile(filename);
        int count;
        string name;
        int weight;
        
        while (myFile >> name >> weight)
        {
            if (name == s)
            {
                count++;
            }
        }
        
        return count;
	}

private:
    int number_of_records;
    
    string names[1000];
    int weights[1000];
    
	// update the data structure with information contained in Baby object
	void addEntry(Baby b) {
        
        names = b.getName();
        weights = b.getWeight();
	}
    
    
   
    
    
    
	// Add private member variables for your data structure along with any 
	// other variables required to implement the public member functions

};
