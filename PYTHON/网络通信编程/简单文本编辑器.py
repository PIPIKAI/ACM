#简单GUI文本编辑器
from tkinter import *
from tkinter.scrolledtext import ScrolledText 
from tkinter import filedialog,messagebox
def load():
    # Floderpath=filedialog.askdirectory()
    contents.delete('1.0', END) 
    Filepath=filedialog.askopenfilename()
    filename.insert(INSERT,Filepath)
    with open(Filepath) as file:
        contents.insert(INSERT, file.read()) 
    
def Out():
    save=messagebox.askquestion(title='注意！', message='是否保存？')
    if(save=='yes'):
        with open(filename.get(), 'w') as file:
            file.write(contents.get('1.0', END)) 
    top.quit()
        
Filepath=""
top = Tk() 
top.title("GUI Editor") 
contents = ScrolledText() 
contents.pack(side=BOTTOM, expand=True, fill=BOTH) 
filename = Entry() 
filename.pack(side=LEFT, expand=True, fill=X) 
Button(text='Open', command=load).pack(side=LEFT) 
Button(text='Quit', command=Out).pack(side=LEFT) 
mainloop()