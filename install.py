import os
import optparse
global Install
def cinstall():
    if not(os.path.isfile("./curl-7.50.1.tar.gz")==True) and not(os.path.isdir("./curl-7.50.1")): 
        print "Downloading curl binary from https://curl.haxx.se/download/curl-7.50.1.zip"
        os.system("wget https://curl.haxx.se/download/curl-7.50.1.zip")
        print "Unzipping curl binary"
        os.system("unzip curl-7.50.1.zip")
    print "Printing working directory"
    os.system("pwd")
    print "Configuring"
    os.system("cd curl-7.50.1 && ./configure")
    print "make"
    os.system("cd curl-7.50.1 && make")
    print "sudo make install"
    os.system("cd curl-7.50.1 && sudo make install")
    if os.path.isdir("/usr/local/include/curl")==True:
        os.system("rm -rfv curl-7.50.1")
        os.system("rm curl-7.50.1.zip")
def install():
    print("Installing hangman onto system\n");
    if not os.path.isfile("./hangman"):
        print("Creating hangman binary\n");
        os.system("gcc -std=c99 hangmanv1.c -o hangman -lcurl");
    if not os.path.isfile(os.path.expanduser("~")+"/hangman"):
        print("Creating absolute file locaiton\n");
        os.system("cp ./hangman ~/hangman");
    try:
        fp = open("~/.bash_profile")
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
        print("Adding command to bash_profile\n");
        os.system("echo 'hangman(){ \n \t~/hangman \n}' >> ~/.bash_profile");
        os.system("echo 'echo \"hangman to play hangman \"' >> ~/.bash_profile");
    if not os.path.isfile("/bin/hangman"):
        print("Copying to /bin")
        os.system("sudo cp ./hangman /bin")
    print("Finished!\n");
    print("Now just restart your console and you will be able to play hangman!");
def main():
    if not os.path.isdir("/usr/local/include/curl"):
        cinstall()
        return 0
    if not (os.path.isfile(os.path.expanduser("~")+"/hangman") and os.path.isfile("/bin/hangman")):
        install()
        return 0
    print "No install needed, restart your terminal and type in 'hangman' to play hangman"

if __name__=="__main__":
    main()