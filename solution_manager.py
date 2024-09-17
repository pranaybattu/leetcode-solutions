#!/usr/bin/env python3
import os
import argparse
import json
from os.path import join, splitext, exists

# Define the repository path and directories
repo_path = os.getcwd()
levels = ["Easy", "Medium", "Hard"]
tree_path = "https://github.com/pranaybattu/leetcode-solutions/tree/master/"
json_file = join(repo_path, "problems.json")  # JSON file to store the tags and metadata

# Function to load existing problems from the JSON file
def load_problems():
    if exists(json_file):
        with open(json_file, 'r') as f:
            return json.load(f)
    return {}

# Function to save problems to the JSON file
def save_problems(problems_dict):
    with open(json_file, 'w') as f:
        json.dump(problems_dict, f, indent=4)

# Function to read all files from a given level directory and update the problem list
def scan_directories(problems_dict):
    for level in levels:
        level_dir = join(repo_path, level)
        if exists(level_dir):
            for file_name in os.listdir(level_dir):
                if file_name.endswith(".cpp"):  # Only consider C++ files
                    problems_dict[file_name] = {'level': level, 'tags': problems_dict.get(file_name, {}).get('tags', [])}
    return problems_dict

# Function to generate README for a given difficulty level and tags
def generate_readme(problems_dict):
    readme_path = join(repo_path, "README.md")
    
    # Remove the existing README if it exists
    if exists(readme_path):
        os.remove(readme_path)
    
    # Create and write to README.md
    with open(readme_path, "w+") as f:
        f.write("# LeetCode Solutions\n\n")
        
        # Separate Table of Contents
        f.write("## Table of Contents\n\n")
        
        # By Difficulty
        f.write("### By Difficulty\n")
        for level in levels:
            f.write(f"- [{level.lower()}](#{level.lower()}-level)\n")

        # By Tags
        f.write("\n### By Tags\n")
        tags = sorted(set(tag for tags in (problem_info['tags'] for problem_info in problems_dict.values()) for tag in tags))  # Get all unique tags
        for tag in tags:
            f.write(f"- [{tag}](#{tag.replace(' ', '-').lower()})\n")

        # Problems by difficulty
        for level in levels:
            f.write(f"\n## {level.lower()} Level\n")
            f.write("S.no | Problem | Tags \n")
            f.write("--- | --- | --- \n")
            count = 1
            for file_name, problem_info in problems_dict.items():
                if problem_info['level'] == level:
                    only_name, _ = splitext(file_name)  # Get file name without extension
                    updated_file_name = file_name.replace(' ', '%20')  # URL encode spaces
                    tag_list = ', '.join(problem_info['tags'])
                    f.write(f"{count} | [{only_name}]({tree_path + level + '/' + updated_file_name}) | {tag_list}\n")
                    count += 1

        # Problems by tags
        for tag in tags:
            f.write(f"\n## {tag}\n")
            f.write("S.no | Problem | Difficulty \n")
            f.write("--- | --- | --- \n")
            count = 1
            for file_name, problem_info in problems_dict.items():
                if tag in problem_info['tags']:
                    level = problem_info['level']
                    only_name, _ = splitext(file_name)  # Get file name without extension
                    updated_file_name = file_name.replace(' ', '%20')
                    f.write(f"{count} | [{only_name}]({tree_path + level + '/' + updated_file_name}) | {level}\n")
                    count += 1

# Function to add a new solution
def add_solution(level, file_name, tags):
    problems_dict = load_problems()  # Load existing problems

    if level not in levels:
        print("Invalid difficulty level!")
        return
    file_path = join(repo_path, level, file_name)
    if not exists(file_path):
        print(f"File {file_name} not found in {level}!")
        return

    # Add problem to problems_dict with its level and tags
    problems_dict[file_name] = {'level': level, 'tags': tags}

    # Save the updated problems to the JSON file
    save_problems(problems_dict)

    # Scan the directories and update the problem list
    problems_dict = scan_directories(problems_dict)

    # Generate the README
    generate_readme(problems_dict)

# Setup CLI argument parsing
def main():
    parser = argparse.ArgumentParser(description='Add a LeetCode solution to the repository.')
    
    # Define the CLI arguments
    parser.add_argument('level', choices=levels, help='The difficulty level of the problem (Easy, Medium, Hard)')
    parser.add_argument('file_name', help='The file name of the solution (e.g., 2028. Find Missing Observations.cpp)')
    parser.add_argument('tags', nargs='+', help='Tags associated with the problem (e.g., Array, Hash Table)')
    
    # Parse the arguments
    args = parser.parse_args()
    
    # Call the add_solution function with CLI arguments
    add_solution(args.level, args.file_name, args.tags)

if __name__ == '__main__':
    main()