# splain
A command‑line tool that **explains what a shell command will do before you run it**.  
It parses the command, inspects the filesystem, analyzes flags, pipes, globs, and redirections, and produces a clear, human‑readable explanation — without executing anything.

splain acts as a safety net for your terminal, a teaching tool for shell newcomers, and a static analyzer for complex commands.

---

## ✨ Features

- Natural‑language explanations of shell commands  
- Filesystem simulation to detect deletes, overwrites, moves, and copies  
- Globbing, variable expansion, pipes, and redirection analysis  
- Deep analyzers for common commands (`rm`, `cp`, `mv`, `tar`, `grep`, `find`, etc.)  
- Man‑page extraction for unknown commands  
- Risk detection for destructive patterns  
- JSON output mode for editor or script integration  
- Zero execution — splain never runs the command  

---

## 🧠 Why splain exists

Shell commands are powerful but easy to misread or misunderstand. A single typo can delete the wrong directory or overwrite important files. splain helps you understand commands before trusting them.

It’s useful for:

- learning shell commands  
- reviewing scripts  
- preventing mistakes  
- understanding pipelines  
- auditing third‑party tools  

---

## 🔍 How it works

### Parsing
splain parses the command into a structured representation:

- program  
- flags  
- arguments  
- pipes  
- redirections  
- globs  
- subshells  
- environment variables  

### Filesystem inspection
splain checks:

- whether paths exist  
- whether they’re files, directories, or symlinks  
- permissions  
- potential overwrites  
- how many files a recursive command would affect  

### Command analyzers
For well‑known commands, splain includes deep semantic analyzers:

- rm  
- cp  
- mv  
- mkdir  
- rmdir  
- chmod  
- chown  
- tar  
- grep  
- find  
- head / tail  
- cat  
- echo  

### Unknown commands
If splain doesn’t recognize a command, it still explains:

- flag meanings (from man pages)  
- argument types  
- redirections  
- pipes  
- potential file writes or overwrites  

### Explanation generation
The structured analysis is turned into readable text or JSON.

---

## 🚀 Usage

### Basic example
```bash
splain rm -rf ~/Downloads
