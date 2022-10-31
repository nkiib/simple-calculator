from asyncio import subprocess
import tkinter as tk
from tkinter import ttk
import subprocess as sp

CALCPATH = "./calc_shiftjis.exe"
CALCTYPES = [
    "最小公倍数",
    "最大公約数",
    "素判定",
    "合計",
    "平均",
    "約分",
    "累乗"
]

CALCCMD = [
    "-m",
    "-d",
    "-c",
    "-s",
    "-a",
    "-r",
    "-p",
]
KEY_ENTER = 13

currenttype = ""

def on_select(e):
    global currenttype
    selected = cb.get()
    for i in range(len(CALCTYPES)):
        if CALCTYPES[i] == selected:
            currenttype = CALCCMD[i]
    print(currenttype)

def on_keydown(e):
    if e.keycode == KEY_ENTER:
        calculate()

def calculate():
    if tb.get() == "":
        return
    res = sp.run(f"{CALCPATH} {currenttype} {tb.get()}",stdout=sp.PIPE,
    universal_newlines=True)
    s = ">> "
    for i in res.stdout.splitlines():
        s += i
        s += "\n"
    lb["text"] = s
    print(f"{CALCPATH} {currenttype} {tb.get()}")

root = tk.Tk()
root.geometry("400x200")
root.title("simple-calculator_GUI")
items = ["a","b","c"]

cb = ttk.Combobox(root,height=3,values=CALCTYPES,state="readonly")
cb.bind("<<ComboboxSelected>>",on_select)
cb.pack()

lb = tk.Label(text=">>")
lb.pack()

tb = ttk.Entry(width=20)
tb.bind("<KeyPress>",on_keydown)
tb.pack()

res = sp.run(f"{CALCPATH} -h",stdout=subprocess.PIPE,universal_newlines=True)
for l in res.stdout.splitlines():
    print(l)
tk.mainloop()