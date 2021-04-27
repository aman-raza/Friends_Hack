from PyPDF2 import PdfFileMerger
import os 
#var = os.getcwd() For extracting from enother folder
merger = PdfFileMerger()
for filename in os.listdir():
  if filename.endswith('.pdf'):
    merger.append(filename)
merger.write("Final_pdf.pdf")
merger.close()
