import PyPDF2
from PyPDF2 import PdfReader , PdfWriter, PdfMerger

pdfWriter = PyPDF2.PdfWriter()
pdfFiles = []
pdf_list = ["C:\\Users\\Rishabh\\University\\Fall 2024\\SENG 300\\Project\\seng300-f24-project\\Iteration_1\\Use_Cases\\backend_use_case_descriptions_diagram.pdf", "C:\\Users\\Rishabh\\University\\Fall 2024\\SENG 300\\Project\\seng300-f24-project\\Iteration_1\\Use_Cases\\backend_use_case_descriptions.pdf", "C:\\Users\\Rishabh\\University\\Fall 2024\\SENG 300\\Project\\seng300-f24-project\\Iteration_1\\Use_Cases\\frontend_use_case_descriptions_diagram.pdf", "C:\\Users\\Rishabh\\University\\Fall 2024\\SENG 300\\Project\\seng300-f24-project\\Iteration_1\\Use_Cases\\frontend_use_case_descriptions.pdf", "C:\\Users\\Rishabh\\University\\Fall 2024\\SENG 300\\Project\\seng300-f24-project\\Iteration_1\\Use_Cases\\networking_use_case_descriptions_diagram.pdf", "C:\\Users\\Rishabh\\University\\Fall 2024\\SENG 300\\Project\\seng300-f24-project\\Iteration_1\\Use_Cases\\networking_use_case_descriptions.pdf"]
for pdf in pdf_list:
    pdfFiles.append(pdf)

for filename in pdfFiles: # Starting a for loop.
    pdfFileObj = open(filename, 'rb') # Opens each of the file paths in filename variable.
    pdfReader = PyPDF2.PdfReader(pdfFileObj) # Reads each of the files in the new varaible you've created above and stores into memory.
    for pageNum in range(len(pdfReader.pages)):
        pageObj = pdfReader.pages[pageNum] # Reads only those that are in the varaible.
        pdfWriter.add_page(pageObj) # Adds each of the PDFs it's read to a new page.
    
pdfOutput = open('use_case_descriptions.pdf', 'wb') 

# Writing the output file using the pdfWriter function.
pdfWriter.write(pdfOutput)
pdfOutput.close()
