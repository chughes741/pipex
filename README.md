# pipex
A project for redirections and piping

Project link: https://cdn.intra.42.fr/pdf/pdf/50539/en.subject.pdf

# Example uses
	./pipex file1 cmd1 cmd2 file2
    ./pipex something.log "grep error" "less" output.txt

## bonus: multiple pipes 
    ./pipex file1 cmd1 cmd2 cmd3 ... file2
    ./pipex hello.txt "ls -l" "grep file" "awk ..."

    ./pipex file_literal cmd1 cmd2 file
    ./pipex "Hello World!" "grep -i w" output.txt
