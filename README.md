# employment-payroll-management-system
🧾 Employment Payroll Management System (C)
📌 Project Overview

The Employment Payroll Management System is a console-based application developed in C that manages employee records and automates payroll calculations.
The system uses role-based authentication, where different users have different permissions, and the Admin has the highest level of access.

This project demonstrates the practical use of C programming concepts, file handling, and modular programming, following real-world software design practices.

🎯 Objectives

To manage employee records efficiently

To implement secure login and registration

To provide role-based access control

To automate salary calculation and payroll generation

To store data permanently using files

👥 User Roles & Permissions
🔐 Admin (Highest Access)

Register new users

Add, view, update, and delete employee records

Generate payroll

View salary reports

Full system control

👤 User (Employee)

Login to the system

View personal details

View salary slip

Limited access (cannot modify records)

⚙️ Features

Registration and Login system

Role-based authentication (Admin/User)

Menu-driven interface

Employee management

Payroll calculation

File-based data storage

Modular and scalable code structure

🛠️ Technologies Used

Programming Language: C

Concepts Used:

Structures

Functions

File Handling

Conditional Statements

Loops

Version Control: Git & GitHub

📁 Project Directory Structure
employment-payroll-management-system/
│
├── main.c
│
├── headers/
│   ├── auth.h
│   ├── employee.h
│   ├── payroll.h
│
├── src/
│   ├── auth.c
│   ├── employee.c
│   ├── payroll.c
│
├── data/
│   ├── users.dat
│   ├── employees.dat
│   ├── payroll.dat
│
├── docs/
│   └── project-report.md
│
├── .gitignore
└── README.md

💾 Data Storage

The project uses binary .dat files to store information permanently:

File Name	Description
users.dat	Stores user credentials and roles
employees.dat	Stores employee details
payroll.dat	Stores payroll and salary data
▶️ How to Compile and Run
Compile:
gcc main.c src/*.c -o payroll

Run:
./payroll

🔄 Program Flow

User/Admin logs into the system

System checks role

Role-based menu is displayed

Allowed operations are performed

Data is stored or retrieved from files

🧠 Key Learning Outcomes

Understanding of role-based authentication

Practical experience with file handling in C

Modular programming and project structuring

Real-world application development using C

Version control using GitHub

🚀 Future Enhancements

Password encryption

Attendance management

Payslip export (PDF/Text)

GUI-based interface

Database integration

📄 Conclusion

This project successfully implements a Payroll Management System using the C programming language.
It follows a modular, scalable, and real-world approach, making it suitable for academic and learning purposes.

👨‍💻 Developed By

Soyam Bhalotia
(Employment Payroll Management System – C Project)
