import socket

RemoteIP = '10.42.0.131' # 送信先のIPアドレス
RemotePort = 65534       # 送信先のポート番号

LocalIP = '10.42.0.1'    # 自身のIPアドレス
LocalPort = 65535        # 自身のポート番号

M_SIZE = 1024

remote_addr = (RemoteIP, RemotePort)
local_addr = (LocalIP, LocalPort)

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(local_addr)

while True:
    try:
        # ②messageを送信する
        print('Input any messages, Type [end] to exit')
        message = input()
        if message != 'end':
            send_len = sock.sendto(message.encode('utf-8'), remote_addr)
        
            # ③Serverからのmessageを受付開始
            print('Waiting response from Server')
            rx_meesage, addr = sock.recvfrom(M_SIZE)
            print(f"[Server]: {rx_meesage.decode(encoding='utf-8')}")

        else:
            print('closing socket')
            sock.close()
            print('done')
            break

    except KeyboardInterrupt:
        print('closing socket')
        sock.close()
        print('done')
        break