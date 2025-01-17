#pragma once
#include <string>
#include <stdexcept>

#include "Baby.h"

using namespace std;

class MedicalRecord {
public:
	// default constructor
    MedicalRecord() {};

	// destructor
	~MedicalRecord() {
        delete[] names;
        delete[] weights;
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
        string name;
        
        for(int i = 0; i < number_of_records; i++)
        {
            for( int i = 0; i < (number_of_records - 1); i++)
            {
                if(names[i] > names[i+1])
                {
                    string temp;
                    temp = names[i];
                    names[i] = names[i+1];
                    names[i+1] = temp;
                    
                }
                
            }
        }
        
        int top = 0;
        int next = 0;
        name = names[0];
        
        for (int i = 0; i < number_of_records; i++)
        {
            if (names[i] == name)
            {
                top++; // 3
            }
            else if (names[i] != name)
            {
                next++; // 0
                if (names[i + 1] != names[i])
                {
                    next = 0;
                }
                if (next > top)
                {
                    top = next;
                    name = names[i];
                    next = 0;
                }
            }
        }
        
		return name;
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
    
    string *names = new string[1000];
    int *weights = new int[1000];
    
	// update the data structure with information contained in Baby object
	void addEntry(Baby b) {
        names[i] = b.getName();
        weights[i] = b.getWeight();
        i++;
	}
    
    
	// Add private member variables for your data structure along with any 
	// other variables required to implement the public member functions

};
