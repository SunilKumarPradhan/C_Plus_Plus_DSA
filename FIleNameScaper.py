import os

def list_files_without_extension(folder_path, output_file):
    # Get a list of files in the specified folder
    files = os.listdir(folder_path)
    
    # Ensure the output directory exists
    os.makedirs(os.path.dirname(output_file), exist_ok=True)
    
    # Open the output file in write mode
    with open(output_file, 'w', encoding='utf-8') as f:
        for file in files:
            # Skip directories, only process files
            if os.path.isfile(os.path.join(folder_path, file)):
                # Get the file name without the extension
                file_name_without_extension = os.path.splitext(file)[0]
                # Write the file name to the output file
                f.write(file_name_without_extension + '\n')
    
    print(f"File names without extensions have been written to {output_file}")

# Specify the folder path and output file name
k = r'E:\[GeeksForGeeks] Data Structures and Algorithms (Self-Paced Course)\04. Recursion [DONE]'  # Replace with your folder path
y = r'C:\Users\sunil\Desktop\GFG\04. Recursion\file_names.txt'  # Replace with your output file path

# Call the function
list_files_without_extension(k, y)
