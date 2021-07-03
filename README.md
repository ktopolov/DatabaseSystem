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

## Setting up SSH on Linux
SSH allows GitHub to ensure secure communication is made to the repository. To use SSH for Git, we must generate a private and public SSH key, add this to our `ssh-agent` such that it can send this key whenever communicating via SSH, and thne add this key to our GitHub profile so it can match the key to our profile. See the following link for detailed instructions:
https://docs.github.com/en/github/authenticating-to-github/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent  

Using the email linked to your GitHub account, enter:
```
ssh-keygen -t ed25519 -C "your_email@example.com"
```

You do not need to enter a filename to save as; just hit enter and you will get a default filename. You should end up with a `<key_name>` private key and a `<key_name>.pub` public key. The passphrase can be left blank too if desired.

To addt the key to the SSH agent, start the SSH agent in the background using:
```
eval "$(ssh-agent -s)"
```

Add the **private** key to the agent using:
```
ssh-add ~/.ssh/<private_key_name>
```

To add to GitHub, go to "Settings >> SSH and GPG Keys >> New SSH Key". Give the key an informative title. Then, paste the contents of the **public key** into the box.
![image](https://user-images.githubusercontent.com/25532284/124362413-969f4e00-dc02-11eb-8e39-dfafe90231f1.png)

To verify the connection between your SSH agent and GitHub, use:
```
ssh -T git@github.com
```
I see:
```
Hi ktopolov! You've successfully authenticated, but GitHub does not provide shell access.
```


