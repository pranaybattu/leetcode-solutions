#!/usr/bin/env python3
import os
import argparse
from os.path import join

# Define the repository path
repo_path = os.getcwd()
levels = ["Easy", "Medium", "Hard"]
tree_path = "https://github.com/your-username/LeetCode-Solutions/tree/master/"
tags_dict = {}

# Function to generate README for a given difficulty level
def generate_readme():
    readme_path = join(repo_path, "README.md")
    
    # Remove the existing README if it exists
    if os.path.exists(readme_path):
        os.remove(readme_path)
    
    # Create and write to README.md
    with open(readme_path, "w+") as f:
        f.write("# LeetCode Solutions\n\n")
        f.write("## Table of Contents\n")
        
        # Difficulty index
        f.write("### By Difficulty\n")
        for level in levels:
            f.write(f"- [{level}](#{level.lower()}-level)\n")
        
        # Tag index
        f.write("\n### By Tags\n")
        for tag in sorted(tags_dict.keys()):
            f.write(f"- [{tag}](#{tag.replace(' ', '-').lower()})\n")

        # Problems by difficulty
        for level in levels:
            f.write(f"\n## {level} Level\n")
            f.write("S.no | Problem | Tags \n")
            f.write("--- | --- | --- \n")
            count = 1
            for file_name, tags in tags_dict.items():
                if level in file_name:
                    only_name = file_name[:file_name.find('.')]
                    updated_file_name = file_name.replace(' ', '%20')
                    tag_list = ', '.join(tags)
                    f.write(f"{count} | [{only_name}]({tree_path + level + '/' + updated_file_name}) | {tag_list}\n")
                    count += 1

        # Problems by tags
        for tag in sorted(tags_dict.keys()):
            f.write(f"\n## {tag}\n")
            f.write("S.no | Problem | Difficulty \n")
            f.write("--- | --- | --- \n")
            count = 1
            for file_name, problem_tags in tags_dict.items():
                if tag in problem_tags:
                    level = [lvl for lvl in levels if lvl in file_name][0]  # Get difficulty from file name
                    only_name = file_name[:file_name.find('.')]
                    updated_file_name = file_name.replace(' ', '%20')
                    f.write(f"{count} | [{only_name}]({tree_path + level + '/' + updated_file_name}) | {level}\n")
                    count += 1

# Function to add a new solution
def add_solution(level, file_name, tags):
    if level not in levels:
        print("Invalid difficulty level!")
        return
    file_path = join(repo_path, level, file_name)
    if not os.path.exists(file_path):
        print(f"File {file_name} not found in {level}!")
        return

    # Add problem to tags_dict
    tags_dict[file_name] = tags

    # Generate the README
    generate_readme()

# Setup CLI argument parsing
def main():
    parser = argparse.ArgumentParser(description='Add a LeetCode solution to the repository.')
    
    # Define the CLI arguments
    parser.add_argument('level', choices=levels, help='The difficulty level of the problem (Easy, Medium, Hard)')
    parser.add_argument('file_name', help='The file name of the solution (e.g., TwoSum.py)')
    parser.add_argument('tags', nargs='+', help='Tags associated with the problem (e.g., Array, Hash Table)')
    
    # Parse the arguments
    args = parser.parse_args()
    
    # Call the add_solution function with CLI arguments
    add_solution(args.level, args.file_name, args.tags)

if __name__ == '__main__':
    main()
