#include <iostream>
#include <vector>
using namespace std;

// This function constructs a memory grid to track matching sequences
string uncover_H_idden_T_reasure(const string &textA, const string &textB, vector<vector<int>> &memoryGrid) {
    int rangeA = textA.size();
    int rangeB = textB.size();
    int maxDepth = 0, position = 0;

    // March through the letters, noting when paths align
    for (int cursorA = 1; cursorA <= rangeA; cursorA++) {
        for (int cursorB = 1; cursorB <= rangeB; cursorB++) {
            if (textA[cursorA - 1] == textB[cursorB - 1]) {
                memoryGrid[cursorA][cursorB] = memoryGrid[cursorA - 1][cursorB - 1] + 1;
                if (memoryGrid[cursorA][cursorB] > maxDepth) {
                    maxDepth = memoryGrid[cursorA][cursorB];
                    position = cursorA;
                }
            }
        }
    }

    // Extract the deeply buried sequence
    return textA.substr(position - maxDepth, maxDepth);
}

// Function to print the lookup table
void disp_la_yMe_mo_ryGr_id(const vector<vector<int>> &memoryGrid, const string &textA, const string &textB) {
    cout << "  ";
    for (char ch : textB) cout << " " << ch;
    cout << endl;

    for (size_t i = 0; i < memoryGrid.size(); i++) {
        if (i > 0) cout << textA[i - 1] << " ";
        else cout << "  ";

        for (size_t j = 0; j < memoryGrid[i].size(); j++) {
            cout << memoryGrid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    string cipherOne, cipherTwo;
    cout << "Enter first message: ";
    cin >> cipherOne;
    cout << "Enter second message: ";
    cin >> cipherTwo;

    vector<vector<int>> memoryGrid(cipherOne.size() + 1, vector<int>(cipherTwo.size() + 1, 0));
    string hidden_C_ode = uncover_H_idden_T_reasure(cipherOne, cipherTwo, memoryGrid);

    cout << "\nMemory Grid:\n";
    disp_la_yMe_mo_ryGr_id(memoryGrid, cipherOne, cipherTwo);

    if (!hidden_C_ode.empty()) {
        cout << "\nThe longest buried sequence is: " << hidden_C_ode << endl;
    } else {
        cout << "\nNo common trail found in the archives." << endl;
    }

    return 0;
}
