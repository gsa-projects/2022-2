import re

f = open('KakaoTalkChats.txt', 'r')
LEN = 473697

for i in range(LEN):
    txt = f.readline()
    
    if re.search(r'와[가-힣]시', txt):
        print(txt)

f.close()