# DatabaseSystem
Multi-language development project to get used to Linux-based C++, Python development as well as Git

The idea of this project is to familiarize myself with Git.  
  
# Getting Started  
## WSL
Download and install WSL (Windows Subsystem Linux) with this link: https://docs.microsoft.com/en-us/windows/wsl/install-win10. This will allow you to run Linux operating system on Windows as a virtual machine.  

## Other Softwares/g++
To install the C compiler gcc and c++ compiler g++, simply run:

*  Update repo packages: `sudo apt update`
*  Install GCC: `sudo apt install gcc g++ cmake codelite git-all`
  
This will get the gcc (C) and g++ (C++) compilers, the CMake build system and the CodeLite IDE, and Git version control software.

## Setting up SSH
SSH allows GitHub to ensure secure communication is made to the repository. To use SSH for Git, we must generate a private and public SSH key, add this to our `ssh-agent` such that it can send this key whenever communicating via SSH, and thne add this key to our GitHub profile so it can match the key to our profile.
https://docs.github.com/en/github/authenticating-to-github/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent  

