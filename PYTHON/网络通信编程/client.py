import socket
from threading import Thread, Lock
import datetime

class Client:
    def __init__(self, name, address):
        self.name = name
        self.addr = address
        self.lock = Lock()

    def start_client(self):
        client = socket.socket()
        client.connect(self.addr)
        """创建一个接收消息的子线程"""
        recv = Thread(target=self.recv_msg, args=(client,))
        recv.start()
        while True:
            msg = input()
            msgs =str(datetime.datetime.now())[:-7]+'  '+ self.name + ":" + msg
            client.send(msgs.encode(encoding="utf-8"))
            if "拜拜" in msg:
                break
        client.close()


    def recv_msg(self, client):
        """接收消息的子线程函数"""
        while True:
            data = client.recv(1024).decode(encoding='utf-8')
            print(data)



def main():
    client = Client("A", ('192.168.2.103', 8080))
    client.start_client()


if __name__ == "__main__":
    main()
