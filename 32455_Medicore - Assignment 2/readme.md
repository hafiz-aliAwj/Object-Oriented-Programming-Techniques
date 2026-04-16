# MediCore: Hospital Management System

**MediCore** is a high-performance, object-oriented hospital management system developed in **C++17**. It manages patient records, hospital staff, ward occupancy, billing, and appointment scheduling with a focus on manual memory management, polymorphic design, and efficient data handling.

## 🏗 Project Structure

The project follows a **Modular Directory Structure** to separate concerns and improve maintainability, following the Package-by-Feature pattern:

* **/headers**: Class definitions and interfaces.
    * `/Staff`: Base `Staff`, `GP`, `Surgeon`, and `Nurse`.
    * `/Ward`: Base `Ward`, `ICU`, `GeneralWard`, and `SurgicalWard`.
    * `/Appointment`: `Appointment` and `AppointmentBook`.
* **/src**: Implementation logic.
    * Follows the exact subdirectory mapping as the headers.

## 🚀 Key Features

### 1. Polymorphic Personnel Management (Requirement 2.1)
Utilizes a deep inheritance hierarchy starting from an abstract `Person` class.
* **Staff Roles:** GPs (Consultation fees), Surgeons (Operation fees), and Nurses (Ward care fees).
* **Virtual Summaries:** A polymorphic `getSummary()` call provides a unique profile format for every person type (Patient vs. Staff roles).

### 2. Rule-Based Ward Admission (Requirement 2.2)
Wards use a **Template Method Pattern** to validate admissions:
* **Logic:** The base `Ward::addPatient` checks capacity and then delegates clinical criteria to the virtual `canAccept()` function.
* **ICU:** Admits only patients with "Critical" flags.
* **Surgical Ward:** Admits only patients requiring surgery.
* **Occupancy Comparison:** Wards can be compared using standard operators (`<`, `>`, `==`) based on their current occupancy percentage.

### 3. Financial & Billing Engine (Requirement 2.3)
Automated itemized billing upon patient discharge:
* **Components:** Treatment costs + Ward stay fees (Daily Rate × Days) + PKR 500 Admin Fee.
* **Operator Overloading:** * `+` : Combines bills for patients moving across multiple wards.
    * `==` : Compares financial totals.
    * `<<` : Generates a professional, itemized receipt.

### 4. Conflict-Aware Scheduling (Requirement 2.4)
The `AppointmentBook` manages complex scheduling logic:
* **Double-Booking Protection:** Rejects any appointment where a staff member is already booked for the same date and time slot.
* **Overlap Logic:** `TimeSlot::overlapsWith` ensures that even partial overlaps are caught.

### 5. Functional Query System (Requirement 2.5)
The system satisfies reporting requirements using **Lambdas and Function Pointers** to ensure flexibility without hard-coded loops:
* **Filtering:** By diagnosis, admission date, or department.
* **Sorting:** By surname, admission date, or total bill amount.
* **Revenue Tracking:** Calculates total income generated from discharged patients per specific ward.

## 🛠 Compilation and Execution

The project is strictly compliant with **C++17** standards. To compile the entire system, navigate to the root directory and run:

```bash
g++ -std=c++17 main.cpp src/*.cpp src/Staff/*.cpp src/Ward/*.cpp src/Appointment/*.cpp -o MediCore