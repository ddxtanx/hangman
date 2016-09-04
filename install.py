import os
global Install
def install():
    print("Installing hangman onto system\n")
    if not os.path.isfile("./hangman"):
        print("Creating hangman binary\n")
        os.system("gcc -std=c99 hangmanv1.c -o hangman")
    if not os.path.isfile(os.path.expanduser("~")+"/hangman"):
        print("Creating absolute file locaiton\n")
        os.system("cp ./hangman ~/hangman")
    try:
        fp = open(os.path.expanduser("~")+"/.bash_profile")
        for line in fp.readlines():
            if "hangman" in line:
                Install = False
                break
            else:
                Install = True
    except:
        os.system("touch ~/.bash_profile")
        Install = True
    if Install:
        print("Adding command to bash_profile\n")
        os.system("echo 'hangman(){ \n \t~/hangman \n}' >> ~/.bash_profile")
        os.system("echo 'echo \"hangman to play hangman \"' >> ~/.bash_profile")
    if not os.path.isfile("/bin/hangman"):
        print("Copying to /bin")
        os.system("sudo cp ./hangman /bin")
    print("Finished!\n")
    print("Now just restart your console and you will be able to play hangman!")
def main():
    try:
        import requests
    except:
        print "Installing wordcreate requirement- requests"
        os.system("pip install requests")
    if not (os.path.isfile(os.path.expanduser("~")+"/hangman") and os.path.isfile("/bin/hangman")):
        install()
        return 0
    print "No install needed, restart your terminal and type in 'hangman' to play hangman"

if __name__=="__main__":
    main()