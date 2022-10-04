import pyexcel as pe
import requests
import time

t = True

data = pe.get_array(file_name='Traffic Data.xlsx')


def TS1(t):
    position = 2
    M = data[t][position]
    T1 = data[t][position + 1]
    T2 = data[t][position + 3]
    T3 = data[t][position + 4]
    T4 = data[t][position + 5]
    T5 = data[t][position - 1]
    T6 = data[t][position + 6]

    if M == 'G':
        M = 1
    elif M == 'O':
        M = 2
    elif M == 'R':
        M = 3
    elif M == 'DR':
        M = 4

    if T1 == 'G':
        T1 = 1
    elif T1 == 'O':
        T1 = 2
    elif T1 == 'R':
        T1 = 3
    elif T1 == 'DR':
        T1 = 4

    if T2 == 'G':
        T2 = 1
    elif T2 == 'O':
        T2 = 2
    elif T2 == 'R':
        T2 = 3
    elif T2 == 'DR':
        T2 = 4

    if T3 == 'G':
        T3 = 1
    elif T3 == 'O':
        T3 = 2
    elif T3 == 'R':
        T3 = 3
    elif T3 == 'DR':
        T3 = 4

    if T4 == 'G':
        T4 = 1
    elif T4 == 'O':
        T4 = 2
    elif T4 == 'R':
        T4 = 3
    elif T4 == 'DR':
        T4 = 4

    if T5 == 'G':
        T5 = 1
    elif T5 == 'O':
        T5 = 2
    elif T5 == 'R':
        T5 = 3
    elif T5 == 'DR':
        T5 = 4

    if T6 == 'G':
        T6 = 1
    elif T6 == 'O':
        T6 = 2
    elif T6 == 'R':
        T6 = 3
    elif T6 == 'DR':
        T6 = 4

    C1 = M - T1
    C2 = M - T2
    C3 = M - T4
    C4 = T3 - T4
    C5 = T6 - T5

    if C1 < 0:
        C1 = 0
    if C2 < 0:
        C2 = 0
    if C3 < 0:
        C3 = 0
    if C4 < 0:
        C4 = 0
    if C5 < 0:
        C5 = 0

    C = C1 + C2 + C3 + C4 + C5

    if C == 0:
        C = 1

    return C


def TS2(t):
    position = 4
    M = data[t][position]
    T1 = data[t][position + 1]
    T2 = data[t][position + 3]
    T3 = data[t][position + 4]
    T4 = data[t][position - 3]
    T5 = data[t][position - 1]
    T6 = data[t][position - 2]
    if M == 'G':
        M = 1
    elif M == 'O':
        M = 2
    elif M == 'R':
        M = 3
    elif M == 'DR':
        M = 4

    if T1 == 'G':
        T1 = 1
    elif T1 == 'O':
        T1 = 2
    elif T1 == 'R':
        T1 = 3
    elif T1 == 'DR':
        T1 = 4

    if T2 == 'G':
        T2 = 1
    elif T2 == 'O':
        T2 = 2
    elif T2 == 'R':
        T2 = 3
    elif T2 == 'DR':
        T2 = 4

    if T3 == 'G':
        T3 = 1
    elif T3 == 'O':
        T3 = 2
    elif T3 == 'R':
        T3 = 3
    elif T3 == 'DR':
        T3 = 4

    if T4 == 'G':
        T4 = 1
    elif T4 == 'O':
        T4 = 2
    elif T4 == 'R':
        T4 = 3
    elif T4 == 'DR':
        T4 = 4

    if T5 == 'G':
        T5 = 1
    elif T5 == 'O':
        T5 = 2
    elif T5 == 'R':
        T5 = 3
    elif T5 == 'DR':
        T5 = 4

    if T6 == 'G':
        T6 = 1
    elif T6 == 'O':
        T6 = 2
    elif T6 == 'R':
        T6 = 3
    elif T6 == 'DR':
        T6 = 4

    C1 = M - T1
    C2 = M - T2
    C3 = M - T4
    C4 = T3 - T4
    C5 = T6 - T5

    if C1 < 0:
        C1 = 0
    if C2 < 0:
        C2 = 0
    if C3 < 0:
        C3 = 0
    if C4 < 0:
        C4 = 0
    if C5 < 0:
        C5 = 0

    C = C1 + C2 + C3 + C4 + C5

    if C == 0:
        C = 1

    return C


