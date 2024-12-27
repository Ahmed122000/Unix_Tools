
# Cat Tool

This project is a custom implementation of the Unix command-line tool `cat`. The Unix command line tools are known for their simplicity and adherence to the Unix Philosophy:
- **Modularity**: Each tool does one thing well and provides a simple CLI that handles text input from files or streams.
- **Composability**: Tools can be easily connected to others, creating powerful combinations.

## Features

The tool supports the following functionalities:

- **Standard Input or Files**: You can either pipe input directly into the tool or specify one or more files to read.
- **Line Numbering Options**:
  - `-n`: Print line numbers, including blank lines.
  - `-b`: Print line numbers, excluding blank lines.
  - **Default**: Print the input as it is, without line numbers.

## Usage

### Command Structure

The tool can be invoked in the following ways:

- **Standard Input**:
  ```
  cat input.txt | ccat [options]
  ```
  
- **File Input**:
  ```
  ccat [options] [file path]
  ```

You can pass multiple files, and the arguments can be rearranged when using files.

### Arguments

- `-n`: Print the line numbers including blank lines.
- `-b`: Print the line numbers excluding blank lines.
- **Default**: Print the input as is, without line numbers.

## Example

To print the contents of `file.txt` with line numbers, excluding blank lines:
```
ccat -b file.txt
```

To read from standard input and print with line numbers, including blank lines:
```
cat input.txt | ccat -n
```

## Acknowledgments

This application was inspired by a challenge provided by [Coding Challenges](https://codingchallenges.fyi/).
