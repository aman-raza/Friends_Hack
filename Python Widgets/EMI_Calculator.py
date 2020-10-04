'''
Created EMI Calculator using Tkinter
Author: @divyhshah
'''

import tkinter as tk
from math import ceil

fields = ('Annual Interest Rate', 'Loan Tenure (in months)', 'Loan Amount', 'Monthly Payment', 'Remaining Loan')

def monthly_payment(entries):
    # period rate:
    r = (float(entries['Annual Interest Rate'].get()) / 100) / 12
    print("r", r)
    # principal loan:
    loan = float(entries['Loan Amount'].get())
    n =  float(entries['Loan Tenure (in months)'].get())
    remaining_loan = float(entries['Remaining Loan'].get())
    
    q = (1 + r)** n
    monthly = ceil(r * ( (q * loan - remaining_loan) / ( q - 1 )))
    entries['Monthly Payment'].delete(0, tk.END)
    entries['Monthly Payment'].insert(0, monthly )
    print("Monthly Payment: %f" % float(monthly))

def final_balance(entries):
    # period rate:
    r = (float(entries['Annual Interest Rate'].get()) / 100) / 12
    print("r", r)
    # principal loan:
    loan = float(entries['Loan Amount'].get())
    n =  float(entries['Loan Tenure (in months)'].get()) 
    monthly = float(entries['Monthly Payment'].get())
    q = (1 + r) ** n
    remaining = q * loan  - ( (q - 1) / r) * monthly
    remaining = ("%8.2f" % remaining).strip()
    entries['Remaining Loan'].delete(0, tk.END)
    entries['Remaining Loan'].insert(0, remaining )
    print("Remaining Loan: %f" % float(remaining))

def makeform(root, fields):
    entries = {}
    for field in fields:
        print(field)
        row = tk.Frame(root)
        lab = tk.Label(row, width=22, text=field+": ", anchor='w')
        ent = tk.Entry(row)
        ent.insert(0, "0")
        row.pack(side=tk.TOP, 
                 fill=tk.X, 
                 padx=5, 
                 pady=5)
        lab.pack(side=tk.LEFT)
        ent.pack(side=tk.RIGHT, 
                 expand=tk.YES, 
                 fill=tk.X)
        entries[field] = ent
    return entries

if __name__ == '__main__':
    root = tk.Tk()
    root.title("EMI Calculator")
    ents = makeform(root, fields)
    b1 = tk.Button(root, text='Final Balance',
           command=(lambda e=ents: final_balance(e)))
    b1.pack(side=tk.LEFT, padx=5, pady=5)
    b2 = tk.Button(root, text='Monthly Payment',
           command=(lambda e=ents: monthly_payment(e)))
    b2.pack(side=tk.LEFT, padx=5, pady=5)
    b3 = tk.Button(root, text='Quit', command=root.quit)
    b3.pack(side=tk.LEFT, padx=5, pady=5)
    root.mainloop()