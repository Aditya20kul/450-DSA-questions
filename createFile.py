import os
import time
from pathlib import Path
template = "#include<bits/stdc++.h>\n#define mod 1000000007\n#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)\n#define pb push_back\n#define mp make_pair\n#define ll long long int\n#define fi first\n#define se second\n#define vll std::vector<ll> vl\n#define ld long double\nusing namespace std;\nint main()\n{\nfastio;\n\n\tll i,j,cnt=0,n;\n\nreturn 0;\n}"
while True:
    fname = input('Enter the cpp filename without file extension\n')
    ext = int(input('Choose the option of required extension -\n1. cpp\n2. py\n'))
    cwd = os.getcwd()
    if ext==1:
        filename = fname+".cpp"
        my_file = Path(os.path.join(cwd,filename))
        if my_file.is_file():
             print ("File exist, Enter a valid File name")
        else:
            f = open(os.path.join(cwd,filename),"w+")
            f.write(template)
            print('File created !')
            f.close()
            time.sleep(2)
    elif ext==2:
        filename = fname+".py"
        my_file = Path(os.path.join(cwd,filename))
        if my_file.is_file():
             print ("File exist, Enter a valid File name")
        else:
            f = open(os.path.join(cwd,filename),"w+")
            print('File created !')
            f.close()
            time.sleep(2)
    else:
        print('Select Valid option for extension')