import os

cpp_template = """#include <bits/stdc++.h>
using namespace std;

int main() {
    
    return 0;
}
"""

# Read the filenames from the text file
with open(r'C:\Users\sunil\Desktop\GFG\02. Mathematics\QuestionList.txt', 'r') as file:
    filenames = file.readlines()

# Create .cpp files with the template
for name in filenames:
    filename = name.strip() + '.cpp'  # Remove any leading/trailing whitespace and add .cpp extension
    filepath = os.path.join(r'C:\Users\sunil\Desktop\GFG\02. Mathematics', filename)
    with open(filepath, 'w') as cpp_file:
        cpp_file.write(cpp_template)
    
    print(f"Created file: {filepath}")
