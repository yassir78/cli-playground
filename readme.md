# Making Your Command Available Everywhere

This guide explains how to make your compiled program accessible from any directory in your terminal (just like standard commands such as `ls` or `echo`).

---

## 📦 1. Compile the Program

First, compile your C file:

```bash
gcc echo.c -o myecho
```

This creates an executable file named `myecho`.

---

## 📁 2. Move the Executable to a PATH Directory

Your system looks for commands in directories listed in the `PATH` environment variable.

### Option A (Recommended): `/usr/local/bin`

```bash
sudo mv myecho /usr/local/bin/
```

This makes the command available system-wide.

---

### Option B: Use a Personal `bin` Directory (No sudo)

Create a local directory:

```bash
mkdir -p ~/bin
mv myecho ~/bin/
```

Then add it to your `PATH`:

```bash
export PATH="$HOME/bin:$PATH"
```

To make this permanent, add the line above to your shell config file:

* Bash → `~/.bashrc`
* Zsh → `~/.zshrc`

Apply changes:

```bash
source ~/.bashrc
```

---

## ✅ 3. Verify Installation

Check if your command is accessible:

```bash
which myecho
```

Expected output:

```bash
/usr/local/bin/myecho
```

---

## ⚠️ Notes

* Avoid naming your program `echo`, as it may conflict with the built-in shell command.
* If needed, run your version explicitly:

  ```bash
  ./myecho
  ```

  or

  ```bash
  /usr/local/bin/myecho
  ```

---

## 🎉 Done!

You can now run your command from anywhere:

```bash
myecho Hello World
```

---

## 💡 Tip

To see all directories in your `PATH`:

```bash
echo $PATH
```
