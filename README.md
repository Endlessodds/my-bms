# 🏦 my-bms: Bank Management System (C++)

- **my-bms** is a lightweight file-based bank management system written in C++. 
- It provides basic banking features such as account creation, balance inquiry, deposit, withdrawal, and money transfers — all using text files for persistent storage.

---

## 💡 Features

- Create and manage accounts with a 4-digit PIN
- Deposit and withdraw money
- Transfer funds between accounts
- View current balance and account details
- File-based storage (no database required)
- Simple terminal-based interface

---

## 🧾 File Structure

my-bms/  
├── main.cpp  (Core application code)  
├── account_number.txt (Tracks latest account number)  
├── <accountNumber>.txt (Individual account files)  
└── README.md (Project documentation)  


---

## 🚀 Usage

1. **Compile the program:**
   ```bash```  
   g++ main.cpp -o my-bms

2. **Run It**

```bash```  
./my-bms


---
## Use the on-screen menu to:

- 🆕 Create a new account

- 🔐 Log in with your account number and PIN

- 💰 Perform deposits, withdrawals, transfers

- 📄 View account information

# Contributing to **my-bms**

Thank you for your interest in contributing to **my-bms**!  
We welcome contributions of all kinds—whether it's fixing bugs, improving documentation, or suggesting new features.

---

## 🚀 How to Contribute

### 1. Fork the Repository  
Click the **Fork** button at the top-right corner of the GitHub repo to create your own copy.

### 2. Clone Your Fork Locally  
```bash
git clone https://github.com/your-username/my-bms.git
cd my-bms
```

### 3. Create a New Branch  
Use a descriptive name for your branch based on your change.

```bash
git checkout -b feature/short-descriptor
```

### 4. Make Your Changes  
- Write clear, maintainable code.  
- Follow the existing coding style and structure.  
- Add helpful comments where needed.

### 5. Test Your Changes  
Ensure your code works as expected and doesn't break existing functionality.

### 6. Commit Your Changes  
Write concise and descriptive commit messages.

```bash
git commit -m "Add: feature X to improve Y"
```

### 7. Push to GitHub  
```bash
git push origin feature/short-descriptor
```

### 8. Open a Pull Request (PR)  
Submit a PR to the `main` branch of the original repository.  
Please include a clear explanation of:
- What you did  
- Why it matters  
- Any potential impacts

---

## 📌 Code Guidelines

- Use clear and descriptive names for variables, functions, and classes.  
- Keep code comments relevant and up to date.  
- Match existing formatting and indentation.  
- Do **not** commit sensitive data (e.g., credentials, personal info).

---

## 🐛 Reporting Issues

Spotted a bug or want to request a new feature?  
Please [open an issue](https://github.com/Endlessodds/my-bms/issues) with:
- A detailed description  
- Steps to reproduce (if applicable)  
- Screenshots or logs (optional but helpful)


---

## 🙌 Thank You

Thank you for helping make **my-bms** better!  
We truly appreciate your time, effort, and creativity.



---
## ⚠️ Important Notes
- 🗂️ Each account is saved in a separate .txt file in the local directory.

- 🔓 PINs and balances are stored as plain text (no encryption or security).

- 📚 This project is intended for educational and demonstration purposes only. It is not secure or production-ready.