def TS3(t):
    position = 6
    M = data[t][position]
    T1 = data[t][position + 1]
    T2 = data[t][position - 5]
    T3 = data[t][position - 4]
    T4 = data[t][position - 3]
    T5 = data[t][position - 1]
    T6 = data[t][position - 2]
    if M == 'G':
        M = 1
    elif M == 'O':
        M = 2
    elif M == 'R':
        M = 3
    elif M == 'DR':
        M = 4

    if T1 == 'G':
        T1 = 1
    elif T1 == 'O':
        T1 = 2
    elif T1 == 'R':
        T1 = 3
    elif T1 == 'DR':
        T1 = 4

    if T2 == 'G':
        T2 = 1
    elif T2 == 'O':
        T2 = 2
    elif T2 == 'R':
        T2 = 3
    elif T2 == 'DR':
        T2 = 4

    if T3 == 'G':
        T3 = 1
    elif T3 == 'O':
        T3 = 2
    elif T3 == 'R':
        T3 = 3
    elif T3 == 'DR':
        T3 = 4

    if T4 == 'G':
        T4 = 1
    elif T4 == 'O':
        T4 = 2
    elif T4 == 'R':
        T4 = 3
    elif T4 == 'DR':
        T4 = 4

    if T5 == 'G':
        T5 = 1
    elif T5 == 'O':
        T5 = 2
    elif T5 == 'R':
        T5 = 3
    elif T5 == 'DR':
        T5 = 4

    if T6 == 'G':
        T6 = 1
    elif T6 == 'O':
        T6 = 2
    elif T6 == 'R':
        T6 = 3
    elif T6 == 'DR':
        T6 = 4

    C1 = M - T1
    C2 = M - T2
    C3 = M - T4
    C4 = T3 - T4
    C5 = T6 - T5

    if C1 < 0:
        C1 = 0
    if C2 < 0:
        C2 = 0
    if C3 < 0:
        C3 = 0
    if C4 < 0:
        C4 = 0
    if C5 < 0:
        C5 = 0

    C = C1 + C2 + C3 + C4 + C5

    if C == 0:
        C = 1

    return C


def TS4(t):
    position = 8
    M = data[t][position]
    T1 = data[t][position - 7]
    T2 = data[t][position - 5]
    T3 = data[t][position - 4]
    T4 = data[t][position - 3]
    T5 = data[t][position - 1]
    T6 = data[t][position - 2]
    if M == 'G':
        M = 1
    elif M == 'O':
        M = 2
    elif M == 'R':
        M = 3
    elif M == 'DR':
        M = 4

    if T1 == 'G':
        T1 = 1
    elif T1 == 'O':
        T1 = 2
    elif T1 == 'R':
        T1 = 3
    elif T1 == 'DR':
        T1 = 4

    if T2 == 'G':
        T2 = 1
    elif T2 == 'O':
        T2 = 2
    elif T2 == 'R':
        T2 = 3
    elif T2 == 'DR':
        T2 = 4

    if T3 == 'G':
        T3 = 1
    elif T3 == 'O':
        T3 = 2
    elif T3 == 'R':
        T3 = 3
    elif T3 == 'DR':
        T3 = 4

    if T4 == 'G':
        T4 = 1
    elif T4 == 'O':
        T4 = 2
    elif T4 == 'R':
        T4 = 3
    elif T4 == 'DR':
        T4 = 4

    if T5 == 'G':
        T5 = 1
    elif T5 == 'O':
        T5 = 2
    elif T5 == 'R':
        T5 = 3
    elif T5 == 'DR':
        T5 = 4

    if T6 == 'G':
        T6 = 1
    elif T6 == 'O':
        T6 = 2
    elif T6 == 'R':
        T6 = 3
    elif T6 == 'DR':
        T6 = 4

    C1 = M - T1
    C2 = M - T2
    C3 = M - T4
    C4 = T3 - T4
    C5 = T6 - T5

    if C1 < 0:
        C1 = 0
    if C2 < 0:
        C2 = 0
    if C3 < 0:
        C3 = 0
    if C4 < 0:
        C4 = 0
    if C5 < 0:
        C5 = 0

    C = C1 + C2 + C3 + C4 + C5

    if C == 0:
        C = 1

    return C


i = 20

TO = 2

