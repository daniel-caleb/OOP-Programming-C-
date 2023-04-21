#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    double sum = 0, mean, std_dev = 0, variance = 0, min_height, max_height;

    cout << "Enter the number of trees: ";
    cin >> n;

    double height[n];

    // Prompt user to enter height for each tree and calculate sum of heights
    for (int i = 0; i < n; i++) {
        cout << "Enter the height of tree " << i+1 << ": ";
        cin >> height[i];
        sum += height[i];
    }

    // Calculate mean
    mean = sum / n;

    // Calculate variance and standard deviation
    for (int i = 0; i < n; i++) {
        variance += pow((height[i] - mean), 2);
    }
    variance /= n;
    std_dev = sqrt(variance);

    // Find minimum and maximum height
    min_height = height[0];
    max_height = height[0];
    for (int i = 1; i < n; i++) {
        if (height[i] < min_height) {
            min_height = height[i];
        }
        if (height[i] > max_height) {
            max_height = height[i];
        }
    }

    // Display the results
    cout << "Mean height: " << mean << endl;
    cout << "Shortest tree height: " << min_height << endl;
    cout << "Tallest tree height: " << max_height << endl;
    cout << "Standard deviation: " << std_dev << endl;
    cout << "Variance: " << variance << endl;

    return 0;
}

