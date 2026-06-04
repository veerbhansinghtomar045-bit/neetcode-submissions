class Solution {
public:
    // Encodes a list of strings into one single string
    string encode(vector<string>& strs) {
        string encoded = "";

        // Go through every string in the list
        for (string& s : strs) {
            // First add the length of the string
            encoded += to_string(s.size());

            // Add a separator between length and actual string
            encoded += '#';

            // Add the actual string
            encoded += s;
        }

        // Return the final encoded string
        return encoded;
    }

    // Decodes the encoded string back into a list of strings
    vector<string> decode(string s) {
        vector<string> result;

        // i points to the start of each encoded part
        int i = 0;

        // Continue until we finish reading the whole encoded string
        while (i < s.size()) {
            int j = i;

            // Move j until we find '#'
            // Everything before '#' is the length of the next string
            while (s[j] != '#') {
                j++;
            }

            // Convert the length from string to integer
            int len = stoi(s.substr(i, j - i));

            // Move j to the first character of the actual string
            j++;

            // Extract exactly len characters
            string original = s.substr(j, len);

            // Add the decoded string to result
            result.push_back(original);

            // Move i to the start of the next encoded string
            i = j + len;
        }

        // Return all decoded strings
        return result;
    }
};
