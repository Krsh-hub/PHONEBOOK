# 📱 PhoneBook Application in C

A simple console-based PhoneBook application written in C that allows you to manage contacts with functionalities like add, delete, and search. It uses efficient sorting and a case-insensitive search mechanism.

---

## 🧾 Features

- ✅ **Add a Contact**  
  Add new contact details (name and number). Duplicate entries are not allowed.

- 🔍 **Search Contact**  
  - By **Name** (case-insensitive)  
  - By **Phone Number**

- ❌ **Delete a Contact**  
  - By **Name**  
  - By **Phone Number**

- 📋 **Auto-Sorting**  
  Contacts are automatically sorted alphabetically using Merge Sort after every addition.

---

## 🧱 Data Structures Used

- **Array** – Stores up to 1000 contact entries.
- **Struct (`Contact`)** – Represents individual contact data (name and phone number).

---

## 🧠 Algorithms Used

- **Custom `strcasecmp` function** – For case-insensitive name comparisons.
- **Merge Sort** – Ensures the contact list remains alphabetically sorted after additions.

---

## 💻 How to Run

1. Clone or download this repository.
2. Compile the code using any C compiler:
   ```bash
   gcc phonebook.c -o phonebook
