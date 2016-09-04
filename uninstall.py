import os
global Command
def delete():
    os.system("rm ./hangman ~/hangman ")
def scrub():
    rf = open(os.path.expanduser("~")+"/.bash_profile", "r")
    lines = rf.readlines()
    rf.close()
    wf = open(os.path.expanduser("~")+"/.bash_profile", "w")
    for line in lines:
        if not(("hangman" in line) or (" \t~/hangman \n}" in line)):
            wf.write(line)
def main():
    scrub()
    delete()
if __name__=="__main__":
    main()