#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "sorting.h"

using namespace std;

const int maxSize = 100;

string candidateList[5] = {
    "Bo Dalton Capistrano",
    "Cornelius Raymon Agustin",
    "Deja Jayla Bañaga",
    "Laila Brielle Yabut",
    "Franklin Relano Castro"
};

void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        cout << arr[i] << " ";
        if ((i + 1) % 20 == 0) {
            cout << "\n";
        }
    }
    cout << endl;
}

int main() {
    int unsortedArr[maxSize];

    srand(time(0));

    // generate 100 random votes (1 to 5)
    for (int i = 0; i < maxSize; i++) {
        unsortedArr[i] = (rand() % 5) + 1;
    }

    cout << "Unsorted Votes:\n";
    displayArr(unsortedArr);

    // sort votes using insertion sort
    insertionSort(unsortedArr, maxSize);

    cout << "\nSorted Votes:\n";
    displayArr(unsortedArr);

    // tallying sorted votes
    int voteCounts[5] = {0};
    for (int i = 0; i < maxSize; i++) {
        int vote = unsortedArr[i];
        voteCounts[vote - 1]++;
    }

    cout << "\n--- Election Tally Results ---\n";
    int highestVote = -1;
    int winnerIdx = 0;

    for (int i = 0; i < 5; i++) {
        cout << "Candidate " << (i + 1) << " (" << candidateList[i] << "): " 
             << voteCounts[i] << " votes\n";

        if (voteCounts[i] > highestVote) {
            highestVote = voteCounts[i];
            winnerIdx = i;
        }
    }

    cout << "\nWinning Candidate: " << candidateList[winnerIdx] 
         << " with " << highestVote << " total votes.\n";

    return 0;
}