## PDM Notes Desktop
### Cross-platform End-to-End encrypted communication and note-taking tool.
This project is made for desktop platforms and includes encryption debug tools, encrypted
database (encrypted sqlite implementation) for pdm-crypt-module. 
by Yi Yang (18604713262@163.com)

# Documentations (PDM notes desktop)
## Dependency
### C++ 17

## Storage
### User Configurations and User information (sqlite)
- User configuration database is stored in the current executable directory in folder **user/${md5hashUserEmail}** as two two files.
    - The files are **${md5hashUserEmail}** and **${md5hashUserEmail}-keyfile**, and encode password is "pdmnotes". It stores the non-essential application information customized by the user (ex. window size, window position, tabs position).
- User data database is stored in the current executable directory in folder **user/${md5hashUserEmail}/data** as two files.
    - The files are **${md5hashUserEmail}.data** and **${md5hashUserEmail}-keyfile.data**. They store all user data in the encrypted sqlite database using a password derived from the master key. 
