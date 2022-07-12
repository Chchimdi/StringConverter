/******************************************************
** Function: convert_to_tilde
** Description:
** This function accepts a pointer to a string and creates a copy.
** The copy will be identical to the original string (which was passed by
** pointer) except for one major change... in the copied string, all
** non-space characters will be replaced by a tilde (~)
** Parameters
** str_in --> A pointer to the C++ string that will be used as the basis for
** the copy. This string will not be modified.
** Pre-Conditions: None
** Post-Conditions:
** Returns a newly created string that is exactly the same length as the string
** parameter that was passed via pointer. However, each non-space character
** in this new string will be replaced by a tilde.
******************************************************/

#include <iostream>
#include <string>

using namespace std;

void get_string(string*);

string convert_to_tilde(string*);

int search_and_replace(char, string, string&);

// Global variable
// string newtildeString;


int main() {
    // Get string from user
    string userInput;
    get_string(&userInput);

    // convert_to_tilde(&userInput);

    string tildeReplace = convert_to_tilde(&userInput);

    cout << "The tilde-version of your string is: \n" << tildeReplace << endl;

    // Search and replace needs a char to query
    char inputCharacter;
    cout << "Please tell me the char that you would like to locate and replace:\n";
    cin >> inputCharacter;

    int replaceResult = search_and_replace(inputCharacter, userInput, tildeReplace);
    cout << "The new version of your string is: \n" << tildeReplace << endl;
    printf("I located %d '%c' characters!\n", replaceResult, inputCharacter);

    return 0;
}

void get_string(string* inputString) {
    cout << "Please enter a string: \n";
    getline(cin, *inputString);
}

string convert_to_tilde(string* tildeString) {
    string newtildeString = *tildeString;    // Made a copy
    // newtildeString = *tildeString;    // copy to global variable (gets saved there)

    for (int i = 0; i < newtildeString.size(); i++)
    {
        if (newtildeString[i] != ' ')
        {
            newtildeString[i] = '~';
        }
    }

    return newtildeString;
}

int search_and_replace(char searchCharacter, string searchInput, string& searchReplace) {
    int countCharacter = 0;
    for (int i = 0; i < searchInput.size(); i++)
    {
        if (searchInput[i] == searchCharacter)
        {
            countCharacter++;
            searchReplace[i] = searchCharacter;
        }
    }
    return countCharacter;
}