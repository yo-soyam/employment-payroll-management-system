<div align="center">

# 💼 Employment Payroll Management System  
### A File-Based Payroll Management System using C

</div>

---

## 📌 Problem Statement

In many organizations, payroll and employee records are managed manually, which leads to:

- Data redundancy and data loss  
- Calculation errors in salary processing  
- Lack of security and access control  
- Difficulty in maintaining employee records  

There is a need for a **secure, automated, and role-based payroll management system** that ensures accuracy, data persistence, and proper authorization.

---

## 👥 System Users

| User Role | Description |
|----------|------------|
| **Admin** | Has full access to the system, manages employees and payroll |
| **Employee (User)** | Can view personal details and salary information |

---

## 🔐 Authentication & Authorization

The system uses a **file-based authentication mechanism**.

### Authentication
- User registration (Admin / Employee)
- Secure login using username and password
- Credentials stored in data files

### Authorization
- Role-based access control
- Admin and Employee have separate permissions
- Unauthorized access is restricted

| Role | Permissions |
|-----|------------|
| Admin | Add/update employees, process payroll, view all records |
| Employee | View own profile and salary details |

---

## 🧱 Software Architecture
```
User
↓
Menu System
↓
Login & Authentication
↓
Role Validation (Admin / Employee)
↓
Function Execution
↓
File Read / Write
↓
Data Display
```
---

## 🗄️ File-Based Database Design

The system uses **file handling** for permanent data storage.

| File Name | Purpose |
|---------|---------|
| admins.dat | Stores admin credentials |
| employees.dat | Stores employee personal details |
| payroll.dat | Stores salary and payroll records |
| logs.dat | Stores system activity logs (optional) |

---

## 📊 Data

### Employee Data
- Employee ID
- Name
- Role
- Basic Salary
- Allowances
- Deductions

### Payroll Data
- Employee ID
- Gross Salary
- Net Salary
- Payment Status

---

## 🧩 Data Structures

The system uses **structures** to organize data efficiently.

```c
struct Employee {
    int id;
    char name[50];
    char role[20];
    float basic_salary;
};
struct Payroll {
    int emp_id;
    float gross_salary;
    float net_salary;
};
```
---
🔄 Data Flow

1. User provides input through menu

2. Authentication module validates credentials

3. Role is checked (Admin / Employee)

4. Allowed function is executed

5. Data is read/written from files

6. Output is displayed to the user

---

##📁Folder Structures
employment-payroll-management-system/
```c
├── src/
│   ├── main.c              # Entry point
│   ├── auth.c              # Login & registration
│   ├── admin.c             # Admin functions
│   ├── employee.c          # Employee functions
│   ├── payroll.c           # Payroll calculations
│
├── header/
│   ├── auth.h
│   ├── admin.h
│   ├── employee.h
│   ├── payroll.h
│
├── data/
│   ├── admins.dat
│   ├── employees.dat
│   ├── payroll.dat
│
├── docs/
│   ├── architecture.md
│   ├── flowchart.png
│   └── report.pdf
│
├── README.md
```
---

## 📋 Menu System

### Main menu
```
1.Login
2.Exit
```
### Admin Menu
```
1.Add Employee
2.View Employees
3.Process Payroll
4.View Payroll Report
5.Logout
```
### Employee Menu
```
1.View Profile
2.View Salary Details
3.Logout
```
## ▶️ How to Run the Project

```bash
gcc src/*.c -o payroll
./payroll
```

---

## 👥 Team Members & Task Assignments

| Member | Role | Assigned Task |
|--------|------|---------------|
| **Soyam (Lead)** | Team Lead | Project Architecture, System Integration, Main Logic |
| **Shreyash** | Developer | Authentication Module (Login/Registration) |
| **Shuvangi** | Developer | Admin Module (Employee Management) |
| **Shristi** | Developer | Payroll Module (Salary Processing) |
| **Sohan** | Developer | Employee Module (Profile & Salary View) & File Handling |

