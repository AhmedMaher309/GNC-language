import tkinter as tk
from tkinter import filedialog
import os
import subprocess

class TextEditor:
    def __init__(self, master):
        self.master = master
        self.master.title("Text Editor")
        self.master.configure(background='#000033')  # Set the background color
        # Create the text widget
        self.text = tk.Text(self.master, background="#000033", foreground="white", insertbackground="white")

        # Create the text widget
        #self.text = tk.Text(self.master)
        self.text.pack(expand=True, fill="both")

        # Create a scrollbar and attach it to the text widget
        scrollbar = tk.Scrollbar(self.master)
        scrollbar.pack(side="right", fill="y")
        scrollbar.config(command=self.text.yview)
        self.text.config(yscrollcommand=scrollbar.set)

        # Create a menu bar
        menubar = tk.Menu(self.master)
        self.master.config(menu=menubar)

        # Create the file menu
        file_menu = tk.Menu(menubar, tearoff=0)
        menubar.add_cascade(label="File", menu=file_menu)
        file_menu.add_command(label="Open", accelerator="Ctrl+O", command=self.open_file)
        file_menu.add_command(label="Save", accelerator="Ctrl+S", command=self.save_file)
        file_menu.add_separator()
        file_menu.add_command(label="Exit", command=self.master.quit)

        # Create the edit menu
        edit_menu = tk.Menu(menubar, tearoff=0)
        menubar.add_cascade(label="Edit", menu=edit_menu)
        edit_menu.add_command(label="Cut", accelerator="Ctrl+X", command=self.cut)
        edit_menu.add_command(label="Copy", accelerator="Ctrl+C", command=self.copy)
        edit_menu.add_command(label="Paste", accelerator="Ctrl+V", command=self.paste)

        # Add keyboard shortcut functionality to the menu items
        self.master.bind("<Control-o>", lambda event: self.open_file())
        self.master.bind("<Control-s>", lambda event: self.save_file())
        self.master.bind("<Control-x>", lambda event: self.cut())
        self.master.bind("<Control-c>", lambda event: self.copy())
        self.master.bind("<Control-v>", lambda event: self.paste())

        # Create a button
        save_button = tk.Button(self.master, text="Save File", command=self.save_file)
        save_button.pack()

        # Create a run button
        run_button = tk.Button(self.master, text="Run", command=self.run_code)
        run_button.pack()

    def open_file(self):
        file_path = filedialog.askopenfilename(
            initialdir="~/Documents/",
            title="Select a file",
            filetypes=(("Text files", "*.txt"), ("All files", "*.*")))
        if file_path:
            with open(file_path, "r") as file:
                self.text.delete("1.0", tk.END)
                self.text.insert(tk.END, file.read())

    def save_file(self):
        file_path = "testcases/input.txt"  # Set the file path to "input.txt"
        with open(file_path, "w") as file:
            file.write(self.text.get("1.0", tk.END))


    def cut(self):
        self.text.event_generate("<<Cut>>")

    def copy(self):
        self.text.event_generate("<<Copy>>")

    def paste(self):
        self.text.event_generate("<<Paste>>")

    def run_code(self):
        # Build the code using make
        subprocess.run(["make", "cleanbuild"])

        # Run the code using make
        subprocess.run(["make", "run"])

if __name__ == "__main__":
    root = tk.Tk()
    editor = TextEditor(root)
    root.mainloop()
