#include <string>
#include  <vector>
using namespace std; // Adding the std namespace

// Function to compress a vector of characters in-place
int compress(vector<char>& chars) {
    int ans = 0; // Variable to keep track of the compressed vector length

    // Iterate through input vector using i pointer
    for (int i = 0; i < chars.size();) {
        const char letter = chars[i]; // Current character being compressed
        int count = 0; // Count of consecutive occurrences of the letter

        // Count consecutive occurrences of the letter in the input vector
        while (i < chars.size() && chars[i] == letter) {
            ++count;
            ++i;
        }

        // Write the letter to the compressed vector
        chars[ans++] = letter;

        // If count is greater than 1, write count as a string to the compressed vector
        if (count > 1) {
            // Convert count to a string and iterate over each character in the string
            for (const char c : to_string(count)) {
                chars[ans++] = c;
            }
        }
    }

    // Return the length of the compressed vector
    return ans;
}

int main() {
    // Example vector
    vector<char> inputVector = {'a', 'b', 'b', 'c', 'c', 'c'};

    // Call the compress function
    int compressedLength = compress(inputVector);

    // Display the compressed vector and its length
    cout << "Compressed Vector: ";
    for (int i = 0; i < compressedLength; ++i) {
        cout << inputVector[i] << " ";
    }
    cout << "\nCompressed Vector Length: " << compressedLength << endl;

    return 0;
}