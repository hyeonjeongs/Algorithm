#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Function to calculate all possible sums for a combination of dices
map<int, int> calculateSumProbabilities(const vector<vector<int>>& dices) {
    map<int, int> sumProbabilities; // Maps sum to its count
    int totalOutcomes = 1;
    for (const auto& dice : dices) {
        totalOutcomes *= dice.size();
    }

    // Initialize sumProbabilities with 0
    for (int i = dices.size(); i <= 6 * dices.size(); ++i) {
        sumProbabilities[i] = 0;
    }

    // Recursive function to calculate all possible sums
    function<void(int, int)> calculateSums = [&](int index, int currentSum) {
        if (index == dices.size()) {
            sumProbabilities[currentSum]++;
            return;
        }
        for (int number : dices[index]) {
            calculateSums(index + 1, currentSum + number);
        }
    };

    calculateSums(0, 0);
    return sumProbabilities;
}

// Function to calculate win probability for a given combination of dices
double calculateWinProbability(const map<int, int>& probA, const map<int, int>& probB) {
    int win = 0, total = 0;
    for (const auto& [sumA, countA] : probA) {
        for (const auto& [sumB, countB] : probB) {
            if (sumA > sumB) {
                win += countA * countB;
            }
            total += countA * countB;
        }
    }
    return static_cast<double>(win) / total;
}

int main() {
    // Example dices
    vector<vector<int>> dices = {
            {1, 2, 3, 4, 5, 6},
            {3, 3, 3, 3, 4, 4},
            {1, 3, 3, 4, 4, 4},
            {1, 1, 4, 4, 5, 5},
            {2, 2, 3, 3, 4, 4},
            {1, 2, 2, 3, 3, 4},
            {1, 1, 1, 2, 2, 3},
            {2, 3, 4, 4, 5, 6}
    };

    // Variables to store the best combination and its probability
    double bestProbability = 0.0;
    vector<int> bestCombo;

    // Check all combinations of choosing 4 dices out of 8
    vector<int> indices(dices.size());
    iota(indices.begin(), indices.end(), 0); // Filling indices with 0, 1, 2, ..., 7

    do {
        vector<vector<int>> comboA, comboB;
        for (int i = 0; i < indices.size() / 2; ++i) {
            comboA.push_back(dices[indices[i]]);
            comboB.push_back(dices[indices[indices.size() / 2 + i]]);
        }

        auto probA = calculateSumProbabilities(comboA);
        auto probB = calculateSumProbabilities(comboB);
        double winProbability = calculateWinProbability(probA, probB);

        if (winProbability > bestProbability) {
            bestProbability = winProbability;
            bestCombo = vector<int>(indices.begin(), indices.begin() + indices.size() / 2);
        }
    } while (next_permutation(indices.begin(), indices.end()));

    // Print the best combination
    cout << "Best combination of dices for A: ";
    for (int index : bestCombo) {
        cout << index + 1 << " ";
    }
    cout << endl << "Win Probability: " << bestProbability << endl;

    return 0;
}
