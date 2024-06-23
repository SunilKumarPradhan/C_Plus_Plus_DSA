import os

cpp_template = """#include <bits/stdc++.h>
using namespace std;

int main() {
    // Your code here
    return 0;
}
"""

# Read the filenames from the text file
with open('QuestionList.txt', 'r') as file:
    filenames = file.readlines()

# Create .cpp files with the template
for name in filenames:
    filename = name.strip() + '.cpp'  # Remove any leading/trailing whitespace and add .cpp extension
    with open(filename, 'w') as cpp_file:
        cpp_file.write(cpp_template)
    
    print(f"Created file: {filename}")
