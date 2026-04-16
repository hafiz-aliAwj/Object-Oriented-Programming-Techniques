# 🏥 MediCore Hospital Management System

A comprehensive **Object-Oriented C++ Hospital Management System** designed to simulate real-world hospital operations including patient management, staff handling, ward allocation, billing, and appointment scheduling.

---

## 📌 Features

- 👨‍⚕️ **Staff Management**
  - Supports multiple staff types: GP, Surgeon, Nurse
  - Polymorphic billing rates using virtual functions

- 🧑‍🤝‍🧑 **Patient Management**
  - Admission & discharge system
  - Treatment tracking
  - Billing generation

- 🏨 **Ward Management**
  - General Ward, ICU, Surgical Ward
  - Admission rules based on patient condition
  - Occupancy tracking and comparison

- 📅 **Appointment Scheduling**
  - Prevents double booking
  - Staff & patient schedules

- 💰 **Billing System**
  - Operator overloading (`+`, `==`)
  - Itemized bill generation

- 📊 **Reporting System**
  - Lambda-based filtering and sorting
  - Revenue calculation per ward

---

## 🧱 System Design

The system follows strong **Object-Oriented Programming principles**:

- **Inheritance**
- **Polymorphism**
- **Encapsulation**
- **Composition**

---

## 🧬 Class Hierarchy Overview


Person
├── Staff
│ ├── GP
│ ├── Surgeon
│ └── Nurse
└── Patient

Ward (Abstract)
├── GeneralWard
├── ICU
└── SurgicalWard

Hospital
├── Manages Patients
├── Manages Staff
├── Manages Wards
└── Uses AppointmentBook

AppointmentBook
└── Stores Appointment

ReportGenerator
└── Utility class


---

## 🧠 Key Design Decisions

### 1. Template Method Pattern (Ward Admission)
The `Ward::addPatient()` function defines a fixed workflow while delegating admission criteria to `canAccept()`.  
This ensures consistency while allowing specialization in ICU and Surgical wards.

---

### 2. Polymorphism Instead of `dynamic_cast`
Pure virtual functions like `getBillingRate()` are used to achieve runtime polymorphism.  
This removes the need for type-checking and keeps the system clean and extensible.

---

### 3. Value Semantics for Patient Data
Patient treatments are stored using `std::vector`, ensuring:
- Automatic memory management
- No manual deletion required

---

### 4. Lambda-Based Reporting
Filtering and sorting are implemented using lambdas and `std::function`, allowing:
- Flexible queries
- No modification to core classes

---

### 5. Operator Overloading (Billing)
The `Bill` class overloads:
- `+` → Combine bills
- `==` → Compare bills

This improves readability and usability.

---

### 6. Separation of Responsibilities

| Class | Responsibility |
|------|--------|
| Hospital | System controller |
| Patient | Medical records |
| Ward | Admission logic |
| ReportGenerator | Data analytics |

---

## 🧾 Memory Ownership Model

### Ownership Table

| Resource | Owner | Allocation | Deletion |
|----------|------|-----------|----------|
| Ward Objects | Hospital | `new` in main | Hospital destructor |
| Staff Objects | Hospital | `new` in main | Hospital destructor |
| Patient Objects | Hospital | `admit()` | Hospital destructor |
| Patient (test cases) | main | `new` | ❗ Must delete manually |
| Treatment Data | Patient | `vector` | Automatic |
| Appointments | AppointmentBook | `vector` | Automatic |

---

### Ownership Rules

- ✅ **Hospital OWNS**
  - Staff
  - Wards
  - Admitted & Archived Patients

- ✅ **Patient OWNS**
  - Treatments (`std::vector`)

- ✅ **AppointmentBook OWNS**
  - Appointments (by value)

---

### ⚠️ Important Note

> Every dynamically allocated object (`new`) must have exactly ONE owner responsible for deleting it.

Failure to follow this rule may result in:
- Memory leaks
- Double deletion crashes

---

## 🧪 Test Cases Covered

- ✔️ Polymorphic display
- ✔️ Billing operator overloading
- ✔️ Ward comparison operators
- ✔️ Admission rules validation
- ✔️ Double booking prevention
- ✔️ Copy independence
- ✔️ Move semantics (archive system)
- ✔️ Lambda-based filtering & sorting
- ✔️ Staff billing polymorphism
- ✔️ Ward revenue calculation

---

## ⚙️ Compilation & Execution

```bash
g++ -std=c++17 main.cpp -o hospital
./hospital
🚀 Future Improvements
Replace raw pointers with std::unique_ptr (modern C++)
Add file persistence (save/load data)
GUI-based interface
Database integration
👨‍💻 Author

Ali AWJ