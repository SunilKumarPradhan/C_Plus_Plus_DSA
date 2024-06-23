import os

# Read the folder names from the text file
with open('foldernames.txt', 'r') as file:
    folder_names = file.readlines()

# Create folders and add a text file with the folder's name inside each one
for name in folder_names:
    folder_name = name.strip()  # Remove any leading/trailing whitespace
    
    # Create the folder
    os.makedirs(folder_name, exist_ok=True)
    
    # Create a text file inside the folder with the folder's name
    with open(os.path.join(folder_name, 'QuestionList.txt'), 'w') as info_file:
        info_file.write(f"This folder is named: {folder_name}")
    
    print(f"Created folder and file: {folder_name}")