while t:

    Time = data[i][0]
    print(Time)
    T1 = TS1(i) * 5
    T2 = TS2(i) * 5
    T3 = TS3(i) * 5
    T4 = TS4(i) * 5
    print("T1 = ", T1)
    print("T2 = ", T2)
    print("T3 = ", T3)
    print("T4 = ", T4)

    para = ['led1Gon', 'led1Goff',  # 0 1
            'led1Oon', 'led1Ooff',  # 2 3
            'led1Ron', 'led1Roff',  # 4 5
            'led2Gon', 'led2Goff',  # 6 7
            'led2Oon', 'led2Ooff',  # 8 9
            'led2Ron', 'led2Roff',  # 10 11
            'led3Gon', 'led3Goff',  # 12 13
            'led3Oon', 'led3Ooff',  # 14 15
            'led3Ron', 'led3Roff',  # 16 17
            'led4Gon', 'led4Goff',  # 18 19
            'led4Oon', 'led4Ooff',  # 20 21
            'led4Ron', 'led4Roff']  # 22 23

    if T3 >= T1:
        URL = "http://192.168.4.1/" + para[12]
        r = requests.get(url=URL)
        URL = "http://192.168.4.1/" + para[4]
        r = requests.get(url=URL)
        URL = "http://192.168.4.1/" + para[10]
        r = requests.get(url=URL)
        URL = "http://192.168.4.1/" + para[22]
        r = requests.get(url=URL)
        time.sleep(T3 - T1)
        URL = "http://192.168.4.1/" + para[0]
        r = requests.get(url=URL)
        URL = "http://192.168.4.1/" + para[5]
        r = requests.get(url=URL)
        time.sleep(T1)

    else:
        URL = "http://192.168.4.1/" + para[0]
        r = requests.get(url=URL)
        URL = "http://192.168.4.1/" + para[10]
        r = requests.get(url=URL)
        URL = "http://192.168.4.1/" + para[16]
        r = requests.get(url=URL)
        URL = "http://192.168.4.1/" + para[22]
        r = requests.get(url=URL)
        T = T1 - T3
        time.sleep(T)
        URL = "http://192.168.4.1/" + para[12]
        r = requests.get(url=URL)
        URL = "http://192.168.4.1/" + para[17]
        r = requests.get(url=URL)
        time.sleep(T3)

    URL = "http://192.168.4.1/" + para[1]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[13]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[2]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[14]
    r = requests.get(url=URL)
    time.sleep(TO)

    URL = "http://192.168.4.1/" + para[1]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[3]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[5]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[7]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[9]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[11]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[13]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[15]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[17]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[19]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[21]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[23]
    r = requests.get(url=URL)

    if T2 >= T4:
        URL = "http://192.168.4.1/" + para[6]
        r = requests.get(url=URL)
        URL = "http://192.168.4.1/" + para[4]
        r = requests.get(url=URL)
        URL = "http://192.168.4.1/" + para[16]
        r = requests.get(url=URL)
        URL = "http://192.168.4.1/" + para[22]
        r = requests.get(url=URL)
        time.sleep(T2 - T4)
        URL = "http://192.168.4.1/" + para[18]
        r = requests.get(url=URL)
        URL = "http://192.168.4.1/" + para[23]
        r = requests.get(url=URL)
        time.sleep(T4)

    if T4 > T2:
        URL = "http://192.168.4.1/" + para[18]
        r = requests.get(url=URL)
        URL = "http://192.168.4.1/" + para[4]
        r = requests.get(url=URL)
        URL = "http://192.168.4.1/" + para[16]
        r = requests.get(url=URL)
        URL = "http://192.168.4.1/" + para[10]
        r = requests.get(url=URL)
        time.sleep(T4 - T2)
        URL = "http://192.168.4.1/" + para[6]
        r = requests.get(url=URL)
        URL = "http://192.168.4.1/" + para[11]
        r = requests.get(url=URL)
        time.sleep(T2)

    URL = "http://192.168.4.1/" + para[8]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[20]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[7]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[19]
    r = requests.get(url=URL)
    time.sleep(TO)

    URL = "http://192.168.4.1/" + para[1]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[3]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[5]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[7]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[9]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[11]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[13]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[15]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[17]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[19]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[21]
    r = requests.get(url=URL)
    URL = "http://192.168.4.1/" + para[23]
    r = requests.get(url=URL)



    i += 1

    if i == 98:
        t = False
