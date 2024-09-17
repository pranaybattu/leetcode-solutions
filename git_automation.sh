#!/bin/sh

# Add all changes to git staging area
git add .

# Initialize variables
commit_message=""

# Get modified and newly added files
modified_files=$(git status --porcelain | grep -E '^( M|A)' | awk '{print $2}')

# Check if there are modified files
if [ -n "$modified_files" ]; then
    for file in $modified_files; do
        # Check if the file exists in the problems.json and is a .cpp file
        problem_file=$(echo "$file" | grep -oE '[0-9]+\..*\.cpp')

        if [ -n "$problem_file" ]; then
            # Extract the folder name (Easy/Medium/Hard) to capture the difficulty level
            folder_name=$(echo "$file" | cut -d'/' -f1)
            # Add the problem filename and folder name (difficulty level) to the commit message
            commit_message+="Added ${problem_file} in ${folder_name} folder, "
        fi
    done

    # Remove the trailing comma and space
    commit_message=$(echo "$commit_message" | sed 's/, $//')

    # If no files matched the criteria, use a default message
    if [ -z "$commit_message" ]; then
        commit_message="Updated files"
    fi

    # Commit with the appropriate message
    git commit -m "$commit_message"

else
    echo "No changes to commit"
fi

# Push the changes
git push